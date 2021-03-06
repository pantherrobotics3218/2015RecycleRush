#include "EnableIntake.h"

EnableIntake::EnableIntake(bool enable) {
	Requires(toteIntake);
	this->enable = enable;
}

// Called just before this Command runs the first time
void EnableIntake::Initialize() {
	if (enable) {
		toteIntake->setMotor(TOTE_INTAKE_MOTOR_FULL);
	} else {
		toteIntake->setMotor(0);
	}
}

// Called repeatedly when this Command is scheduled to run
void EnableIntake::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool EnableIntake::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void EnableIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableIntake::Interrupted() {

}
