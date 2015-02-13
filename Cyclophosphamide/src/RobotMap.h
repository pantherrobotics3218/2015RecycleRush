#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

#define DOESNT_EXIST 0x420

#define SAFE_INIT(port, thingy) \
	if (port != 0x420) { \
		thingy \
	}

// Autonomous Configuration Settings
#define AUTO_SCRIPT_MAXLENGTH	(256)
#define AUTO_SCRIPT_MAXLINES	(64)
#define AUTO_SCRIPT_COMMAND_MAXLENGTH	(20)
#define AUTO_SCRIPT_LOCATIONS	"/c/automagic/"
#define AUTO_SCRIPT_CHARMASK(a,b) ((((int)a) << 8) | ((int)b))

// C++ changes
#define floaterino float
#define returnerino return

// DriveBase
#define DRIVE_MOTOR_TYPE CANTalon
#define DRIVE_MOTOR_FRONT_LEFT 14
#define DRIVE_MOTOR_FRONT_RIGHT 0
#define DRIVE_MOTOR_BACK_LEFT 15
#define DRIVE_MOTOR_BACK_RIGHT 1
#define DRIVE_ROT_P  3.0
#define DRIVE_ROT_I 0.0
#define DRIVE_ROT_D 5.0
#define DRIVE_DRIVE_P 0.5
#define DRIVE_DRIVE_I 0.0
#define DRIVE_DRIVE_D 0.0
#define DRIVE_ASPECT_RATIO (0.5)
#define DRIVE_TICKS_TO_DISTANCE 420
#define GYRO_TIMEOUT 5000 // milliseconds
#define ENCODER_TICKS_PER_REV 360.0

//Tote Intake
#define TOTE_INTAKE_SENSOR 0
#define TOTE_INTAKE_MOTOR 8
#define TOTE_INTAKE_MOTOR_FULL 0.3 //1000000000.0 // ayy lmao
#define TOTE_INTAKE_MOTOR_NONE 0.0
#define TOTE_INTAKE_P 0.05
#define TOTE_INTAKE_I 0.0
#define TOTE_INTAKE_D 0.0

// Tote Lifter
#define TOTE_LIFTER_LEFT 3
#define TOTE_LIFTER_RIGHT 12
#define TOTE_LIFTER_SENSOR DOESNT_EXIST
#define TOTE_LIFTER_ENCODER_DEADBAND 5000
#define TOTE_LIFTER_ENCODER_CA 0
#define TOTE_LIFTER_ENCODER_CB 1
#define TOTE_LIFTER_ENCODER_REVERSED false
#define TOTE_LIFTER_TOTE_INPUT 6
#define TOTE_LIFTER_TICKS_PER_INCH 1000

#define TOTE_LIFTER_PID_P .05
#define TOTE_LIFTER_PID_I .001
#define TOTE_LIFTER_PID_D 0

#define TOTE_LIFTER_HIGH 10
#define TOTE_LIFTER_MID 5
#define TOTE_LIFTER_LOW 1
#define TOTE_LIFTER_FLOOR 0
#define TOTE_LIFTER_ELEVATOR_TOP_INPUT_PORT 4

#define LIFT_TO_HEIGHT_CONSTANT 1

#define MAX_MOTOR_PORTS 420

// Mecanum
#define ONE_STICK false
#define FIELD_ORIENTED true
#define LOAD_LEFT_ANGLE 30.0
#define LOAD_RIGHT_ANGLE -30.0

// Auto
#define AUTO_DRIVE_SPEED (0.25)
#define AUTO_TURN_SLOW_DOWN (12)
#define AUTO_TURN_SPEED_MIN (0.2)
#define AUTO_TURN_SPEED_MAX (0.5)
#define AUTO_TURN_SPEED_RANGE (AUTO_TURN_SPEED_MAX - AUTO_TURN_SPEED_MIN)
#define AUTO_TURN_GYRO_THRESHOLD (0.25)

