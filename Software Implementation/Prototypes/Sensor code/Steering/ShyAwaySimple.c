#include <math.h>
#define WIDTH_BUFFER 132
#define WIDTH 102
/*Set to one meter for now*/
#define LIMIT 100
#define LEFT_TURN 107
#define RIGHT_TURN 73

/* This function is used to make a movement decision when an object is hit by
 * either the left sensor, the right sensor, or both.
 */ 
void shyAwaySimple(double left, double right, int* angle) {
   /* If both sensors read a value, reverse the car.*/
   if (left < LIMIT && right < LIMIT) {
      *angle = -1;
   }
   /*If the left reads a value, turn right*/
   else if (left < LIMIT) {
      *angle = RIGHT_TURN;
   }
   /*If the right reads a value, turn left*/
   else if (right < LIMIT) {
      *angle = LEFT_TURN;
   }
   /*If no value is read, go straight*/
   else {
      *angle = 90;
   }
}
