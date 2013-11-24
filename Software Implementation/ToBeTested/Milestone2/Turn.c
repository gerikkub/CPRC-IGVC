/*
 turn inputs:
   (float) input
  
 turn function:
    turns left or right if input is less than 66 and greater than 66, respectively
 */

void Turn(float input) {
   analogWrite(SteerIN1pin, input);
   analogWrite(SteerIN2pin, input);
}