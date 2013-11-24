/* 
  Straighten input:
    none
    
  Straighten function:
     corrects steering to get to 90 degrees  
    
  */

void Straighten() {
   if(currentAngle < 92 && currentAngle > 88)
    return;
   
   steerAngle.calculateCorrection(currentAngle,90);
   
   steerAngle.result = -steerAngle.result;

   if(signum(steerAngle.result) == 1) 
      steerAngle.result = (steerAngle.result*30)+72;
      
   if(signum(steerAngle.result) == -1) 
      steerAngle.result = (steerAngle.result*35)+68; 
 
   turn(steerAngle.result);
}