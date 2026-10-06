# 7. Antennas, Propagation, and Link Concepts

## Antenna as a Transducer

An antenna converts between guided electrical energy and electromagnetic radiation.

Its behaviour depends strongly on:
- frequency
- geometry
- polarisation
- environment
- surrounding conductors
- matching
- orientation

---

## Wavelength and Antenna Dimensions

Because:

```
λ = c/f
```

antenna dimensions are naturally related to wavelength.

At 2.4 GHz:

```
λ = (3 × 10⁸) / (2.4 × 10⁹) ≈ 0.125 m = 12.5 cm
λ/4 ≈ 3.1 cm
λ/2 ≈ 6.25 cm
```

Common reference dimensions include fractions such as λ/4 and λ/2, but practical
antenna behaviour depends on geometry and environment.

**Project application:** The NRF24L01+PA+LNA module uses an SMA connector with a
stub or whip antenna. The exact antenna type, gain, and radiation pattern are
**MISSING** from the surviving evidence.

---

## Radiation Pattern

An antenna does not generally radiate equally in every direction.

A radiation pattern represents directional response.

Important terms include:
- main lobe
- sidelobes
- nulls
- beamwidth
- front-to-back ratio

---

## Gain and Directivity

Directivity describes concentration of radiation relative to an isotropic radiator.

Gain additionally accounts for efficiency.

Antenna gain is commonly expressed in dBi when referenced to an isotropic radiator.

**Project note:** The `+PA+LNA` suffix on the NRF24L01 module refers to the power
amplifier and low-noise amplifier integrated on the module board — not to the
antenna gain specifically. The antenna gain figures are **MISSING** from the
surviving evidence.

---

## Polarisation

The orientation and time evolution of the electric field determine polarisation.

Two linearly polarised antennas with significant polarisation mismatch can experience
reduced received power.

---

## Free-Space Path Loss

A common idealised relationship is:

```
FSPL = (4πd/λ)²
```

In decibels:

```
FSPL_dB = 20 log₁₀(4πd/λ)
```

This model assumes ideal free-space propagation and does not capture all real
environments.

At 2.4 GHz, 1 metre distance:

```
FSPL_dB = 20 log₁₀(4π × 1 / 0.125) ≈ 40.1 dB
```

---

## Real Propagation

Real environments introduce:
- reflection
- diffraction
- scattering
- absorption
- multipath
- shadowing

Therefore measured levels can differ substantially from simple free-space predictions.

---

## Project Relevance

These concepts are useful when interpreting any documented antenna/interface or
spatial measurement in the project.

Exact antenna model, orientation, gain, distance, and environment must come from the
original evidence.

**Project-specific evidence:**
- Antenna type: **INFERRED** (SMA stub/whip typical for NRF24L01+PA+LNA)
- Effective range: **MISSING**
- Propagation measurements: **MISSING** — likely in demonstration videos

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Antenna module description | [`docs/hardware.md`](../hardware.md) — component 2 |
| Schematic (antenna connectors) | `media/schematic.jpg` |

---

## Related Theory Sections

- [02 — Electromagnetics and RF Fundamentals](02-electromagnetics-and-rf-fundamentals.md)
- [08 — RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md)
- [09 — Measurement, Instrumentation, and Validation](09-measurement-instrumentation-and-validation.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *RF*, *Fundamentals* (What is wavelength?).
