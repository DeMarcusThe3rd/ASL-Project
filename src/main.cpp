#include <Arduino.h>
#include "car.h"


char bt;

void setup () {
/*Initialize Class*/
  Serial.begin (9600); 

/*Pin Mode*/
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {

  /*forward(100);
  delay(1000);
  backward(100);
  delay(3000);
  turn(100,255); //turn left
  delay(3000);
  turn(200,100);
  delay(3000);
  turn(-100,100);
  delay(3000);
  turn(100,-100);
  delay(3000);*/
bt = Serial.read();

  if(bt == 'F'){  //striaght forward
    forward(150);
  }
  else if(bt == 'B'){  //straight backwards
    backward(150);
  }
  else if(bt == 'L'){  //left on itself
    turn(-150, 150);
  }
  else if(bt == 'R'){  //right on itself
    turn(150, -150);
  }

  else if(bt == 'Q'){   //diagonal left top
    turn(100,150);
  }


  else if(bt == 'E'){   //diagonal right top 
    turn(150,100);
  }


  else if(bt == 'Z'){  //diagonal left back
    turn(-100,-150);
  }


  else if(bt == 'C'){  //diagonal right back
    turn(-150,-100);
  }

  else if(bt == 'S'){  //stop 
    stop(0);
  }
}
