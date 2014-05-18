
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "SerialComms.h"

#define COMM_PORT_NUMBER	16        /* /dev/ttyS0 (COM1 on windows) */
#define BAUD_RATE			115200

using namespace std;

int main(int argc, char** argv){

	int successCount = 0,count = 0;
	char input;
	char FNRState;
	unsigned char cartSpeed;
	

	Packet FNRPacket;
	Packet speedPacket;
	Packet sendPacket;
	ReturnPayload results;

	SerialComms atmega;

	if(atmega.initializeComms(COMM_PORT_NUMBER,BAUD_RATE) != COMM_SUCCESS){
		cout << "Unable to initialize Serial Connection\n";
		return 1;
	}	

	cout << "Connection Initialized" << endl;

	FNRPacket.groupID = 4;
	FNRPacket.cmd = 0;
	FNRPacket.payloadSize = 1;
	FNRPacket.payload = (unsigned char*)&FNRState;

	speedPacket.groupID = 2;
	speedPacket.cmd = 1;
	speedPacket.payloadSize = 1;
	speedPacket.payload = &cartSpeed;


	while(scanf("%c",&input) != EOF){
		count = 0;
		switch(input){
		case 'F':
			FNRState = 1;
			sendPacket = FNRPacket;
			break;
		case 'N':
			FNRState = 0;
			sendPacket = FNRPacket;
			break;
		case 'R':
			FNRState = -1;
			sendPacket = FNRPacket;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			cartSpeed = 12 * (input - 0x30);
			sendPacket = speedPacket;
			break;
		default:
			continue;
		}

		while(atmega.sendPacket(&sendPacket) != COMM_SUCCESS){
			cout << "Failure sending packet. Trying again\n";
			usleep(400000);
			count++;
			if(count > 5){	
				break;
			}
		}
		if(count > 5){
			cout << "Command unsuccessful!\n";
		} else {
			cout << "Successfully sent command\n";
		}
	}

	//results = atmega.getResults();

	/*for(int i = 0;i < results.size;i++){
		cout << "Byte: " << i << " is " << results.payload[i] << endl;
	}*/

	return 0;
}
