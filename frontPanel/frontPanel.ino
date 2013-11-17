#include "frontPanel.h"

int updateDisplay(int FNR, int throttle, int steering, char FLR) {
  int outputDisplay=0;
  switch(FNR) {
    case 1: 
      outputDisplay |= FORWARDS_DISPLAY;
      break;
    case 0: 
      outputDisplay |= NEUTRAL_DISPLAY;
      break;
    case -1:
      outputDisplay |= REVERSE_DISPLAY;
      break;
  };
  
  if(throttle == 100) {
    outputDisplay |= (THROTTLE_25_DISPLAY | THROTTLE_50_DISPLAY | THROTTLE_75_DISPLAY | THROTTLE_100_DISPLAY);
  } else if (throttle >= 75) {
    outputDisplay |= (THROTTLE_25_DISPLAY | THROTTLE_50_DISPLAY | THROTTLE_75_DISPLAY);
  } else if (throttle >= 50) {
    outputDisplay |= (THROTTLE_25_DISPLAY | THROTTLE_50_DISPLAY);
  } else if (throttle >=25) {
    outputDisplay |= (THROTTLE_25_DISPLAY);
  };

  if(steering < 60) {
    outputDisplay |= STEERING_30_DISPLAY;
    if(steering >=45) outputDisplay |= STEERING_60_DISPLAY;
  } else if(steering <90) {
    outputDisplay |= STEERING_60_DISPLAY;
    if(steering >=75) outputDisplay |= STEERING_90_DISPLAY;
  } else if(steering < 120) {
    outputDisplay |= STEERING_90_DISPLAY;
    if(steering >= 105) outputDisplay |= STEERING_120_DISPLAY;
  } else if(steering < 150) {
    outputDisplay |= STEERING_120_DISPLAY;
    if(steering >=135) outputDisplay |= STEERING_150_DISPLAY;
  } else {
    outputDisplay |= STEERING_150_DISPLAY;
  };

  switch(FLR) {
    case 'F':
      outputDisplay |= FRONT_DISPLAY;
      break;
    case 'L':
      outputDisplay |= LEFT_DISPLAY;
      break;
    case 'R':
      outputDisplay |= RIGHT_DISPLAY;
      break;
  }

  return outputDisplay;
}

void driveDisplay(int outputDisplay) {
  if(outputDisplay & FORWARDS_DISPLAY) digitalWrite(52, HIGH);
  if(outputDisplay & NEUTRAL_DISPLAY) digitalWrite(50, HIGH);
  if(outputDisplay & REVERSE_DISPLAY) digitalWrite(48, HIGH);
  if(outputDisplay & THROTTLE_25_DISPLAY) digitalWrite(46, HIGH);
  if(outputDisplay & THROTTLE_50_DISPLAY) digitalWrite(44, HIGH);
  if(outputDisplay & THROTTLE_75_DISPLAY) digitalWrite(42, HIGH);
  if(outputDisplay & THROTTLE_100_DISPLAY) digitalWrite(40, HIGH);
  if(outputDisplay & STEERING_30_DISPLAY) digitalWrite(53, HIGH);
  if(outputDisplay & STEERING_60_DISPLAY) digitalWrite(51, HIGH);
  if(outputDisplay & STEERING_90_DISPLAY) digitalWrite(49, HIGH);
  if(outputDisplay & STEERING_120_DISPLAY) digitalWrite(47, HIGH);
  if(outputDisplay & STEERING_150_DISPLAY) digitalWrite(45, HIGH);
  if(outputDisplay & LEFT_DISPLAY) digitalWrite(43, HIGH);
  if(outputDisplay & FRONT_DISPLAY) digitalWrite(41, HIGH);
  if(outputDisplay & RIGHT_DISPLAY) digitalWrite(39, HIGH);
}

void clearDisplay() {
  for(int i=39;i<=53;i++) {
    digitalWrite(i, LOW);
  };
}

void setup() {
  clearDisplay();
}

void loop() {
  int throttle=0;
  driveDisplay(updateDisplay(1, 0, 0, 'F'));
  delay(600);
  clearDisplay();
  driveDisplay(updateDisplay(0,0,0,'N'));
  delay(600);
  clearDisplay();
  driveDisplay(updateDisplay(-1,0,0,'R'));
  delay(600);
  clearDisplay();
  
  for(throttle=0;throttle<=100;throttle+=25) {
    driveDisplay(updateDisplay(0,throttle,0,'N'));
    delay(600);
    clearDisplay();
  };
  
  for(int steering=0;steering<=150;steering+=15) {
    driveDisplay(updateDisplay(0,0,steering,'N'));
    delay(600);
    clearDisplay();
  };
}

