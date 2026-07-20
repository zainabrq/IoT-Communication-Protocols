#include <WiFi.h> 
#include <Adafruit_MQTT.h> 
#include <Adafruit_MQTT_Client.h> 
#define WIFI_SSID "zenny" 
#define WIFI_PASS "zenny123" 
#define USERNAME "VTU" 
#define KEY "xyz" 
WiFiClient client; 
Adafruit_MQTT_Client mqtt( 
&client, 
"io.adafruit.com", 
1883, 
USERNAME, 
KEY 
); 
Adafruit_MQTT_Subscribe temp = 
Adafruit_MQTT_Subscribe( 
&mqtt, 
USERNAME "/feeds/Temperature" 
); 
void setup() 
{ 
Serial.begin(115200); 
WiFi.begin(WIFI_SSID, WIFI_PASS); 
while (WiFi.status() != WL_CONNECTED) 
{ 
} 
delay(500); 
Serial.print("."); 
Serial.println("\nWiFi Connected");
 mqtt.subscribe(&temp); 
} 
 
void loop() 
{ 
  while (!mqtt.connected()) 
  { 
    Serial.println("Connecting to MQTT..."); 
    mqtt.connect(); 
    delay(5000); 
  } 
  Adafruit_MQTT_Subscribe *sub; 
  while ((sub = mqtt.readSubscription(5000))) 
  { 
    if (sub == &temp) 
    { 
      Serial.print("Temperature = "); 
      Serial.println((char *)temp.lastread); 
    } 
  } 
}