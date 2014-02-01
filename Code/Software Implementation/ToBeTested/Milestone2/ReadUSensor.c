/**
 * Read in Ultrasonic sensor with TRIG pin located at defined pin
 * Echo pin plugged into PIN + 1.
 * For example, if Trig pin is plugged into pin 4, echo should be on pin 5
 */
int ReadUSensor(int sensor)
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