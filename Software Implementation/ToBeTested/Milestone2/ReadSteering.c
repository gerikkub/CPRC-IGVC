/**
 * Read in Linear Encoder located on defined pin 
 * For now there exists only one encoder.
 * Allows for more because of int pin parameter
 * assumes straight ahead (north) is 90 degrees, 
 * with a 90 degree turn to the right (east) being 0 degrees,
 * and a 90 degree turn left (West) being 180 degrees
 * @return Degree of steering wheel
 */
int ReadSteering(int pin)
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