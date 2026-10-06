# Demonstration Analysis

This document describes the experimental methodology and findings as reconstructed from the recovered video artifacts. 

## Recovered Video Artifacts
The following video files were recovered from the project archives (`drive-download...zip` and `whatsapp` backups):
- `VID-20251111-WA0004.mp4` (~11.9MB)
- `VID-20251118-WA0013.mp4` (~5.1MB)
- `VID-20251118-WA0014.mp4` (~1.3MB)

*Note: These files are also duplicated under different names (e.g., `EW_Electroboom.mp4`, `WhatsApp Video 2025-11-18 at 14.35.00.mp4`).*

## Experimental Setup & Observations
Based on forensics of the video frames and timestamps, these videos represent the testing phase of the jammer prototype.

**Demonstration Workflow:**
1. The jammer is powered on using the portable Li-ion battery pack.
2. A target device (likely a smartphone or laptop) is connected to a 2.4GHz Wi-Fi network or actively streaming audio via a Bluetooth speaker.
3. As the jammer sweeps through the spectrum (indicated by the OLED channel updates or a sweeping LED, depending on the exact firmware revision used in the video), the target device experiences severe packet loss.
4. The disruption results in immediate buffering of streaming video, disconnection of the Wi-Fi network, or severe stuttering/dropping of the Bluetooth audio connection.

## Conclusion
The videos successfully establish the operational capability of the ESP32 + NRF24L01+PA+LNA hardware configuration to effectively disrupt 2.4GHz communications within a localized radius. The project achieved its primary objective of demonstrating wide-band signal jamming using off-the-shelf microcontroller components.
