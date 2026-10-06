# 4. Modulation and Communications Fundamentals

## Why Modulation Exists

A baseband information signal is often translated to another frequency range for
transmission or system processing.

A carrier can be represented as:

```
c(t) = A_c cos(2πf_c t + φ)
```

Modulation changes one or more carrier properties according to a signal.

---

## Amplitude Modulation

A simple AM signal can be written:

```
s(t) = A_c [1 + μm(t)] cos(2πf_c t)
```

where μ controls modulation depth under a normalised message convention.

For a single-tone message, sidebands appear around the carrier.

---

## Frequency Modulation

FM varies instantaneous frequency according to the message.

The instantaneous phase determines frequency through:

```
f_i(t) = (1/2π) dφ(t)/dt
```

A simplified FM form for a sinusoidal message is:

```
s(t) = A_c cos(2πf_c t + β sin(2πf_m t))
```

where β is the modulation index.

---

## Phase Modulation

PM varies carrier phase according to the message:

```
s(t) = A_c cos(2πf_c t + k_p m(t))
```

---

## Gaussian Frequency-Shift Keying (GFSK)

The NRF24L01 uses **GFSK modulation** internally.

GFSK is a continuous-phase FSK variant where the frequency-shift pulse is filtered
by a Gaussian filter before modulation. This reduces the occupied spectrum compared
to rectangular-pulse FSK.

Key parameters for GFSK:
- symbol rate (bits/s)
- frequency deviation (Hz)
- Gaussian filter bandwidth-time product (BT)

> **Provenance note:** The exact GFSK parameters of the NRF24L01+PA+LNA variant used
> in this project are **not confirmed** from surviving evidence. Refer to the
> nRF24L01+ product specification (Nordic Semiconductor) for published parameters.

---

## Sidebands

Modulation redistributes spectral energy.

Understanding sidebands is essential for interpreting spectrum measurements.

---

## Harmonics versus Sidebands

A harmonic is generally an integer multiple of a fundamental frequency.

A modulation sideband is a frequency offset from a carrier produced by modulation.

These are different physical mechanisms and should not be conflated.

---

## Occupied Bandwidth

A modulated signal can occupy a range around a carrier.

The required bandwidth depends on:
- modulation type
- message bandwidth
- modulation index
- pulse shaping
- the definition used for occupied bandwidth

**Project application:** At `RF24_2MBPS`, the NRF24L01 transmits at 2 Mb/s.
The occupied bandwidth (99% power) is approximately 2–3 MHz per channel
(exact figures: **MISSING** — verify from datasheet or spectrum measurement).

---

## Project Relevance

The project''s signal behaviour should be explained using these concepts only where
supported by the actual implementation and experimental evidence.

Exact modulation parameters should be recovered from project artifacts.

**Project-specific evidence:** Modulation parameters are **MISSING** from current
evidence. Spectrum analyser captures from the demonstration videos would be
the appropriate source.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Data rate setting | [`src/main.cpp`](../../src/main.cpp) — `RF24_2MBPS` |
| RF architecture | [`docs/architecture.md`](../architecture.md) |

---

## Related Theory Sections

- [03 — Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md)
- [05 — Noise, Interference, and SNR](05-noise-interference-and-snr.md)
- [08 — RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Signals*, *RF*.
