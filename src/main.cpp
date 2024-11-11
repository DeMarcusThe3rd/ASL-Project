#include <Arduino.h>
#include "Servo.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "car.h"

//intialize classes and variables
car Car;
Servo servo;
RF24 radio (9,10); //CE, CSN
const byte address [6] = "00001";
int coordinate[11];

//setup code that runs once
void setup() {
  Serial.begin (9600); 
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN) ;
  radio.startListening();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  servo.attach(10);
}

void loop() {
  Car.readCoord();
}
