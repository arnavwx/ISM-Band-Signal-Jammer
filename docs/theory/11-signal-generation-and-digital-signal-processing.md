# 11. Signal Generation and Digital Signal Processing

## Digital Representation

A continuous-time signal can be represented by samples:

```
x[n] = x(nT_s)
```

where `T_s` is the sampling interval.

The sampling frequency is:

```
f_s = 1 / T_s
```

---

## Quantization

A finite-resolution ADC maps continuous amplitude values to discrete levels.

Quantization introduces an error:

```
e[n] = x[n] - x_q[n]
```

For an ideal uniform quantizer, the error is often approximated as a bounded
noise-like quantity under appropriate assumptions.

---

## DAC Concepts

A digital-to-analog converter reconstructs an analog waveform from discrete numerical
values.

Practical reconstruction includes filtering because the sampled sequence represents
spectral replicas.

---

## Numerically Generated Waveforms

A sampled sinusoid can be represented as:

```
x[n] = A cos(2πf₀n/f_s + φ)
```

The ratio `f₀/f_s` determines how the waveform is represented digitally.

---

## Frequency Resolution

For an N-point FFT at sampling frequency `f_s`:

```
Δf = f_s / N
```

Longer records provide finer frequency resolution, subject to stationarity and other
practical considerations.

---

## Aliasing and Image Components

Sampling creates periodic spectral replicas.

This is why anti-alias filtering and reconstruction filtering are fundamental in
mixed-signal systems.

---

## Signal Generation in This Project (RECONSTRUCTED)

The NRF24L01+ generates RF signals internally from firmware commands. The
"signal generation" from the ESP32''s perspective is:

1. **ESP32 firmware** — generates a 32-byte noise payload:
   ```c
   const uint8_t noiseData[32] = {
     0xFF, 0xAA, 0x55, 0x00, ...
   };
   ```
   This is a repeating pattern designed to produce broadband spectral content.

2. **SPI transfer** — the payload is written to the NRF24 via `writeFast()`.

3. **NRF24L01 internal baseband** — converts the byte sequence to GFSK-modulated
   RF at the selected channel frequency.

The waveform generation is therefore performed inside the NRF24 IC, not in the
ESP32. The ESP32 only selects the channel and triggers transmissions.

> **Provenance note:** The exact spectral content of the transmitted noise payload
> is **INFERRED** from the firmware logic. Direct measurement is **MISSING**.

---

## DSP Pipeline

A generic pipeline may be:

```
acquire → condition → sample → process → analyse → visualise
```

**Project pipeline (RECONSTRUCTED):**

```
ESP32 (SPI command) → NRF24 baseband → PA → antenna → radiated field
                                              ↑
                                    (no ADC/DSP on transmit path)
```

The project does not appear to use software-domain DSP for signal generation —
signal generation is hardware-based inside the NRF24 module.

Software DSP (FFT, filtering, etc.) would be relevant if spectral measurements were
performed and analysed on a computer. Whether such analysis was performed is
**UNKNOWN** from surviving evidence.

---

## Project Relevance

This theory supports any digital waveform generation, sampling, spectral analysis,
data processing, or visualisation documented by the project.

**Project-specific evidence:** No ADC captures or software spectrum analysis scripts
are present in the current repository. Spectrum analyser plots from the demonstration
videos are the expected evidence source.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Noise payload definition | [`src/main.cpp`](../../src/main.cpp) — `noiseData` array |
| Channel sweep (signal generation) | [`src/main.cpp`](../../src/main.cpp) — `loop()` |

---

## Related Theory Sections

- [03 — Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md)
- [04 — Modulation and Communications Fundamentals](04-modulation-and-communications-fundamentals.md)
- [10 — Embedded Systems and Control Architecture](10-embedded-systems-and-control-architecture.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Signals* (What is aliasing?), *Fundamentals* (What is bandwidth?).
