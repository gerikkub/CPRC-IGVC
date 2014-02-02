
//battery controller functions

//read battery strength in a char. Might need to be unsigned, specs don't say
//anything regarding that.
char getBatteryVoltage(char *sensorResponse) {
   //fake battery reading
   *sensorResponse = 0;
   //return success
   return 1;
}

//gets voltage from steering?
char getSteeringVoltage(char *sensorResponse) {
   //fake steering voltage reading
   *sensorResponse = 0;
   //return success
   return 1;
}
