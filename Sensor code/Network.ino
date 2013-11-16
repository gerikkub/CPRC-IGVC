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
//Hall Effects sensor D8
//AMS
//AMS sensor pin digital D9
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
 * Still need to include side sensors inorder to use
 *
 * Returns the angle of the golfcart to the wall
 * Golfcart side compared to wall
 *    Parallel - 90 degs
 *    Nose towards wall - "fill it in louie"
 *    Back towards wall - "   ^   ^   ^   "
 *
 * int side determines which side to use
 *    one for left
 *    two for right
 */
int sideAngleToWall (int side)
{
  //distance0 - distance of front-side
  //distance1 - distance of back-side
  int distance0, distance1;
  int angle;
  
  if (side == 1)
  {
    distance0 = readUSensor(/*left-front*/);
    distance1 = readUSensor(/*left-back*/);
  }
  else
  {
    distance0 = readUSensor(/*right-front*/);
    distance1 = readUSensor(/*right-back*/);
  }
  
  //20 - sensor distance (cm)
  return angle = (atan((distanceA-distanceB)/20) * RAD2DEG)+90;
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
    readValue = analogRead(A0);
  }
  else if (sensor == 5)
  {
    readValue = analogRead(A1);
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
  //pin should be A2
  int readValue = analogRead(A2);
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
//Hall Effects sensor D8
//AMS
//AMS sensor pin digital D9
  /** Read in Ultrasonic sensors */
  int US1 = readUSensor(1); 
  int US2 = readUSensor(5); 
  int US3 = readUSensor(4); 
  int US4 = readUSensor(6); 
  int US5 = readUSensor(5); 
  int US6 = readUSensor(0); 
  /** Read in steering degrees */
  int STEERING = readSteering(0);
  /** Read in hall effects */
  double HE = readHallEffects(8);
  /** Read in if auto mode is on */
  int AMS = readAMS(9);
   
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
