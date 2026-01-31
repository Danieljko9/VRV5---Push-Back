using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:

// Robot configuration code.
extern controller Controller1;
extern digital_out ArmOpen;
extern digital_out ArmClose;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor_group LeftDriveSmart;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor_group RightDriveSmart;
extern inertial DrivetrainInertial;
extern smartdrive Drivetrain;

extern motor Hood;

extern motor Intake3;

extern motor Intake2;

extern digital_out FlossClose;
extern digital_out FlossOpen;
extern inertial Inertial17;

extern rotation Rotation20;

extern motor Decider;

extern motor Intake1;

extern motor Intake4;

extern optical Optical1;

void  vexcodeInit( void );