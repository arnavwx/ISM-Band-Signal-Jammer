# 14. Viva Questions and Concept Checks

Questions are labelled:
- **[GENERAL]** — standard engineering concept applicable to any RF/electronics project
- **[PROJECT]** — specific to the ISM Band Signal Jammer; answer requires evidence from the project archive

---

## Fundamentals

### [GENERAL] What is frequency?
Frequency is the number of cycles of a periodic phenomenon per unit time.

### [GENERAL] What is wavelength?
For propagation speed v:

```
λ = v/f
```

For free-space electromagnetic propagation, v ≈ c.

At 2.4 GHz: λ ≈ 12.5 cm.

### [GENERAL] What is bandwidth?
Bandwidth is a measure of the frequency extent associated with a signal or system,
with the exact definition depending on context (3-dB, null-to-null, occupied, etc.).

### [GENERAL] What is gain?
Gain describes the ratio of output to input. Power gain and voltage gain use different
logarithmic conversions (10 log and 20 log respectively).

### [GENERAL] What is dB?
dB expresses a ratio logarithmically.

### [GENERAL] What is dBm?
dBm expresses absolute power relative to 1 mW.

---

## Signals

### [GENERAL] Why use Fourier analysis?
Because many systems are naturally frequency-selective, and Fourier analysis reveals
how signal energy/content is distributed over frequency.

### [GENERAL] What causes spectral leakage?
Finite-duration observation corresponds to windowing in time, which convolves the
ideal spectrum with the transform of the window.

### [GENERAL] What is aliasing?
Aliasing is the ambiguity created when sampling causes spectral replicas to overlap.

---

## RF

### [GENERAL] Why does impedance matter?
It determines voltage/current relationships and affects power transfer and reflections
at interfaces.

### [GENERAL] What is reflection coefficient?

```
Γ = (Z_L - Z₀) / (Z_L + Z₀)
```

### [GENERAL] Why can RF measurements be misleading?
Because cables, connectors, loading, instrument settings, calibration, environment,
and noise can all affect observations.

### [PROJECT] What frequency range does the jammer operate in?
2.4 GHz ISM band, channels 1–83, covering approximately 2401–2483 MHz.
Evidence: `docs/architecture.md`, `src/main.cpp`.

### [PROJECT] How does the dual-radio approach increase effectiveness?
Radio 1 sweeps channel `ch`; Radio 2 simultaneously sweeps channel `(ch+40)%84`.
This covers two different 1 MHz segments per iteration, doubling simultaneous
spectral coverage. Evidence: `src/main.cpp` loop logic.

---

## Amplification

### [GENERAL] Why do nonlinear devices create harmonics?
Because nonlinear transfer characteristics can be represented by polynomial terms
that transform a sinusoidal input into multiple frequency components.

### [GENERAL] What is compression?
Compression occurs when an amplifier''s incremental gain decreases as signal level
increases.

### [GENERAL] What is noise figure?
Noise figure quantifies degradation of SNR introduced by a system.

### [PROJECT] What power level do the NRF24 modules operate at?
Configured to `RF24_PA_MAX` in firmware. Exact dBm output: **MISSING** from
surviving evidence. Typical manufacturer data for the +PA+LNA variant suggests
elevated power relative to the base NRF24L01, but this must be verified from the
specific module datasheet.

---

## Filtering

### [GENERAL] Why is the −3 dB point important?
For a power ratio, −3 dB corresponds approximately to half power. For voltage across
equal impedance, the magnitude is approximately 0.707 of the reference.

### [GENERAL] What is Q?
For a resonant system, Q commonly relates center frequency to bandwidth:

```
Q = f₀ / BW
```

Higher Q means narrower passband and greater frequency selectivity.

---

## Modulation

### [GENERAL] What modulation does the NRF24L01 use?
GFSK (Gaussian Frequency-Shift Keying). This is continuous-phase FSK with a Gaussian
pulse-shaping filter, providing controlled occupied bandwidth.

### [PROJECT] What data rate is used?
`RF24_2MBPS` (2 Megabits per second). Configured in `src/main.cpp`.

### [PROJECT] What does the jammer transmit?
A 32-byte repeating pattern: `{0xFF, 0xAA, 0x55, 0x00, ...}`, transmitted 5 times
per channel per radio. The pattern is designed to produce broadband spectral content
within each GFSK channel. Evidence: `src/main.cpp`, `noiseData` array.

---

## Measurement

### [GENERAL] Why distinguish simulation and measurement?
Simulation often uses simplified component models and controlled assumptions; physical
hardware introduces parasitics, tolerances, environment, and instrument effects.

### [GENERAL] Why repeat measurements?
To distinguish stable system behaviour from random variation or measurement error.

### [PROJECT] What instruments were used to validate the jammer?
**UNKNOWN.** No measurement records are present in the current repository.
Expected evidence: demonstration videos, lab report.

---

## Embedded Systems

### [PROJECT] What microcontroller was used?
ESP32-WROOM-32D. Evidence: `docs/hardware.md`, `src/main.cpp`.

### [PROJECT] What framework was used?
Arduino framework, compiled with PlatformIO. Evidence: `platformio.ini`.

### [PROJECT] What libraries are required?
- `RF24` by TMRh20
- `Adafruit SSD1306`
- `Adafruit GFX Library`

Evidence: `platformio.ini`, `src/main.cpp` includes.

---

## Project-Specific Viva

The exact final viva questions should be extracted from the original project chat/report
once those artifacts are available. Until then, see the question register:
[13 — Project Doubts and Questions Register](13-project-doubts-and-questions-register.md).
