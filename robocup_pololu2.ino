// Trigger rotate each time

#include<Servo.h>
#include <SPI.h>
Servo servo;
int distance;
int serv=3;
int sensor=4;
int dt=10;
int starttime;
int endtime;
int i;
int buttonState;

void setup() {
Serial.begin(9600);
//servo.attach(serv);
//servo.write(270);
//servo.detach();
pinMode(serv, OUTPUT);
pinMode(sensor,INPUT_PULLUP);
int i=0;
}

void loop() {
int buttonState = digitalRead(sensor);
Serial.write(digitalRead(sensor));
servo.detach();
if(buttonState==LOW){
  if (i==0){
    endtime = millis();
    starttime = millis();
    while (endtime - starttime < 3000){
      buttonState = digitalRead(sensor);
      endtime = millis();
      if(buttonState!=LOW){
        break;
      }
    }
    if(endtime-starttime >= 3000){
      servo.attach(serv);
      for (int angle = 270; angle > 0; angle -= 1) {
        servo.write(angle);
        delay (10);
        }
      servo.detach();
      delay(3000);
      i = 1;
    }
  }
  if (i==1){
    endtime = millis();
    starttime = millis();
    while(endtime - starttime < 3000){
      buttonState = digitalRead(sensor);
      endtime = millis();
      if(buttonState!=LOW){
        break;
      }
    }
    if(endtime-starttime >= 3000){
      servo.attach(serv);
      for (int angle = 0; angle < 270; angle += 1) {
        servo.write (angle);
        delay (10);
        }
      servo.detach();
      delay(3000);
      i = 0;
    }
  }
  }
}
