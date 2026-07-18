# MQTT Communication using ESP32 and DHT22

This project demonstrates the implementation of the MQTT (Message Queuing Telemetry Transport) protocol using an ESP32 microcontroller and a DHT22 temperature and humidity sensor. The ESP32 acts as an MQTT client, publishing sensor readings to a broker while simultaneously subscribing to MQTT topics for receiving messages or control commands.

---

## Overview

MQTT is a lightweight publish/subscribe messaging protocol widely used in Internet of Things (IoT) applications due to its low bandwidth consumption and efficient communication model.

In this implementation, the ESP32 periodically reads temperature and humidity data from the DHT22 sensor and publishes the values to an MQTT broker. The ESP32 also subscribes to predefined topics to receive incoming messages, enabling two-way communication.

---

## Features

- ESP32 Wi-Fi connectivity
- DHT22 temperature and humidity monitoring
- MQTT Publish functionality
- MQTT Subscribe functionality
- Real-time data transmission
- Lightweight IoT communication
- Bidirectional messaging

---

## Hardware Components

- ESP32 Development Board
- DHT22 Temperature & Humidity Sensor
- USB Cable
- Breadboard
- Jumper Wires

---

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- PubSubClient Library
- DHT Sensor Library
- Wi-Fi Network
- MQTT Broker (Mosquitto, HiveMQ, etc.)

---

## Working Principle

1. ESP32 connects to the Wi-Fi network.
2. The device establishes a connection with the MQTT broker.
3. Temperature and humidity values are read from the DHT22 sensor.
4. Sensor readings are published to MQTT topics.
5. The ESP32 subscribes to specified topics.
6. Incoming messages are received and processed in real time.

