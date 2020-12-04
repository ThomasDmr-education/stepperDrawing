#include "stepperDrawing.h"

// Initialize the mirror controller class : pinDIR, pinPU, pinMF
StepperDrawing mirrorX(3, 4, 5);
StepperDrawing mirrorY(8, 9, 10);

void setup()
{
  // For debug purpose only
  Serial.begin(115200);

  // Set the rotation speed of the mirror
  mirrorX.setSpeed(20);
  // Initialize the library
  mirrorX.init();

  // Activate the stepper driver
  mirrorX.activateMotors();

  mirrorY.setSpeed(20);
  mirrorY.init();
  mirrorY.activateMotors();
}

void loop()
{
  // activate the motors
  mirrorX.activateMotors();
  mirrorY.activateMotors();

  // Draw a House 100 consecutive times
  for(int i=0; i< 100; i++)
  {
    drawHouse(10);
  }

  // Desactivate the motors
  mirrorX.deactivateMotors();
  mirrorY.deactivateMotors();

  // Wait for 10 seconds before starting the sequence over
  delay(10000);
}

/**
 * ============================================================================
 * ======================   WRITE YOUR FUNCTIONS HERE  ========================
 * ============================================================================
**/

// Draw a simple house with a fixed size
void drawHouse()
{
  moveRight(10);
  moveUp(10);
  moveLeftDiagonalUp(5);
  moveLeftDiagonalDown(5);
  moveDown(10);
}

// Draw a simple house with a variable size
void drawHouse(int houseSize)
{
  moveRight(houseSize * 2);
  moveUp(houseSize * 2);
  moveLeftDiagonalUp(houseSize);
  moveLeftDiagonalDown(houseSize);
  moveDown(houseSize * 2);
}

/**
 * ============================================================================
 * ======================   KEEP THIS CODE UNTOUCHED ! ========================
 * ============================================================================
**/

void moveUp(int numberOfSteps)
{
    mirrorY.move(numberOfSteps, true);
}

void moveDown(int numberOfSteps)
{
    mirrorY.move(numberOfSteps, false);
}

void moveRight(int numberOfSteps)
{
    mirrorX.move(numberOfSteps, false);
}

void moveLeft(int numberOfSteps)
{
    mirrorX.move(numberOfSteps, true);
}

void moveRightDiagonalUp(int numberOfSteps)
{
    for(int i=0; i<numberOfSteps; i++)
    {
      mirrorX.makeOneStep(false);
      mirrorY.makeOneStep(true);
    }
}

void moveRightDiagonalDown(int numberOfSteps)
{
    for(int i=0; i<numberOfSteps; i++)
    {
      mirrorX.makeOneStep(false);
      mirrorY.makeOneStep(false);
    }
}

void moveLeftDiagonalUp(int numberOfSteps)
{
    for(int i=0; i<numberOfSteps; i++)
    {
      mirrorX.makeOneStep(true);
      mirrorY.makeOneStep(true);
    }
}

void moveLeftDiagonalDown(int numberOfSteps)
{
    for(int i=0; i<numberOfSteps; i++)
    {
      mirrorX.makeOneStep(true);
      mirrorY.makeOneStep(false);
    }
}

/**
 * ============================================================================
 * ============================================================================
**/
