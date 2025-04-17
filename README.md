# 🌱 Smart Farming System using ESP8266 + DHT11 + Soil Moisture + NPK Sensor 🌾

This project uses an **ESP8266 NodeMCU**, **DHT11 sensor**, **soil moisture sensor**, and a **simulated NPK sensor** to collect environmental data and automatically control a water pump based on soil moisture. The data is uploaded to **ThingSpeak** for remote monitoring.

## 🔧 Features

- 📶 WiFi-enabled real-time monitoring
- 🌡️ Temperature & Humidity sensing (DHT11)
- 🌿 Soil Moisture detection
- 𝺪 Simulated NPK value detection
- 💧 Automatic water pump control using a relay
- 📊 Cloud data logging on ThingSpeak

---

## 🧰 Hardware Requirements

- ESP8266 NodeMCU
- DHT11 Temperature and Humidity Sensor
- Soil Moisture Sensor
- Relay Module
- Optional: NPK sensor (simulated in code)
- Jumper wires
- Breadboard
- Power source (USB or battery)

---

## 🔌 Circuit Connections

| Component        | NodeMCU Pin |
|------------------|-------------|
| DHT11            | D2          |
| Soil Moisture    | A0          |
| NPK Sensor       | A0 (simulated reading) |
| Relay Module     | D5          |

---

## ⚖️ ThingSpeak Configuration

1. Create a ThingSpeak account at [https://thingspeak.com](https://thingspeak.com)
2. Create a new channel and enable 4 fields:
   - Field 1: Temperature
   - Field 2: Humidity
   - Field 3: Soil Moisture
   - Field 4: NPK Value
3. Copy your **Channel Number** and **Write API Key**
4. Replace the placeholders in the code:
```cpp
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER;
const char * myWriteAPIKey = "YOUR_THINGSPEAK_API_KEY";
```

---

## ✅ How It Works

- Reads data from DHT11 and soil moisture sensors
- Simulates NPK sensor readings
- Controls pump via relay if moisture is below threshold
- Sends all data to ThingSpeak every 20 seconds

---

## 🚀 Getting Started

1. Install the following Arduino libraries:
   - `ESP8266WiFi`
   - `DHT sensor library`
   - `ThingSpeak`
2. Upload the code to your ESP8266
3. Open Serial Monitor at 115200 baud to debug
4. Check your ThingSpeak channel for live updates

---

## 📊 Sample Output (Serial Monitor)
```
Temperature: 28.5
Humidity: 62.1
Soil Moisture: 370
NPK Value: 512
Data sent to ThingSpeak
```

---

## 🚧 Future Improvements
- Real NPK sensor integration
- Weather API integration
- Android dashboard via MIT App Inventor

---

## ✨ Credits
Developed by **Rakesh**

LinkedIn: [Rakesh R](https://www.linkedin.com/in/rakesh-r-91a324274)
