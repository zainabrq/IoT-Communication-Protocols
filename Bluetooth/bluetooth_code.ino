// Interfacing LED with ESP32 and controlling LED through Bluetooth   
#include <BluetoothSerial.h>  
#define ledPIN 14 //D2 pin  
BluetoothSerial SerialBT;  
byte BTData;  
/* Check if Bluetooth configurations are enabled in the SDK */  
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)  
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it  
#endif  
void setup()  
{  
}  
pinMode(ledPIN, OUTPUT);  
Serial.begin(115200);  
SerialBT.begin();  
Serial.println("Bluetooth Started! Ready to pair...");  
void loop()  
{  
if(SerialBT.available())  
{  
}  
BTData = SerialBT.read();  
Serial.write(BTData);  
if(BTData == '1')  
{  
}  
digitalWrite(ledPIN, HIGH);  
/* If received Character is 0, then turn OFF the LED */  
if(BTData == '0')  
{  
}  
}  
digitalWrite(ledPIN, LOW);  
}  
}  