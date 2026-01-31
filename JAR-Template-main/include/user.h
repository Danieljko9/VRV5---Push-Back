#include "tools.h"
using namespace vex;

void runUser(){
//buttons with functions
Controller1.ButtonUp.pressed(toggleFront); //switch front
Controller1.ButtonR1.pressed(togglePneumo); //arm
Controller1.ButtonL1.pressed(toggleFloss); //front thing

Intake3.setVelocity(100,percent);
Intake4.setVelocity(100,percent);

//initializes on intake
int leftVel = 0;
int rightVel = 0;
float spe = 2;
float side = 1.5;
int hood = -1;
int intaket = 1;
int R = 1;
int L = 1;

//initializes motors
// Hood.setVelocity(hood*100,percent);
// Hood.spin(forward);
// IntakeT.setVelocity(intaket*100,percent);
// IntakeT.spin(forward);
// IntakeM.setVelocity(100,percent);
// IntakeM.spin(forward);
// IntakeB.setVelocity(100,percent);
// IntakeB.spin(forward);

LeftDriveSmart.setMaxTorque(100, percent);
RightDriveSmart.setMaxTorque(100, percent);
RightDriveSmart.setVelocity(rightVel, percent);
LeftDriveSmart.setVelocity(leftVel, percent);
RightDriveSmart.setStopping(coast);
LeftDriveSmart.setStopping(coast);
RightDriveSmart.spin(fwd);
LeftDriveSmart.spin(fwd);

//clear screen
Controller1.Screen.clearScreen();

while(true){

 //pneumatics
 if(doPneumo){
   ArmClose.set(true);
   ArmOpen.set(false);
 }
 else{
   ArmOpen.set(true);
   ArmClose.set(false);
 }

//Long goal
  if(Controller1.ButtonA.pressing()){
   hood = 1;
   intaket = 1;
    R = 1;
    L = -1;
  }

//Center middle
  if(Controller1.ButtonB.pressing()){
    hood = 0;
    intaket = -1;
    R = 1;
    L = -1;
    }

//Load
    if(Controller1.ButtonX.pressing()){
     hood = -1;
     intaket = 1;
     R = 1;
     L = 0;
     }

//change intake direction
if(Controller1.ButtonY.pressing()){
  R = -1;
  L = 1;
}

if(Controller1.ButtonL2.pressing()){
  spe = 0.67;
  side = 1;
}
if(Controller1.ButtonR2.pressing()){
  spe = 2;
  side = 1.5;
}

//turn on intake
if (Controller1.ButtonA.pressing()||Controller1.ButtonB.pressing()||Controller1.ButtonX.pressing()||Controller1.ButtonY.pressing()){ //long goal
  Hood.spin(forward,R*hood*100,percent);
  Decider.spin(forward,R*intaket*100,percent);
  Intake1.spin(forward,R*100,percent);
  Intake2.spin(forward,R*100,percent);
  Intake3.spin(forward,R*100,percent);
  Intake1.spin(forward,R*100,percent);
  Intake4.spin(forward,L*100,percent);

}
else{
  Hood.stop();
  Decider.stop();
  Intake1.stop();
  Intake2.stop();
  Intake3.stop();
  Intake4.stop();
}

//  if(doIntake){
//   Hood.setVelocity(R*hood*100,percent);
//   IntakeT.setVelocity(R*intaket*100,percent);
//   IntakeM.setVelocity(R*100,percent);
//   IntakeB.setVelocity(R*100,percent);
//  }

//  else{
//   Hood.setVelocity(0,percent);
//   IntakeT.setVelocity(0,percent);
//   IntakeM.setVelocity(0,percent);
//   IntakeB.setVelocity(0,percent);
//  }

//tongue mech/loader mech/floss mech?
 if(doFloss){
  FlossClose.set(false);
  FlossOpen.set(true);
 }
 else{
  FlossClose.set(true);
  FlossOpen.set(false);
 }

  Controller1.Screen.setCursor(1,1);

 //set direction to reverse
 if(!doFront){
   leftVel = Controller1.Axis3.position() + ((Controller1.Axis1.position()));
   rightVel = Controller1.Axis3.position() - ((Controller1.Axis1.position()));
   LeftDriveSmart.setVelocity(leftVel, percent);
   RightDriveSmart.setVelocity(rightVel, percent);
 }

   //set direction to normal
 if(doFront){
     leftVel = Controller1.Axis3.position() - ((Controller1.Axis1.position()/side));
     rightVel = Controller1.Axis3.position() + ((Controller1.Axis1.position()/side)); 
     LeftDriveSmart.setVelocity(-1*leftVel, percent);
     RightDriveSmart.setVelocity(-1*rightVel, percent);
   }
 }
}