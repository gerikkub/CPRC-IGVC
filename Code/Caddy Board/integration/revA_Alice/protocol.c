/**
 * Skeleton of command recieve and response
 *
 * @author Louie Thiros
 */

#include "protocol.h"
#include "Components/Sonar/Sonar.h"


//function to CRC the command structure
char commandIntegCheck(Command *command) {
   //CRC the command with 0x00 in place of the CRC
   //return success for now
   return 1;
}

char processUltrasonicCommand(char commandCode, void* commandData,char* size, void* responseData) {
   switch(commandCode) {
      case GET_ALL_SENSORS:
         getAllSensors((int*) responseData);
         *size = 6;
         break;
      case GET_CERTAIN_SENSORS:
         getCertainSensor(((char*)commandData)[0], (int*) responseData);
         break;
      case GET_SENSOR_GROUP:
         getSensorGroup(((char*)commandData)[0], (int*) responseData);
         break;
   }
   //return success for now...
   return 1;
}

char processSpeedCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case GET_SPEED:
         getSpeed((char*) responseData);
         break;
      case SET_SPEED:
         setSpeed(((char*)commandData)[0]);
         break;
   }
   //return success for now
   return 1;
}

char processSteeringCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case SET_ANGLE:
         setAngle(*((char*)commandData));
         break;
      case GET_ANGLE:
         getAngle((char*) responseData);
         break;
      case GET_DESIRED_ANGLE:
         getDesiredAngle((char*) responseData);
         break;
      case CHANGE_PID:
         changePID(((char*)commandData)[0], ((char*)commandData)[1], ((char*)commandData)[2]);
         break;
      case SET_LIMITS:
         setLimits(((char*)commandData)[0], ((char*)commandData)[1]);
         break;
   }
   //return success for now
   return 1;
}

char processFNRCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case SET_FNR:
         setFNR(*((char*)commandData));
         break;
      case GET_FNR:
         getFNR((char*) responseData);
         break;
   }
}

char processBrakeCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case SET_BRAKE:
	 setBrake(*((char*)commandData));
	 break;
      case GET_BRAKE:
	 getBrake((char*) responseData);
	 break; 
   }
}

char processBatteryCommand(char commandCode, void* commandData, void* responseData) {
   switch(commandCode) {
      case GET_BATTERY_VOLTAGE:
         getBatteryVoltage((char*) responseData);
         break;
      case GET_STEERING_VOLTAGE:
         getSteeringVoltage((char*) responseData);
         break;
   }
}

char processLightCommand(char commandCode, void* commandData, void* responseDate) {
   switch(commandCode) {
      case SET_LIGHT:
	 setLight(*((char*)commandData));
         break;
   }
}



//Function that will take in a command (as char array) and process it into a
//correct response to be stored into response
char processCommand(Command *command, Response *response) {
   if(commandIntegCheck(command)) {
      switch(command->groupID) {
         case ULTRASONIC_GROUP:
            processUltrasonicCommand(command->cmd, command->payload,&response->size, response->payload);
            break;
         case SPEED_GROUP:
            /*do speed things*/
            break;
         case STEERING_GROUP:
            /*do steering things*/
            break;
         case FNR_GROUP:
            /*do FRN things*/
            break;
         case BRAKES_GROUP:
            /*do brakes things*/
            break;
         case BATTERY_GROUP:
            /*do battery things*/
            break;
         case LIGHTS_GROUP:
            /*do light things*/
            break;
         case ERROR_GROUP:
            /*do error things*/
            break;
      }
      //return a dummy success for now
      return 1;
   } else {
      return 0;
   }
}
