#include "stepperDrawing.h"


StepperDrawing::StepperDrawing(const int pinDIR, const int pinPU, const int pinMF)
{
    _pinDir = pinDIR;
    _pinPU = pinPU;
    _pinMF = pinMF;
    _stepsPerRevolution = 1600; //default value
    _lastStep = 0;
}

void StepperDrawing::init()
{
    pinMode(_pinDir, OUTPUT);
    pinMode(_pinPU, OUTPUT);
    pinMode(_pinMF, OUTPUT);
    digitalWrite(_pinMF, LOW); // enable driver
}

void StepperDrawing::setSpeed(int speedRPM)
{
    if(_speedRpm != speedRPM)
    {
        _stepInterval = (long) 60 * 1000000 / ((long)speedRPM * _stepsPerRevolution);
        _speedRpm = speedRPM;
    }
}

int StepperDrawing::getSpeed()
{
    return (_stepInterval * _stepsPerRevolution) / (60.0 * 1000000.0);
}

void StepperDrawing::setStepsPerRevolution(int stepsPerRevolution)
{
    _stepsPerRevolution = stepsPerRevolution;
}

void StepperDrawing::activateMotors()
{
    digitalWrite(_pinMF, LOW); // activate driver
}

void StepperDrawing::deactivateMotors()
{
    digitalWrite(_pinMF, HIGH); // activate driver
}

void    StepperDrawing::makeOneStep(bool direction)
{
    _setDirection(direction);
    _lastStep = micros();

    while(!_makeOneStep()){}
}

void StepperDrawing::move(int numberOfSteps, bool direction)
{
    _setDirection(direction);
    _lastStep = micros();

    int currentStep = 0;

    while(currentStep < numberOfSteps)
    {
        if(_makeOneStep())
        {
            currentStep++;
        }
    }
}

void    StepperDrawing::_setDirection(bool direction)
{
    digitalWrite(_pinDir, direction);
}

bool    StepperDrawing::_makeOneStep()
{
    if(micros() - _lastStep > _stepInterval)
    {
        digitalWrite(_pinPU, LOW);
        _lastStep = micros();
        delayMicroseconds(10);
        digitalWrite(_pinPU, HIGH);
        return true;
    }
    return false;
}
