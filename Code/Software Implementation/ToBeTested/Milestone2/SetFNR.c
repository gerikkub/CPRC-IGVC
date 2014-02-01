/**
 * Set FNR accordingly 
 */
void SetFNR(int FNR)
{
  /** 1 is forward */
  if (FNR == 1)
  {
    digitalWrite(FNRbackwardPin, LOW);
    delay(200);
    digitalWrite(FNRforwardPin, HIGH);
  }
  /** zero is neutral */
  else if (FNR == 0)
  {
    digitalWrite(FNRbackwardPin, LOW);
    digitalWrite(FNRforwardPin, LOW);
  }
  /** -1 is reverse */
  else if (FNR == -1)
  {
    digitalWrite(FNRforwardPin, LOW);
    delay(100);
    digitalWrite(FNRbackwardPin, HIGH);
  }
}