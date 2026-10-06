# 3. Signals, Spectra, and Fourier Analysis

## Time Domain versus Frequency Domain

A signal can be viewed in time:

```
x(t)
```

or represented by its frequency content.

Fourier analysis provides the bridge between these descriptions.

The continuous-time Fourier transform is:

```
X(f) = ∫ x(t) e^(-j2πft) dt
```

and the inverse transform is:

```
x(t) = ∫ X(f) e^(j2πft) df
```

The magnitude `|X(f)|` describes spectral magnitude while the phase `∠X(f)` describes
spectral phase.

---

## Pure Sinusoid

For an ideal sinusoid, spectral energy is concentrated at its frequency components.

This is why frequency-domain measurements are extremely useful for RF work.

---

## Bandwidth

Bandwidth describes the extent of a signal''s occupied or relevant frequency range.

The exact definition depends on context:
- null-to-null bandwidth
- 3-dB bandwidth
- occupied bandwidth
- channel bandwidth
- noise-equivalent bandwidth

These must not be treated as interchangeable.

**Project application:** The NRF24L01+ transmits packets at `RF24_2MBPS`. The 2 Mb/s
data rate implies a minimum occupied bandwidth on the order of a few MHz per channel.
The exact spectral shape depends on the modulation used internally by the NRF24 (GFSK).

---

## Spectrum of a Real Signal

A real-valued time-domain signal has conjugate-symmetric Fourier components.

Therefore positive and negative frequency components are mathematically related.

---

## Sampling

If a continuous signal is sampled at rate `f_s`, spectral replicas occur at integer
multiples of `f_s`.

The Nyquist condition for a strictly bandlimited signal with highest frequency `B` is:

```
f_s > 2B
```

Violating the condition causes aliasing.

---

## Aliasing

Aliasing occurs when spectral replicas overlap after sampling.

Once aliased components overlap, the original continuous-time components cannot
generally be uniquely recovered from the sampled sequence.

---

## FFT

The discrete Fourier transform is:

```
X[k] = Σ_{n=0}^{N-1} x[n] e^(-j2πkn/N)
```

The direct computation is O(N²).

FFT algorithms exploit structure in the DFT to reduce computational cost, commonly to
O(N log N).

---

## Spectral Leakage

A finite observation window effectively multiplies the signal by a window function.

Multiplication in time corresponds to convolution in frequency.

Therefore a finite observation interval can spread energy across nearby frequency bins.

This is spectral leakage.

---

## Windowing

Common windows include:
- rectangular
- Hann
- Hamming
- Blackman

Window choice trades frequency resolution against sidelobe suppression.

---

## Project Relevance

Frequency-domain reasoning is central to interpreting:
- the 2.4 GHz spectrum being swept
- the channel spacing in the NRF24L01 (1 MHz per channel)
- the GFSK spectrum of individual packets
- any spectrum analyser plots from the project demonstration

Before claiming a spectral feature represents a physical signal component, check:
- sampling rate
- record length
- window
- FFT size
- frequency resolution
- instrument bandwidth
- noise floor
- possible harmonics and spurs

**Project-specific evidence:** Spectrum plots are **MISSING** from the current
repository. The project paper/videos may contain spectrum analyser captures.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Channel sweep logic | [`src/main.cpp`](../../src/main.cpp), `loop()` function |
| Frequency range used | [`docs/architecture.md`](../architecture.md) |

---

## Related Theory Sections

- [04 — Modulation and Communications Fundamentals](04-modulation-and-communications-fundamentals.md)
- [05 — Noise, Interference, and SNR](05-noise-interference-and-snr.md)
- [06 — Filters, Bandwidth, and Frequency Selectivity](06-filters-bandwidth-and-frequency-selectivity.md)
- [11 — Signal Generation and Digital Signal Processing](11-signal-generation-and-digital-signal-processing.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Signals* (Why use Fourier analysis? What causes spectral leakage? What is aliasing?).
