---

# 🧠 Raspberry Pi Pico UF2 Collection

A curated collection of compiled **`.uf2` firmware examples** built for the **Raspberry Pi Pico**, covering peripherals, subsystems, and SDK demonstrations.
Each file can be dragged directly onto the Pico’s USB drive to flash the board.

---

## 📂 Root

| File                 | Description                                        |
| -------------------- | -------------------------------------------------- |
| `hello_divider.uf2`  | Demonstrates hardware divider operation on RP2040. |
| `hello_watchdog.uf2` | Tests and showcases watchdog timer reset handling. |

---

## 📁 adc

| File                      | Description                                           |
| ------------------------- | ----------------------------------------------------- |
| `adc_console.uf2`         | Interactive ADC readings printed via console.         |
| `adc_dma_capture.uf2`     | Captures ADC samples using DMA transfer.              |
| `hello_adc.uf2`           | Basic analog-to-digital conversion example.           |
| `joystick_display.uf2`    | Reads joystick ADC values and shows position.         |
| `microphone_adc.uf2`      | Streams analog microphone data via ADC input.         |
| `onboard_temperature.uf2` | Reads Pico’s internal temperature sensor through ADC. |
| `read_vsys.uf2`           | Measures VSYS voltage using ADC channel.              |

---

## 📁 binary_info

| File                 | Description                                        |
| -------------------- | -------------------------------------------------- |
| `blink_any.uf2`      | Minimal binary info blink demo.                    |
| `hello_anything.uf2` | Custom metadata and binary info embedding example. |

---

## 📁 blink

| File        | Description                               |
| ----------- | ----------------------------------------- |
| `blink.uf2` | Classic LED blink demo using GPIO output. |

---

## 📁 blink_simple

| File               | Description                              |
| ------------------ | ---------------------------------------- |
| `blink_simple.uf2` | Simplified minimal version of LED blink. |

---

## 📁 clocks

| File                           | Description                                           |
| ------------------------------ | ----------------------------------------------------- |
| `clocks_detached_clk_peri.uf2` | Demonstrates detached peripheral clock configuration. |
| `hello_48MHz.uf2`              | Sets and verifies 48 MHz clock output.                |
| `hello_gpout.uf2`              | Outputs clock signal on GPIO pin.                     |
| `hello_resus.uf2`              | Tests clock resuscitation after failure.              |

---

## 📁 cmake

| File                 | Description                             |
| -------------------- | --------------------------------------- |
| `build_variant1.uf2` | Example build variant configuration #1. |
| `build_variant2.uf2` | Example build variant configuration #2. |

---

## 📁 dma

| File                     | Description                              |
| ------------------------ | ---------------------------------------- |
| `dma_channel_irq.uf2`    | DMA transfer with interrupt callback.    |
| `dma_control_blocks.uf2` | Linked DMA control blocks demonstration. |
| `hello_dma.uf2`          | Basic DMA memory copy test.              |
| `sniff_crc.uf2`          | Computes CRC using DMA sniff hardware.   |

---

## 📁 flash

| File                      | Description                             |
| ------------------------- | --------------------------------------- |
| `flash_cache_perfctr.uf2` | Measures flash cache performance.       |
| `flash_nuke.uf2`          | Erases all flash memory on board.       |
| `flash_program.uf2`       | Demonstrates flash programming via SDK. |
| `flash_ssi_dma.uf2`       | Writes flash using SSI DMA engine.      |
| `flash_xip_stream.uf2`    | Reads data directly via XIP interface.  |

---

## 📁 gpio

| File                 | Description                                     |
| -------------------- | ----------------------------------------------- |
| `dht.uf2`            | Reads DHT temperature/humidity sensor via GPIO. |
| `hello_7segment.uf2` | Drives a 7-segment display using GPIO pins.     |
| `hello_gpio_irq.uf2` | Shows interrupt handling on GPIO input.         |

---

## 📁 hello_world

| File               | Description                              |
| ------------------ | ---------------------------------------- |
| `hello_serial.uf2` | Sends text via UART serial console.      |
| `hello_usb.uf2`    | Sends text via USB CDC serial interface. |

---

## 📁 i2c

| File                      | Description                                    |
| ------------------------- | ---------------------------------------------- |
| `bmp280_i2c.uf2`          | Reads temperature/pressure from BMP280 sensor. |
| `ht16k33_i2c.uf2`         | Drives LED matrix via HT16K33 driver.          |
| `i2c_bus_scan.uf2`        | Scans and lists I²C devices on the bus.        |
| `lcd_1602_i2c.uf2`        | Controls 16×2 LCD using I²C interface.         |
| `lis3dh_i2c.uf2`          | Reads accelerometer data via LIS3DH sensor.    |
| `mcp9808_i2c.uf2`         | Reads ambient temperature from MCP9808.        |
| `mma8451_i2c.uf2`         | Demonstrates MMA8451 motion sensor.            |
| `mpl3115a2_i2c.uf2`       | Altitude/pressure sensor example via I²C.      |
| `mpu6050_i2c.uf2`         | Reads 6-axis gyro/accel data from MPU6050.     |
| `pa1010d_i2c.uf2`         | GPS module demo using PA1010D via I²C.         |
| `pcf8523_i2c.uf2`         | Real-time clock communication with PCF8523.    |
| `slave_mem_i2c.uf2`       | Implements an I²C slave with memory buffer.    |
| `slave_mem_i2c_burst.uf2` | Burst read/write slave memory example.         |
| `ssd1306_i2c.uf2`         | OLED display demo via SSD1306 controller.      |

