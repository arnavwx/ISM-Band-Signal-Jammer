# 9. Measurement, Instrumentation, and Validation

## Why Measurement is Part of the Engineering

A system is not validated merely because a circuit exists.

A defensible experiment connects:

```
theory → setup → measurement → analysis → conclusion
```

---

## Oscilloscope

An oscilloscope primarily provides time-domain information.

Important controls include:
- vertical scale
- horizontal scale
- trigger
- bandwidth
- coupling
- sampling rate
- record length

---

## Spectrum Analysis

Frequency-domain instruments display signal magnitude against frequency.

Important considerations include:
- frequency span
- resolution bandwidth
- video bandwidth where applicable
- detector mode
- averaging
- reference level
- input attenuation
- noise floor

---

## Resolution Bandwidth

A narrower measurement bandwidth can improve the ability to distinguish nearby
spectral components, but it changes measurement time and noise bandwidth.

---

## Calibration and Reference Planes

Measured values depend on where the measurement is made.

Cable loss, connector loss, attenuators, probes, and fixtures can affect results.

---

## Uncertainty

Every measurement has uncertainty.

Sources include:
- instrument accuracy
- repeatability
- calibration
- environmental variation
- component tolerance
- operator procedure

---

## Validation Hierarchy

A strong project should distinguish:

| Level | Description |
| :--- | :--- |
| 1. Theoretical prediction | Expected behaviour from equations |
| 2. Simulation | Software model under controlled assumptions |
| 3. Bench measurement | Physical instrument measurements |
| 4. Integrated-system demonstration | End-to-end system operating as intended |

Agreement between these levels increases confidence.

Disagreement should trigger investigation rather than arbitrary adjustment of theory.

**Project assessment:**

| Level | Status |
| :--- | :--- |
| Theoretical prediction | Partially covered in theory archive |
| Simulation | **MISSING** from current repository |
| Bench measurement | **MISSING** from current repository |
| Demonstration | Referenced via submitted/mid-lab videos, NOT imported |

---

## Common Measurement Mistakes

- confusing peak and RMS
- confusing dB with dBm
- ignoring impedance
- forgetting probe loading
- interpreting an FFT without considering windowing
- treating instrument noise as system behaviour
- measuring a signal outside the instrument''s valid range
- ignoring cable and connector losses

---

## Project Relevance

This section should ultimately be populated with the project''s actual instruments,
screenshots, measured plots, and experimental observations once the original
report/video evidence is available.

**Project-specific evidence:** Measurement instruments are **UNKNOWN** from surviving
artifacts. Demonstration videos are the expected source of validated results.

Expected evidence (MISSING):
- spectrum analyser plot showing 2.4 GHz sweep
- oscilloscope capture of GFSK waveform
- RSSI or range measurements from victim receivers

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Serial monitor output format | [`docs/setup.md`](../setup.md) — verification section |
| OLED status display | [`src/main.cpp`](../../src/main.cpp) — display updates |

---

## Related Theory Sections

- [05 — Noise, Interference, and SNR](05-noise-interference-and-snr.md)
- [12 — System Integration and Engineering Tradeoffs](12-system-integration-and-engineering-tradeoffs.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Measurement* (Why distinguish simulation and measurement? Why repeat measurements?).
