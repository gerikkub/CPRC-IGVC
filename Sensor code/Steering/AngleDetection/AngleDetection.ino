#include <NewPing.h>

//Angle Detection
//Louie Thiros
//Used to determine the angle of the igvc to an adjacent wall
//Steering correction will eventually be applied

#include <math.h>

#define TRIG_PIN0 5
#define ECHO_PIN0 4
#define TRIG_PIN1 3
#define ECHO_PIN1 2
#define MIN_DIST 250

//distance between sensors in cm
#define SENSOR_DISTANCE 20

#define RAD2DEG 180/3.14159265359

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN0, OUTPUT);
  //pins are input by default
  pinMode(ECHO_PIN0, INPUT);
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
};

//returns distance calculated in cm.
float findDistance(char trigger, char echo) {
  long duration, distance;
  digitalWrite(trigger, HIGH);
  duration = pulseIn(echo, HIGH);
  digitalWrite(trigger, LOW);
  return (duration/2)/29.1;
}
void loop() 
{
  //distance A will be that of the frontmost sonar
  //the defines might need to be changed
  //float distanceA = findDistance(TRIG_PIN0, ECHO_PIN0);
  //float distanceB = findDistance(TRIG_PIN1, ECHO_PIN1);
  NewPing sonarA(TRIG_PIN0,ECHO_PIN0,200);
  NewPing sonarB(TRIG_PIN1,ECHO_PIN1,200);

  //atan2 might work better
  //Serial.println(angle);
  //sound wave takes 58.77 us to make a 1cm round trip (2cm)
  float distanceA = sonarA.ping_median(10)/58.77;
  float distanceB = sonarB.ping_median(10)/58.77;
  Serial.print("Sensor A: "); Serial.println(distanceA);
  Serial.print("Sensor B: "); Serial.println(distanceB);
  float angle = atan((distanceA-distanceB)/SENSOR_DISTANCE) * RAD2DEG;
  Serial.print("Angle:"); Serial.println(angle);
  delay(100);
}
