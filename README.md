Automated Flood Warning System

A STEM project for Grade 12 featuring an Arduino Uno R3-based real-time flood monitoring system. The project uses an ultrasonic sensor to measure water levels continuously and displays live status updates on an LCD 1602 display, alongside a 3mm 3-LED visual alert system (Green, Yellow, Red). All electronics are safely housed inside a transparent custom enclosure for clean presentation and structural protection.


Project Features

- Real-Time Distance Sensing: Measures water level height using an ultrasonic sensor.
- Visual Alert LEDs: 3-stage warning system (Safe / Caution / Flood Warning).
- Live Display: Displays current distance and alert state on an LCD 1602 screen.
- Protective Enclosure: Encased in a clear transparent housing for durability and visual demonstration during presentations.


Hardware Requirements

Microcontroller & Sensing:
- Arduino Uno R3
- HC-SR04 Ultrasonic Distance Sensor

Outputs & Visuals:
- LCD 1602 or 16x2 Screen (with I2C Module)
- 3x LEDs 3mm (Green, Yellow, Red)
- 3x 220 Ohm Resistors (for LEDs)

Other Components:
- Breadboard & Jumper Wires
- Transparent Enclosure Box
- Power Supply / USB Cable for Arduino


Development Setup & Required Libraries

Software Needed:
- Arduino IDE

Required Libraries (Install via Arduino Library Manager):
- LiquidCrystal_I2C (for driving the LCD screen)


System Logic & Status Levels

1. SAFE (Green LED ON): Water level is within normal range (far from sensor).
2. WARNING (Yellow LED ON): Water level is rising past the caution threshold.
3. ALARM (Red LED ON): High water level detected; flood alert triggered.
## 📝 License
