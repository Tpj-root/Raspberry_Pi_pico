// main.c
// HID keyboard example: after USB mount wait 10s, then type "hello" 10 times.
//
// Requires: pico sdk + tinyusb. Keep your existing usb_descriptors.c/h and tusb_config.h.

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "tusb.h"

// HID usages for a-z (HID usage IDs start at 0x04 for 'a')
#define HID_KEY_A 0x04
// space
#define HID_KEY_SPACE 0x2C

// Translate a simple ASCII lowercase letter or space to HID key usage.
// Only implements: 'a'..'z' and ' ' (space). Returns 0 if unsupported.
static uint8_t ascii_to_hid(char c) {
    if (c >= 'a' && c <= 'z') {
        return (uint8_t)(HID_KEY_A + (c - 'a'));
    }
    if (c == ' ') return HID_KEY_SPACE;
    return 0;
}

// send one HID keyboard report (up to 6 keys). We send single key then release.
static void hid_send_key(uint8_t keycode)
{
    if (!tud_hid_ready()) return; // ensure host is ready to receive reports

    uint8_t report[6] = {0};
    report[0] = keycode;
    // modifier = 0 (no shift)
    tud_hid_keyboard_report(0, 0, report);
    // short hold so host registers key press
    sleep_ms(20);
    // release keys
    memset(report, 0, sizeof(report));
    tud_hid_keyboard_report(0, 0, report);
    // small gap after release
    sleep_ms(20);
}

// send a plain-lowercase string (letters and spaces only)
static void hid_send_string_lower(const char *s)
{
    for (size_t i = 0; i < strlen(s); ++i) {
        char c = s[i];
        uint8_t key = ascii_to_hid(c);
        if (key) {
            hid_send_key(key);
        } else {
            // unsupported char -> send space as fallback
            hid_send_key(HID_KEY_SPACE);
        }
    }
}

// Called when host requests data from device (e.g. Get Report)
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id,
                               hid_report_type_t report_type,
                               uint8_t* buffer, uint16_t reqlen)
{
    (void) instance;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) reqlen;
    return 0; // No data to send
}

// Called when host sends data to device (e.g. Set Report)
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id,
                           hid_report_type_t report_type,
                           uint8_t const* buffer, uint16_t bufsize)
{
    (void) instance;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) bufsize;
    // Not used for keyboard example
}



int main(void)
{
    stdio_init_all();

    // initialize TinyUSB stack
    tusb_init();

    printf("HID keyboard example starting...\n");
    printf("Plug board into a host and wait for 10s after mount to send 'hello' x10.\n");

    bool sent = false;

    while (true) {
        // TinyUSB background tasks
        tud_task(); // tinyusb device task

        // when device is mounted, perform action once
        if (tud_mounted() && !sent) {
            // give host a moment
            sleep_ms(100);

            // Wait 10 seconds (while still servicing tinyusb)
            const uint32_t wait_ms = 10000;
            const uint32_t slice = 10;
            uint32_t elapsed = 0;
            while (elapsed < wait_ms) {
                tud_task();
                sleep_ms(slice);
                elapsed += slice;
            }

            // Now send "hello" 10 times
            for (int i = 0; i < 10; ++i) {
                // ensure HID interface ready before each send
                // (if not ready, wait a bit)
                uint32_t wait_for = 0;
                while (!tud_hid_ready() && wait_for < 5000) {
                    tud_task();
                    sleep_ms(10);
                    wait_for += 10;
                }

                hid_send_string_lower("hello");
                // small pause between repeated words
                sleep_ms(300);
            }

            sent = true;
            printf("Done sending.\n");
        }

        // light sleep to avoid burning CPU, still call tud_task frequently
        sleep_ms(10);
    }

    return 0;
}

