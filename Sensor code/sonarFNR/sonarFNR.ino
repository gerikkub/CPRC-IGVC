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
#define MinDist 250
void setup() {
  Serial.begin (9600);
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() 
{
  long duration0, duration1, distance0, distance1;
  digitalWrite(trigPin0, LOW);  
  digitalWrite(trigPin0, HIGH);
  digitalWrite(trigPin0, LOW); 
  duration0 = pulseIn(echoPin0, HIGH); 
  delay(10);
  distance0 = (duration0 / 2) / 29.1;
  int brightness0 = 255 - distance0;
  if (distance0 < MinDist)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }
  Serial.print("R:");
  Serial.print(distance0);
  Serial.println(" cm");
  delay(10);
}
