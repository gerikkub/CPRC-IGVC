
//Ultrasonic group

//distance in cm stored as int in sensorResponse, returns success
char getCertainSensor(char sensor, int* sensorResponse) {
   //returns dummy value for now
   *sensorResponse = 0;
   //return success
   return 1;
}

//takes in 6 int array to store response, returns success
char getAllSensors(int* sensorResponse) {
   for(char i = 0; i < 6; i++) {
      getCertainSensor(i, &sensorResponse[i]);
   }
   //no error checking for now, return success
   return 1;
}

//stores cm values of a sensor group in sensorResponse
char getSensorGroup(char groupID, int *sensorResponse) {
   //different group ID's might mean different lengths. the dummy
   //implementation will place 3 0x0000's in the response
   for(int i = 0; i < 3; i++) {
      *sensorResponse=0;
   }
   //return success
   return 1;
}

