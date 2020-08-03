
#include "Wire.h"
byte value=0;  //store sensor value

void setup()
{
  Wire.begin();//i2c bus wake up
  Wire.beginTransmission(0x20);//slave address
  Wire.write(0x00);//A reg IO direction
  Wire.write(0x01);//PIN 0 AS INPUT
  Wire.endTransmission();
  Serial.begin(9600);
  
}
void loop()
{
   Wire.beginTransmission(0x20);//slave address
   Wire.write(0x12);//Memory pointer to GPIOA 
   Wire.endTransmission();
   Wire.requestFrom(0x20,1);// request 1 byte data
   value=Wire.read();//store incoming byte in value
   Serial.print("the value from motion sensor is:");
   Serial.println(value,BIN);//display the vlaue in binary
   delay(200);   
}
