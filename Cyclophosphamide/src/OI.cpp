#include <Buttons/JoystickButton.h>
#include <Commands/Armerino/Arms/MoveArms.h>
#include <Commands/Armerino/Arms/MoveArmsKnock.h>
#include <Commands/Armerino/Arms/MoveWrist.h>
#include <Commands/Armerino/CollectCan.h>
#include <Commands/Armerino/Craaaw/ActuateCanStabilizer.h>
#include <Commands/Armerino/MoveArmsFancy.h>
#include <Commands/Armerino/TransferCan.h>
#include <Commands/AutoCanGrabber/GrabCenterCan.h>
#include <Commands/Score.h>
#include <Commands/ToteLifting/LiftToHeightVelocity.h>
#include <Commands/ToteLifting/PIDHoldLiftToHeightVelocity.h>
#include <Commands/ToteLifting/SafeLiftToHeight.h>
#include <Commands/ToteLifting/zeroing/ResetElevatorEncoder.h>
#include <Joystick.h>
#include <OI.h>
#include <RobotMap.h>
#include <Subsystems/AutoCanGrabber.h>
#include <string>

#define SAFE_BUTTON(name, cmd) {if (name!=NULL){cmd;}}
#define VIRTUAL_OI false
#define OPERATOR_PORT 2

OI::OI() {
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	op = new Joystick(OPERATOR_PORT);

	// Can getting
	canArms = new JoystickButton(op, 11);
	canCollectFwd = new JoystickButton(op, 13);
	canCollectRvs = new JoystickButton(op, 12);
	canToCraaawTransfer = new JoystickButton(op, 10);
	craaawToggle = new JoystickButton(op, 14);

	// Tote stacking
	loadPos = new JoystickButton(op, 6);
	floorPos = new JoystickButton(op, 5);

	// Scoring
	// TODO tune upper and lower thresholds
	floorLoader = new AnalogRangeIOButton(OPERATOR_PORT, Joystick::kXAxis, 0.5f,
			0.9f);
	carryPos = new AnalogRangeIOButton(OPERATOR_PORT, Joystick::kXAxis, -0.25f,
			0.25f);
	score = new AnalogRangeIOButton(OPERATOR_PORT, Joystick::kXAxis, -1.0f,
			-0.4f);

	// Overrides
	canArmOverrideUp = new JoystickButton(op, 3);
	canArmOverrideDown = new JoystickButton(op, 4);
	wristOverride = new JoystickButton(op, 2);
	toteLifterUp = new JoystickButton(op, 9);
	toteLifterDown = new JoystickButton(op, 15);
	zeroLifter = new JoystickButton(op, 16);

	// Driver buttons
	moveArmsWhackMode = new JoystickButton(joystickLeft, 1);
	toteLifterUpDriver = new JoystickButton(joystickLeft, 5);
	toteLifterDownDriver = new JoystickButton(joystickLeft, 4);
	toggleCanBurgle = new JoystickButton(joystickLeft, 2);
	scoreOverride = new JoystickButton(joystickLeft, 3);
	wristToggleDriver = new JoystickButton(joystickRight, 1);
}

OI::~OI() {
	delete canToCraaawTransfer;
	delete score;
	delete floorLoader;
	delete carryPos;
	delete loadPos;
	delete floorPos;
	delete moveArmsWhackMode;
	delete canArms;
	delete canCollectFwd;
	delete canCollectRvs;
	delete wristOverride;
	delete craaawToggle;
	delete toteLifterUp;
	delete toteLifterDown;
	delete zeroLifter;
	delete canArmOverrideUp;
	delete canArmOverrideDown;
	delete toteLifterUpDriver;
	delete toteLifterDownDriver;
	delete wristToggleDriver;
	delete toggleCanBurgle;
}

Joystick *OI::getJoystickOperator() {
	return op;
}

Joystick *OI::getJoystickLeft() {
	return joystickLeft;
}

Joystick *OI::getJoystickRight() {
	return joystickRight;
}

double OI::getAnalogValue(int input) {
	//find input at port %input%
	//return analog value for that device
	return 0.0;
}

