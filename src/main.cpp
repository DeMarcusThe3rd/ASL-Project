#include <Arduino.h>
#include "Servo.h"
#include "car.h"

Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  servo.attach(10);
}

void loop() {
  forward(5000,255);
  backward(5000,255);
  turn(0,255,-255); //turn left
  turn(0,-255,255); //turn right
  stop(0,0);
  turn(0,255,255); //forward
  turn(0,-255,-255); //backwards
  servoLeft();
  //servoRight();
}
