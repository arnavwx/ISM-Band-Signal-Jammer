# 12. System Integration and Engineering Tradeoffs

## Engineering is Optimisation Under Constraints

A real project must balance:

| Metric | Project example |
| :--- | :--- |
| Performance | Spectrum coverage, sweep rate, interference range |
| Cost | Bill of materials; off-the-shelf modules |
| Complexity | Dual-radio SPI multiplexing; firmware sweep logic |
| Power | 3.7 V Li-ion; PA power draw |
| Size | Dual-breadboard prototyping |
| Reliability | Decoupling capacitors; radio init checks |
| Availability | Off-the-shelf ESP32 and NRF24 modules |
| Measurement accuracy | **UNKNOWN** — no measurement plan recovered |
| Safety | Academic disclaimer; frequency band regulations |

Improving one metric can worsen another.

---

## Hardware/Software Co-Design

A task can often be implemented:
- physically in analog hardware
- digitally in firmware/software
- or through a hybrid architecture

**Project choice:** The channel sweep is implemented in firmware (software loop over
channels 1–83). The RF modulation and PA are hardware-based inside the NRF24 module.

The correct choice depends on bandwidth, latency, precision, power, complexity, and
component availability.

---

## Simulation versus Hardware

Simulation provides:
- rapid iteration
- parameter sweeps
- idealised analysis
- debugging before fabrication

Hardware introduces:
- parasitics
- component tolerance
- thermal effects
- supply noise
- layout effects
- connector/cable behaviour
- environmental coupling

Therefore simulation and measurement should be compared, not assumed identical.

**Project status:** No simulation files are present in the current repository. Whether
circuit simulation (e.g., LTspice) or RF simulation was performed is **UNKNOWN**.

---

## Debugging Methodology

A disciplined debugging process isolates one subsystem at a time.

Useful progression:

1. verify power
2. verify clocks/control
3. verify interfaces
4. verify static operating conditions
5. inject/observe known signals
6. verify expected intermediate behaviour
7. integrate stages
8. perform end-to-end validation

**Project evidence:** The firmware''s startup sequence (`Radio 1 Initialized`, `Radio 2
Initialized`) provides a basic interface-level check. End-to-end validation
(spectrum measurement, victim receiver response) is **MISSING** from current artifacts.

---

## Dual-Radio Design Decision

Using two NRF24L01+ radios offset by 40 channels is a specific engineering tradeoff:

| Benefit | Explanation |
| :--- | :--- |
| Wider simultaneous bandwidth | Two radios cover different spectrum segments at the same instant |
| Faster effective sweep | Both halves of the band are disrupted per sweep cycle |
| Complexity increase | Dual SPI CS lines; more firmware coordination |
| Power increase | Two PA stages drawing current simultaneously |

This tradeoff is documented in [`docs/architecture.md`](../architecture.md).

---

## Failure Analysis

For every unexpected result ask:

- Is the theory wrong?
- Is the implementation wrong?
- Is the measurement wrong?
- Is the environment different?
- Is there an unmodelled parasitic?
- Is the observed feature an artefact?

---

## Reproducibility

A good project archive preserves:
- component versions
- software versions
- configuration
- test conditions
- measurement setup
- raw results
- processed results
- analysis scripts

This is especially important when reconstructing a lost development environment.

**Project assessment:** The current repository recovers:
- component list (RECOVERED from PDF)
- software (RECONSTRUCTED)
- build configuration (RECONSTRUCTED — `platformio.ini`)
- schematic (RECOVERED — whiteboard photo)
- test conditions: **MISSING**
- measurement results: **MISSING**

---

## Cross-References

| Topic | Repository artifact |
| :--- | :--- |
| Dual-radio architecture | [`docs/architecture.md`](../architecture.md) |
| Component tradeoffs | [`docs/hardware.md`](../hardware.md) |
| Build configuration | [`platformio.ini`](../../platformio.ini) |
| Firmware implementation | [`src/main.cpp`](../../src/main.cpp) |

---

## Related Theory Sections

- [01 — Project Scope and System Context](01-project-scope-and-system-context.md)
- [09 — Measurement, Instrumentation, and Validation](09-measurement-instrumentation-and-validation.md)
- [15 — Evidence and Provenance Register](15-evidence-and-provenance-register.md)

---

## Related Viva Questions

See [14 — Viva Questions and Concept Checks](14-viva-questions-and-concept-checks.md),
sections: *Measurement* (Why distinguish simulation and measurement? Why repeat measurements?).
