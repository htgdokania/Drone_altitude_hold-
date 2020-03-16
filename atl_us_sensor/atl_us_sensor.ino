#include<Servo.h>
Servo channel3;// throttle output 

//variables used to read input from channel 3 and 5 
unsigned long  counter_3,counter_5, current_count; 
byte last_CH3_state,last_CH5_state;

//initial value 1000
float input_modeval=1000;//for channel 5 input
float input_THROTTLE=1000;//channel 3 input
float input_THROTTLE1;

//variables for UltraSonic Sensor
int echoPin1=2,trigPin1=3;
int duration1;
float current_height = 0.0;
float temp_height = 0.0;  float temp1_height = 0.0; float temp2_height = 0.0;
float Required_height=0;//(in cm)

//PID Variables 
float p=1.5;float p_value=0;
float I=0.00;float I_value=0;
float D=.1;float D_value=0;
float total=0;
float error=0;float pre_error=0;float derror=0;float ierror=0;
