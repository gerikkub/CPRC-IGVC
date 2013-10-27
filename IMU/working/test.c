#include "3dmgx2.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

using std::cerr;
using std::cout;
using std::endl;
int main()
{
   microstrain_3dmgx2_imu::IMU imu;
   imu.openPort("/dev/ttyUSB0");
   imu.initTime(0);
   imu.setContinuous(microstrain_3dmgx2_imu::IMU::CMD_ACCEL_ANGRATE_MAG);

   while (true)
   {
      uint64_t time;
      double accel[3], angrate[3], magn[3];
      imu.receiveAccelAngrateMag(&time, accel, angrate, magn);
      //Thanks jordan
      int heading = (180 / 3.14159) * atan2(magn[1], magn[0] );
      accel[2] += imu.G;
      int readableAccel = (int) sqrt(accel[0] * accel[0] + accel[1] * accel[1] + accel[2] * accel[2]);
      int readableAng = (int) sqrt(angrate[0] * angrate[0] + angrate[1] * angrate[1] + angrate[2] * angrate[2]);

      cout << "Heading:" << heading << "        Acceleration: " << readableAccel << "         AngRate:" << readableAng <<endl;
      usleep(5000);
   }
   imu.closePort();
}
int accelMagnitude(microstrain_3dmgx2_imu::IMU imu)
{
   uint64_t time;
   int readableAccel;
   double accel[3], angrate[3], magn[3];
   imu.receiveAccelAngrateMag(&time, accel, angrate, magn);
   accel[2] += imu.G;
   readableAccel = (int) sqrt(accel[0] * accel[0] + accel[1] * accel[1] + accel[2] * accel[2]);
   return readableAccel;
}

int magVector(microstrain_3dmgx2_imu::IMU imu)
{
   uint64_t time;
   double accel[3], angrate[3], magn[3];
   imu.receiveAccelAngrateMag(&time, accel, angrate, magn);
   //Thanks jordan
   int heading = (180 / 3.14159) * atan2(magn[1], magn[0] );
   return heading;
}
  
