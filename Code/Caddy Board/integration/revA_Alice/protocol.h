/**
 * Skeleton of command recieve and response
 *
 * @author Louie Thiros
 */

#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#define MAX_PAYLOAD_SIZE 32

#define ULTRASONIC_GROUP 0x01
#define SPEED_GROUP 0x02
#define STEERING_GROUP 0x03
#define FNR_GROUP 0x04
#define BRAKES_GROUP 0x05
#define BATTERY_GROUP 0x06
#define LIGHTS_GROUP 0x07
#define ERROR_GROUP 0x08

//ultrasonic commands
#define GET_ALL_SENSORS 0x01
#define GET_CERTAIN_SENSORS 0x02
#define GET_SENSOR_GROUP 0x03

//speed commands
#define GET_SPEED 0x00
#define SET_SPEED 0x01

//steering commands
#define SET_ANGLE 0x00
#define GET_ANGLE 0x01
#define GET_DESIRED_ANGLE 0x02
#define CHANGE_PID 0x03
#define SET_LIMITS 0x04

//FNR commands
#define SET_FNR 0x00
#define GET_FNR 0x01

//brake commands
#define SET_BRAKE 0x00
#define GET_BRAKE 0x01

//battery commands
#define GET_BATTERY_VOLTAGE 0x00
#define GET_STEERING_VOLTAGE 0x01

//light commands
#define SET_LIGHT 0x00

struct command {
   char groupID;
   char cmd;
   char crc;
   char payload[MAX_PAYLOAD_SIZE];
};

struct response {
   char commandBack;
   char size;
   char payload[MAX_PAYLOAD_SIZE];
};

typedef struct command Command;
typedef struct response Response;


//function to CRC the command structure
char commandIntegCheck(Command *command);

//Function that will take in a command (as char array) and process it into a
//correct response to be stored into response
char processCommand(Command *command, Response *response);

#endif