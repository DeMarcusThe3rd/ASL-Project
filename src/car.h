#include <Arduino.h>

/*pin allocation*/
#define IN1 13
#define IN2 12
#define IN3 A4
#define IN4 A5
#define ENA 11
#define ENB 3

/*function definitions*/
void send_to_driver(unsigned char bit, int PWML, int PWMR);
void backward (int t, int PWM);
void forward(int t, int PWM);
void stop(int t, int PWM);
void turn(int t, int PWML, int PWMR);