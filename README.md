# Raspberry_Pi_pico


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





