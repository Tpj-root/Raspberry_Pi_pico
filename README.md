# Raspberry_Pi_pico

picotool

```
sudo apt install cmake gcc g++ git libusb-1.0-0-dev build-essential
git clone https://github.com/raspberrypi/picotool.git
mkdir build
cd build
cmake ..
make -j4
alias picotool='~/Desktop/RUN_TIME/picotool/build/picotool'


```



🧩 1. Install required tools
Basic essendial packahes for build pico firmware

```
sudo apt update
sudo apt install cmake gcc-arm-none-eabi build-essential git



```


2. Get the Pico SDK

```


mkdir ~/pico
cd ~/pico
git clone -b master https://github.com/raspberrypi/pico-sdk.git
git clone -b master https://github.com/raspberrypi/pico-examples.git


```


Then link SDK path:

```
cd ~/pico/pico-sdk
git submodule update --init

export PICO_SDK_PATH=~/pico/pico-sdk
```




🏗️ 3. Build a sample (like blink)

```
cd ~/pico/pico-examples/blink
mkdir build && cd build
cmake ..
make


```



After it runs, list files again:

```bash
ls
```

You’ll see files like:

```
blink.uf2
blink.elf
blink.bin
```

👉 The one you need to upload is:

```
blink.uf2
```

---

### 🚀 To upload:

1. Hold **BOOTSEL** on Pico.
2. Plug it into USB — it shows as a drive (e.g. `RPI-RP2`).
3. Copy `blink.uf2` into that drive.
4. The board reboots — LED starts blinking ✅




Perfect 👍 — your Pico is in **BOOTSEL mode** (`2e8a:0003`).

Now just copy your built UF2 file to it:

```bash
cp blink.uf2 /media/$USER/RPI-RP2/
```

or manually:

* Open file manager
* You’ll see a drive named **RPI-RP2**
* Drag and drop `blink.uf2` into it

After a few seconds it’ll auto-disconnect and reboot —
✅ the onboard LED (GPIO 25) should start blinking.


No — that won’t work ⚠️

`/media/$USER/RPI-RP2/` is the Pico’s flash drive **only when it’s in BOOTSEL mode**.
You can **copy *to* it**, but not **from** it — it’s read-only except for flashing UF2 files.

So:

```bash
cp blink.uf2 /media/$USER/RPI-RP2/
```

✅ **works** (uploads firmware)

but

```bash
cp /media/$USER/RPI-RP2/blink.uf2 .
```

❌ **doesn’t work**, because the Pico’s drive doesn’t keep files — once copied, it flashes the chip and unmounts itself.







Bus 005 Device 005: ID cafe:4004 TinyUSB TinyUSB Device






That message means your Pico is **detected** (USB connection works), but your **user doesn’t have permission** to access it directly.

Here’s how to fix it:

---

### 🧩 Option 1 — Run with `sudo`

Quick test:

```bash
sudo ./picotool info
```

If that works, it’s just a permissions issue (most likely).

---

### ⚙️ Option 2 — Create a udev rule (permanent fix)

1. Create a new udev rule file:

   ```bash
   sudo nano /etc/udev/rules.d/99-pico.rules
   ```

2. Paste this line inside:

   ```bash
   SUBSYSTEM=="usb", ATTRS{idVendor}=="2e8a", MODE="0666"
   ```

3. Save and exit (`Ctrl+O`, `Enter`, `Ctrl+X`).

4. Reload udev rules:

   ```bash
   sudo udevadm control --reload-rules
   sudo udevadm trigger
   ```

5. Unplug your Pico and plug it in again.

6. Now try:

   ```bash
   ./picotool info
   ```

   or just:

   ```bash
   picotool info
   ```

✅ You’ll get full Pico information **without sudo**.

---



Good question.

That **udev rule** tells Linux to automatically give **normal user-level access** to your Raspberry Pi Pico when it connects over USB.

Without it, only **root (sudo)** can talk to the device, because by default USB devices under `/dev/bus/usb/...` are readable only by `root`.

---

### 🔍 What the line does

```bash
SUBSYSTEM=="usb", ATTRS{idVendor}=="2e8a", MODE="0666"
```

| Part                      | Meaning                                                              |
| ------------------------- | -------------------------------------------------------------------- |
| `SUBSYSTEM=="usb"`        | Applies this rule only to USB devices.                               |
| `ATTRS{idVendor}=="2e8a"` | Matches Raspberry Pi Pico boards (their USB vendor ID is `2e8a`).    |
| `MODE="0666"`             | Sets read/write permission for all users (so you don’t need `sudo`). |

---

### ✅ Result

After adding it:

* You can run `picotool info`, `picotool load`, or `picotool reboot` **without sudo**.
* No need to change file permissions each time you plug the Pico in.

It’s a **standard, safe fix** used in most Pico setups.


