#ifndef ToteLifterino_H
#define ToteLifterino_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "robotmap.h"
#include "../utilities/DoubleMotorPIDWrapper.h"

class ToteLifterino: public Subsystem {
private:
	DigitalInput *toteUnderInput, *elevatorTopInput;
	Talon *rightMotor, *leftMotor;
	Encoder *encoder;
	DoubleMotorPIDWrapper *pid;
	bool pidEnabled;
public:
	/**
	 * Default Constructor. Normal Initialization
	 */
	ToteLifterino();
	/**
	 * Does nothing because SetDefaultCommand call creates circular includes and compile errors
	 */
	void InitDefaultCommand();

	bool getElevatorDigitalInput();

	Talon *getLeftMotor();
	Talon *getRightMotor();

	DoubleMotorPIDWrapper *getPID();

	double getEncPosition();

	bool isToteUnder();
	/**
	 * Used to check if the stacker is close enough to its encoder value for each position.
	 * Allowed variablitity determined by TOTE_LIFTER_ENCODER_DEADBAND.
	 * Takes a constant and checks if (value > constant - deadband && value < constant + deadband)
	 * @return if the value is close enough to the constant
	 */
	bool closeEnough(int destination);
	void setMotorSpeed(double speed);
	void setSetPoints(double setPoint);
	void enablePID(bool enable);

};

#endif
