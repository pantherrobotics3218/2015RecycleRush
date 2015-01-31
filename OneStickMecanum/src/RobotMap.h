#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

// DriveBase
#define DRIVE_MOTOR_TYPE CANTalon
#define DRIVE_MOTOR_FRONT_LEFT 10
#define DRIVE_MOTOR_FRONT_RIGHT 20
#define DRIVE_MOTOR_BACK_LEFT 3
#define DRIVE_MOTOR_BACK_RIGHT 2

// Mecanum
#define ONE_STICK false
#define FIELD_ORIENTED true
#define JOYSTICK_DEGREES_PER_TICK -.5 // max 1
#define MECANUM_CORRECTION_INTENSITY .01
#define MECANUM_CORRECTION_THRESHOLD 2.0

// Stack pusher
#define PUSHER_RIGHT 0
#define PUSHER_LEFT 1

// Pneumatics
#define COMPRESSOR_PRESSURE_SENSOR 0
#define COMPRESSOR_RELAY 0

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
#define OI_JOYSTICK_ROT_DEADBAND (0.1)
#define OI_PUSH_STACK_BUTTON (3)

#endif
