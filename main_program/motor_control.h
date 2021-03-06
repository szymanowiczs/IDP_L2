#ifndef motor_control_h
#define motor_control_h

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

class RobotMotor {
public:
	//Initialises motor shield
	void start();

};

class RobotServo : public RobotMotor {
public:
	//Sets how many degrees the servo should turn
	void subtendAngle(int degrees);

	//Sets speed of servo in RPM
	void setServoSpeed(int speed);
};

class DCMotor : public RobotMotor {
	//Motors are referred to as left and right ('l', 'r') not 1 and 2
public:
  //To keep track of speeds in order to adjust them
  int currentL;
  int currentR;

	//Sets which motors are connected to which pins
	void setMotors(int mL, int mR);

	//Sets the speed of each motor (1-250)
	void setMotorSpeed(int mL, int mR);

	//Changes motor speeds to update path of robot (+ve for right -ve for left)
	void adjustSpeed(int diff);

	//Sets motor (L or R) to run (true) or stop (false)
	void runMotor(bool boo, char motor);

	//Tells robot to turn left ('l') or right ('r') or 180 degrees ('o')
	void turn(char dir);

  /********TRIAL**********/
  void giveNudge(char dir);
};



#endif
