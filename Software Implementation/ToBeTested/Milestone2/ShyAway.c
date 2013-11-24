#define WIDTH_BUFFER 132
#define WIDTH 102
/*Set to one meter for now*/
#define LIMIT 100
#define LOWER_LIMIT 20
#define LEFT_TURN 107
#define RIGHT_TURN 73
#include <math.h>

/* This function is used to make a movement decision when an object is hit by
 * either the left sensor, the right sensor, or both.
 */ 
void shyAway (double left, double right, double center, int* angle) {
   static int turningLeft = 0;
   static int turningRight = 0;
   static int centerBehaveLeft = 0;
   static int centerBehaveRight = 0;
   int diff, tunnelWidth;
   
   if (left <= LOWER_LIMIT || right <= LOWER_LIMIT || center <= LOWER_LIMIT) {
      *angle = -1;
   }
   else if (left < LIMIT && right < LIMIT) {
      
      /*If both sensors read an equal value, reverse the car.*/
      if (left == right) {
         *angle = -1;
      }
      else {
         diff = left - right;
         tunnelWidth = sqrt(diff*diff + WIDTH*WIDTH);
         
         /* If the cones are wide enough for the car to fit 
          * through, continue, otherwise reverse the car.
          */
         if(tunnelWidth > WIDTH_BUFFER) {
            /* Take the smaller distance, and turn according
             * to that behavior. Set a flag (turningLeft/turningRight)
             * that you are in the process of turning the car and attempting
             * to get through the cones.
             */            
            if (left < right) {
               *angle = RIGHT_TURN;
               turningRight = 1;
               centerBehaveLeft = 1;
            }
            else {
               *angle = LEFT_TURN;
               turningLeft = 1;
               centerBehaveRight = 1;
            }
         }
         else {
            *angle = -1;
         }
      }
   }
   else if (left < LIMIT) {
      turningLeft = 0;
      centerBehaveRight = 0;
      if (turningRight) {
         *angle = LEFT_TURN;
      }
      else {   
         *angle = RIGHT_TURN;
      }
   }
   /* If the right sensor reads a value closer than a meter
    * set the turning angle to turn left.
    */
   else if (right < LIMIT) {
      centerBehaveLeft = 0;
      turningRight = 0;
      if (turningLeft) {
         *angle = RIGHT_TURN;
      }
      else {
         *angle = LEFT_TURN;
      }
   }
   else if (center < LIMIT) {
      if (centerBehaveRight) {
         *angle = RIGHT_TURN;
      }
      else if (centerBehaveLeft) {
         *angle = LEFT_TURN;
      }
      else {
         *angle = LEFT_TURN;
      }
   }
   else {
      *angle = 90;     
   }
}
