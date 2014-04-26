#include "3dmgx2.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//There are so many magic numbers here, I am so sorry - Joe
/*
pan
tilt
*/
using std::cerr;
using std::cout;
using std::endl;
int main() {
   microstrain_3dmgx2_imu::IMU imu;
   imu.openPort("/dev/ttyUSB0");
   imu.initTime(0);
   imu.setContinuous(microstrain_3dmgx2_imu::IMU::CMD_EULER);

   while (true) {
		double roll, pitch, yaw;
      uint64_t time;
		imu.receiveEuler(&time, &roll, &pitch, &yaw);
		printf("roll: %.5lf | pitch: %.5lf\n", roll, pitch);
     // usleep(5000);
   }
   imu.closePort();
}
