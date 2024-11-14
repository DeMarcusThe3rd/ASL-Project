#include <Arduino.h>
#include "car.h"

/*
 *   Hex to Binary Cheat Sheet
 *  ==========================================
 *   5 = 0101 -> both motors forwards 
 *   A = 1010 -> both motors backwards 
 *   9 = 1001 -> left forward, right backward 
 *   6 = 0110 -> right forward, left backward 
 */

/* accepts input as a user defined literal hex operator and converts to 4 bit binary, each bit for each of the 4 motor driver pins  */
void send_to_driver(unsigned char bit, int PWML, int PWMR){
    digitalWrite(IN1, ((bit >> 3) & 0x1)); //right forward
    digitalWrite(IN2, ((bit >> 2) & 0x1)); //right backward
    digitalWrite(IN3, ((bit >> 1) & 0x1)); //left forward
    digitalWrite(IN4, ((bit >> 0) & 0x1)); //left backward

    analogWrite(ENA, PWMR); //right pwm
    analogWrite(ENB, PWML); //left pwm
}

/* forward for time t in milliseconds */
void forward(int PWM){
    send_to_driver(0x5, PWM, PWM);
    //delay(t);
}

/* backward for time t in milliseconds */
void backward(int PWM){
    send_to_driver(0xA, PWM, PWM);
    //delay(t);
}

/* stop for time t in milliseconds */
void stop(int PWM){
    send_to_driver(0x0, PWM, PWM);
    //delay(t);
}

/* turns the vehicle for time t in milliseconds */
void turn(int PWML, int PWMR){
    if(PWML < 0){   //left motor backward, right motor forward
        send_to_driver(0x6, -PWML, PWMR);
        //delay(t);
    }
    else if(PWMR < 0){  //right motor backward, left motor forward
        send_to_driver(0x9, PWML, -PWMR);
        //delay(t);
    }
    else if((PWML < 0) && (PWMR < 0)){  //both motor backward
        send_to_driver(0xA, -PWML, -PWMR);
        //delay(t);
    }
    else{   //both motor forward
        send_to_driver(0x5, PWML, PWMR);
        //delay(t);
    }
}
