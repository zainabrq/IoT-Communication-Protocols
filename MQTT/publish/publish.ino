#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// Wi-Fi Credentials
#define WLAN_SSID "ZENNY"
#define WLAN_PASS "zenny123"

// Adafruit IO Configuration
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "abc"
#define AIO_KEY         "xyz"

// Create WiFi Client
WiFiClient client;

// Create MQTT Client
Adafruit_MQTT_Client mqtt(
  &client,
  AIO_SERVER,
  AIO_SERVERPORT,
  AIO_USERNAME,
  AIO_KEY
);

// Subscribe to Temperature Feed
Adafruit_MQTT_Subscribe temp = Adafruit_MQTT_Subscribe(
  &mqtt,
  AIO_USERNAME "/feeds/Temperature"
);

// Subscribe to Humidity Feed
Adafruit_MQTT_Subscribe hum = Adafruit_MQTT_Subscribe(
  &mqtt,
  AIO_USERNAME "/feeds/Humidity"
);

void setup()
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WLAN_SSID, WLAN_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Subscribe to MQTT Topics
  mqtt.subscribe(&temp);
  mqtt.subscribe(&hum);

  Serial.println("Subscribed to Temperature and Humidity feeds");
}

void loop()
{
  // Reconnect if MQTT is disconnected
  if (!mqtt.connected())
  {
    Serial.print("Connecting to MQTT... ");

    while (mqtt.connect() != 0)
    {
      Serial.println("Failed");
      delay(5000);
    }

    Serial.println("Connected");
  }

  // Read subscribed messages
  Adafruit_MQTT_Subscribe *subscription;

  while ((subscription = mqtt.readSubscription(5000)))
  {
    if (subscription == &temp)
    {
      Serial.print("Temperature = ");
      Serial.println((char *)temp.lastread);
    }

    if (subscription == &hum)
    {
      Serial.print("Humidity = ");
      Serial.println((char *)hum.lastread);
    }
  }
}
