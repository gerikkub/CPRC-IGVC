// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h> 
#define trigPin0 A1
#define echoPin0 A0
#define trigPin1 A3
#define echoPin1 A2
#define MinDist 250
// DC motor on M2
AF_DCMotor motor(2);
AF_DCMotor motor2(3);
// DC hobby servo
Servo servo1;
Servo servo2;
// Stepper motor on M3+M4 48 steps per revolution
AF_Stepper stepper(48, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  
  // turn on servo
  servo1.attach(9);
  servo2.attach(9);
   
  // turn on motor #2
  motor.setSpeed(0);
  motor.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  
    pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!

void loop() 
{
  long duration0, duration1, distance0, distance1;
  digitalWrite(trigPin0, LOW);  
  digitalWrite(trigPin1, HIGH); 
  duration0 = pulseIn(echoPin0, HIGH); 
  delay(10);
  digitalWrite(trigPin0, HIGH);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance0 = (duration0 / 2) / 29.1;
  distance1 = (duration1 / 2) / 29.1;
  int speed0 = 255 - distance0;
  int speed1 = 255 - distance1;
//  if (distance0 < MinDist || distance1 < MinDist)
//  {
//    digitalWrite(3, HIGH);
//    digitalWrite(10, LOW);
//  }
//  else
//  {
//    digitalWrite(3, LOW);
//    digitalWrite(10, HIGH);
//  }
  Serial.print("R:");
  Serial.print(distance0);
  Serial.println(" cm");
  Serial.print("L:");
  Serial.print(distance1);
  Serial.println(" cm");
  delay(10);
  
  motor.run(FORWARD);
  motor2.run(FORWARD);
  
  
}
