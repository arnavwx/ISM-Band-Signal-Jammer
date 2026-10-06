# Theory Archive — ISM Band Signal Jammer

This directory is the structured engineering theory archive for the **EW1 — ISM Band
Signal Jammer** project developed by **Team Electroboom**.

The archive has two purposes:

1. **Academic background** — standard engineering theory needed to understand the
   project''s technical domain (RF, electromagnetics, signals, modulation, filtering, etc.)
2. **Project-specific reference** — cross-referenced to the surviving project artifacts,
   with explicit provenance labels for everything that is RECOVERED, RECONSTRUCTED,
   INFERRED, or MISSING.

> **Provenance policy:** This archive deliberately distinguishes general academic
> theory from verified historical project facts. Do not treat theoretical explanations
> as confirmed experimental results. See
> [15 — Evidence and Provenance Register](15-evidence-and-provenance-register.md).

---

## Files

| # | File | Contents |
| :- | :--- | :--- |
| 01 | [Project Scope and System Context](01-project-scope-and-system-context.md) | Project background, recovered parameters, system decomposition |
| 02 | [Electromagnetics and RF Fundamentals](02-electromagnetics-and-rf-fundamentals.md) | EM waves, impedance, dBm, matching, VSWR |
| 03 | [Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md) | Fourier transform, bandwidth, FFT, windowing, leakage |
| 04 | [Modulation and Communications Fundamentals](04-modulation-and-communications-fundamentals.md) | AM, FM, PM, GFSK, sidebands, occupied bandwidth |
| 05 | [Noise, Interference, and SNR](05-noise-interference-and-snr.md) | Thermal noise, SNR, interference, dynamic range, spurs |
| 06 | [Filters, Bandwidth, and Frequency Selectivity](06-filters-bandwidth-and-frequency-selectivity.md) | Filter classes, RC response, Q factor, real filters |
| 07 | [Antennas, Propagation, and Link Concepts](07-antennas-propagation-and-link-concepts.md) | Antenna parameters, FSPL, polarisation, real propagation |
| 08 | [RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md) | Gain, noise figure, compression, harmonics, PA/LNA |
| 09 | [Measurement, Instrumentation, and Validation](09-measurement-instrumentation-and-validation.md) | Oscilloscope, spectrum analysis, calibration, validation hierarchy |
| 10 | [Embedded Systems and Control Architecture](10-embedded-systems-and-control-architecture.md) | ESP32, SPI, I2C, state machine, timing |
| 11 | [Signal Generation and Digital Signal Processing](11-signal-generation-and-digital-signal-processing.md) | DAC, sampling, quantization, noise payload analysis |
| 12 | [System Integration and Engineering Tradeoffs](12-system-integration-and-engineering-tradeoffs.md) | Tradeoff table, dual-radio design decision, reproducibility |
| 13 | [Project Doubts and Questions Register](13-project-doubts-and-questions-register.md) | Question bank with resolution status |
| 14 | [Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md) | General and project-specific Q&A |
| 15 | [Evidence and Provenance Register](15-evidence-and-provenance-register.md) | Authoritative provenance table |

---

## Recommended Learning Path

Read in this order to build understanding from fundamentals to system-level integration:

1. **[01]** Project Scope — understand what was built and what evidence survives
2. **[02]** Electromagnetics — establish the RF physics foundation
3. **[03]** Signals and Fourier Analysis — understand frequency-domain thinking
4. **[04]** Modulation — understand GFSK and how the NRF24 transmits
5. **[05]** Noise and Interference — understand what the jammer achieves at the victim
6. **[06]** Filters — understand frequency selectivity and occupied bandwidth
7. **[07]** Antennas and Propagation — understand the radiated field and range
8. **[08]** RF Front Ends — understand the PA/LNA and signal chain
9. **[09]** Measurement — understand how results should be validated
10. **[10]** Embedded Systems — understand the ESP32 firmware and interfaces
11. **[11]** Signal Generation and DSP — understand the noise payload and NRF24 baseband
12. **[12]** System Integration — understand the design decisions and tradeoffs

Then consult:
- **[13]** for open project questions and their resolution status
- **[14]** for viva preparation
- **[15]** for provenance and what requires further evidence

---

## Concept Map

The documents form a layered dependency structure:

```
[01] Project Context
        │
        ├─── [02] EM/RF Physics ──────────────────────── [07] Antennas/Propagation
        │           │                                            │
        │           └─── [08] RF Front Ends (PA/LNA) ──────────┤
        │                       │                               │
        ├─── [03] Signals/Fourier ─── [04] Modulation (GFSK) ──┤
        │           │                       │                   │
        │           └─── [06] Filters ──────┤                   │
        │                       │           │                   │
        │           [05] Noise/SNR ─────────┴───────────────────┘
        │                                                        │
        ├─── [10] Embedded Systems (ESP32, SPI, firmware) ───────┤
        │           │                                            │
        │           └─── [11] Signal Generation (NRF24 baseband)─┘
        │
        └─── [09] Measurement/Validation
                    │
                    └─── [12] System Integration & Tradeoffs
                                    │
                      ┌─────────────┼──────────────┐
                   [13] Doubts   [14] Viva      [15] Provenance
```

---

## Project-Specific Questions

Open questions, resolved questions, and evidence requirements:
→ [13 — Project Doubts and Questions Register](13-project-doubts-and-questions-register.md)

---

## Viva Preparation

General concept checks and project-specific Q&A labelled [GENERAL] / [PROJECT]:
→ [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md)

---

## Provenance

Authoritative record of what is RECOVERED, RECONSTRUCTED, INFERRED, DERIVED, and MISSING:
→ [15 — Evidence and Provenance Register](15-evidence-and-provenance-register.md)
