# ISM Band Signal Jammer: Team Electroboom

**University Engineering Project Repository**

![Project Status](https://img.shields.io/badge/Status-Reconstructed-blue)
![Platform](https://img.shields.io/badge/Platform-ESP32-green)
![Framework](https://img.shields.io/badge/Framework-Arduino%20%28PlatformIO%29-orange)

## 1. Project Overview
This repository contains the reconstructed firmware, documentation, and hardware design for an ISM Band Signal Jammer, developed by Team Electroboom. 

Originally assigned a 555-timer-based low-frequency jammer project, the team successfully proposed and pivoted to a more advanced ISM band jammer utilizing an ESP32 microcontroller and dual NRF24L01+PA+LNA transceiver modules. 

> **Disclaimer**: This is a reconstructed repository built for archival, documentation, and academic purposes. Do not use this project for illegal interference with authorized radio communications.

## 2. Motivation
Modern communications rely heavily on the 2.4GHz ISM band (Wi-Fi, Bluetooth, Zigbee). A 555-timer-based circuit is generally limited to <400MHz, which makes it ineffective against modern devices. This project demonstrates how inexpensive, commercially available components can be leveraged to create a wide-band 2.4GHz noise generator capable of disrupting localized communications.

## 3. System Architecture
The system consists of an ESP32 microcontroller operating as the central control unit, orchestrating two NRF24L01+PA+LNA transceivers via the SPI bus. To maximize disruption efficiency, the frequency band is divided between the two radios, allowing them to simultaneously blast garbage packets (noise) across the spectrum. A 0.96" OLED display provides visual feedback on the jamming status.

*For detailed architectural notes and the circuit diagram, see [docs/architecture.md](docs/architecture.md).*

## 4. Hardware Components
The core components required to replicate this project include:
- **1x ESP32-WROOM-32D** (Main Microcontroller)
- **2x 2.4GHz NRF24L01+PA+LNA SMA Wireless Transceivers**
- **1x 0.96" OLED Display Module (I2C)**
- **1x 3.7V Lithium-ion Rechargeable Battery (JST-PH 2.0)**
- **1x TP4056 Battery Charging Module**
- **2x 10uF Capacitors** (For NRF module power smoothing)
- **1x 3mm Blue LED & 4.7k Ohm Resistor**
- **1x Dip Switch** (Power toggle)
- **Breadboards & Jumper Wires**

*For a full breakdown of components and reference links, see [docs/hardware.md](docs/hardware.md).*

## 5. Repository Structure
```
project-root/
├── README.md                 # This document
├── LICENSE                   # Open-source license
├── CITATION.cff              # Academic citation file
├── .gitignore                # Git ignore configuration
├── platformio.ini            # PlatformIO build configuration
├── docs/
│   ├── architecture.md       # System design and circuit diagrams
│   ├── setup.md              # Installation and build instructions
│   ├── hardware.md           # Component list and physical setup
│   ├── demonstration.md      # Details of the video demonstrations
│   ├── reconstruction-notes.md # Mapping of original project to this repo
│   └── reconstruction-audit.md # Final audit of reconstructed vs recovered artifacts
├── src/
│   └── main.cpp              # Main ESP32 jammer firmware
└── media/
    └── README.md             # Index of recovered media/videos
```

## 6. Installation & Setup
This project uses PlatformIO for dependency management and building.
See [docs/setup.md](docs/setup.md) for full instructions on how to compile and flash the firmware to your ESP32.

## 7. Running the Project
Once the firmware is flashed and the hardware is assembled:
1. Toggle the Dip Switch to power the system via the Li-ion battery.
2. The blue LED will illuminate, indicating power flow.
3. The OLED will display the "Team Electroboom" initialization screen.
4. The ESP32 will verify connection to both NRF24L01+ modules.
5. The device will automatically begin sweeping the 2.4GHz spectrum (Channels 1-83), blasting noise packets. The OLED will periodically update the current channel being jammed.

## 8. Experimental Methodology & Results
The project successfully demonstrated targeted disruption of 2.4GHz communications. The experimental evidence (recovered via video demonstrations) showcases the jammer's ability to interfere with local signals. 

*For an analysis of the video demonstrations, see [docs/demonstration.md](docs/demonstration.md).*

## 9. Reproducibility & Limitations
- **Reproducibility**: The software has been cleanly reconstructed using standard Arduino libraries (`RF24`, `Adafruit_SSD1306`) and is fully reproducible on a fresh machine using PlatformIO. The hardware design is fully documented based on original recovered schematics.
- **Limitations**: The exact original source code was lost. The provided `main.cpp` is a faithful reconstruction based on project documentation, team chats, and standard NRF24 jamming implementations. The effectiveness of the jammer depends heavily on the proximity to the target and the antenna quality.

## 10. Team Information
- **Team**: Electroboom (Section C)
- **Members**: Arnav Jain, Shreyansh Rawat, Aditya Anand Karel
- **Course**: Electronic Warfare (EW) Project

## 11. References
- Original inspiration drawn from ESP32 Bluetooth/WiFi Jammer repositories (e.g., *ESP32-BlueJammer*, *Cypher-Jammer*).
- NRF24L01+ Datasheet and `RF24` Arduino Library documentation.
