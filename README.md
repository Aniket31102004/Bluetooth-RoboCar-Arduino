# Bluetooth-RoboCar-Arduino
# 🤖 Megatron – Bluetooth-Controlled Robot Car

A powerful and agile **Arduino-powered robot car** controlled via Bluetooth, equipped with a **ball-kicking mechanism** and an engineered **voltage recovery circuit** for optimal motor performance.

![Megatron Animation](images/megatron-demo.gif)

---

## 🚀 Features

- 🔷 **Bluetooth Control** via HC-05 module and smartphone
- 🧠 **Arduino Uno** at the core of operations
- ⚽ **Servo-based Kicking Mechanism** for ball-pushing action
- 🔋 **Custom Voltage Recovery Circuit** to fix 3V drop and power 12V DC motors effectively
- 🏁 **Competition Performance**: 🥈 Secured **2nd Place** at *Roboholic* for speed and efficiency

---

## 🛠️ Tech Stack & Components

| Component              | Description                           |
|------------------------|---------------------------------------|
| Arduino UNO            | Main microcontroller                  |
| HC-05                  | Bluetooth Module                      |
| L298N Motor Driver     | Dual H-Bridge driver for DC motors    |
| 12V DC Motors (x4)     | Main drive motors                     |
| Servo Motor            | Kicking mechanism                     |
| Li-ion Battery Pack    | Power supply                          |
| Custom PCB             | For voltage recovery circuitry        |
| Android Bluetooth App  | To control movements                  |

---

## 🔧 How It Works

1. **Pair HC-05** with your Android phone.
2. Upload the Arduino `.ino` code to the Uno.
3. Control robot using an Android Bluetooth terminal or custom app.
4. Servo kicks when "K" command is received. Movement via `F`, `B`, `L`, `R`.

---

## 🧩 System Block Diagram

![Block Diagram](circuit diagram/)

---

## ⚡ Voltage Recovery Circuit

Ensures full **12V output** to motors by compensating for **voltage drops** caused by load or wiring.
Used 2 relays to bypass the voltage driver. This Directly connect's the battry with motor, so no drop. Also one more design is to use an SCR or Transistor. I had many designs ready but due to restrictions couldnt execute them. 

---

## 🏆 Achievements

| Event       | Award        | Remarks                          |
|-------------|--------------|----------------------------------|
| Roboholic   | 🥈 2nd Place | Fastest bot with powerful servo  |

---

## 📸 Project Gallery

| Demo Video | Close-up | Action Shot |
|------------|----------|-------------|
| ![Video](images/demo1.gif) | ![Close](images/servo.png) | ![Kick](images/kick.gif) |

---

## 💻 Code & Commands

```cpp
// Sample movement command logic
if (receivedChar == 'F') moveForward();
if (receivedChar == 'B') moveBackward();
if (receivedChar == 'L') turnLeft();
if (receivedChar == 'R') turnRight();
if (receivedChar == 'K') kickBall();
