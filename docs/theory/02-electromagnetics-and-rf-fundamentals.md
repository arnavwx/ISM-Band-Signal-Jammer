# 2. Electromagnetics and RF Fundamentals

## Electromagnetic Waves

A time-varying electric field and magnetic field can propagate through space as an
electromagnetic wave.

In a uniform plane wave in free space, the electric and magnetic fields are mutually
perpendicular and both are perpendicular to the direction of propagation.

The free-space wave impedance is approximately:

```
η₀ ≈ 377 Ω
```

and the propagation speed is approximately:

```
c ≈ 3 × 10⁸ m/s
```

For a sinusoidal wave:

```
λ = c/f
```

where λ is wavelength and f is frequency. Thus higher frequency corresponds to shorter
wavelength.

---

## Why Frequency Matters

RF systems are naturally described in frequency because:
- antennas have frequency-dependent behaviour
- filters select frequency ranges
- amplifiers have frequency-dependent gain
- propagation depends on wavelength
- measurement instruments often display spectral content

**Project application:** The NRF24L01+ operates in the 2.4 GHz ISM band. At 2.4 GHz:

```
λ = c/f = (3 × 10⁸) / (2.4 × 10⁹) ≈ 0.125 m = 12.5 cm
```

The SMA antennas on the NRF24L01+PA+LNA module are therefore short relative to a
quarter-wave, typically stub or whip types tuned for the ISM band.

---

## Power and Decibels

Power ratios are commonly expressed as:

```
G_dB = 10 log₁₀(P₂/P₁)
```

Voltage ratios for equal impedances are:

```
G_dB = 20 log₁₀(V₂/V₁)
```

> **Caution:** The 20-log expression assumes the impedance relationship needed to
> convert voltage ratio into power ratio. Do not mix these without checking impedance.

---

## dBm

Absolute power relative to 1 mW is expressed as:

```
P_dBm = 10 log₁₀(P_mW)
```

Therefore:

```
P_mW = 10^(P_dBm / 10)
```

The NRF24L01+PA+LNA is configured to `RF24_PA_MAX` in the firmware.
The exact output power level in dBm is **MISSING** from the surviving evidence and
should be verified from the datasheet for the specific PA variant used.

---

## Impedance

RF circuits are sensitive to impedance because voltage/current relationships depend on
the load.

For a resistive load:

```
P = V_rms² / R = I_rms² R
```

When complex impedance is involved:

```
Z = R + jX
```

and voltage/current phase relationships matter.

---

## Matching

A source, transmission line, and load need not have identical physical characteristics,
but impedance matching is important for efficient power transfer and predictable RF
behaviour.

The reflection coefficient is:

```
Γ = (Z_L - Z₀) / (Z_L + Z₀)
```

where `Z_L` is load impedance and `Z₀` is characteristic impedance.

The magnitude `|Γ|` indicates the fraction of the travelling-wave voltage amplitude
that is reflected.

---

## Standing-Wave Concepts

Reflections can produce standing-wave patterns.

The voltage standing-wave ratio is:

```
VSWR = (1 + |Γ|) / (1 - |Γ|)
```

These concepts are fundamental when discussing RF interconnects and antenna interfaces.

---

## Project Relevance

These concepts provide the academic foundation for interpreting:
- the NRF24L01+PA+LNA module behaviour
- the SMA antenna interface
- any spectral plots appearing in project evidence
- the significance of the 10 µF decoupling capacitors (supply stability under RF load)

Exact project impedances, matching networks, and power measurements should be
recovered from the original project evidence.

**Project-specific evidence:** whiteboard schematic in `media/schematic.jpg` shows
the SPI connections and decoupling placement but does **not** show antenna matching
network details.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| NRF24 PA level setting | [`src/main.cpp`](../../src/main.cpp), line 58/70 |
| Physical antenna description | [`docs/hardware.md`](../hardware.md) |
| Power supply decoupling | [`docs/hardware.md`](../hardware.md), assembly notes |

---

## Related Theory Sections

- [01 — Project Scope and System Context](01-project-scope-and-system-context.md)
- [07 — Antennas, Propagation, and Link Concepts](07-antennas-propagation-and-link-concepts.md)
- [08 — RF Front Ends, Amplification, and Power Concepts](08-rf-frontends-amplification-and-power.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Fundamentals*, *RF*, *Amplification*.
