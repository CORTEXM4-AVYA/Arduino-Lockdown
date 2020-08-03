#include<ESP8266WiFi.h>
#include<Ethernet.h>
#define WIFI_SSID "avya25042"
#define WIFI_PASS "12345678"
IPAddress gateway;
IPAddress staticip;
 void setup()
{
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Wifi not conected");
  }

  else
  {
    gateway=WiFi.gatewayIP();
    Serial.println(gateway);
    staticip=gateway;
   Serial.print("ip adress:");
    Serial.println(staticip);

  }
}
    
void loop()
{
}
