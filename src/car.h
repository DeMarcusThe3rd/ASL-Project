#pragma once
#include <Arduino.h>
#include "Servo.h"

/*pin allocation*/
#define IN1 8
#define IN2 7
#define IN3 3
#define IN4 2
#define ENA 5
#define ENB 6
extern Servo servo;

/*function definitions*/
void send_to_driver(unsigned char bit, int PWML, int PWMR);
void backward (int t, int PWM);
void forward(int t, int PWM);
void stop(int t, int PWM);
void turn(int t, int PWML, int PWMR);
void servoLeft();
void servoRight();