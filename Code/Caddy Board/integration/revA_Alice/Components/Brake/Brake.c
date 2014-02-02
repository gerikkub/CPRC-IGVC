//Brake controller functions. THERE IS CURRENTLY NO WAY TO GET THE DESIRED
//BRAKE TARGET IN THE SPECS

//set brake target
char setBrake(char gainTarget) {
   //dummy function, nothing happens
   //return success
   return 1;
}

//get what is assumed to be the current brake value?
char getBrake(char* sensorResponse) {
   //fake brake reading
   *sensorResponse = 0;
   //return success
   return 1;
}

