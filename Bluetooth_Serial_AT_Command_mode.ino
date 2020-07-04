#include<SoftwareSerial.h>
SoftwareSerial BT(10,11);//RX/TX
void setup()
{
  Serial.begin(38400);
  BT.begin(38400);
  Serial.println("Bluetooth AT command mode");
}
void loop()
{
  if(BT.available())
    Serial.write(BT.read());
    
  if(Serial.available())
    BT.write(Serial.read());
}

