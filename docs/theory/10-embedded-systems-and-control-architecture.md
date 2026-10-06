# 10. Embedded Systems and Control Architecture

## Embedded System Viewpoint

An embedded controller can provide:
- configuration
- timing
- state management
- user interface
- data acquisition
- digital processing
- communication with peripherals

The controller is normally only one part of a larger hardware system.

---

## Hardware/Software Boundary

A useful architecture distinguishes:

```
software
  ↓
digital interface (SPI, I2C)
  ↓
peripheral (NRF24L01, SSD1306)
  ↓
analog/electrical subsystem (PA, antenna)
  ↓
physical environment (radiated field)
```

This prevents software behaviour from being confused with physical behaviour.

---

## Project Implementation (RECOVERED)

The ESP32-WROOM-32D runs Arduino framework firmware built with PlatformIO.

**SPI bus (shared):**

| Signal | ESP32 Pin |
| :--- | :--- |
| MOSI | 23 |
| MISO | 19 |
| SCK | 18 |

**NRF24L01+ Radio 1:**

| Signal | ESP32 Pin |
| :--- | :--- |
| CE | 4 |
| CSN | 5 |

**NRF24L01+ Radio 2:**

| Signal | ESP32 Pin |
| :--- | :--- |
| CE | 2 |
| CSN | 15 |

**OLED Display (I2C, INFERRED):**

| Signal | ESP32 Pin |
| :--- | :--- |
| SDA | 21 |
| SCL | 22 |

> **Provenance note:** OLED pins 21/22 are the standard ESP32 I2C defaults and are
> INFERRED. They are not explicitly confirmed in the whiteboard schematic.

Source: [`docs/architecture.md`](../architecture.md)

---

## Timing

Embedded systems often require deterministic timing.

**Project timing (RECONSTRUCTED from firmware):**

The jammer sweeps channels 1–83. For each channel:
1. Set Radio 1 to channel `ch`
2. Set Radio 2 to channel `(ch + 40) % 84`
3. Transmit `noiseData[32]` five times per radio
4. Update OLED every 20 channels

The `writeFast()` calls are non-blocking; the exact sweep rate depends on SPI clock,
NRF24 TX timing, and processor overhead. Exact timing measurements are **MISSING**.

---

## State Machine

The firmware''s logical states:

```
SETUP:
  ↓ init display
  ↓ init Radio 1
  ↓ init Radio 2
  → JAMMING

JAMMING:
  ↓ set channel (Radio 1 = ch, Radio 2 = (ch+40)%84)
  ↓ transmit noise x5 on each radio
  ↓ update display if (ch % 20 == 0)
  → repeat ch = 1..83 indefinitely
```

Error states (RADIO_FAIL) are detected at startup only. There is no runtime fault recovery.

---

## Serial Interfaces

The project uses:
- **SPI** — dual NRF24L01+ transceivers (shared bus, separate CS)
- **I2C** — SSD1306 OLED display
- **UART** — Serial monitor at 115200 baud (USB, debug output only)

---

## Reliability

The firmware has minimal fault handling:
- OLED init failure: error message printed, execution continues
- Radio init failure: printed, execution continues (radio may be non-functional)
- No runtime watchdog: not evident from reconstructed firmware
- No runtime radio health check in the loop

**Project-specific evidence:** Whether additional error handling was present in the
original firmware is **UNKNOWN**.

---

## Project Relevance

Use this section to explain:
- the ESP32 controller role
- the dual SPI topology
- the I2C display interface
- the software-to-hardware data path

Do not infer a particular firmware feature unless supported by surviving evidence.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Full firmware | [`src/main.cpp`](../../src/main.cpp) |
| Pin mapping table | [`docs/architecture.md`](../architecture.md) |
| Build configuration | [`platformio.ini`](../../platformio.ini) |

---

## Related Theory Sections

- [01 — Project Scope and System Context](01-project-scope-and-system-context.md)
- [11 — Signal Generation and Digital Signal Processing](11-signal-generation-and-digital-signal-processing.md)
- [12 — System Integration and Engineering Tradeoffs](12-system-integration-and-engineering-tradeoffs.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Measurement* (Why distinguish simulation and measurement?).
