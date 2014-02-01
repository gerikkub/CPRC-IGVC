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