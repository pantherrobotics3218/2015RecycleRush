#ifndef DriveBase_H
#define DriveBase_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "GyroDriver/IMU.h"

class DriveBase: public PIDSubsystem
{
private:
	DRIVE_MOTOR_TYPE *motorFrontLeft;
	DRIVE_MOTOR_TYPE *motorFrontRight;
	DRIVE_MOTOR_TYPE *motorBackLeft;
	DRIVE_MOTOR_TYPE *motorBackRight;

	IMU *gyro;
	SerialPort *serialPort;
public:
	DriveBase();
	~DriveBase();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void setSpeed(double speedFrontLeft, double speedFrontRight,
			double speedBackLeft, double speedBackRight);
	IMU *getGyro();
	void setTargetAngle(double theta);
};

#endif
