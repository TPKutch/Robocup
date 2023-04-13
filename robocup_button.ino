
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
servo.attach(serv);
servo.write(270);
servo.detach();
pinMode(serv, OUTPUT);
pinMode(sensor,INPUT_PULLUP);
}

void loop() {
int buttonState = digitalRead(sensor);
Serial.write(digitalRead(sensor));

if(buttonState==HIGH){
  endtime = millis();
  starttime = millis();
  while (endtime - starttime < 3000){
    endtime = millis();
    if(buttonState==LOW){
      break;
    }
  }
  if(endtime-starttime >= 3000){
    for (int angle = 270; angle > 0; angle -= 1) {
      servo.attach(serv);
      servo.write(angle);
      delay (10);
      i = 1;
      }
      servo.detach();
      Serial.write('1');
  }
}

if(i == 1){
  if(buttonState==HIGH){
    endtime = millis();
    starttime = millis();
    while(endtime - starttime < 3000){
      endtime = millis();
      if(buttonState==LOW){
        break;
      }
    }
    if(endtime-starttime >= 3000){
      for (int angle = 0; angle < 270; angle += 1) {
        servo.attach(serv);
        servo.write (angle);
        delay (10);
        i = 0;
        }
        servo.detach();
        Serial.write('0');
    }
  }
}
}
