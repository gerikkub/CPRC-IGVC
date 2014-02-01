/* 
  SetSteeringAngle input:
    (float) targetAngle
    
  SetSteeringAngle function:
     corrects steering to get desired Angle  
    
  */

void SetSteeringAngle(int targetAngle){
  if(targetAngle < (currentAngle+delta) && targetAngle > (currentAngle-delta))
    return;
  
     steerAngle.calculateCorrection(currentAngle,targetAngle);
     
    
     steerAngle.result = -steerAngle.result;

     if(signum(steerAngle.result) == 1) 
      steerAngle.result = (steerAngle.result*30)+72;
      
     if(signum(steerAngle.result) == -1) 
      steerAngle.result = (steerAngle.result*35)+68;  
      
    turn(steerAngle.result);  
}