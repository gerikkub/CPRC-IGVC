String ToJSON()
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