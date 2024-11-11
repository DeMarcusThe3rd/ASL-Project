#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "car.h"

RF24 radio (9,10); //CE, CSN

const byte address [6] = "00001";
int coordinate[11];

void setup () {
// put your setup code here, to run once:
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
}

void loop() {
// put your main code here, to run repeatedly:
  if (radio.available()){
    radio.read(&coordinate, sizeof(coordinate));
    char name[10][11] = {"X Coor: ", "|Y Coor: ", " |Angle: ", " |A: ", " |B: ", " |C: ", " |D: ", " |e: ", " |f: ", " |joy: "};
    //char name[4][11] = {"X Coor: ", "|Y Coor: ", " |Angle: ", " |ButtonState: "};
    for (int i=0; i<10; i++ ){
      Serial.print(name[i]);
      Serial.print(coordinate[i]);
    }
    Serial.println(" ");
    //delay(50);
  }
  if (coordinate[0]>300 && coordinate[0]<330){
    if (coordinate[1]>330 && coordinate[1]<712){
        forward(255);
    }
  }
  if (coordinate[0]>502 && coordinate[0]<522){
    if (coordinate[1]>0 && coordinate[1]<512){
        backward(255);
    }
  }

  // Turn Right
  if (coordinate[0]>512 && coordinate[0]<1023){
    if (coordinate[1]>502 && coordinate[1]<522){ // middle right
        turn(-255, 255); 
    }
    if (coordinate[1]>522 && coordinate[1]<1023){ // top right
        turn(100, 200);
    }
    if (coordinate[1]>0 && coordinate[1]<502){ // bottom right
        turn(-200, -100);
    }
  }

  // Turn Left
  if (coordinate[0]>0 && coordinate[0]<512){
    if (coordinate[1]>502 && coordinate[1]<522){
        turn(255, -255); //left
    }
    if (coordinate[1]>522 && coordinate[1]<1023){ // top left
        turn(200, 100);
    }
    if (coordinate[1]>0 && coordinate[1]<502){ // bottom left
        turn(-100, -200);
    }
  }
  if (coordinate[0]>502 && coordinate[0]<522 && coordinate[1]>502 && coordinate[1]<522){
    stop(0);
  }
}