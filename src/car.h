#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Servo.h"

/*pin allocation*/
#define IN1 8
#define IN2 7
#define IN3 3
#define IN4 2
#define ENA 5
#define ENB 6

extern Servo servo;
extern RF24 radio;        // Declare radio as an external variable
extern int coordinate[11]; // Declare coordinate array as an external variable
extern const byte address [6];

class car{
    private:

    public:
    /*Motor Functions*/
        void send_to_driver(unsigned char bit, int PWML, int PWMR);
        void backward (int PWM);
        void forward(int PWM);
        void stop(int PWM);
        void turn(int PWML, int PWMR);

    /*Servo Functions*/
        void servoLeft();
        void servoRight();
    
    /*Receiver Function*/
        void readCoord();
        void updateMovement();
};