#define trigPin0 13 //put trig on 13
#define echoPin0 12 //echo on 12
#define MinDist 250 //maximum distance is 250 cm
void setup() {
  Serial.begin (9600);
  pinMode(trigPin0, OUTPUT); //set up all the pins
  pinMode(echoPin0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() 
{
  long duration0, duration1, distance0, distance1;
  digitalWrite(trigPin0, LOW);  
  digitalWrite(trigPin0, HIGH); //PING
  digitalWrite(trigPin0, LOW); 
  duration0 = pulseIn(echoPin0, HIGH); //translate to a duration 
  delay(10);
  distance0 = (duration0 / 2) / 29.1; //convert to CM, yes that is a magic number
  int brightness0 = 255 - distance0; //this is old but worth keeping if LEDs will be used again
  if (distance0 < MinDist) //if something is within distance
  {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH); //light up 3
  }
  else
  {
    digitalWrite(3, LOW); //else light up 2
    digitalWrite(2, HIGH);
  }
  Serial.print("R:");
  Serial.print(distance0);
  Serial.println(" cm");
  delay(10);
}
