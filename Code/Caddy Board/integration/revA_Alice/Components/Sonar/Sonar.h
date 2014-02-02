//Ultrasonic group

//distance in cm stored as int in sensorResponse, returns success
char getCertainSensor(char sensor, int* sensorResponse); 

//takes in 6 int array to store response, returns success
char getAllSensors(int* sensorResponse);

//stores cm values of a sensor group in sensorResponse
char getSensorGroup(char groupID, int *sensorResponse);
