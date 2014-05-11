
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "SerialComms.h"

#define COMM_PORT_NUMBER	16        /* /dev/ttyS0 (COM1 on windows) */
#define BAUD_RATE			115200

using namespace std;

int main(int argc, char** argv){

	int successCount = 0,count = 0;
	unsigned char lightState = atoi(argv[1]);

	Packet commPacket;
	ReturnPayload results;

	SerialComms atmega;

	if(atmega.initializeComms(COMM_PORT_NUMBER,BAUD_RATE) != COMM_SUCCESS){
		cout << "Unable to initialize Serial Connection\n";
		return 1;
	}	

	cout << "Connection Initialized" << endl;

	commPacket.groupID = 7;
	commPacket.cmd = 0;
	commPacket.payloadSize = 1;
	commPacket.payload = &lightState;


	for(int i=0 ; i < 1; i++){
		if(atmega.sendPacket(&commPacket) != COMM_SUCCESS){
			cout << "Failure sending packet\n";
		} else {
			successCount++;
		}
		count++;
		usleep(100000);
	}

	cout << (double)successCount/count * 100 << " percent of results were successful\n";

	//results = atmega.getResults();

	/*for(int i = 0;i < results.size;i++){
		cout << "Byte: " << i << " is " << results.payload[i] << endl;
	}*/

	return 0;
}
