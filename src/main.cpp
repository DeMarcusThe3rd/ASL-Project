#include <Arduino.h>
#include "car.h"


void setup () {
// put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
  /*forward(100);
  delay(3000);
  backward(100);
  delay(3000);*/
  turn(100,255); //turn left
  delay(3000);
  turn(200,100);
  delay(3000);
  turn(-100,100);
  delay(3000);
  turn(100,-100);
  delay(3000);

}