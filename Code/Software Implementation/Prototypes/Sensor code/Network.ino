#include <NewPing.h>
//Joe Leija
//Wiring:
//US1
//Maxbotix FRONT left analog pin A0
//US5
//Maxbotix FRONT right analog pin A1
//STEERING
//Steering Linear Actuator on pin A2
//US 6
//Hobby US LEFT front TRIG digital pin D0
//Hobby US LEFT front ECHO digital pin D1
//US 2
//Hobby US LEFT back TRIG digital pin D2
//Hobby US LEFT back ECHO digital pin D3
//US 3
//Hobby US RIGHT front TRIG digital pin D4
//Hobby US RIGHT front ECHO digital pin D5
//US 4 
//Hobby US RIGHT back TRIG digital pin D6
//Hobby US RIGHT back ECHO digital pin D7
//Hall Effects
//Hall Effects sensor A3
//AMS
//AMS sensor pin digital D9
//controls:
//FNR
//FNR-forward : D10
//FNR-backward: D11
//Steering
//IN1: D12
//IN2: D13

/* Ultrasonic front left pin input*/
int usFLpin = A0;

/* Ultrasonic front right pin input */
int usFRpin = A1;

/** Linear actuator input */
int LEpin = A2;

/** ultrasonic left front trig ouput */
int usLfTrigPin = 0;
/** ultrasonic left front echo input */
int usLfEchoPin = 1;

/** ultrasonic left back trig ouput */
int usLbTrigPin = 2;
/** ultrasonic left back echo input */
int usLbEchoPin = 3;

/** ultrasonic right front trig ouput */
int usRfTrigPin = 4;
/** ultrasonic right front echo input */
int usRfEchoPin = 5;

/** ultrasonic right back trig ouput */
int usRbTrigPin = 6;
/** ultrasonic right back echo input */
int usRbEchoPin = 7;

/** hall effects sensor */
int HEpin = A3;

/** AMS input pin */
int AMSpin = 9;

/** FNR forward output */
int FNRforwardPin = 10;
/** FNR backward output */
int FNRbackwardPin = 11;

/**Steering motor output IN1 */
int SteerIN1pin = 12;
/** Steering motor output IN2 */
int SteerIN2pin = 13;

/** FNR and SteerDegrees are the last read inputs */
int tic, FNR, SteerDegrees; 
boolean hasBeenRead;
int time;
void setup()
{
  tic = 0;
  hasBeenRead = false;
  time = 0;
  Serial.begin(115200);
  pinMode(FNRforwardPin, OUTPUT);
  pinMode(FNRbackwardPin, OUTPUT);
  pinMode(SteerIN1pin, OUTPUT);
  pinMode(SteerIN2pin, OUTPUT);
  pinMode(usLfTrigPin, OUTPUT);
  pinMode(usLfEchoPin, INPUT);
  pinMode(usLbTrigPin, OUTPUT);
  pinMode(usLbEchoPin, INPUT);
  pinMode(usRfTrigPin, OUTPUT);
  pinMode(usRfEchoPin, INPUT);
  pinMode(usRbTrigPin, OUTPUT);
  pinMode(usRbEchoPin, INPUT);
  pinMode(AMSpin, INPUT);
  Serial.setTimeout(200);
}

void loop()
{
  /* This is the original network code that will light up LEDs corresponding to JSON input 
  String JSON = toJSON();
  Serial.println(JSON);
  if (Serial.available())
  {
    dealWithInput();
  }
  */
  
  /* This is the code that merely tests for Serial input 
  HOW IT WORKS: 
    Abstract: prints NOTFOUND until the character 'c' is inputed
    
  Not - Abstract:
  */
  char string[100]; //create a new array
  int index = 0; //start index at 0
  /** As long as serial is available, put characters into the string array */
  while(Serial.available())
  {
    string[index++] = Serial.read(); //incremenet index postfix
  }
  string[index] = '\0'; //add null character to make it a string
  delay(100); //chill out
  /** If the character c is in the string then print it out FOUND forever */
  for (int i = 0; i < index; i++)
  {
    if (string[i] == 'c')
    {
      while(1)
      {
        Serial.println("FOUND THE C!");
      }
    }
  }
  /** If loop is broken i.e. c is not contained, then print out not found */
  Serial.println("not found");
}

void setFNR(int FNR)
{
  if (FNR == 1)
  {
    digitalWrite(FNRbackwardPin, LOW);
    delay(200);
    digitalWrite(FNRforwardPin, HIGH);
  }
  else if (FNR == 0)
  {
    digitalWrite(FNRbackwardPin, LOW);
    digitalWrite(FNRforwardPin, LOW);
  }
  else if (FNR == -1)
  {
    digitalWrite(FNRforwardPin, LOW);
    delay(100);
    digitalWrite(FNRbackwardPin, HIGH);
  }
}

void gotoSteer(int steerDegrees)
{
  if (steerDegrees > 90)
  {
    digitalWrite(SteerIN1pin, LOW);
    digitalWrite(SteerIN2pin, HIGH);
  }
  else if (steerDegrees < 90)
  {
    digitalWrite(SteerIN1pin, LOW);
    digitalWrite(SteerIN2pin, HIGH);
  }
  else
  {
    digitalWrite(SteerIN1pin, LOW);
    digitalWrite(SteerIN2pin, LOW);
  }
  //Robert code
}
  
