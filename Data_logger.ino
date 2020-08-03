#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "datalogger-6015f.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "B1wCeYKcRgBxudXcutzK1XTVAPyFcZy3FhCQAv90"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "avya25042"
#define safty_time 10000
//Define Firebase Data object
FirebaseData firebaseData;

void setup()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);

    //if wifi is not availaible then put module in sleep
    if(millis()> safty_time)
    {
        ESP.deepSleep(300e6); 
      }
  }


  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
  String path = "Data_Logger/";


     /**********Get timeStamp***********/
  if (Firebase.setTimestamp(firebaseData, path + "Set/Timestamp"))
  {

    // firebaseData.payload()will return timeStamp in milliseconds
    String inst_path = path + "SenseData/" + firebaseData.payload();
    
    /**********Upload data with timeStamp***********/
    if (Firebase.setInt(firebaseData,inst_path,analogRead(A0)))
    {
      //data uploaded
    }
    else
    {
      //error
    }

  }
  else
  {
        //error
  }

  ESP.deepSleep(300e6); 

}
void loop()
{
}
