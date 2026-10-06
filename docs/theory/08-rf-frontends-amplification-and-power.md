# 8. RF Front Ends, Amplification, and Power Concepts

## RF Signal Chain

A generic RF signal chain may contain:

```
source → conditioning → filtering → amplification → interface → measurement
```

**Project signal chain (RECONSTRUCTED):**

```
ESP32 SPI → NRF24L01 baseband → NRF24 PA → SMA connector → antenna
```

The exact project chain must be verified from the original evidence.

---

## Gain

Voltage gain:

```
A_v = V_out / V_in
```

Power gain:

```
G_p = P_out / P_in
```

In decibels:

```
G_dB = 10 log₁₀(G_p)
```

---

## Cascaded Gain

For cascaded stages, linear gains multiply:

```
G_total = G₁ × G₂ × ... × G_n
```

In dB they add:

```
G_total,dB = G₁,dB + G₂,dB + ... + G_n,dB
```

---

## Noise Figure

Noise figure compares the degradation of SNR caused by a system:

```
F = SNR_in / SNR_out
```

Noise figure in dB:

```
NF_dB = 10 log₁₀(F)
```

**Project note:** The NRF24L01+PA+LNA includes an LNA (low-noise amplifier) on the
receive path. In this project, the module operates exclusively in transmit mode
(`stopListening()` in firmware). The LNA is therefore not exercised during normal
jammer operation, but its presence affects the module''s sensitivity if used for
reception.

---

## Compression and Nonlinearity

Real amplifiers are not perfectly linear.

At sufficiently high input levels, gain compression occurs.

A common metric is the 1-dB compression point, where actual gain is 1 dB below the
extrapolated small-signal gain.

---

## Harmonic Distortion

Nonlinear behaviour can generate harmonics.

For a nonlinear response:

```
y = a₁x + a₂x² + a₃x³ + ...
```

a sinusoidal input can therefore produce components at multiples of the input frequency.

**Project application:** The NRF24L01+PA+LNA module operating at maximum PA level
(`RF24_PA_MAX`) may produce harmonic components. The second harmonic of 2.4 GHz
would appear near 4.8 GHz (outside the ISM band). Whether harmonics were observed
is **UNKNOWN** from surviving evidence.

---

## Intermodulation

With multiple tones, nonlinearities can create sum and difference products such as:

```
2f₁ - f₂
2f₂ - f₁
```

These can be important because some products may fall near frequencies of interest.

---

## PA and LNA in the NRF24L01+PA+LNA Module

The `+PA+LNA` variant adds:
- a **Power Amplifier (PA)** on the transmit path — increases transmitted power
- a **Low-Noise Amplifier (LNA)** on the receive path — increases receive sensitivity

The firmware sets `RF24_PA_MAX` for both radios. The exact output power in dBm is
**MISSING** — it depends on the specific module variant and PCB layout. Typical
values quoted for common NRF24L01+PA+LNA modules are on the order of +20 dBm,
but this must be verified against the actual module datasheet.

---

## Power Supply Considerations

RF/electronic systems are sensitive to:
- supply ripple
- regulator noise
- decoupling
- grounding
- current capability
- thermal dissipation

Digital switching circuitry can also couple unwanted components into analog/RF sections.

**Project application:** The hardware documentation explicitly notes that 10 µF
capacitors must be placed across each NRF24 module''s VCC/GND pins to prevent
voltage brown-outs during high-power RF bursts. This is consistent with the PA
stage drawing significant instantaneous current.

---

## Project Relevance

This theory supports analysis of amplification, signal conditioning, nonlinearity,
spurs, and power behaviour visible in project evidence.

Do not infer an exact amplifier architecture or operating point without source evidence.

**Project-specific evidence:** PA output power is **MISSING** from surviving
artifacts. Module typical power from generic datasheets is mentioned above but is
**INFERRED**, not RECOVERED from project-specific measurement.

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| PA level configuration | [`src/main.cpp`](../../src/main.cpp) — `RF24_PA_MAX` |
| Decoupling capacitor placement | [`docs/hardware.md`](../hardware.md) — component 6 |
| Module description | [`docs/hardware.md`](../hardware.md) — component 2 |

---

## Related Theory Sections

- [02 — Electromagnetics and RF Fundamentals](02-electromagnetics-and-rf-fundamentals.md)
- [05 — Noise, Interference, and SNR](05-noise-interference-and-snr.md)
- [07 — Antennas, Propagation, and Link Concepts](07-antennas-propagation-and-link-concepts.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Amplification* (Why do nonlinear devices create harmonics? What is
compression? What is noise figure?).
