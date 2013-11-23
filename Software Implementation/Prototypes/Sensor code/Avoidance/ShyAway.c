/*buffer width that car can fit through*/
#define WIDTH_BUFFER 132
/*car width*/
#define WIDTH 102
/*Set to one meter for now*/
#define LIMIT 100
/*angle for turning left*/
#define LEFT_TURN 107
/*angle for turning right*/
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
      *angle = TURN_RIGHT;
   }
   /*If the right reads a value, turn left*/
   else if (right < LIMIT) {
      *angle = TURN_LEFT;
   }
   /*If no value is read, go straight*/
   else {
      *angle = 90;
   }
}

/* This function is used to make a movement decision when an object is hit by
 * either the left sensor, the right sensor, or both.
 */ 
void shyAway (double left, double right, int* angle) {
   static int turningLeft = 0;
   static int turningRight = 0;
   static int changeLeftBehavior = 0;
   static int changeRightBehavior = 0;
   int diff, tunnelWidth;
    
   if (left < LIMIT && right < LIMIT) {
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
            }
            else {
               *angle = LEFT_TURN;
               turningLeft = 1;
            }
         }
         else {
            *angle = -1;
         }
   }
   else if (left < LIMIT) {
      /*Reset flags if they had been set.*/
      changeRightBehavior = 0;
      turningLeft = 0;
      
      /* If the behavior of the sensor has been
       * changed, then turn in the opposite
       * direction than usual.
       */
      if (changeLeftBehavior) {
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
      /*Reset flags if they had been set.*/
      changeLeftBehavior = 0;
      turningRight = 0;
      
      /* If the behavior of the sensor has been
       * changed, then turn in the opposite
       * direction than usual.
       */
      if (changeRightBehavior) {
         *angle = RIGHT_TURN;
      }
      else {   
         *angle = LEFT_TURN;
      }
   }
   else {
      /* If two cones had previously been detected,
       * and the car is currently turning in order to
       * orient itself, keep turning, and change the behavior
       * of one sensor if it has not already been changed. 
       * Otherwise, reset all flags and go straight.
       */
      if (changeRightBehavior && !turningLeft) {
         *angle = RIGHT_TURN;
      }
      else if (changeLeftBehavior && !turningRight) {
         *angle = LEFT_TURN;
      }
      else if (turningLeft) {
         *angle = LEFT_TURN;
         changeRightBehavior = 1;
         changeLeftBehavior = 0;
      }
      else if (turningRight) {
         *angle = RIGHT_TURN;
         changeLeftBehavior = 1;
         changeRightBehavior = 0;
      }
      else {
         changeRightBehavior = 0;
         changeLeftBehavior = 0;
         *angle = 90;
      }     
   }
} 
