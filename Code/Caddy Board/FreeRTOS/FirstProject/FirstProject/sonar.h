#ifndef __SONAR_C__
#define __SONAR_C__

	#define PCINT16	(1<<0)
	#define PCINT17	(1<<1)
	#define PCINT18	(1<<2)
	#define PCINT19	(1<<3)
	#define PCINT20	(1<<4)
	#define PCINT21	(1<<5)
	#define PCINT22	(1<<6)
	#define PCINT23	(1<<7)


	void setSonarData(int i,unsigned char data);
	unsigned char getSonarData(int i);
	void vTaskSonar(void* parameter);

#endif
