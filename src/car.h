/*pin allocation*/
#define IN1 8
#define IN2 7
#define IN3 3
#define IN4 2
#define ENA 5
#define ENB 6


/*function definitions*/
void send_to_driver(unsigned char bit, int PWML, int PWMR);
void backward (int PWM);
void forward(int PWM);
void stop(int PWM);
void turn(int PWML, int PWMR);