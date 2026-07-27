# ThingSpeak IoT Cloud Monitoring using ESP32

This project demonstrates the integration of an ESP32 microcontroller with the ThingSpeak IoT cloud platform for remote sensor data monitoring. Temperature and humidity data are collected from a DHT22 sensor and uploaded to ThingSpeak for cloud-based storage and visualization.

A second ESP32 program retrieves the stored sensor data from the ThingSpeak channel and displays the temperature and humidity values on the Serial Monitor.

---

## Overview

ThingSpeak is an IoT analytics platform that enables devices to collect, store, visualize, and analyze sensor data in the cloud.

In this experiment, the ESP32 is used to:

1. Read temperature and humidity data from a DHT22 sensor.
2. Connect to the internet using Wi-Fi.
3. Upload the sensor readings to a ThingSpeak channel.
4. Store the data in the ThingSpeak cloud.
5. Retrieve the stored data using a second program.
6. Display the retrieved temperature and humidity values on the Serial Monitor.

This demonstrates both **cloud data transmission** and **cloud data retrieval** in an IoT environment.

---

## Features

- ESP32-based IoT system
- DHT22 temperature and humidity monitoring
- Wi-Fi connectivity
- Cloud-based data storage
- ThingSpeak IoT platform integration
- Real-time sensor data visualization
- Retrieval of cloud data
- Serial Monitor-based data display

---

## Hardware Components

- ESP32 Development Board
- DHT22 Temperature and Humidity Sensor
- Breadboard
- Jumper Wires
- USB Cable
- Wi-Fi Network

---

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- DHT Sensor Library
- ThingSpeak Library
- ThingSpeak Account
- Wi-Fi Internet Connection

---

## System Architecture

```text
DHT22 Sensor
     │
     │ Temperature & Humidity
     ▼
   ESP32
     │
     │ Wi-Fi
     ▼
ThingSpeak Cloud
     │
     │ Data Retrieval
     ▼
   ESP32
     │
     ▼
Serial Monitor
```

---

## Experiment 1: Uploading Sensor Data to ThingSpeak

The first program reads temperature and humidity values from the DHT22 sensor and uploads the data to the ThingSpeak cloud platform.

### Working Process

1. ESP32 connects to the Wi-Fi network.
2. DHT22 sensor measures temperature and humidity.
3. ESP32 reads the sensor values.
4. Temperature data is assigned to ThingSpeak Field 1.
5. Humidity data is assigned to ThingSpeak Field 2.
6. ESP32 sends the data to the ThingSpeak cloud.
7. ThingSpeak stores and visualizes the received data.

### ThingSpeak Fields

| Field | Data |
|-------|------|
| Field 1 | Temperature |
| Field 2 | Humidity |

---

## Experiment 2: Retrieving Sensor Data

The second program retrieves the previously uploaded temperature and humidity values from the ThingSpeak channel.

### Working Process

1. ESP32 connects to the internet through Wi-Fi.
2. The program sends a request to the ThingSpeak channel.
3. The latest temperature value is retrieved from Field 1.
4. The latest humidity value is retrieved from Field 2.
5. The retrieved values are displayed on the Serial Monitor.

### Output

Example Serial Monitor output:

```text
Temperature: 28.5 °C
Humidity: 65.2 %
```

---



## License

This project is intended for educational and research purposes.
