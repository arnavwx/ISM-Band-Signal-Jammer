# System Architecture

This document describes the hardware and software architecture of the ISM Band Signal Jammer reconstructed for this repository.

## Hardware Architecture

The core of the system is the **ESP32-WROOM-32D** microcontroller. It handles the logic for frequency sweeping and communicating with the RF transceivers.

Two **NRF24L01+PA+LNA** modules are utilized to broadcast the jamming signal. By using two modules, the system can split the 2.4GHz spectrum (Channels 1-83), allowing for faster sweeping and higher interference density across the band.

An **0.96" OLED Display (I2C)** provides a user interface to display initialization status, radio health checks, and the current frequency channel being targeted.

The system is powered by a **3.7V Lithium-ion battery** connected through a **TP4056** charging module and a physical dip switch for power control. A 3mm Blue LED serves as a power indicator.

### Circuit Diagram Configuration

Based on the original recovered whiteboard circuit diagram (`IMG-20251017-WA0007.jpg`), the pin mapping is as follows:

| Component | Pin | ESP32 Pin | Notes |
| :--- | :--- | :--- | :--- |
| **Shared SPI Bus** | MOSI | 23 | |
| | MISO | 19 | |
| | SCK | 18 | |
| **NRF24L01+ (Radio 1)** | CE | 4 | Left module in diagram |
| | CSN | 5 | |
| | VCC | 3V3 | Requires a 10uF capacitor across VCC and GND |
| | GND | GND | |
| **NRF24L01+ (Radio 2)** | CE | 2 | Right module in diagram |
| | CSN | 15 | |
| | VCC | 3V3 | Requires a 10uF capacitor across VCC and GND |
| | GND | GND | |
| **OLED Display** | SDA | 21 (Default) | Inferred (not shown in draft diagram) |
| | SCL | 22 (Default) | Inferred (not shown in draft diagram) |

*Note: The original whiteboard diagram focused primarily on the SPI connections for the dual NRF24 modules. The OLED and power indicator connections have been logically inferred based on standard ESP32 I2C pins and the recovered components list.*

## Software Architecture

The firmware is built using the Arduino framework via PlatformIO. 

**Core Execution Flow:**
1. **Setup Phase:**
   - Initializes Serial for debugging.
   - Initializes the I2C OLED display and presents the startup splash screen.
   - Initializes both NRF24L01+ modules via the SPI bus.
   - Configures the radios for maximum power (`RF24_PA_MAX`) and maximum data rate (`RF24_2MBPS`) to maximize noise bandwidth.
   - Disables Auto-Ack and Retries, as the goal is one-way noise generation, not reliable communication.

2. **Loop Phase:**
   - Enters a continuous sweeping loop from Channel 1 to 83.
   - **Radio 1** sets its frequency to the current loop channel `ch`.
   - **Radio 2** sets its frequency to `(ch + 40) % 84` to simultaneously jam a different portion of the spectrum.
   - Both radios rapidly transmit a payload of pseudo-random/garbage bytes (`0xFF`, `0xAA`, `0x55`, `0x00`).
   - The OLED display is updated intermittently (every 20 channels) to maintain a fast sweep rate while providing visual feedback.
