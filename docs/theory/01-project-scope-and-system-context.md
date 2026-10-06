# 1. Project Scope and System Context

## Known Project Context

The project is an **Electronic Workshop 1 (EW1)** university engineering project, referred to as
`EW1-Jammer` or **ISM Band Signal Jammer**. It was developed by **Team Electroboom**
(Arnav Jain, Shreyansh Rawat, Aditya Anand Karel).

The original development laptop was reset and the original firmware files were lost.
This repository is a reconstruction and preservation archive.

### Surviving Project Evidence

| Artifact | Reconstruction Status | Notes |
| :--- | :--- | :--- |
| Final submitted paper | MISSING from current interface | Referenced in provenance register |
| Original chat log (WhatsApp) | MISSING from current interface | Zip archive on disk, not parsed |
| Whiteboard schematic photo | **RECOVERED** | `media/schematic.jpg` |
| Components list PDF | **RECOVERED** | Source of `docs/hardware.md` |
| Firmware source code | **RECONSTRUCTED** | `src/main.cpp` — see provenance |
| OLED pin assignment | **INFERRED** | Standard ESP32 I2C defaults |
| Submitted demonstration videos | Referenced but NOT in repo | Not yet imported |
| Mid-lab demonstration videos | Referenced but NOT in repo | Not yet imported |

### Verified Project Parameters

The following specific implementation facts are **RECOVERED** from the surviving
components list and schematic:

- **Microcontroller:** ESP32-WROOM-32D
- **RF Transceivers:** 2× NRF24L01+PA+LNA (2.4 GHz ISM band)
- **Target band:** 2.4 GHz (channels 1–83 per NRF24L01 spec)
- **Framework:** Arduino / PlatformIO
- **Display:** 0.96″ OLED (SSD1306, I2C)
- **Power:** 3.7 V Li-ion + TP4056 charging module
- **Architecture:** Dual-transceiver SPI, channel-sweep firmware

See [`docs/hardware.md`](../hardware.md) and [`docs/architecture.md`](../architecture.md) for full details.

---

## Engineering Viewpoint

The project should be understood as a **system** rather than a single circuit.

The ISM Band Signal Jammer decomposes into:

| Stage | Implementation in this project |
| :--- | :--- |
| Signal generation | NRF24L01+ firmware-controlled channel sweep |
| Frequency-selective operation | NRF24 channel register (1 MHz spacing, 2.4 GHz band) |
| Amplification/interface | Integrated PA+LNA in NRF24L01+PA+LNA module |
| Physical transducer | SMA antenna connectors on NRF24 modules |
| Power subsystem | Li-ion battery + TP4056 + 10 µF decoupling capacitors |
| Control/embedded subsystem | ESP32-WROOM-32D, Arduino framework, SPI + I2C |
| Measurement/validation | OLED feedback; serial monitor; **measurement instruments: UNKNOWN** |

> **Provenance note:** The exact block diagram and experimental results require
> verification against the final paper and chat log once those artifacts are accessible.

---

## System-Level Questions

A technically complete project description must answer:

- What signal or phenomenon is being generated/observed?
- What representation is used: time domain, frequency domain, or both?
- Which components operate at baseband, IF, or RF?
- Where does filtering occur?
- Where does amplification occur?
- What is controlled digitally?
- What is measured experimentally?
- What constitutes successful system behaviour?
- Which claims are theoretical and which are experimentally demonstrated?

These questions are systematically addressed in
[`13-project-doubts-and-questions-register.md`](13-project-doubts-and-questions-register.md).

---

## Signal Representation

A general RF sinusoid:

```
x(t) = A cos(2πf₀t + φ)
```

where:
- `A` is amplitude
- `f₀` is carrier frequency
- `φ` is phase

RF systems are fundamentally concerned with how signals occupy time and frequency.
The NRF24L01 operates at frequencies:

```
f = (2400 + channel) MHz,  channel ∈ {0, 1, ..., 125}
```

The project sweeps channels 1–83, covering approximately 2401–2483 MHz.

---

## Reconstruction Status

| Parameter | Status |
| :--- | :--- |
| Exact block diagram | MISSING — requires original paper |
| Pin mapping (SPI) | RECOVERED — from whiteboard schematic |
| Pin mapping (I2C OLED) | INFERRED — standard ESP32 defaults |
| Exact gain figures | MISSING |
| Measured range/effectiveness | MISSING |
| Experimental conditions | MISSING |

---

## Cross-References

| Theory topic | Repository artifact |
| :--- | :--- |
| RF chain concepts | [`docs/architecture.md`](../architecture.md) |
| Component specifications | [`docs/hardware.md`](../hardware.md) |
| Firmware logic | [`src/main.cpp`](../../src/main.cpp) |
| Evidence register | [`15-evidence-and-provenance-register.md`](15-evidence-and-provenance-register.md) |

---

## Related Theory Sections

- [02 — Electromagnetics and RF Fundamentals](02-electromagnetics-and-rf-fundamentals.md)
- [10 — Embedded Systems and Control Architecture](10-embedded-systems-and-control-architecture.md)
- [12 — System Integration and Engineering Tradeoffs](12-system-integration-and-engineering-tradeoffs.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Fundamentals*, *RF*, *Measurement*.
