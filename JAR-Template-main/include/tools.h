#include "vex.h"
using namespace vex;

void setup(){
 Brain.Screen.clearScreen();
 Brain.Screen.setCursor(1,1);
}

// Begin project code
float Rd = 7.3;
float D = 4;
int r = -1;
int t = 0;

// Booleaens for Functions
bool doIntake = false;
bool doRIntake = false;
bool doBackIntake = false;
bool doPneumo = false;
bool doFloss = false;
bool doLong = false;
bool doCMid = false;
bool doHopper = false;
bool doFront = false;
bool allHelper = false;
bool front = false;
//add a boolean to add doHelper functions
int direction = 1;


bool setAllHelper(){ //add an or statement for new function
 return doFront; //|| doHelper2;
}

void toggleFront(){
 doFront = !doFront;
 allHelper = setAllHelper();
}

void togglePneumo(){
 doPneumo = !doPneumo;
}

void toggleIntake(){
 doIntake = !doIntake;
}

void toggleRIntake(){
 doRIntake = !doRIntake;
}

void toggleBackIntake(){
 doBackIntake = !doBackIntake;
}

void toggleFloss(){
 doFloss = !doFloss;
}

void toggleLong(){
 doLong = !doLong;
 doCMid = false;
 doHopper = false;
}

void toggleCMid(){
 doCMid = !doCMid;
 doLong = false;
 doHopper = false;
}

void toggleHopper(){
 doHopper = !doHopper;
 doLong = false;
 doCMid = false;
}

//add new toggle function

void drive(float lv, float rv, float x){
 LeftDriveSmart.setVelocity(lv,percent);
 RightDriveSmart.setVelocity(rv,percent);
 RightDriveSmart.spin(forward);
 LeftDriveSmart.spin(forward);
}

void driveBrake(){
 LeftDriveSmart.stop();
 RightDriveSmart.stop();
}

 void inchTurn(float target, float v){
  leftMotorA.setPosition(0, rev);
 float deg = 0.0;
 float error = target - deg;
 float speed = v;
 float accuracy = 2;
  deg = leftMotorA.position(rev)*(D*360)/Rd;
Brain.Screen.printAt(1, 40, "inchTurn start=  %.3f  ",deg);
 while(fabs(error) > accuracy){
   if(!allHelper) return;
   drive(speed*fabs(error)/error, -speed*fabs(error)/error, 10);
   deg = leftMotorA.position(rev)*(D*360)/Rd;
   error = target-deg;
 }
 driveBrake();
  deg = leftMotorA.position(rev)*(D*360)/Rd;
  Brain.Screen.printAt(1, 60, "inchTurn complete=  %.3f  ",deg);
}

void inchDrive(float target, float v) {
 Brain.Screen.printAt(1, 20, "Inch Drive Start");
 float G = 1;
 float x = 0.0;
 //distance to desired position is equal to target minus motor position
 float error = target - x;
 float speed = v;
 float accuracy = 0.2;
 float ks = 1.0;
 float yaw = 0.0;
 float lspeed = speed * fabs(error) / error + ks * yaw;
 float rspeed = speed * fabs(error) / error + ks * yaw;


 leftMotorA.setPosition(0.0, deg);
 leftMotorA.setPosition(0, rev);
 while (fabs(error) > accuracy) {
//if a function is active, stop loop
  if(!allHelper) return;
   drive(lspeed, rspeed, 10);
//motor position = # of revolutions times perimeter of wheel
   x = leftMotorA.position(rev) * 3.1415926 * D * G;
   //distance to desired position is equal to target minus motor position
   error = target - x;
   yaw = leftMotorA.position(rev) - rightMotorA.position(rev);
   lspeed = speed * fabs(error) / error + ks * yaw;
   rspeed = speed * fabs(error) / error + ks * yaw;
 }
 driveBrake();
}

//add a function that sets the allhelper and dohelper_ to false

//turns off intake
void istop(){
}

//turns on intake
void intake(){
}