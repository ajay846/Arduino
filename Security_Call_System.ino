#include<SoftwareSerial.h>

SoftwareSerial gsm(2,3);
int sen=4; //Motion Sensor
float dis; 
float t;
int r=5; //Red Of Rgb
int b=6; //Blue of rgB
int g=7; //Green of rGb
int trig=8;
int echo=9;

void setup(){
  pinMode(sen, INPUT);
  pinMode(r, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop(){
    Serial.println("Any Issues/Query DM me on my Instagram -> https://www.instagram.com/iamsainath.u/ \n Username @iamsainath.u");
    if(digitalRead(sen)==HIGH){
    digitalWrite(trig, LOW);
    delay(500);
    
    digitalWrite(trig, HIGH);
    delay(1000);
    
    digitalWrite(trig, LOW);
    t=pulseIn(echo, HIGH);
    
    dis= t/29/2;
    
    delay(50);
    Serial.println(dis);
    
    if(dis<=100){
      digitalWrite(b, HIGH);
      delay(90);
      digitalWrite(b, LOW);
      delay(500);
    }
    else{
      if(dis<=70){
        digitalWrite(g, HIGH);
        digitalWrite(r, LOW);
        
        delay(90);
        
        digitalWrite(g, LOW);
        digitalWrite(r, LOW);
        delay(500);
      }
      else{
        if(dis<=55){
          delay(100);
          Serial.begin(9600);
          gsm.begin(9600);
          gsm.println("ATD7569******;"); // your phone number
          gsm.println("ATH");
          digitalWrite(r, HIGH);
          digitalWrite(b, LOW);
          digitalWrite(g, LOW);
          
          delay(100);
          
          digitalWrite(b, HIGH);
          digitalWrite(r, LOW);
          digitalWrite(g, LOW);
          
          delay(100);
          
          digitalWrite(g, HIGH);
          digitalWrite(b, LOW);
          digitalWrite(r, LOW);
          delay(100);
        }
      }
    }
  }
}