void OI::registerButtonListeners() {
	// Can manipulation
	createSwitch("canArms", canArms, new MoveArmsFancy(MoveArmsFancy::up),
			new MoveArmsFancy(MoveArmsFancy::down));
	createButton("transfer", canToCraaawTransfer, new TransferCan());
	createSwitch("collect Fwd", canCollectFwd,
			new Collect(CAN_GRAB_SPEED, MoveWrist::close),
			new Collect(0, MoveWrist::close));
	createSwitch("collect Rvs", canCollectRvs,
			new Collect(-CAN_GRAB_SPEED, MoveWrist::close),
			new Collect(0, MoveWrist::close));
	createSwitch("toggle craaaw", craaawToggle,
			new ActuateCanStabilizer(ActuateCanStabilizer::open),
			new ActuateCanStabilizer(ActuateCanStabilizer::close));

	// Loading/stacking
	createButton("lifter load", loadPos,
			new SafeLiftToHeight(TOTE_LIFTER_LOAD_HEIGHT));
	createButton("lifter floor", floorPos,
			new SafeLiftToHeight(TOTE_LIFTER_FLOOR_HEIGHT));

	createButton("toggleAutoZone", toggleCanBurgle,
			new GrabCenterCan(AutoCanGrabber::GrabberState::TOGGLE));

	// Scoring
	createButton("floor loader", floorLoader,
			new SafeLiftToHeight(TOTE_LIFTER_ONE_TOTE));
	createButton("score", score, new Score());
	createButton("lifter carry", carryPos,
			new SafeLiftToHeight(TOTE_LIFTER_CARRY_HEIGHT));

	// Overrides
	createSwitch("wrist override", wristOverride,
			new MoveWrist(MoveWrist::close, true),
			new MoveWrist(MoveWrist::open, true));
	createSwitch("lifter up override", toteLifterUp,
			new LiftToHeightVelocity(.5), new LiftToHeightVelocity(0)); // TODO sketchy
	createSwitch("lifter down override", toteLifterDown,
			new LiftToHeightVelocity(-.5), new LiftToHeightVelocity(0));
	createButton("zero lifter", zeroLifter, new ResetElevatorEncoder());
	createButton("arm up override", canArmOverrideUp,
			new MoveArms(CAN_POT_UP_POSITION));
	createButton("arm down override", canArmOverrideDown,
			new MoveArms(CAN_POT_DOWN_POSITION));

	// Special driver buttons
	createButton("whack mode", moveArmsWhackMode, new MoveArmsKnock());
	SAFE_BUTTON(toteLifterUpDriver,
			toteLifterUpDriver->WhileHeld(new PIDHoldLiftToHeightVelocity(.75)));
	SAFE_BUTTON(toteLifterDownDriver,
			toteLifterDownDriver->WhileHeld(
					new PIDHoldLiftToHeightVelocity(-0.75)));
	createButton("Driver toggle wrist", wristToggleDriver,
			new MoveWrist(MoveWrist::toggle));
	createButton("Drive score override", scoreOverride, new Score());
}

void OI::createButton(std::string key, Button *b, Command *c) {
	SAFE_BUTTON(b, b->WhenPressed(c));
#if VIRTUAL_OI
	SmartDashboard::PutData(key, c);
#endif
}

void OI::createSwitch(std::string key, Button *b, Command *on, Command *off) {
	SAFE_BUTTON(b, b->WhenPressed(on));
	SAFE_BUTTON(b, b->WhenReleased(off));
#if VIRTUAL_OI
	SmartDashboard::PutData(key + " ON", on);
	SmartDashboard::PutData(key + " OFF", off);
#endif
}

bool OI::isJoystickButtonPressed(bool isLeft, int val) {
	if (isLeft) {
		return val > 0 && val < joystickLeft->GetButtonCount()
				&& joystickLeft->GetRawButton(val);
	} else {
		return val > 0 && val < joystickRight->GetButtonCount()
				&& joystickRight->GetRawButton(val);
	}
}

