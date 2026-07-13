# ⚡ IoT-Based Multi-Room Smart Energy Monitoring System using ESP32

A smart IoT-based energy monitoring system that measures and visualizes real-time power consumption across multiple rooms using **ESP32**, **Blynk IoT**, and **ThingSpeak**. The system provides room-wise energy monitoring, overload detection, relay control, and cloud-based visualization to help users monitor electricity usage efficiently.

---

## 📌 Table of Contents

- Overview
- Features
- Hardware Components
- Software & Technologies
- System Architecture
- Working Principle
- Project Structure
- Getting Started
- Screenshots
- Future Enhancements
- License
- Author

---

# 📖 Overview

Managing electricity consumption efficiently is becoming increasingly important in homes, hostels, offices, and educational institutions.

This project presents an IoT-based smart energy monitoring system capable of monitoring electrical parameters from multiple rooms in real time using an ESP32 microcontroller. Sensor readings are transmitted to cloud platforms for visualization while users can remotely monitor the system using the Blynk mobile application.

The project was designed to demonstrate IoT communication, cloud integration, and embedded system development using simulation tools before hardware implementation.

---

# ✨ Features

- 📊 Real-time room-wise energy monitoring
- ⚡ Total power consumption calculation
- ☁️ Cloud monitoring using ThingSpeak
- 📱 Mobile monitoring using Blynk IoT
- 🚨 Overload detection
- 🔌 Relay control for connected loads
- 📈 Live visualization of sensor values
- 🌐 ESP32 Wi-Fi connectivity
- 🧪 Fully simulated using Wokwi

---

# 🛠 Hardware Components

| Component | Quantity |
|------------|---------:|
| ESP32 Development Board | 1 |
| Potentiometers (Current Simulation) |  |
| Relay Module | 1 |
| LEDs |  |
| Breadboard | 1 |
| Jumper Wires | As Required |

---

# 💻 Software & Technologies

- Arduino IDE
- ESP32
- Embedded C++
- Wokwi Simulator
- Blynk IoT
- ThingSpeak
- Git & GitHub

---

# 🏗 System Architecture

```
Room Loads
      │
      ▼
Current Measurement
      │
      ▼
ESP32 Controller
      │
 ┌────┴─────┐
 │          │
 ▼          ▼
Blynk    ThingSpeak
 │          │
 ▼          ▼
Mobile    Cloud Dashboard
```

---

# ⚙ Working Principle

1. ESP32 reads the simulated current values from multiple room inputs.
2. The controller calculates power consumption for each room.
3. Total energy consumption is computed continuously.
4. Data is transmitted to the Blynk IoT platform for mobile monitoring.
5. Sensor values are uploaded to ThingSpeak for cloud visualization.
6. If power exceeds the predefined threshold, overload protection activates the relay.

---

# 📂 Project Structure

```
Multi-Room-Smart-Energy-Monitor/
│
├── README.md
├── LICENSE
├── code/
│   └── Multi_Room_Smart_Energy_Monitor.ino
│
├── images/
│   ├── circuit_diagram.png
│   ├── wokwi_simulation.png
│   ├── blynk_dashboard.png
│   └── thingspeak_dashboard.png
│
├── docs/
│   └── Project_Report.pdf
│
└── media/
    └── demo_video.mp4
```

---

# 🚀 Getting Started

1. Clone this repository.

```
git clone https://github.com/priyadharshinit2025ece-boop/Multi-Room-Smart-Energy-Monitor.git
```

2. Open the project in Arduino IDE.

3. Install the required ESP32 board package.

4. Install the Blynk library.

5. Replace:

```
YOUR_BLYNK_AUTH_TOKEN
```

with your own Blynk Authentication Token.

6. Replace:

```
YOUR_THINGSPEAK_API_KEY
```

with your own ThingSpeak API Key.

7. Upload the program to ESP32 or run the project using Wokwi.

---

# 📷 Project Screenshots

## Wokwi Simulation

> *<img width="1522" height="727" alt="image" src="https://github.com/user-attachments/assets/a0be9c6b-edb0-4b5e-8803-7ddf3f839035" />
*

---

## Circuit Diagram

> *<img width="941" height="637" alt="image" src="https://github.com/user-attachments/assets/2f1e31e2-4bd8-41e6-8ded-0ffad6b125ff" />
*

---

## Blynk Dashboard

> *<img width="1835" height="801" alt="image" src="https://github.com/user-attachments/assets/d0a349a6-5610-4d9e-90df-2d111a3c487b" />
*

---

## ThingSpeak Dashboard

> *<img width="1287" height="453" alt="image" src="https://github.com/user-attachments/assets/683abafa-bdb7-4cab-a940-77781c5f8653" />
<img width="1283" height="448" alt="image" src="https://github.com/user-attachments/assets/d46e961e-b158-4749-8448-c0483ba967f3" />
<img width="671" height="426" alt="image" src="https://github.com/user-attachments/assets/31077b43-b665-44ce-9984-6aaaeff7ab37" />


*

---

# 📈 Future Enhancements

- Mobile notifications for abnormal power consumption
- Firebase cloud integration
- Energy usage history
- AI-based power consumption prediction
- Smart billing system
- Appliance-wise energy monitoring
- Mobile application using Flutter
- Physical hardware implementation

---

# 📄 License

This project is developed for educational and learning purposes.

---

# 👩‍💻 Author

**Priyadharshini T**

Electronics and Communication Engineering

Rajalakshmi Engineering College

GitHub:
https://github.com/priyadharshinit2025ece-boop

LinkedIn:
https://www.linkedin.com/in/priyadharshini-tamilselvan-707497383/

---

⭐ If you found this project helpful, consider giving it a star!
