String text;
int LED1=13;
//int LED2=12;
//int LED3=11;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED1,OUTPUT);
//pinMode(LED2,OUTPUT);
//pinMode(LED3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    delay(10);
    char c=Serial.read();
    text +=c;
  }
  if(text.length()>0)
  {
    Serial.println(text);
    if(text=="on")
    {
      digitalWrite(LED1,HIGH);
    //  digitalWrite(LED2,HIGH);
      //digitalWrite(LED3,HIGH);
    }
    if(text=="off")
    {
      digitalWrite(LED1,LOW);
     // digitalWrite(LED2,LOW);
      //digitalWrite(LED3,LOW);
      
    }
      
    text="";}
    }
  
