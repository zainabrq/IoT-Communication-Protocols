# Bluetooth LED Control using ESP32

This project demonstrates wireless LED control using Bluetooth Serial communication with an ESP32 microcontroller. The ESP32 receives commands wirelessly from a Bluetooth-enabled device, such as a smartphone, and controls an LED based on the received commands.

---

## Overview

Bluetooth Serial communication enables short-range wireless communication between the ESP32 and a smartphone or other Bluetooth-enabled device.

In this experiment, the ESP32 is configured as a Bluetooth Serial device. A user can connect to the ESP32 using a Bluetooth Serial Terminal application and send commands to turn the LED **ON** or **OFF** remotely.

---

## Features

- Wireless communication using Bluetooth
- ESP32-based Bluetooth Serial communication
- Remote LED control
- Command-based device control
- Real-time response to Bluetooth commands

---

## Hardware Components

- ESP32 Development Board
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- Smartphone or Bluetooth-enabled device

---

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- Bluetooth Serial Library
- Bluetooth Serial Terminal application

---

## Working Principle

1. The ESP32 initializes its Bluetooth Serial interface.
2. A Bluetooth-enabled device connects to the ESP32.
3. The user sends a command through a Bluetooth Serial Terminal application.
4. The ESP32 receives the command.
5. Based on the received command:
   - `ON` → LED turns ON
   - `OFF` → LED turns OFF
6. The LED status is updated in real time.

---

## Commands

| Command | Action |
|---------|--------|
| `ON` | Turns the LED ON |
| `OFF` | Turns the LED OFF |

---

## Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| LED Anode (+) | GPIO 2 |
| LED Cathode (-) | GND through 220Ω resistor |

> **Note:** The GPIO pin may be changed depending on the circuit and ESP32 board being used.

---


## License

This project is intended for educational and research purposes.
