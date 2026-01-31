#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:

// Robot configuration code.
controller Controller1 = controller(primary);
digital_out ArmOpen = digital_out(Brain.ThreeWirePort.F);
digital_out ArmClose = digital_out(Brain.ThreeWirePort.E);
motor leftMotorA = motor(PORT12, ratio18_1, true);
motor leftMotorB = motor(PORT14, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT18, ratio18_1, false);
motor rightMotorB = motor(PORT19, ratio18_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial DrivetrainInertial = inertial(PORT6);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 319.19, 320, 40, mm, 0.8333333333333334);

motor Hood = motor(PORT8, ratio18_1, false);

motor Intake3 = motor(PORT3, ratio18_1, false);

motor Intake2 = motor(PORT10, ratio18_1, false);

digital_out FlossClose = digital_out(Brain.ThreeWirePort.C);
digital_out FlossOpen = digital_out(Brain.ThreeWirePort.D);
inertial Inertial17 = inertial(PORT17);

rotation Rotation20 = rotation(PORT20, false);

motor Decider = motor(PORT9, ratio18_1, false);

motor Intake1 = motor(PORT5, ratio18_1, true);

motor Intake4 = motor(PORT15, ratio18_1, true);

optical Optical1 = optical(PORT1);

void vexcodeInit( void ) {
  // nothing to initialize
}