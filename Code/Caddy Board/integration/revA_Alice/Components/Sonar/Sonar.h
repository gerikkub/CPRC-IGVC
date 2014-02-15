#ifndef __SONAR_H__
#define __SONAR_H__

	#define SONAR_PCINT16	(1<<0)
	#define SONAR_PCINT17	(1<<1)
	#define SONAR_PCINT18	(1<<2)
	#define SONAR_PCINT19	(1<<3)
	#define SONAR_PCINT20	(1<<4)
	#define SONAR_PCINT21	(1<<5)
	#define SONAR_PCINT22	(1<<6)
	#define SONAR_PCINT23	(1<<7)

	#define SONAR_GROUP_LEFT	0
	#define SONAR_GROUP_FRONT	1
	#define SONAR_GROUP_RIGHT	2

	//Sonars are numbered from left to right
	//  23
	// 1  4
	// 0  5

	//distance in cm stored as int in sensorResponse, returns success
	char getCertainSensor(char sensor, int* sensorResponse); 

	//takes in 6 int array to store response, returns success
	char getAllSensors(int* sensorResponse);

	//stores cm values of a sensor group in sensorResponse
	char getSensorGroup(char groupID, int *sensorResponse);

	void setSonarData(int i,unsigned char data);
	unsigned char getSonarData(int i);
	void vTaskSonar(void* parameter);

#endif