---

## 📁 interp

| File               | Description                                |
| ------------------ | ------------------------------------------ |
| `hello_interp.uf2` | Demonstrates RP2040 interpolator hardware. |

---

## 📁 multicore

| File                         | Description                               |
| ---------------------------- | ----------------------------------------- |
| `hello_multicore.uf2`        | Simple multicore printing demo.           |
| `multicore_fifo_irqs.uf2`    | Core-to-core FIFO with interrupts.        |
| `multicore_runner.uf2`       | Basic multicore function runner.          |
| `multicore_runner_queue.uf2` | Task queue synchronization between cores. |

---

## 📁 picoboard

| File                   | Description                     |
| ---------------------- | ------------------------------- |
| `picoboard_blinky.uf2` | PicoBoard LED blink demo.       |
| `picoboard_button.uf2` | PicoBoard button input example. |

---

## 📁 pio

| File                                 | Description                                      |
| ------------------------------------ | ------------------------------------------------ |
| `hello_pio.uf2`                      | Minimal PIO program demonstration.               |
| `pio_addition.uf2`                   | Performs addition in PIO logic.                  |
| `pio_apa102.uf2`                     | Drives APA102 (DotStar) LEDs using PIO.          |
| `pio_blink.uf2`                      | LED blink implemented entirely in PIO.           |
| `pio_clocked_input.uf2`              | Samples input data synchronized to a clock.      |
| `pio_differential_manchester.uf2`    | Encodes/decodes differential Manchester signals. |
| `pio_hub75.uf2`                      | Drives RGB matrix using HUB75 protocol.          |
| `pio_i2c_bus_scan.uf2`               | I²C scanner implemented with PIO.                |
| `pio_ir_loopback.uf2`                | IR transmit/receive test with PIO.               |
| `pio_logic_analyser.uf2`             | Basic logic analyzer using PIO.                  |
| `pio_manchester_encoding.uf2`        | Demonstrates Manchester encoding scheme.         |
| `pio_onewire.uf2`                    | One-Wire protocol example.                       |
| `pio_pwm.uf2`                        | PWM waveform generation using PIO.               |
| `pio_quadrature_encoder.uf2`         | Reads rotary encoder using PIO.                  |
| `pio_quadrature_encoder_substep.uf2` | High-precision quadrature decoding.              |
| `pio_spi_flash.uf2`                  | SPI flash interface driven by PIO.               |
| `pio_spi_loopback.uf2`               | SPI data loopback test using PIO.                |
| `pio_squarewave.uf2`                 | Generates square wave signal.                    |
| `pio_squarewave_div_sync.uf2`        | Synchronized square wave output example.         |
| `pio_st7789_lcd.uf2`                 | Drives ST7789 TFT display via PIO SPI.           |
| `pio_uart_dma.uf2`                   | UART communication via DMA using PIO.            |
| `pio_uart_rx.uf2`                    | PIO-based UART receiver example.                 |
| `pio_uart_rx_intr.uf2`               | UART RX with interrupt handling.                 |
| `pio_uart_tx.uf2`                    | PIO-based UART transmitter example.              |
| `pio_ws2812.uf2`                     | Controls WS2812 RGB LEDs (Neopixels).            |
| `pio_ws2812_parallel.uf2`            | Parallel control of multiple WS2812 LED strips.  |

---

## 📁 pwm

| File                         | Description                               |
| ---------------------------- | ----------------------------------------- |
| `hello_pwm.uf2`              | Basic PWM signal output.                  |
| `pwm_led_fade.uf2`           | LED brightness fade using PWM duty cycle. |
| `pwm_measure_duty_cycle.uf2` | Measures input signal duty cycle.         |

---

## 📁 reset

| File              | Description                                       |
| ----------------- | ------------------------------------------------- |
| `hello_reset.uf2` | Demonstrates software and hardware reset control. |

---

## 📁 rtc

| File                   | Description                           |
| ---------------------- | ------------------------------------- |
| `hello_rtc.uf2`        | Shows real-time clock setup and read. |
| `rtc_alarm.uf2`        | RTC alarm trigger demonstration.      |
| `rtc_alarm_repeat.uf2` | Periodic repeating RTC alarm.         |

---

## 📁 spi

