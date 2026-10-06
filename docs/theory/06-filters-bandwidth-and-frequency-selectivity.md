# 6. Filters, Bandwidth, and Frequency Selectivity

## Purpose of Filtering

A filter modifies a signal according to frequency.

The transfer function is:

```
H(f) = Y(f) / X(f)
```

or in angular frequency:

```
H(jω) = Y(jω) / X(jω)
```

Magnitude: `|H(f)|`

Phase: `∠H(f)`

---

## Common Filter Classes

| Class | Function |
| :--- | :--- |
| Low-pass | Passes low frequencies; attenuates high |
| High-pass | Passes high frequencies; attenuates low |
| Band-pass | Passes a selected frequency range |
| Band-stop (notch) | Attenuates a selected frequency range |

---

## First-Order Low-Pass Example

For an RC low-pass:

```
H(jω) = 1 / (1 + jωRC)
```

The cutoff angular frequency is:

```
ω_c = 1 / RC
```

and:

```
f_c = 1 / (2πRC)
```

At cutoff, the magnitude is approximately `1/√2` of the low-frequency value,
corresponding to −3.01 dB.

---

## Band-Pass Behaviour

A band-pass network attenuates frequencies outside a selected range while passing
frequencies inside a useful region.

Important quantities include:
- lower cutoff frequency
- upper cutoff frequency
- center frequency
- bandwidth
- quality factor

For a simple resonant definition:

```
Q = f₀ / BW
```

---

## Selectivity

Higher Q generally corresponds to narrower bandwidth around resonance.

However, practical selectivity depends on topology, losses, loading, component
tolerances, and parasitics.

---

## Real Filters

Real filters have:
- finite roll-off
- insertion loss
- phase response
- component tolerance
- temperature dependence
- parasitic effects

---

## Filtering in the NRF24L01

The NRF24L01+ uses internal GFSK modulation, which inherently involves Gaussian
filtering of the frequency-deviation pulse. This provides some occupied-bandwidth
control without an external filter.

However, the PA (power amplifier) stage can generate harmonics. It is **UNKNOWN**
from the surviving evidence whether additional filtering was applied between the
NRF24L01 module and the SMA connector.

---

## Project Relevance

Filter theory is important for understanding:
- why the jammer affects a limited frequency range (2.4 GHz band)
- why the occupied bandwidth per channel is finite
- how the sweep rate interacts with victim receiver bandwidth

Any exact component values or implementation topology should be sourced from the
original project evidence.

**Project-specific evidence:** No filter schematic is visible in the current
surviving artifacts. The internal NRF24 filtering is documented in the Nordic
Semiconductor product specification.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Frequency channel selection | [`src/main.cpp`](../../src/main.cpp) — `setChannel()` |
| Architecture description | [`docs/architecture.md`](../architecture.md) |

---

## Related Theory Sections

- [03 — Signals, Spectra, and Fourier Analysis](03-signals-spectra-and-fourier-analysis.md)
- [08 — RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Filtering* (Why is the −3 dB point important? What is Q?).
