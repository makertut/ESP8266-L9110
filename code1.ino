#include <Stepper.h>

// change this to fit the number of steps per revolution

const int stepsPerRevolution = 200; 



Stepper myStepper(stepsPerRevolution, 14, 12, 13, 15);



int stepCount = 0;         // number of steps the motor has taken

int dirStep = 1;

void setup() {

   Serial.begin(9600);

}

void loop() {

 

  myStepper.step(dirStep);

  Serial.print("steps:");

  Serial.println(stepCount);

  stepCount++;



  if( stepCount > 500){

      stepCount = 0;

      if( dirStep == 1) dirStep = -1;

      else dirStep = 1;

  }

  delayMicroseconds(50);

}

