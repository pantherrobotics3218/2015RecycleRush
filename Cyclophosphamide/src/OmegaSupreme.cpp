/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Drivebase/ZeroGyro.h>
#include <OmegaSupreme.h>
#include "WPILib.h"
#include "Commands/Command.h"

#include "Commands/Autonomous/Scripting.h"

#include "CommandBase.h"
#include "RobotMap.h"
#include <stdio.h>

#include "Commands/Autonomous/Autonomous.h"

OmegaSupreme::OmegaSupreme() {
	PIDChange = 0;
	lw = NULL;
	autonomousCommand = NULL;
	chooser = NULL;
}

OmegaSupreme::~OmegaSupreme() {
	delete autonomousCommand;
	delete chooser;
}

void OmegaSupreme::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	// Create autonomous
	/*chooser = new SendableChooser();
	chooser->AddDefault("Blank", new Autonomous());
	chooser->AddObject("Drive forward 1000 ticks",
			Autonomous::createDriveDistance(360.0f, BestDrive::forward));
	chooser->AddObject("Drive forward 1 second",
			Autonomous::createDriveDuration(1.0f, -90.0f));
	chooser->AddObject("Turn 90 degrees", Autonomous::createTurnTo(90.0));*/

	chooser = Scripting::generateAutonomousModes(AUTO_SCRIPT_LOCATIONS);
	SmartDashboard::PutData("Auto Modes", chooser);

	CommandBase::oi->registerButtonListeners();

	if (CommandBase::driveBae != NULL) {
		SmartDashboard::PutData("Zero yaw", new ZeroGyro);
		bool zeroed = false;
		double initialTime = GetFPGATime();
		while (!zeroed) {
			bool isCalibrating =
					CommandBase::driveBae->getGyro()->IsCalibrating();
			if (!isCalibrating || GetFPGATime() - initialTime > GYRO_TIMEOUT) {
				Wait(0.2);
				CommandBase::driveBae->getGyro()->ZeroYaw();
				CommandBase::driveBae->startRotPID(); // enable the pid. May want to move this
				zeroed = true;
			}
		}
	}
//	SmartDashboard::PutNumber("realEncoder:",
//			CommandBase::toteLifterino->getEncoder()->GetDistance());
}

void OmegaSupreme::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	((ScriptRunner*) chooser->GetSelected())->startCommand();

	autonomousCommand = (Command *) chooser->GetSelected();
	autonomousCommand->Start();
	/*
	 float startingOffset = SmartDashboard::GetNumber("Auto angle offset", 0.0);
	 CommandBase::driveBae->getGyro()->SetYawPitchRoll(startingOffset, 0.0f,
	 0.0f, 0.0f);
	 */
}

void OmegaSupreme::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	WatchDogg();
}

void OmegaSupreme::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	SmartDashboard::PutNumber("motorLEFTCurrentOMG",
			CommandBase::toteLifterino->getLeftMotor()->GetOutputCurrent());
	SmartDashboard::PutNumber("motorRIGHTCurrentOMG",
			CommandBase::toteLifterino->getRightMotor()->GetOutputCurrent());
	CommandBase::canCollecterino->getDatStatus();
	SmartDashboard::PutNumber("intakeEncoder", CommandBase::toteIntakerino->getEncoder()->Get());
	WatchDogg();
}

void OmegaSupreme::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void OmegaSupreme::TestPeriodic() {
	lw->Run();
}

void OmegaSupreme::WatchDogg() {
// there are now doggs to watch
// lmao XDDD
	/*if (CommandBase::stackPusher->getValue()
	 == DoubleSolenoid::kForward&& CommandBase::canCollecterino->getArmPID()->GetSetpoint() == CAN_POT_UP_POSITION) {
	 CommandBase::canCollecterino->disableArms();
	 }
	 if (CommandBase::toteIntakerino->isLoaded()
	 && (CommandBase::toteLifterino->getPID()->GetSetpoint()
	 < TOTE_LIFTER_STACK_HEIGHT
	 && CommandBase::toteLifterino->getEncoder()->Get()
	 >= TOTE_LIFTER_STACK_HEIGHT - 100)) {
	 CommandBase::toteLifterino->enablePID(false);
	 } else if (CommandBase::toteIntakerino->isLoaded()
	 && (CommandBase::toteLifterino->getPID()->GetSetpoint()
	 < TOTE_LIFTER_STACK_HEIGHT)) {
	 CommandBase::toteLifterino->setSetPoints(TOTE_LIFTER_STACK_HEIGHT);
	 }*/
}

START_ROBOT_CLASS(OmegaSupreme);
