Here’s a fast-track **Picotool guide** — from basic to advanced — all in short, practical commands 👇

---

## 🧩 1. What it is

`picotool` is a command-line tool to:

* Detect RP2040 boards
* Flash UF2 or BIN files
* Read info and memory
* Erase or reboot the board

---

## 🚀 2. Check connection

Put Pico in **BOOTSEL** mode (hold BOOTSEL button → plug USB).

```bash
picotool info
```

Shows flash range, program name, version, etc.
If it says *“No device found”*, try `sudo` or fix udev rule.

---

## 📦 3. Flash new program

```bash
picotool load myprogram.uf2
```

or

```bash
picotool load myfirmware.bin --offset 0x10000000
```

✅ It automatically reboots after upload unless you use `--no-auto-reboot`.

---

## 🔍 4. List connected devices

```bash
picotool list
```

Shows all Pico boards detected.

---

## 🧠 5. Memory / Flash operations

Read a portion of memory or save flash contents:

```bash
picotool save flash_dump.bin
picotool save flash_part.bin --offset 0x10000000 --length 0x2000
```

Erase flash completely:

```bash
picotool erase
```

---

## 🔄 6. Reboot modes

Reboot normally:

```bash
picotool reboot
```

Reboot into BOOTSEL:

```bash
picotool reboot --usb-boot
```

---

## ⚙️ 7. Inspect firmware info

Get metadata inside the loaded binary:

```bash
picotool info --all
```

It lists:

* Program name
* Build date
* Git revision
* SDK version
* Sections and memory map

---

## 💡 8. Combine with Make or scripts

Example script to build and flash automatically:

```bash
mkdir build && cd build
cmake ..
make -j4
picotool load my_app.uf2 && picotool reboot
```

---

## 🧠 9. Debugging tip

If the board doesn’t show:

* Check `lsusb` → should show `2e8a:0003`
* Try another USB cable or port
* Make sure the board is in BOOTSEL mode

---

## ⚡ 10. Pro shortcuts

| Task                  | Command                      |
| --------------------- | ---------------------------- |
| Flash + reboot        | `picotool load app.uf2`      |
| Just get program name | `picotool info -n`           |
| Save firmware         | `picotool save backup.uf2`   |
| Erase flash           | `picotool erase`             |
| Reboot to BOOTSEL     | `picotool reboot --usb-boot` |

---

Want me to make a **one-file Bash helper script** with shortcuts like
`pico_flash app.uf2`, `pico_reboot`, `pico_save` etc.?




Perfect — here’s a clean and powerful **Bash function set** that gives you quick Pico commands:

---

### ⚙️ Add these to your `~/.bashrc`

```bash
# =============================
# 🧩 Raspberry Pi Pico Tools
# =============================

# Flash a UF2 or BIN file to Pico
pico_flash() {
    if [ -z "$1" ]; then
        echo "Usage: pico_flash <file.uf2 | file.bin>"
        return 1
    fi

    local file="$1"
    echo "🔍 Checking for Pico in BOOTSEL mode..."
    if ! picotool list >/dev/null 2>&1; then
        echo "❌ No Pico found. Hold BOOTSEL and plug in your Pico."
        return 1
    fi

    echo "🚀 Flashing: $file"
    if [[ "$file" == *.bin ]]; then
        picotool load "$file" --offset 0x10000000
    else
        picotool load "$file"
    fi

    echo "✅ Flash complete! Rebooting..."
    picotool reboot
}

# Save the current firmware from Pico
pico_save() {
    local out="${1:-pico_backup.uf2}"
    echo "💾 Saving firmware to: $out"
    picotool save "$out"
    echo "✅ Backup done!"
}

# Reboot Pico normally
pico_reboot() {
    echo "🔄 Rebooting Pico..."
    picotool reboot
    echo "✅ Done!"
}

# Reboot Pico into BOOTSEL mode
pico_bootsel() {
    echo "🌀 Rebooting Pico into BOOTSEL mode..."
    picotool reboot --usb-boot
    echo "✅ Pico is now in BOOTSEL mode."
}

# Show Pico info
pico_info() {
    echo "📋 Pico Information:"
    picotool info --all
}
```

---

### 🧠 How to activate

1. Open:

   ```bash
   nano ~/.bashrc
   ```
2. Paste all the functions at the end.
3. Save and reload:

   ```bash
   source ~/.bashrc
   ```

---

### ⚡ Usage

```bash
pico_flash blink.uf2      # Flash new firmware
pico_reboot               # Normal reboot
pico_bootsel              # Reboot to BOOTSEL
pico_save backup.uf2      # Save firmware to file
pico_info                 # Show full details
```

---


where@slave:~/Desktop/MY_GIT/Raspberry_Pi_pico/pico-examples/usb/device/dev_hid_composite$     picotool info --all
Program Information
 name:              dev_hid_composite
 binary start:      0x10000000
 binary end:        0x10005500

Fixed Pin Information
 0:                 UART0 TX
 1:                 UART0 RX
 25:                LED

Build Information
 sdk version:       2.2.0
 pico_board:        pico
 boot2_name:        boot2_w25q080
 build date:        Nov  9 2025
 build attributes:  Release

Device Information
 type:              RP2040
 revision:          B2
 flash size:        2048K
 flash id:          0xE6612483CB6B6424

Metadata Blocks





If the file includes metadata (like example_auto_set_url()), you’ll see something like:


where@slave:~/pico/pico-examples/build/adc/adc_console$ picotool info adc_console.uf2
File adc_console.uf2 family ID 'rp2040':

Program Information
 name:          adc_console
 web site:      https://github.com/raspberrypi/pico-examples/tree/HEAD/adc/adc_console
 features:      UART stdin / stdout
 binary start:  0x10000000
 binary end:    0x10004fbc
where@slave:~/pico/pico-examples/build/adc/adc_console$ 




