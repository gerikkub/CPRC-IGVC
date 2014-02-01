/**
 * Returns whether defined pin is high or low 
 */
int ReadAMS(int pin)
{
  return digitalRead(pin);
}