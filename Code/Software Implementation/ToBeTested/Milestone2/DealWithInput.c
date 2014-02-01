
//Deals with input...
//Reads in serial stream and assigns corresponding values
int DealWithInput()
{
    
  /**
   * Read in FNR
   */
  if (Serial.find("FNR:"))
  {
    FNR = Serial.parseInt();
    setFNR(FNR);  
  }
  
  /**
   * Read in Steer 
   */
  if (Serial.find("STEER:"))
  {
    currentAngle = Serial.parseInt();
    //gotoSteer(currentAngle);
  }
  
}