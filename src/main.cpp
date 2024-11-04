#include <Arduino.h>
#include "car.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  forward(5000,255);
  backward(5000,255);
  stop(0,0);
  turn(0,-255,255); //turn right
  turn(0,255,-255); //turn left
  turn(0,255,255); //forward
  turn(0,-255,-255); //backwards
}
