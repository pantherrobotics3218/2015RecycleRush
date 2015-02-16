/*
 * ProtoRobot.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Administrator
 */

#include <Commands/Automatic/TimedDrive.h>
#include <Commands/Drivebase/ZeroGyro.h>
#include <RefactorMe.h>
#include "WPILib.h"
#include "Commands/Command.h"

#include "Commands/Autonomous/Scripting.h"

#include "CommandBase.h"
#include "RobotMap.h"
#include <stdio.h>

#include "Commands/Autonomous/Autonomous.h"

RefactorMeBot::RefactorMeBot() {
	PIDChange = 0;
	lw = NULL;
	autonomousCommand = NULL;
	chooser = NULL;
}

RefactorMeBot::~RefactorMeBot() {
	delete autonomousCommand;
	delete chooser;
}

void RefactorMeBot::RobotInit() {
	CommandBase::init();
	lw = LiveWindow::GetInstance();

	// Create autonomous
	chooser = new SendableChooser();
	chooser->AddDefault("Blank", new Autonomous());
	if (CommandBase::driveBae != NULL) {
		chooser->AddObject("Drive forward 1000 ticks",
				Autonomous::createDriveDistance(360.0f, BestDrive::forward));
		chooser->AddObject("Drive forward 1 second",
				Autonomous::createDriveDuration(1.0f, -90.0f));
		chooser->AddObject("Turn 90 degrees", Autonomous::createTurnTo(90.0));
	}
	SmartDashboard::PutData("Auto Modes", chooser);

	//chooser = Scripting::generateAutonomousModes(AUTO_SCRIPT_LOCATIONS);

	CommandBase::oi->registerButtonListeners();

	if (CommandBase::driveBae != NULL) {
		SmartDashboard::PutData("Zero yaw", new ZeroGyro);
		bool zeroed = false;
		double initialTime = GetFPGATime();
		while (!zeroed) {
			bool isCalibrating = false; //CommandBase::driveBae->getGyro()->IsCalibrating();
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

void RefactorMeBot::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	((ScriptRunner*) chooser->GetSelected())->startCommand();

	//autonomousCommand = (Command *) chooser->GetSelected();
	//autonomousCommand->Start();

	float startingOffset = SmartDashboard::GetNumber("Auto angle offset", 0.0);
	CommandBase::driveBae->getGyro()->SetYawPitchRoll(startingOffset, 0.0f,
			0.0f, 0.0f);
}

void RefactorMeBot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	WatchDogg();
}

void RefactorMeBot::TeleopInit() {
	if (autonomousCommand != NULL) {
		autonomousCommand->Cancel();
	}
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("toteLiferEnc",
			CommandBase::toteLifterino->getEncoder()->Get());
	SmartDashboard::PutNumber("MotorSetPoint",
			CommandBase::toteLifterino->getPID()->GetSetpoint());
	WatchDogg();
}

void RefactorMeBot::DisabledInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TestInit() {
	Scheduler::GetInstance()->RemoveAll();
}

void RefactorMeBot::TestPeriodic() {
	lw->Run();
}

void RefactorMeBot::WatchDogg() {
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

START_ROBOT_CLASS(RefactorMeBot);
