# 15. Evidence and Provenance Register

> **This document is authoritative.** Do not remove or weaken the uncertainty
> statements it contains. The repository must remain honest about what is RECOVERED,
> RECONSTRUCTED, INFERRED, and MISSING.

---

## Provenance Levels

| Label | Meaning |
| :--- | :--- |
| **RECOVERED** | Directly available from a surviving project artifact |
| **RECONSTRUCTED** | Re-created from surviving context; functionally equivalent but not byte-for-byte original |
| **DERIVED** | Calculated or determined from RECOVERED or RECONSTRUCTED artifacts using standard methods |
| **INFERRED** | Logically implied by evidence but not directly stated |
| **MISSING** | Not present in any surviving artifact |

---

## Verified from Surviving Project Context

| Fact | Provenance | Source |
| :--- | :--- | :--- |
| Project name: `EW1-Jammer` / ISM Band Signal Jammer | RECOVERED | Project context |
| University engineering project | RECOVERED | Project context |
| Original development laptop reset; firmware lost | RECOVERED | Project context |
| Team name: Team Electroboom | RECOVERED | `src/main.cpp` OLED string |
| Team members: Arnav Jain, Shreyansh Rawat, Aditya Anand Karel | RECOVERED | `CITATION.cff` |
| Microcontroller: ESP32-WROOM-32D | RECOVERED | Components list PDF → `docs/hardware.md` |
| RF transceivers: 2× NRF24L01+PA+LNA | RECOVERED | Components list PDF → `docs/hardware.md` |
| Display: 0.96″ OLED (SSD1306, I2C) | RECOVERED | Components list PDF → `docs/hardware.md` |
| Power: 3.7 V Li-ion + TP4056 charging module | RECOVERED | Components list PDF → `docs/hardware.md` |
| Decoupling: 10 µF capacitors on NRF24 VCC/GND | RECOVERED | Components list PDF → `docs/hardware.md` |
| LED: 3mm blue + 4.7 kΩ resistor | RECOVERED | Components list PDF → `docs/hardware.md` |
| Dip switch for power control | RECOVERED | Components list PDF → `docs/hardware.md` |
| SPI pin mapping (MOSI=23, MISO=19, SCK=18) | RECOVERED | Whiteboard schematic → `docs/architecture.md` |
| Radio 1 CE=4, CSN=5 | RECOVERED | Whiteboard schematic → `docs/architecture.md` |
| Radio 2 CE=2, CSN=15 | RECOVERED | Whiteboard schematic → `docs/architecture.md` |
| Firmware framework: Arduino / PlatformIO | RECOVERED | `platformio.ini` |
| Libraries: RF24 (TMRh20), Adafruit SSD1306, Adafruit GFX | RECOVERED | `platformio.ini` |
| Frequency band: 2.4 GHz ISM, channels 1–83 | RECOVERED | `src/main.cpp` — loop |
| Dual-radio offset: 40 channels | RECOVERED | `src/main.cpp` — `(ch+40)%84` |
| PA level: RF24_PA_MAX | RECOVERED | `src/main.cpp` |
| Data rate: RF24_2MBPS | RECOVERED | `src/main.cpp` |
| Noise payload: 32-byte `{0xFF,0xAA,0x55,0x00,...}` | RECOVERED | `src/main.cpp` |
| Whiteboard schematic photo | RECOVERED | `media/schematic.jpg` |
| Submitted demonstration videos | MISSING from repository | Referenced in project context |
| Mid-lab demonstration videos | MISSING from repository | Referenced in project context |
| Final submitted paper/report | MISSING from repository | Referenced in project context |

---

## Must Verify Before Publishing as Historical Fact

The following items are NOT confirmed from surviving evidence and must not be
presented as historically documented project facts:

- exact PA output power in dBm
- exact antenna model, gain, and radiation pattern
- exact measured interference range
- exact victim receiver response
- exact spectrum analyser captures
- exact experimental conditions (environment, distance, orientation)
- exact conclusions stated in the final paper
- exact viva questions asked and answers given
- specific modulation parameters (NRF24 GFSK deviation, BT product)
- whether circuit simulation was performed
- whether the OLED pin assignments were explicitly confirmed (currently INFERRED)

---

## Important Uncertainty

The complete historical project chat log and final paper are not available via
the file-reading interface.

Therefore this archive does NOT claim to contain every historical doubt or every
project-specific parameter.

---

## Provenance Rule

For every project-specific number or implementation detail in the final GitHub
repository, retain a source pointer to one of:

- final paper
- original chat log
- surviving source file
- whiteboard schematic photograph
- demonstration video (with timestamp)
- measurement file

If no source exists, label the item with one of the provenance level tags above
rather than silently presenting it as recovered historical fact.

---

## Reconstruction Status Summary

| Repository area | Status |
| :--- | :--- |
| `src/main.cpp` | RECONSTRUCTED |
| `docs/hardware.md` | RECOVERED (from components PDF) |
| `docs/architecture.md` | RECOVERED (SPI pins) + INFERRED (OLED pins) |
| `docs/setup.md` | RECONSTRUCTED |
| `media/schematic.jpg` | RECOVERED |
| `docs/theory/` (all files) | RECONSTRUCTED from theory context; cross-referenced to RECOVERED artifacts |
| Demonstration videos | MISSING from repository |
| Final paper | MISSING from repository |
| Spectrum measurements | MISSING |
| Range measurements | MISSING |
| Simulation files | MISSING |
