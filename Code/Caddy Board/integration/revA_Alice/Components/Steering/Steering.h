//Steering group

//JUST SETS ANGLE TARGET. Actual angle changing is lower level
char setAngle(char angleTarget);

//get the current angle of the steering system
char getAngle(char* sensorResponse);

//get the angle target. argument name is sensorResponse for the sake of consistancy
char getDesiredAngle(char* sensorResponse);

//change the PID controller
char changePID(char P, char I, char D);

//not sure what this does. Also not sure why upper and lower are separated
//but its in the specs so...
char setLimits(char upper, char lower);

