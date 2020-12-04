// stepperDrawing.h
/**
 * MirrorController is a stepper motor controller class designed to control stepper motors that are combined with mirrors
 * in order to make a simple 'laser show'. 
 * Allows to easily draw lines in different directions and make forms and drawings by sequencing the different lines
 * 
 * 
 */

#ifndef __STEPPER_DRAWING__
#define __STEPPER_DRAWING__

#include "Arduino.h"

class StepperDrawing 
{
    public:

    /**
     * MirrorController : constructor allowing to define the stepper driver pins
     * @param pinDIR pin number of the DIR output 
     * @param pinPU pin number of the PU or STEP output
     * @param pinMF pin number of the MF or ENABLE output (you can also not connect the MF pin)
     */
    StepperDrawing(const int pinDIR, const int pinPU, const int pinMF);

    /**
     * Init : initialize the pins and library
     * Needs to be called after the constructor in the setup() function
    */
    void init();

    /**
     * setSpeed : set the rotation speed of the axle
     * @param speed in Rotation per Minute (RPM), integers only
    */
    void setSpeed(int speed);

    /**
     * setStepsPerRevolution : set the number of steps the stepper motor needs to make for an entire revolution 
     * @param stepsPerRevolution number of steps per revolution (default value is 800)
    */
    void setStepsPerRevolution(int stepsPerRevolution);

    /**
     * getSpeed : get the current speed setting 
     * @return integer value corresponding to the set speed in RPM
    */
    int     getSpeed();

    /**
     * activateMotors : activates the motors by enabling the MF/ENABLE pin
    */
    void activateMotors();

    /**
     * deactivateMotors : deactivate the motors by disabling the MF/ENABLE pin
    */
    void deactivateMotors();

    /**
     * makeOneStep : move the motor of one step in the given direction
     * @param : direction, true clockwise rotation, false counter clockwise rotation
    */
    void makeOneStep(bool direction);

    /**
     * move : move the motor of the given number of steps in the given direction
     * @param direction true clockwise rotation, false counter clockwise rotation
     * @param numberOfSteps number of steps you want to move
    */
    void move(int numberOfSteps, bool direction);

    private:

    void        _setDirection(bool direction);
    bool        _makeOneStep();

    int         _pinDir;
    int         _pinPU;
    int         _pinMF;

    int         _stepsPerRevolution;
    int         _speedRpm; 

    uint32_t    _stepInterval;
    uint32_t    _lastStep;
};

#endif // __STEPPER_DRAWING__
