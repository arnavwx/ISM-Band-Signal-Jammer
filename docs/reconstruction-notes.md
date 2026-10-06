# Reconstruction Notes

This project repository was reconstructed after the original development machine was reset. The final submitted project report/paper was **not recovered** in the provided archives. Therefore, the repository and its documentation were built by conducting forensics on the surviving project chat logs, component lists, circuit diagrams, and demonstration videos.

## Reconstruction Matrix

| Project Component       | Repository Artifact   | Status        | Evidence Source |
| ----------------------- | --------------------- | ------------- | --------------- |
| Original Motivation / Idea | `README.md` | Reconstructed | WhatsApp Chat Log (Initial assigned project was 555-timer, team pivoted to ESP32 2.4GHz jammer) |
| System Architecture / Schematic | `docs/architecture.md` | Reconstructed | `IMG-20251017-WA0007.jpg` (Whiteboard circuit sketch) |
| Hardware Components List | `docs/hardware.md` | Recovered | `Components_Electroboom_EW1.pdf` |
| Jammer Source Code | `src/main.cpp` | Reconstructed | WhatsApp Chat references to GitHub repos (`ESP32-BlueJammer`, `cypher-jammer`) + circuit diagram pinouts. |
| Experimental Results | `docs/demonstration.md` | Recovered | Video files (`VID-*.mp4` / `WhatsApp Video...mp4`) |
| Build System / Toolchain | `platformio.ini` | Reconstructed | Standard industry practice applied for ESP32 + Arduino framework projects. |

## Major Reconstruction Decisions
1. **Source Code**: The original source files were completely lost. The chat logs indicated the team referenced existing open-source ESP32 jammers (like `ESP32-BlueJammer`). The code in this repository (`src/main.cpp`) is a clean, ground-up implementation using the `RF24` library to perform rapid frequency sweeping across the 2.4GHz band, mirroring the intended functionality without directly plagiarizing external repos.
2. **Missing OLED Logic**: While the component list includes a 0.96" OLED display, the whiteboard circuit diagram did not show its wiring. It was inferred that standard I2C pins (SDA=21, SCL=22) were used. Basic UI logic was added to the reconstructed code to display the current jamming channel.
3. **Absence of Final Paper**: Because the final paper was missing from the evidence, there is no direct mapping to specific paper sections. Instead, the documentation focuses on the architecture and the recovered hardware/video evidence.
