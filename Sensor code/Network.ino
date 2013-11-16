//Maxbotix FRONT left analog pin A0
//Maxbotix FRONT right analog pin A1
//Hobby US LEFT front TRIG digital pin 2
//Hobby US LEFT front ECHO digital pin 3
//Hobby US LEFT back TRIG digital pin 4
//Hobby US LEFT back ECHO digital pin 5
//Hobby US RIGHT front TRIG digital pin 6
//Hobby US RIGHT front ECHO digital pin 7
//Hobby US RIGHT back TRIG digital pin 8
//Hobby US RIGHT back ECHO digital pin 9
//Hall Effects sensor analog pin A2
//Steering Linear Actuator on pin 10
//AMS sensor pin digital pin 11
#include <NewPing.h>

int tic; 
boolean hasBeenRead;
int time;
void setup()
{
  tic = 0;
  hasBeenRead = false;
  time = 0;
  Serial.begin(9600);
}

void loop()
{
  String JSON = toJSON();
  Serial.println(JSON);
  delay(500);
}

/**
 * Read in Ultrasonic sensor with TRIG pin located at defined pin
 * Echo pin plugged into PIN + 1.
 * For example, if Trig pin is plugged into pin 4, echo should be on pin 5
 */
int readUSensor(int pin)
{
  int readValue = -1; //value that is read
  /** If the sensor is the MaxBotix sensor */
  if (pin == 1)
  {
    readValue = analogRead(A0);
  }
  else if (pin == 2)
  {
    readValue = analogRead(A1);
  }
  else
  {
    /** Taken from Angle Detection - Louie Thiros */
    /** Trig pin is sensor number, echo should be in sensor number + 1 */
    NewPing sonar(pin, pin + 1, 200); //create a new Ping object
    readValue = sonar.ping_median(3); //Ping 3 times, take median, Joe found that 3 pings was sufficient in debounce days
    /** I will restore higher if inconsistent data occurs, but for now, 10 is way to high */
    readValue /=58.77; //sound wave takes 58.77 us to make a 1cm round trip (2cm)
  }
  return readValue;
}

/**
 * Read in Linear Encoder located on defined pin 
 * For now there exists only one encoder
 * assumes straight ahead (north) is 90 degrees, 
 * with a 90 degree turn to the right (east) being 0 degrees,
 * and a 90 degree turn left (West) being 180 degrees.
 * @return Degree of steering wheel
 */
int readSteering(int pin)
{
//.9016*pow(analogRead(STEERBOX), 0.8139);
/** These are called magic numbers */
/** Written by Derek and Alex */
/** Decomposed by Joe */
/** Derek and Alex, please explain this magic nonsense - Joe */
  int readValue = analogRead(pin);
  readValue = pow(readValue, .8139);
  readValue *= .9016; 
  return readValue;
}

/**
 * Reads in hall effects sensor plugged into Analog ports at pin # (pin)
 * @param pin The Analog port the pin is plugged into
 * @return Speed read from hall effects sensor
 */
double readHallEffects(int pin)
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
  int US1 = readUSensor(0); //FRONT left
  int US2 = readUSensor(1); //FRONT right
  int US3 = readUSensor(2); //LEFT front
  int US4 = readUSensor(4); //LEFT back
  int US5 = readUSensor(6); //RIGHT front
  int US6 = readUSensor(2); //RIGHT back
  /** Read in steering degrees */
  int STEERING = readSteering(10);
  /** Read in hall effects */
  double HE = readHallEffects(2);
  /** Read in if auto mode is on */
  int AMS = readAMS(11);
   
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
  JSON += (int) (HE * 100);
  JSON += ",AMS:";
  JSON += (int) AMS;
  JSON += "}";
  return JSON;
}  
