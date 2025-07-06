# Real-Time Clock and Temperature Monitoring System

This project simulates a real-time temperature monitoring system using an Arduino Uno, DS1307 RTC, DS18B20 temperature sensor, and a 16x2 I2C LCD display. If the temperature exceeds a predefined threshold (30°C), a warning LED is triggered, and a message is displayed on the LCD. Link to the project: https://wokwi.com/projects/435387799425219585

## Project Aim

To design and simulate a system that continuously monitors temperature, displays it alongside real-time clock data, and alerts the user if the temperature goes beyond a safe limit.

## Problem Statement

In environments like server rooms, cold storage, or smart homes, constant monitoring of temperature is crucial. Manual tracking is inefficient and error-prone. This system provides automated monitoring and real-time alerts, helping prevent damage or failure due to overheating.

## Scope of the Solution

### Includes:
- Real-time clock tracking using DS1307 RTC
- Live temperature monitoring using DS18B20
- User interface via 16x2 LCD
- Warning system using LED and LCD message when threshold is exceeded

### Excludes:
- Data logging to SD card or cloud
- Network-based alerting (SMS or email)
- Precision calibration beyond sensor defaults

## Required Components

### Hardware

| Component       | Description                       |
|----------------|-----------------------------------|
| Arduino Uno     | Microcontroller board             |
| DS1307 RTC      | Real-time clock via I2C           |
| DS18B20 Sensor  | Temperature sensor (digital)      |
| 16x2 LCD (I2C)  | Display for time and temperature  |
| LED (Red)       | Warning indicator                 |
| 4.7kΩ Resistor  | Pull-up for DS18B20 data line     |
| Breadboard and Wires | For circuit prototyping     |

Alternative sensors like DHT22 or LM35 can also be used with minor code modifications.

### Software

- Arduino IDE or PlatformIO
- Required libraries:
  - OneWire.h
  - DallasTemperature.h
  - Wire.h
  - RTClib.h
  - LiquidCrystal_I2C.h
- Wokwi online simulator for testing

## Circuit Diagram (Wokwi Simulation)

To simulate this project:
1. Go to https://wokwi.com
2. Upload the provided `diagram.json`
3. Upload `sketch.ino` with the code

### Connections Summary

| Sensor/Module | Pin Connections |
|---------------|-----------------|
| DS18B20       | DQ → D2, VCC → 5V, GND → GND, 4.7kΩ from DQ → VCC |
| DS1307 RTC    | SDA → A4, SCL → A5, VCC → 5V, GND → GND |
| LCD I2C       | SDA → A4, SCL → A5, VCC → 5V, GND → GND |
| Warning LED   | Anode → D13, Cathode → GND |

## How It Works

1. Arduino reads temperature from DS18B20 every second
2. RTC provides current time via I2C
3. LCD displays time on row 1 and temperature on row 2
4. If temperature exceeds 30°C:
   - Red LED turns on
   - LCD displays "**TEMP WARNING**"

## Flowchart
![ChatGPT Image Jul 6, 2025, 10_52_38 AM](https://github.com/user-attachments/assets/d3359fe6-dbbf-44a1-80c5-de03a7e81d65)

