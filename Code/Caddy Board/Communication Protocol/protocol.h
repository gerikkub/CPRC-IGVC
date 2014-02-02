/**
 * Skeleton of command recieve and response
 *
 * @author Louie Thiros
 */

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
#define GET_ALL_SENSORS 0x00
#define GET_CERTAIN_SENSORS 0x01
#define GET_SENSOR_GROUP 0x02

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

struct __attribute__ ((__packed__)) command {
   char groupID;
   char cmd;
   char crc;
   char payload[MAX_PAYLOAD_SIZE];
};

struct __attribute__ ((__packed__)) response {
   char commandBack;
   char size;
   char payload[MAX_PAYLOAD_SIZE];
};

typedef struct command Command;
typedef struct response Response;

//Ultrasonic group

//distance in cm stored as int in sensorResponse, returns success
char getCertainSensor(char sensor, int* sensorResponse); 

//takes in 6 int array to store response, returns success
char getAllSensors(int* sensorResponse);

//stores cm values of a sensor group in sensorResponse
char getSensorGroup(char groupID, int *sensorResponse);

//Speed Sensor group

//get the speed of the vehicle
char getSpeed(char* sensorResponse);

//will set just the speed of the wheels of the car
char setSpeed(char speedTarget);

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

//FNR controller functions

//set the FNR controller, inputs are either -1, 0, or 1.
char setFNR(char FNR);

//get the current FNR state. Function follows same format for consistancy
char getFNR(char *sensorResponse);

//Brake controller functions. THERE IS CURRENTLY NO WAY TO GET THE DESIRED
//BRAKE TARGET IN THE SPECS

//set brake target
char setBrake(char gainTarget);

//get what is assumed to be the current brake value?
char getBrake(char* sensorResponse);

//battery controller functions

//read battery strength in a char. Might need to be unsigned, specs don't say
//anything regarding that.
char getBatteryVoltage(char *sensorResponse);

//gets voltage from steering?
char getSteeringVoltage(char *sensorResponse);

//light controller functions

//turn lights on and off
char setLight(char lightTarget);

//specs make no mention of a getLight

//function to CRC the command structure
char commandIntegCheck(Command *command);

//Function that will take in a command (as char array) and process it into a
//correct response to be stored into response
char processCommand(Command *command, Response *response);
