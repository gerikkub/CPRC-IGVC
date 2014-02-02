
//Steering group

//JUST SETS ANGLE TARGET. Actual angle changing is lower level
char setAngle(char angleTarget) {
   //dummy function, nothing will happen for now...
   //return success
   return 1;
}

//get the current angle of the steering system
char getAngle(char* sensorResponse) {
   //store fake angle reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//get the angle target. argument name is sensorResponse for the sake of consistancy
char getDesiredAngle(char* sensorResponse) {
   //fake response
   *sensorResponse = 0;
   //return success
   return 1;
}

//change the PID controller
char changePID(char P, char I, char D) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//not sure what this does. Also not sure why upper and lower are separated
//but its in the specs so...
char setLimits(char upper, char lower) {
   //dummy function, nothing happens
   //return success
   return 1;
}

