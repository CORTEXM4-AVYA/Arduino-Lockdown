int trigger_pin = 2;

int echo_pin = 3;

int buzzer_pin = 10; 
int led=13;

int time;

int distance; 
int counter = 0;




void setup ( ) {

        Serial.begin (9600); 

        pinMode (trigger_pin, OUTPUT); 

        pinMode (echo_pin, INPUT);

        pinMode (buzzer_pin, OUTPUT);
        pinMode(led,OUTPUT);




}



 
void loop ( ) {

    digitalWrite (trigger_pin, HIGH);

    delayMicroseconds (10);

    digitalWrite (trigger_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.034) / 2;

    

  if (distance <= 10) 

        {

        Serial.println (" Door Open ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

     //   digitalWrite (buzzer_pin, HIGH);
        digitalWrite(led,HIGH);
       
 delay(650);
                                                                                             

       

        }

  else {

        Serial.println (" Door closed ");

        Serial.print (" Distance= ");              

        Serial.println (distance);        

        digitalWrite (buzzer_pin, LOW);
        digitalWrite(led,LOW);

        delay (500);        

  } 

  }
