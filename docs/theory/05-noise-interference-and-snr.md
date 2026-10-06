# 5. Noise, Interference, and SNR

## Noise

Noise is unwanted random variation in a measured or transmitted signal.

Common categories include:
- thermal noise
- shot noise
- flicker noise
- quantization noise
- phase noise
- environmental electromagnetic noise

---

## Thermal Noise

For a resistor R over bandwidth B at temperature T:

```
P_n = kTB
```

where k is Boltzmann''s constant.

The corresponding noise voltage across a resistor can be expressed through:

```
v_{n,rms} = sqrt(4kTRB)
```

under the usual assumptions.

---

## Signal-to-Noise Ratio

SNR is:

```
SNR = P_signal / P_noise
```

In decibels:

```
SNR_dB = 10 log₁₀(P_signal / P_noise)
```

A higher SNR generally means the desired signal is easier to distinguish from noise.

---

## Interference

Interference is structured or environmental energy that affects another signal or
measurement.

Unlike random noise, interference may have:
- deterministic frequency components
- harmonics
- periodic structure
- correlated behaviour
- identifiable sources

**Project application:** The project generates intentional RF interference across
the 2.4 GHz ISM band. From the perspective of a victim receiver (e.g., a Wi-Fi or
Bluetooth device), the jammer signal appears as wideband interference that raises
the noise floor and reduces SNR below the receiver''s threshold.

---

## Noise Floor

A measurement instrument has a finite sensitivity.

The noise floor is the background level below which small signals may become difficult
to distinguish.

---

## Dynamic Range

Dynamic range describes the ratio between the largest usable signal and the smallest
distinguishable signal under specified conditions.

---

## Spur versus Noise

A narrow spectral line is not automatically noise.

Possible causes include:
- harmonics
- clock leakage
- switching converters
- local oscillators
- digital interfaces
- environmental emitters
- instrument artifacts

**Project application:** The ESP32 clock and SPI interface can produce switching
artefacts. Any spectrum measurement should identify whether features are:
- intended NRF24 transmissions
- ESP32 clock leakage
- power supply switching noise
- environmental sources

---

## Project Relevance

Any project result involving spectral visibility, signal detection, or measured
frequency content should distinguish:
- intended signal (NRF24 GFSK packets)
- harmonics
- spurious components (ESP32 digital noise)
- broadband noise
- environmental interference
- instrument artifacts

This distinction is essential for scientifically defensible conclusions.

**Project-specific evidence:** SNR measurements and interference effectiveness
are **MISSING** from the current repository. The demonstration videos are the
expected source.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Noise generation firmware | [`src/main.cpp`](../../src/main.cpp) — `noiseData` array |
| Power decoupling (supply noise) | [`docs/hardware.md`](../hardware.md) — assembly notes |

---

## Related Theory Sections

- [03 — Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md)
- [08 — RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md)
- [09 — Measurement, Instrumentation, and Validation](09-measurement-instrumentation-and-validation.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *RF* (Why can RF measurements be misleading?), *Measurement*.