int dealWithInput()
{
    
  if (Serial.find("FNR:"))
  {
    FNR = Serial.parseInt();
    setFNR(FNR);  
  }
  
  if (Serial.find("STEER:"))
  {
    SteerDegrees = Serial.parseInt();
    gotoSteer(SteerDegrees);
  }
  
}


/**
 * Read in Ultrasonic sensor with TRIG pin located at defined pin
 * Echo pin plugged into PIN + 1.
 * For example, if Trig pin is plugged into pin 4, echo should be on pin 5
 */
int readUSensor(int sensor)
{
  int readValue = -1; //value that is read
  /** If the sensor is the MaxBotix sensor */
  if (sensor == 1)
  {
    readValue = analogRead(usFLpin);
  }
  else if (sensor == 5)
  {
    readValue = analogRead(usFRpin);
  }
  else
  {
    /** Taken from Angle Detection - Louie Thiros */
    /** Trig pin is sensor number, echo should be in sensor number + 1 */
    NewPing sonar(sensor, sensor + 1, 200); //create a new Ping object
    readValue = sonar.ping_median(3); //Ping 3 times, take median, Joe found that 3 pings was sufficient in debounce days
    /** I will restore higher if inconsistent data occurs, but for now, 10 is way to high */
    readValue /=58.77; //sound wave takes 58.77 us to make a 1cm round trip (2cm)
  }
  return readValue;
}

/**
 * Read in Linear Encoder located on defined pin 
 * For now there exists only one encoder.
 * Allows for more because of int pin parameter
 * assumes straight ahead (north) is 90 degrees, 
 * with a 90 degree turn to the right (east) being 0 degrees,
 * and a 90 degree turn left (West) being 180 degrees
 * @return Degree of steering wheel
 */
int readSteering(int pin)
{
//.9016*pow(analogRead(STEERBOX), 0.8139);
/** These are called magic numbers */
/** Written by Derek and Alex */
/** Decomposed by Joe */
/** Derek and Alex, please explain this magic nonsense - Joe */
  //pin should be A2
  int readValue = analogRead(HEpin);
  readValue = pow(readValue, .8139);
  readValue *= .9016; 
  return readValue;
}

/**
 * Reads in hall effects sensor plugged into Analog ports at pin # (pin)
 * @param pin The Analog port the pin is plugged into
 * @return Speed read from hall effects sensor in cm/s
 */
int readHallEffects(int pin)
{
  int third = .465; //third of the circumference of the wheel
  
  int readValue = 0; //the read value
  double distance = 0; //the distance traversed
  double velocity = 0; //the velocity of the car
  /** If the pin is on two */
  if (pin == 2)
  {
    readValue = analogRead(A2);
  }
  /** if the read value is greater than 50, such that a magnet is present, and it hasnt been read -*/
  if (readValue > 50 && !hasBeenRead)
  {
    /** Increment tic */
    tic++;
    /** Distance is the number of tics divided by 1.3, a value found through empiricle analysis.
    * Explanation of 1.3
    * When 4 tics were read, it turned out 4 * 1.3 tics had actually been traversed.  Such that about 30% of tics weren't being read.
    * This 1.3 is a correction factor */
    /** So multiply a tic by a third of a wheel, ideally, 3 tics is equal to the circumerference of the wheel
    * Since there are 3 magnets attatched to the wheel */
    int distance = (tic / 1.3) * third;
    /** Value has been read, reduces chance of magnetic presence being read twice */
    hasBeenRead = true;
    /** Find the elapsed time */
    time = millis() - time;
    /** velocity = delta distance / time in seconds */
    velocity = third / (time / 1000);
    /** Value has been read */
    hasBeenRead = true;
    /** Store current time */
    time = millis();
  }
  /** If magnet isnt sensed */
  if (readValue < 50)
  {
    /** Then a value hasnt been read */
    hasBeenRead = false;
  }
  return velocity * 100;
}

/**
 * Returns whether defined pin is high or low 
 */
int readAMS(int pin)
{
  return digitalRead(pin);
}  
String toJSON()
{
  /** Read in Ultrasonic sensors */
  /** This sensor mapping is horrible */
  /** It's just the way it worked out */
  int US1 = readUSensor(1); 
  int US2 = readUSensor(5); 
  int US3 = readUSensor(4); 
  int US4 = readUSensor(6); 
  int US5 = readUSensor(5); 
  int US6 = readUSensor(0); 
  /** Read in steering degrees */
  int STEERING = readSteering(0);
  /** Read in hall effects */
  int HE = readHallEffects(HEpin);
  /** Read in if auto mode is on */
  int AMS = readAMS(AMSpin);
   
  /** Create the string */
  String JSON = "{";
  JSON += "US1:";
  JSON += US1;
  JSON += ",US2:"; 
  JSON += US2;
  JSON += ",US3:";
  JSON += US3;
  JSON += ",US4:";
  JSON += US4;
  JSON += ",US5:";
  JSON += US5;
  JSON += ",US6:";
  JSON += US6;
  JSON += ",STEERING:";
  JSON += STEERING;
  JSON += ",HE:";
  JSON += HE;
  JSON += ",AMS:";
  JSON += AMS;
  JSON += "}";
  return JSON;
}  
