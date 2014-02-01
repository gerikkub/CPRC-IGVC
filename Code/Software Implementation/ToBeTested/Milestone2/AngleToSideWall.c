/**
 * returns the angle the golf cart is the the side wall
 * 90 - parallel
 * > 90 nose close to wall
 * < 90 tail closer to wall
 *
 * front - the sensor value of the side front
 * back  - sensor value of the side back
 */
 #define SENSOR_DISTANCE 20 //in cm
 #define RAD2DEG 180/3.14159265359
 
float AngleToSideWall(int front, int back)
{
   	return (atan(((float)front-(float)back)/SENSOR_DISTANCE) * RAD2DEG)+90;
}