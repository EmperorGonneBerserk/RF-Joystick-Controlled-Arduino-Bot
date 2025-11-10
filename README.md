# 🤖 RF Joystick-Controlled Arduino Bot

A **wireless Arduino robot** controlled using a **joystick and 433 MHz RF modules**.  
This project uses two Arduinos — a **Transmitter (TX)** with a joystick, and a **Receiver (RX)** connected to motors through a motor driver.  
The system sends commands (`F`, `B`, `L`, `R`, `S`) via **RadioHead ASK** protocol to control the bot’s movement wirelessly.

---

## 🧠 Project Overview

| Part | Description |
|------|--------------|
| **Transmitter (TX)** | Reads joystick position and transmits direction commands wirelessly using 433 MHz RF transmitter. |
| **Receiver (RX)** | Receives commands and controls DC motors accordingly using a motor driver. |
| **Technology** | Arduino UNO / Nano, RadioHead ASK library, L298N or L293D Motor Driver. |

---

## ⚙️ Components Used

### Transmitter
- Arduino UNO / Nano  
- Joystick module (2-axis)  
- 433 MHz RF Transmitter module  
- Breadboard & jumper wires  
- 9V battery  

### Receiver
- Arduino UNO / Nano  
- 433 MHz RF Receiver module  
- L298N / L293D motor driver  
- 2 DC motors + wheels  
- Robot chassis & battery pack  

---

## 🧩 Circuit Overview

| Connection | Description |
|-------------|-------------|
| **Joystick → Arduino** | X → A0, Y → A1 |
| **RF TX Module → Arduino** | DATA → D12 (default for RadioHead ASK) |
| **RF RX Module → Arduino** | DATA → D11 (default for RadioHead ASK) |
| **Motor Driver → Arduino** | ENA → D5, IN1 → D8, IN2 → D9, ENB → D6, IN3 → D10, IN4 → D7 |

---

🎞️ **Watch it here:**  
👉 [View Demo Video](https://github.com/EmperorGonneBerserk/RF-Joystick-Controlled-Arduino-Bot/raw/main/bot_demo.mp4)
