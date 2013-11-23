/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#define trigPin0 13
#define echoPin0 12
#define trigPin1 8
#define echoPin1 7
#define MinDist 250
void setup() {
  Serial.begin (9600);
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
}

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
  int brightness0 = 255 - distance0;
  int brightness1 = 255 - distance1;
  if (distance0 < MinDist || distance1 < MinDist)
  {
    digitalWrite(3, HIGH);
    digitalWrite(10, LOW);
  }
  else
  {
    digitalWrite(3, LOW);
    digitalWrite(10, HIGH);
  }
  Serial.print("R:");
  Serial.print(distance0);
  Serial.println(" cm");
  Serial.print("L:");
  Serial.print(distance1);
  Serial.println(" cm");
  delay(10);
}
