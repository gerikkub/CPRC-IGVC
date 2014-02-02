
//battery controller functions

//read battery strength in a char. Might need to be unsigned, specs don't say
//anything regarding that.
char getBatteryVoltage(char *sensorResponse);

//gets voltage from steering?
char getSteeringVoltage(char *sensorResponse);
