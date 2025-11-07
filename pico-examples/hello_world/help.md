





before `pico_add_extra_outputs`, add these two lines to enable USB serial output:

```cmake
pico_enable_stdio_usb(hello_serial 1)
pico_enable_stdio_uart(hello_serial 0)
```

so final lines should look like:

```cmake
target_link_libraries(hello_serial pico_stdlib)

pico_enable_stdio_usb(hello_serial 1)
pico_enable_stdio_uart(hello_serial 0)

pico_add_extra_outputs(hello_serial)
```

then rebuild → copy the new `.uf2` → replug Pico →
check `ls /dev/ttyACM*` → use `screen /dev/ttyACM0 115200`.





Afr also work
```

where@slave:~$ lsusb
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 002 Device 002: ID 292b:f115 USB 2.0 USB Audio Device
Bus 003 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 003 Device 002: ID 1a2c:2124 China Resource Semico Co., Ltd Keyboard
Bus 004 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 004 Device 002: ID 30fa:0301  USB OPTICAL MOUSE 
Bus 005 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 005 Device 016: ID 2e8a:000a Raspberry Pi Pico
where@slave:~$ 


show the value 
Bus 005 Device 016: ID 2e8a:000a Raspberry Pi Pico

```





ls /dev/ttyACM*

where@slave:~/Desktop/MY_GIT/Raspberry_Pi_pico/pico-examples/blink/build$ ls /dev/ttyACM*
/dev/ttyACM0


After that work


screen /dev/ttyACM0 115200


minicom -b 115200 -o -D /dev/ttyACM0









* **hello_serial** → uses **UART** (TX/RX pins, e.g. GP0/GP1).

  * You connect via USB-to-UART cable.
  * Output visible on `/dev/ttyUSB0` (external adapter).
  * `pico_enable_stdio_uart(1)`

* **hello_usb** → uses **USB CDC (TinyUSB)** — the Pico becomes a **USB device** itself.

  * Connect Pico directly with USB cable.
  * Output visible on `/dev/ttyACM0`.
  * `pico_enable_stdio_usb(1)`

🧠 In short:

* **serial = physical UART pins**
* **usb = virtual serial port over USB**



Exactly ✅

Here’s the difference:

* **`/dev/ttyACM0` → USB CDC (Virtual Serial Port)**

  * Created by the **Pico’s USB interface** using TinyUSB.
  * Works like a *USB device* (like a virtual COM port).
  * It’s **not a real UART pin**, but handled by USB.
  * Can act like a keyboard/mouse **only if firmware is changed to HID mode**.

* **`/dev/ttyUSB0` → Hardware Serial (via USB-Serial adapter)**

  * Connected to **TX/RX GPIO pins** through an external USB-UART converter (e.g., CH340, CP2102, FTDI).
  * This is **true UART communication**, not USB emulation.

🧠 So:

* `ttyACM0` → virtual USB serial (firmware-side emulated).
* `ttyUSB0` → real hardware serial pins through adapter.



Here’s a clear table 👇

| Feature              | Enable Function                                                         | Port Name (on Linux)                               | Connection Type                               | Purpose / Use                                                            |
| -------------------- | ----------------------------------------------------------------------- | -------------------------------------------------- | --------------------------------------------- | ------------------------------------------------------------------------ |
| **UART Serial**      | `pico_enable_stdio_uart(target 1)`<br>`pico_enable_stdio_usb(target 0)` | `/dev/ttyUSB0` *(via external USB-Serial adapter)* | Uses **GPIO 0 (TX)** and **GPIO 1 (RX)** pins | For debugging through hardware UART lines; needs a USB-Serial converter. |
| **USB Serial (CDC)** | `pico_enable_stdio_usb(target 1)`<br>`pico_enable_stdio_uart(target 0)` | `/dev/ttyACM0`                                     | Virtual **USB COM port** using TinyUSB        | For printing logs over USB without external hardware.                    |
| **Both enabled**     | `pico_enable_stdio_usb(target 1)`<br>`pico_enable_stdio_uart(target 1)` | `/dev/ttyACM0` and `/dev/ttyUSB0` (both visible)   | USB + UART together                           | Send same output to both ports for testing or redundancy.                |

💡 **Summary:**

* `/dev/ttyUSB0` → hardware serial via pins (needs adapter).
* `/dev/ttyACM0` → virtual serial over USB (built-in TinyUSB).





ls /dev/ttyACM*


ls /dev/ttyUSB*


Your **CMake file is correct** for UART output 👍 —
but the reason you **don’t see any port** is simple:

🧩 **UART (stdio_uart=1)** doesn’t create a USB device.
It uses **Pico’s GPIO pins**:

* TX → **GP0**
* RX → **GP1**

So Linux won’t show `/dev/ttyACM0` or `/dev/ttyUSB0`.

To **view the output**, you must:

1. Connect a **USB–Serial adapter** (e.g. CH340, CP2102, FTDI) to Pico’s pins:

   * Pico GP0 → Adapter RX
   * Pico GND → Adapter GND
2. Plug adapter into your PC → it appears as `/dev/ttyUSB0`.
3. Then run:

   ```bash
   screen /dev/ttyUSB0 115200
   ```

   or

   ```bash
   minicom -b 115200 -D /dev/ttyUSB0
   ```

💡 If you want output via Pico’s **own USB port**, change:

```cmake
pico_enable_stdio_usb(hello_serial 1)
pico_enable_stdio_uart(hello_serial 0)
```

That makes it appear as `/dev/ttyACM0`.



