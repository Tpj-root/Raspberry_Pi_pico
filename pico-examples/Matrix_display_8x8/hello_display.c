#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi1
#define PIN_MOSI 11
#define PIN_SCK  12
#define PIN_CS   10

void max7219_send(uint8_t reg, uint8_t data) {
    gpio_put(PIN_CS, 0);
    uint8_t buf[2] = {reg, data};
    spi_write_blocking(SPI_PORT, buf, 2);
    gpio_put(PIN_CS, 1);
}

void max7219_init() {
    max7219_send(0x09, 0x00); // Decode mode off
    max7219_send(0x0A, 0x03); // Intensity (0x00–0x0F)
    max7219_send(0x0B, 0x07); // Scan limit = 8 LEDs
    max7219_send(0x0C, 0x01); // Normal operation
    max7219_send(0x0F, 0x00); // Test mode off
}

void max7219_clear() {
    for (int i = 1; i <= 8; i++)
        max7219_send(i, 0x00);
}

void max7219_pattern(const uint8_t *pattern) {
    for (int i = 0; i < 8; i++)
        max7219_send(i + 1, pattern[i]);
}

int main() {
    stdio_init_all();

    spi_init(SPI_PORT, 10000000);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);

    max7219_init();

    uint8_t smiley[8] = {
        0b11111111,
        0b11111111,
        0b11111111,
        0b10000001,
        0b11111111,
        0b11111111,
        0b11111111,
        0b11111111
    };

    while (true) {
        max7219_pattern(smiley);
        sleep_ms(500);
        max7219_clear();
        sleep_ms(500);
    }
}



