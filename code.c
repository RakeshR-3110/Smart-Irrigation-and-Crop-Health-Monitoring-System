#include <ESP8266WiFi.h>
#include <DHT.h>
#include "ThingSpeak.h"

#define DHTPIN D2
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN A0
#define NPK_PIN A0  // Using same analog pin, read alternately
#define RELAY_PIN D5

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

WiFiClient client;
unsigned long myChannelNumber = YOUR_CHANNEL_NUMBER;
const char * myWriteAPIKey = "YOUR_THINGSPEAK_API_KEY";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Initially off

  dht.begin();
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  delay(1000); // Wait before switching analog inputs
  int npkValue = analogRead(NPK_PIN);  // Simulated read

  // Pump control
  if (soilMoisture < 400) { // adjust threshold as per calibration
    digitalWrite(RELAY_PIN, HIGH);  // Turn on pump
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Turn off pump
  }

  // Debug prints
  Serial.println("Temperature: " + String(temperature));
  Serial.println("Humidity: " + String(humidity));
  Serial.println("Soil Moisture: " + String(soilMoisture));
  Serial.println("NPK Value: " + String(npkValue));

  // Send to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, soilMoisture);
  ThingSpeak.setField(4, npkValue);

  int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak");
  } else {
    Serial.println("Failed to send data. HTTP error: " + String(status));
  }

  delay(20000); // ThingSpeak accepts 1 update every 15+ seconds
}
