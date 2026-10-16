# 🌊 Arduino Automated Flood Warning System

An environmental monitoring prototype built with an Arduino to track rising water levels and simulate urban flood warning alerts. Developed as part of a "Green Arduino" environmental initiative.

## 📌 Project Overview
Urban flooding is a major challenge in many regions (such as Thailand). This project uses ultrasonic distance sensing to continuously monitor water levels in real-time. Depending on how close the water gets to street level, the system triggers different LED indicators and an emergency buzzer to simulate an early-warning alert system.

---

## 🛠️ Components & Materials
* **Arduino Uno / Nano** (Included in the Arduino Student Kit)
* **HC-SR04 Ultrasonic Distance Sensor** *(Extra component required)*
* **3x LEDs** (Green, Yellow, Red) + **220-ohm Resistors** (Included in kit)
* **Piezo Buzzer / Capsule** (Included in kit)
* **Breadboard & Jumper Wires** (Included in kit)
* **USB Power Cable / Power Source**

---

## 🔌 Wiring Guide

| Component | Component Pin | Arduino / Board Connection |
| :--- | :--- | :--- |
| **HC-SR04 Sensor** | VCC | 5V Rail |
| | GND | GND Rail |
| | Trig | Digital Pin 7 |
| | Echo | Digital Pin 6 |
| **Green LED (Safe)** | Anode (via 220Ω resistor) | Digital Pin 3 |
| | Cathode | GND Rail |
| **Yellow LED (Warning)** | Anode (via 220Ω resistor) | Digital Pin 4 |
| | Cathode | GND Rail |
| **Red LED (Danger)** | Anode (via 220Ω resistor) | Digital Pin 5 |
| | Cathode | GND Rail |
| **Piezo Buzzer** | Positive (+) | Digital Pin 2 |
| | Negative (-) | GND Rail |

---

## ⚙️ System Logic
* **Safe Zone (Distance > 30 cm):** Green LED is ON. Normal conditions.
* **Warning Zone (15 cm – 30 cm):** Yellow LED is ON. Water level is rising.
* **Danger Zone (Distance < 15 cm):** Red LED is ON and the Buzzer sounds a continuous alarm simulating an emergency alert.

---

## 💻 Arduino Code
You can find the source code in the `flood_warning.ino` file in this repository, or copy it below:

```cpp
// Define pins for the Ultrasonic Sensor
const int trigPin = 7;
const int echoPin = 6;

// Define pins for LEDs and Buzzer
const int greenLed = 3;
const int yellowLed = 4;
const int redLed = 5;
const int buzzer = 2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  Serial.print("Water distance from sensor: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance > 30 || distance <= 0) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  } 
  else if (distance <= 30 && distance > 15) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  } 
  else {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000);
  }
  
  delay(500);
}
