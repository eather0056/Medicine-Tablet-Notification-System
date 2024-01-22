#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo; 
LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);

int Alarm = 7;
int S = 9;
int pos;

void setup() {
      Serial.begin(9600);

      pinMode(S,INPUT);
      pinMode(Alarm,OUTPUT);
      myservo.attach(13);
      
}
void loop() {

      for (pos = 0; pos <= 90; pos += 5)
      {
          myservo.write(pos);   
      }
      delay(500);
      
        myservo.write(0);

        lcd.setCursor(0,0);
        lcd.print("Take Medicin");
        digitalWrite(Alarm ,HIGH);
        delay(500);

        for(;;)
        {
          
        if(digitalRead(S) == HIGH){
          
            
            digitalWrite(Alarm ,LOW);
            Serial.println();
            Serial.println("AT+CMGF=1");
            Serial.println("AT+CMGS=\"01789653425\"\r"); 
            Serial.println("Patient Took The Medicine");
            lcd.clear();
            break;
        }
        else
        {
            Serial.println();
            Serial.println("AT+CMGF=1");
            Serial.println("AT+CMGS=\"01789653425\"\r"); 
            Serial.println("Patient did not Take the Medicine Yet");
        }
          delay (2000);

        } 
    delay (10000);
    lcd.clear();
    
}
