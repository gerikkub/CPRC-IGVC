#define trigPin0 13
#define echoPin0 12
#define MinDist 250

int ss = 3;
void setup() {
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  if (distance() < MinDist)
  {
    for(int i = 0; i < ss; i++)
    {
      if (distance() >= MinDist)
      {
        i = ss;
      }
      if (i == ss - 1)
      {
        digitalWrite(2,LOW);
        digitalWrite(3, HIGH);
        delay(3000);
      }
    }
  }
  else
  {
    for(int i = 0; i < ss; i++)
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
  digitalWrite(trigPin0, HIGH);
  digitalWrite(trigPin0, LOW); 
  duration0 = pulseIn(echoPin0, HIGH); 
  int distance = (duration0 / 2) / 29.1;
  Serial.println(distance);
  return distance;
}
