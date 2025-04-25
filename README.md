
# WaterWise – Smart Water Management System

WaterWise is a low-cost, solar-powered smart water monitoring system designed for rural areas. It uses an ultrasonic sensor to detect water levels and sends SMS alerts when tanks need refilling.

## 💡 Features
- Ultrasonic-based level detection
- GSM SMS alerts when water is low
- Solar-powered setup for remote locations
- Easy to deploy and scale

## 🛠 Hardware Components
- Arduino Uno or ESP32
- Ultrasonic Sensor (HC-SR04)
- GSM Module (SIM800L)
- 18650 Battery + Solar Panel
- Jumper wires, resistors, breadboard

## 📦 Setup
1. Wire the components as per the diagram.
2. Upload `waterwise.ino` to your Arduino using the Arduino IDE.
3. Insert a SIM card into the GSM module.
4. Power up the system and test it.

## 📱 Alerts
You will receive an SMS like:  
`"Water level low! Please refill the tank."`

## 📸 Wiring Diagram
![Wiring Diagram](wiring-diagram.png)

## 🔓 License
MIT – free for personal or commercial use.
