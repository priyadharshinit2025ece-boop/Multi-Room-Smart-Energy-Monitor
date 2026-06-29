# Multi-Room Smart Energy Monitoring System
### ESP32 · Wokwi Simulation

> Real-time energy consumption tracking and visualization across multiple rooms — built on ESP32 with a fully simulated IoT architecture.

---

## Table of Contents

- [Overview](#overview)
- [Platform](#platform)
- [Features](#features)
- [Simulated Components](#simulated-components)
- [Circuit Design](#circuit-design)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Wokwi Simulation](#wokwi-simulation)
- [Learning Outcomes](#learning-outcomes)
- [Future Improvements](#Future-Improvements)

---

## Overview

This project demonstrates a **smart energy monitoring system** simulated entirely within the [Wokwi ESP32 Simulator](https://wokwi.com). It models how an IoT-based system tracks, processes, and visualizes real-time power consumption across multiple rooms — making it an ideal learning platform for embedded systems, sensor integration, and IoT architecture design.

---

## Platform

| Tool | Purpose |
|------|---------|
| **Wokwi Simulator** | Full ESP32 hardware simulation |
| **ESP32** | Microcontroller and WiFi connectivity |
| **Arduino / C++** | Firmware development |

---

## Features

- **Multi-room monitoring** — Independently tracks energy usage across several rooms simultaneously
- **Real-time updates** — Sensor readings are processed and displayed with minimal latency
- **IoT architecture** — Designed around a publish/subscribe or polling model for scalable data flow
- **Dashboard simulation** — Visualizes consumption data via serial output or a connected cloud endpoint
- **Modular design** — Each room's monitoring logic is encapsulated and easily extensible

---

## Simulated Components

| Component | Role |
|-----------|------|
| ESP32 | Main microcontroller; handles computation and WiFi |
| Virtual Current Sensors | Simulate AC/DC current draw per room |
| Simulated WiFi | Enables cloud/MQTT data publishing within the simulation |
| Serial Monitor | Displays real-time energy readings during the simulation |

---

## Circuit Design

The circuit schematic is defined in `diagram.json` and is fully compatible with the Wokwi simulator. No physical hardware is required.

To inspect the circuit:
1. Open the [Wokwi project link](#wokwi-simulation)
2. Navigate to the **Diagram** tab
3. The `diagram.json` file in this repository reflects the exact same configuration

---

## Getting Started

### Option 1 — Run in Wokwi (Recommended)

1. Click the [Wokwi Project Link](#wokwi-simulation) below
2. The simulation will load automatically with all components pre-configured
3. Press **▶ Start Simulation** to begin
4. Open the **Serial Monitor** to view live energy readings

### Option 2 — Clone and Load Manually

```bash
git clone https://github.com/priyadharshinit2025ece-boop/Multi-Room-Smart-Energy-Monitor.git
cd Multi-Room-Smart-Energy-Monitor
```

1. Go to [wokwi.com](https://wokwi.com) and create a new ESP32 project
2. Replace the default `diagram.json` with the one from this repository
3. Copy the contents of `main.ino` (or `main.cpp`) into the editor
4. Press **▶ Start Simulation**

---

## Project Structure

```
├── diagram.json        # Wokwi circuit definition
├── sketch.ino          # Main firmware (Arduino-style)
├── README.md           # Project documentation
└── assets/             # Screenshots or simulation output (optional)
```

---

## Wokwi Simulation

**▶ [Open in Wokwi](https://wokwi.com/projects/449596575415278593)**


---

## Learning Outcomes

Working through this project covers the following concepts:

- **ESP32 programming** — GPIO, ADC reading, timing, and serial communication
- **IoT system design** — Sensor-to-cloud data pipelines and device architecture
- **Sensor data simulation** — Modeling real-world analog signals in a virtual environment
- **Energy monitoring principles** — Calculating power (P = V × I) and aggregating usage over time
- **Wokwi simulator** — Using simulation tooling for rapid embedded prototyping without hardware

---
## Future Improvements

-- Deploy the system on physical ESP32 hardware with current sensors (e.g., ACS712).
- Integrate cloud storage and analytics using Firebase or Blynk.
- Develop a mobile application for real-time monitoring and notifications.
- Add historical energy usage reports and data visualization.

## Skills Demonstrated

- Embedded Systems
- ESP32 Programming
- Arduino IDE
- IoT
- Wokwi Simulation
- C++
- Sensor Interfacing

<p align="center">Built with ☕ and curiosity · Simulated on <a href="https://wokwi.com">Wokwi</a></p>