// OI
#define OI_JOYSTICK_LEFT (0)
#define OI_JOYSTICK_RIGHT (1)
#define OI_JOYSTICK_DRIVE_DEADBAND (0.05)
#define OI_JOYSTICK_ROT_DEADBAND (0.15)
#define JOYSTICK_DEGREES_PER_TICK 5.0
#define OI_JOYSTICKBUTTON_PUSHBUTTON 1
#define OI_JOYSTICKBUTTON_ACTUATEBUTTON 2
#define OI_JOYSTICKBUTTON_UNACTUATEBUTTON 3
#define OI_JOYSTICKBUTTON_LIFTARMSBUTTON 4
#define OI_JOYSTICKBUTTON_LOWERARMSBUTTON 5
#define OI_JOYSTICKBUTTON_TOTEINTAKE_BUTTON_FORWARD 8
#define OI_JOYSTICKBUTTON_TOTEINTAKE_BUTTON_REVERSE 7
#define OI_JOYSTICKBUTTON_TOTELIFTERBUTTON 6
#define OI_JOYSTICKBUTTON_MOTORFOWARDBUTTON 1
#define OI_JOYSTICKBUTTON_MOTORBACKWARDBUTTON 2
#define OI_JOYSTICKBUTTON_WRISTINBUTTON 3
#define OI_JOYSTICKBUTTON_WRISTOUTNBUTTON 4
#define OI_JOYSTICKBUTTON_ARMSUPBUTTON 5
#define OI_JOYSTICKBUTTON_ARMSDOWNBUTTON 6
#define OI_LOAD_LEFT 11
#define OI_LOAD_RIGHT 12
#define OI_JOYSTICK_STACK 2
#define OI_LINEARPOT_MAX 4.20
#define OI_LINEARPOT_TOTE_LIFTER_OVR_PORT 2

// Can Collector
#define CAN_MOTOR_TYPE CANTalon
#define CAN_MOTOR_LIFT_LEFT DOESNT_EXIST
#define CAN_MOTOR_LIFT_RIGHT DOESNT_EXIST
#define CAN_MOTOR_GRAB_LEFT 0
#define CAN_MOTOR_GRAB_RIGHT 1
#define CAN_WRIST_SOLENOID DOESNT_EXIST, DOESNT_EXIST
#define CAN_MOTOR_WRIST_RIGHT DOESNT_EXIST

#define CAN_SENSOR 0
#define CAN_BRAKE DOESNT_EXIST

#define CAN_POT_LIFT_LEFT DOESNT_EXIST
#define CAN_POT_LIFT_RIGHT DOESNT_EXIST
#define CAN_POT_UP_POSITION 0.9
#define CAN_POT_DOWN_POSITION 0.0
#define CAN_LIFT_THRESHOLD 0.5
#define CAN_UP_SPEED 1.0
#define CAN_DOWN_SPEED -1.0
#define CAN_GRAB_SPEED 0.2

#define CAN_WRIST_THRESHOLD 0.5
#define CAN_WRIST_OPEN_POSITION 1.0
#define CAN_WRIST_CLOSE_POSITION 0.0
#define CAN_WRIST_SPEED 1.0

#define CAN_ARM_P 1.0
#define CAN_ARM_I 1.0
#define CAN_ARM_D 1.0

// Auto Canerino
#define AUTO_CAN_MOTOR_TYPE Talon
#define AUTO_CAN_ARM_ACTUATE DOESNT_EXIST, DOESNT_EXIST
#define AUTO_CAN_WINCH DOESNT_EXIST
#define AUTO_CAN_PAAAT DOESNT_EXIST

#define AUTO_CAN_WENCH_PULL_SPEED 1.0
#define AUTO_CAN_WENCH_SLOW_SPEED 0.2

#define AUTO_CAN_PULL_DIST 420
#define AUTO_CAN_LET_DOWN 420
#define AUTO_CAN_PUT_BACK 420

#define AUTO_CAN_DRIVE_BACK 420

//Downward Dog Craaaw
#define CRAAAW_CAN_DETECTOR 0
#define CRAAAW_LOCK_LEFT 0 // todo figure out what these are
#define CRAAAW_LOCK_RIGHT 1

//stack pusher
#define PUSHER_LEFT 0
#define PUSHER_RIGHT 1

// Pneumatics
#define COMPRESSOR_PRESSURE_SENSOR 61 // 62
#define COMPRESSOR_RELAY 61 // 61

// Stallable Motor
#define STALLABLE_MOVE_THRESHOLD 20000
#define STALLABLE_TIME_STOP 1500

#endif
