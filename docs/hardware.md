# Hardware

This document details the exact hardware components used for the Team Electroboom 2.4GHz EW Jammer project, as recovered from the original `Components_Electroboom_EW1.pdf`.

## Component List

| Sno | Name of the Component | Number of pieces | General use case |
| :--- | :--- | :--- | :--- |
| 1 | **ESP32-WROOM-32D** | 1 | The main control unit through which we operate the antennas to create noise. |
| 2 | **2.4GHz NRF24L01+PA+LNA SMA Wireless Transceiver Antenna** | 2 | The antenna module and antennas which will be used to transmit the generated noise towards the targeted area. |
| 3 | **0.96″ OLED Display Module – SPI/I2C** | 1 | To give the user an interface to communicate with ESP while selecting frequency modes. |
| 4 | **3.7v Lithium ion Rechargeable Battery with JST-PH 2.0 terminal** | 1 | To make the device portable, essentially for the ease of testing but also to operate it remotely if needed. |
| 5 | **TP4056 3.7V Lithium Battery Charging Module 1A USB Type-C Port PH2.0 Terminal** | 1 | To charge the battery being attached. |
| 6 | **10uF capacitor** | 2 | To ensure smooth current flow to antenna modules and to minimize load on the ESP in case of any fluctuation. |
| 7 | **3mm LED (Blue)** | 1 | To indicate if the system is getting power when turned on. |
| 8 | **4.7k Ohm resister** | 1 | To regulate the current as per the LED’s capacity. |
| 9 | **Breadboard** | 2 | To setup the circuit on in the first stage of project and to help us deal with wiring much neatly. |
| 10 | **Dip Switch** | 1 | To control the power on and off state from battery. |

## Physical Assembly Notes

- The circuit was originally prototyped across 2 breadboards due to the physical footprint of the ESP32-WROOM-32D and the two NRF24L01+PA+LNA modules.
- **Critical Power Requirement:** The NRF24L01+ modules are highly sensitive to voltage fluctuations. The 10uF capacitors MUST be placed across the VCC and GND pins of each NRF module as close to the pins as possible to prevent brown-outs and maintain stable transmission power.
- The 3mm Blue LED and 4.7k Ohm resistor should be placed in series between the output of the TP4056 (or the switched battery line) and ground.
