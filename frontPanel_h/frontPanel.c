void updateDisplay(char FNR, int throttle, int steering, char FLR) {
  int outputDisplay=0;
  switch(FNR) {
    case 'F':
      outputDisplay |= FORWARDS_DISPLAY;
      break;
    case 'N':
      outputDisplay |= NEUTRAL_DISPLAY;
      break
    case 'R':
      outpudDisplay |= REVERSE_DISPLAY;
      break;
  };
  
  if(throttle == 100) {
    outputDisplay
