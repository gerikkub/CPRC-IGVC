#define trigPin0 13
#define echoPin0 12
#define MinDist 250
//ss is the sure safe, i.e. how many times the sensor will recheck values before anouncing change
int ss = 3;
void setup() {
  pinMode(trigPin0, OUTPUT); //set up all the pins
  pinMode(echoPin0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

/**
 * Prevents light flickering between states unwarrented 
 */
void loop() 
{
  
  if (distance() < MinDist) //if something is within the distance
  {
    for(int i = 0; i < ss; i++) //DEBOUNCE
    {
      if (distance() >= MinDist)
      {
        i = ss; //if something is ever outside of the distance, break out of the loop
      }
      if (i == ss - 1) //if you're super sure then make the change
      {
        digitalWrite(2,LOW);
        digitalWrite(3, HIGH);
        delay(3000);
      }
    }
  }
  else
  {
    for(int i = 0; i < ss; i++) //identical to the above just for switching back
    {
      if (distance() < MinDist)
      {
        i = ss;
      }
      if (i == ss - 1)
      {
        digitalWrite(3,LOW);
        delay(200);
        digitalWrite(2, HIGH);
      }
    }
  }
}

int distance()
{
  long duration0;
  digitalWrite(trigPin0, LOW);  
  digitalWrite(trigPin0, HIGH); //PING
  digitalWrite(trigPin0, LOW); 
  duration0 = pulseIn(echoPin0, HIGH); //read response
  int distance = (duration0 / 2) / 29.1; //shamwow convert to CM with a little magic number
  Serial.println(distance);
  return distance;
}
