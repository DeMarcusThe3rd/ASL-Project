#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "car.h"
#include "Servo.h"

/*
 *   Hex to Binary Cheat Sheet
 *  ==========================================
 *   A = 1010 -> both motors forward
 *   9 = 1001 -> right forward, left backward
 *   6 = 0110 -> left forward, right backward
 *   5 = 0101 -> both motors backward
 */

// Private helper to update motor state only if changed
void car::send_to_driver(unsigned char bit, int PWML, int PWMR){
    digitalWrite(IN1, ((bit >> 3) & 0x1)); // right forward
    digitalWrite(IN2, ((bit >> 2) & 0x1)); // right backward
    digitalWrite(IN3, ((bit >> 1) & 0x1)); // left forward
    digitalWrite(IN4, ((bit >> 0) & 0x1)); // left backward

    analogWrite(ENA, PWMR); // right pwm
    analogWrite(ENB, PWML); // left pwm
}

// Forward movement
void car::forward(int PWM){
    send_to_driver(0x5, PWM, PWM);
}

// Backward movement
void car::backward(int PWM){
    send_to_driver(0xA, PWM, PWM);
}

// Stop movement
void car::stop(int PWM){
    send_to_driver(0x0, PWM, PWM);
}

// Turns the car by setting each motor's PWM
void car::turn(int PWML, int PWMR){
    if (PWML < 0) { // left motor backward, right motor forward
        send_to_driver(0x6, -PWML, PWMR);
    } else if (PWMR < 0) { // right motor backward, left motor forward
        send_to_driver(0x9, PWML, -PWMR);
    } else if (PWML < 0 && PWMR < 0) { // both motors backward
        send_to_driver(0xA, -PWML, -PWMR);
    } else { // both motors forward
        send_to_driver(0x5, PWML, PWMR);
    }
}

// Servo movement functions
void car::servoLeft(){
    for (int pos = 0; pos <= 180; pos += 10) { 
        servo.write(pos);
        delay(5); // Adjust if needed for smoother movement
    }
}

void car::servoRight(){
    for (int pos = 180; pos >= 0; pos -= 10) {
        servo.write(pos);
        delay(5);
    }
}

// Main joystick command interpreter based on coordinates
void car::readCoord() {
    if (radio.available()) {
        radio.read(&coordinate, sizeof(coordinate));
        updateMovement();
    }
}

// Decides movement based on joystick position
void car::updateMovement() {
    if (coordinate[0] > 502 && coordinate[0] < 522) {  //top
        if (coordinate[1] > 512 && coordinate[1] < 1023){
            forward(255); 
        } 
        else if (coordinate[1] > 0 && coordinate[1] < 512){  //bottom
            backward(255);
        } 
        else {  //center 
            stop(0); 
        }
    } 
    
    else if (coordinate[0] > 512) {
        // Right-side joystick movement
        if (coordinate[1] > 522 && coordinate[1] < 1023){
            turn(100, 200); // top right
        }
        else if (coordinate[1] > 0 && coordinate[1] < 502){
             turn(-200, -100); // bottom right
        }
        else{
            turn(-255, 255); // middle right
        }
    }

    else if (coordinate[0] < 512) { //joytsick on left
        if (coordinate[1] > 522 && coordinate[1] < 1023){  //top left side
            turn(200, 100); //turn left
        }
        else if (coordinate[1] > 0 && coordinate[1] < 502){  //bottom left side
            turn(-100, -200); // reverse left
        }
        else{ //middle left side
            turn(255, -255); //turn on itself left
        }
    }
}
