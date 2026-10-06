# Setup & Installation

This guide explains how to compile and flash the reconstructed firmware to your ESP32.

## Prerequisites
- Visual Studio Code with the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode) installed.
- An ESP32-WROOM-32D development board and a micro-USB (or USB-C) cable capable of data transfer.

## Hardware Assembly
Ensure the hardware is assembled according to the specifications in [architecture.md](architecture.md) and [hardware.md](hardware.md). **Do not apply power** to the ESP32 until wiring is double-checked. Specifically, verify that the NRF24L01+ modules are connected to the 3.3V pin and NOT the 5V pin, as 5V will destroy them.

## Building and Flashing
1. Clone this repository to your local machine.
2. Open the `reconstructed_repo` folder in VS Code.
3. PlatformIO will automatically read the `platformio.ini` file and download the required dependencies:
   - `RF24` by TMRh20
   - `Adafruit SSD1306`
   - `Adafruit GFX Library`
4. Connect the ESP32 to your computer via USB.
5. Click the **PlatformIO: Upload** button (the right-pointing arrow icon in the bottom taskbar).
6. PlatformIO will compile the C++ source code and flash it to the ESP32.

## Verification
1. Once flashed, open the **PlatformIO: Serial Monitor** (the plug icon in the bottom taskbar). Ensure the baud rate is set to `115200`.
2. The ESP32 should reboot and print the following initialization sequence:
   ```
   Team Electroboom
   Jammer Initializing
   Radio 1 Initialized
   Radio 2 Initialized
   ```
3. If it prints "Radio 1 Failed" or "Radio 2 Failed", disconnect power immediately and double-check your SPI wiring and module power connections.
