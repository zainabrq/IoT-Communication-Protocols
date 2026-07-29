#include <WiFi.h> 
#include <ThingSpeak.h> 
#include <DHT.h> 
#define DHTPIN 14 
#define DHTTYPE DHT11 
const char* ssid = "zenny"; 
const char* password = "password"; 
unsigned long channelID = ***enter channel id****; 
const char* writeAPIKey = "*******enter API Key*********"; 
WiFiClient client; 
DHT dht(DHTPIN, DHTTYPE); 
void setup() 
{ 
Serial.begin(9600); 
dht.begin(); 
 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) 
  { 
    delay(500); 
    Serial.print("."); 
  } 
  Serial.println("\nWiFi Connected"); 
  Serial.println(WiFi.localIP()); 
  ThingSpeak.begin(client); 
} 
void loop() 
{ 
  float temp = dht.readTemperature(); 
  float humidity = dht.readHumidity(); 
  Serial.print("Temperature: "); 
  Serial.print(temp); 
  Serial.println(" C"); 
  Serial.print("Humidity: "); 
  Serial.print(humidity); 
  Serial.println(" %"); 
  ThingSpeak.setField(1, temp); 
  ThingSpeak.setField(2, humidity); 
  ThingSpeak.writeFields(channelID, writeAPIKey); 
  delay(15000); 
} 