| File                     | Description                                    |
| ------------------------ | ---------------------------------------------- |
| `bme280_spi.uf2`         | Reads environmental data from BME280 via SPI.  |
| `max7219_8x7seg_spi.uf2` | Drives 8×7-segment displays using MAX7219.     |
| `max7219_32x8_spi.uf2`   | 32×8 LED matrix example with MAX7219.          |
| `mpu9250_spi.uf2`        | Communicates with MPU9250 9-axis IMU over SPI. |
| `spi_dma.uf2`            | SPI communication using DMA transfers.         |
| `spi_flash.uf2`          | Reads/writes data to SPI flash device.         |
| `spi_master.uf2`         | Master mode SPI demo.                          |
| `spi_slave.uf2`          | SPI slave mode demonstration.                  |

---

## 📁 status_led

| File               | Description                                |
| ------------------ | ------------------------------------------ |
| `color_blink.uf2`  | Multi-color RGB LED blink pattern.         |
| `status_blink.uf2` | System status indication via LED blinking. |

---

## 📁 system

| File                   | Description                                 |
| ---------------------- | ------------------------------------------- |
| `hello_double_tap.uf2` | Tests double-tap reset bootloader feature.  |
| `narrow_io_write.uf2`  | Demonstrates narrow I/O write timing.       |
| `rand.uf2`             | Hardware random number generator example.   |
| `unique_board_id.uf2`  | Reads and displays Pico’s unique serial ID. |

---

## 📁 timer

| File                   | Description                             |
| ---------------------- | --------------------------------------- |
| `hello_timer.uf2`      | Simple timer-based LED blink.           |
| `periodic_sampler.uf2` | Samples data periodically using timers. |
| `timer_lowlevel.uf2`   | Direct hardware timer access example.   |

---

## 📁 uart

| File                | Description                                     |
| ------------------- | ----------------------------------------------- |
| `hello_uart.uf2`    | Basic UART send/receive demonstration.          |
| `lcd_uart.uf2`      | Controls character LCD via UART interface.      |
| `uart_advanced.uf2` | Advanced UART config: parity, FIFO, interrupts. |

---

## 📁 usb

| File                             | Description                                                                 |
| -------------------------------- | --------------------------------------------------------------------------- |
| `dev_hid_composite.uf2`          | HID composite device example.                                               |
| `dev_lowlevel.uf2`               | Low-level USB device setup.                                                 |
| `dev_multi_cdc.uf2`              | Multiple virtual COM ports via USB.                                         |
| `dev_midi_test.uf2`              | USB MIDI sound test.                                                        |
| `dev_board_test.uf2`             | Board capability USB test.                                                  |
| `dev_cdc_msc.uf2`                | Combined serial and mass storage device.                                    |
| `dev_cdc_dual_ports.uf2`         | Dual serial interface demo.                                                 |
| `dev_cdc_uac2.uf2`               | Composite USB Audio + CDC demo.                                             |
| `dev_dfu.uf2`                    | USB DFU firmware update example.                                            |
| `dev_dfu_runtime.uf2`            | Runtime DFU descriptor demo.                                                |
| `dev_dynamic_configuration.uf2`  | Demonstrates runtime USB configuration switching.                           |
| `dev_hid_boot_interface.uf2`     | HID boot protocol example.                                                  |
| `dev_hid_generic_inout.uf2`      | Generic HID in/out data example.                                            |
| `dev_hid_multiple_interface.uf2` | HID device with multiple report interfaces.                                 |
| `dev_msc_dual_lun.uf2`           | Dual logical unit USB mass storage.                                         |
| `dev_net_lwip_webserver.uf2`     | USB Ethernet interface with LWIP webserver.                                 |
| `dev_audio_4_channel_mic.uf2`    | Four-channel USB microphone streaming.                                      |
| `dev_audio_test_multi_rate.uf2`  | Audio streaming with multiple sample rates.                                 |
| `dev_audio_test.uf2`             | Basic USB audio loopback test.                                              |
| `dev_uac2_headset.uf2`           | USB Audio Class 2 headset example.                                          |
| `dev_uac2_speaker_fb.uf2`        | Feedback-enabled USB speaker.                                               |
| `dev_usbtmc.uf2`                 | USB Test & Measurement Class (TMC) demo.                                    |
| `dev_video_capture.uf2`          | Simple USB video device.                                                    |
| `dev_video_capture_2ch.uf2`      | Dual-channel USB video stream example.                                      |
| `host_bare_api.uf2`              | Bare-metal USB host stack example.                                          |
| `host_cdc_msc_hid.uf2`           | USB host for CDC, MSC, HID devices.                                         |
| `host_device_info.uf2`           | Reads descriptors of attached USB devices.                                  |
| `host_hid_controller.uf2`        | USB host handling HID gamepad/mouse.                                        |
| `host_msc_file_explorer.uf2`     | USB host mass-storage file explorer.                                        |
| `tinyusb_host_bare_api.uf2`      | TinyUSB host API minimal example.                                           |
| `tinyusb_dev_*` (all)            | TinyUSB device demos for composite, audio, video, HID, and network classes. |

---

