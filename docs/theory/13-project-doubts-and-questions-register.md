# 13. Project Doubts and Questions Register

This is a conservative register of project-specific questions established from the
surviving project context. It is **not** a verbatim transcript of the lost chat log.

Questions are tagged:
- ✅ **RESOLVED** — answered from surviving repository artifacts
- ⚠️ **PARTIAL** — partially answerable from evidence
- ❌ **UNRESOLVED** — no supporting artifact currently available

---

## Architecture Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| A1 | What were the exact functional blocks in the final architecture? | ⚠️ PARTIAL | RECONSTRUCTED: see [`docs/architecture.md`](../architecture.md) |
| A2 | Which blocks were actually implemented versus proposed? | ✅ RESOLVED | Firmware + hardware list RECOVERED |
| A3 | Where was the boundary between digital control and analog/RF hardware? | ✅ RESOLVED | ESP32 SPI → NRF24 internal PA/RF |
| A4 | Which portions were simulated? | ❌ UNRESOLVED | No simulation files in repository |
| A5 | Which portions were demonstrated physically? | ⚠️ PARTIAL | Videos referenced but not imported |

---

## Signal Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| S1 | What was the mathematical representation of the project signal? | ✅ RESOLVED | NRF24 GFSK, 2401–2483 MHz, channel sweep |
| S2 | Was analysis performed in time domain, frequency domain, or both? | ❌ UNRESOLVED | No measurement captures in repository |
| S3 | What sampling assumptions applied? | ❌ UNRESOLVED | No ADC/DSP in transmit path confirmed |
| S4 | What spectral features were expected? | ⚠️ PARTIAL | GFSK spectrum per channel; see [Doc 04](04-modulation-and-communications-fundamentals.md) |
| S5 | Which observed spectral components were fundamental, harmonic, modulation-related, spurious, or noise? | ❌ UNRESOLVED | No spectrum plots available |

---

## RF Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| R1 | What exact frequency ranges were involved? | ✅ RESOLVED | 2.4 GHz ISM band, channels 1–83 (2401–2483 MHz) |
| R2 | What impedance environment was assumed? | ❌ UNRESOLVED | Likely 50 Ω (SMA standard); not confirmed from evidence |
| R3 | What antenna/interface was used? | ⚠️ PARTIAL | SMA stub/whip on NRF24+PA+LNA (type INFERRED) |
| R4 | What losses were present in cables/connectors? | ❌ UNRESOLVED | No measurement |
| R5 | How did measured behaviour compare with idealised propagation assumptions? | ❌ UNRESOLVED | No range measurements available |

---

## Electronics Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| E1 | What active devices were used? | ✅ RESOLVED | NRF24L01+PA+LNA; ESP32-WROOM-32D |
| E2 | What bias conditions were used? | ⚠️ PARTIAL | 3.3 V supply to NRF24; ESP32 supplied via TP4056 |
| E3 | What gain was expected? | ❌ UNRESOLVED | PA gain not stated in surviving evidence |
| E4 | Where could nonlinear behaviour occur? | ⚠️ PARTIAL | PA stage at RF24_PA_MAX; see [Doc 08](08-rf-frontends-amplification-and-power.md) |
| E5 | What filtering was required? | ⚠️ PARTIAL | Internal GFSK Gaussian filter in NRF24; external filter UNKNOWN |
| E6 | How was the power subsystem isolated from sensitive signal paths? | ✅ RESOLVED | 10 µF decoupling capacitors across each NRF24 VCC/GND |

---

## Measurement Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| M1 | Which instruments were used? | ❌ UNRESOLVED | Not in surviving artifacts |
| M2 | What were their relevant settings? | ❌ UNRESOLVED | |
| M3 | What constituted the measurement reference? | ❌ UNRESOLVED | |
| M4 | Were readings peak, peak-to-peak, RMS, or power? | ❌ UNRESOLVED | |
| M5 | How was instrument loading handled? | ❌ UNRESOLVED | |
| M6 | What uncertainty or repeatability was observed? | ❌ UNRESOLVED | |

---

## Embedded/Software Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| SW1 | Was a microcontroller involved? | ✅ RESOLVED | ESP32-WROOM-32D, confirmed |
| SW2 | What peripherals were used? | ✅ RESOLVED | Two NRF24L01+ (SPI), OLED SSD1306 (I2C) |
| SW3 | What data path connected software to hardware? | ✅ RESOLVED | SPI bus (MOSI=23, MISO=19, SCK=18) |
| SW4 | Was waveform generation or DSP performed digitally? | ⚠️ PARTIAL | Channel selection in firmware; RF modulation hardware-based in NRF24 |
| SW5 | What timing constraints existed? | ❌ UNRESOLVED | Sweep rate not measured |

---

## Experimental Questions

| # | Question | Status | Evidence / Notes |
| :- | :--- | :--- | :--- |
| X1 | What was the exact experimental objective? | ✅ RESOLVED | Disrupt 2.4 GHz communications (Wi-Fi, Bluetooth, Zigbee) in a localised area |
| X2 | What variable was changed? | ⚠️ PARTIAL | Channel (swept 1–83); offset between radios (40 channels); OTHERS UNKNOWN |
| X3 | What was held constant? | ❌ UNRESOLVED | |
| X4 | What was measured? | ❌ UNRESOLVED | No measurement records available |
| X5 | What was predicted? | ❌ UNRESOLVED | No theoretical prediction documented |
| X6 | Did the experiment agree with theory? | ❌ UNRESOLVED | |

---

## Viva-Style Conceptual Doubts

These are general engineering questions (not project-specific facts):

- Why use frequency-domain analysis?
  → See [03 — Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md)

- Why does filtering alter both magnitude and phase?
  → See [06 — Filters, Bandwidth, and Frequency Selectivity](06-filters-bandwidth-and-frequency-selectivity.md)

- Why can nonlinear stages create harmonics?
  → See [08 — RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md)

- Why does sampling produce spectral replicas?
  → See [03 — Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md)

- Why is impedance relevant to RF power transfer?
  → See [02 — Electromagnetics and RF Fundamentals](02-electromagnetics-and-rf-fundamentals.md)

- Why can a measured spectrum differ from an ideal spectrum?
  → See [05 — Noise, Interference, and SNR](05-noise-interference-and-snr.md) and
     [09 — Measurement, Instrumentation, and Validation](09-measurement-instrumentation-and-validation.md)

- Why is a demonstration not automatically a quantitative validation?
  → See [09 — Measurement, Instrumentation, and Validation](09-measurement-instrumentation-and-validation.md)

---

## Historical-Project Verification

Before publishing project-specific answers to unresolved questions, compare against:
- final paper
- original WhatsApp chat log
- schematics
- demonstration videos (submitted and mid-lab)
- surviving source files
- photographs

See [15 — Evidence and Provenance Register](15-evidence-and-provenance-register.md)
for the complete provenance policy.
