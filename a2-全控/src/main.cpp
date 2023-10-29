/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       CMDY                                                      */
/*    Created:      10/28/2023, 8:34:46 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
    vex::motor ClawMotor(9);
    vex::motor ClawMotor2(19);
    vex::motor ArmMotor(2);
    vex::motor ArmMotor2(12);
    vex::motor Leftmotor1(0);
    vex::motor Leftmotor2(4);
    vex::motor Rightmotor1(10);
    vex::motor Rightmotor2(14);
    vex::controller Controller1(primary);
void whenControllerR1Pressed() {
  ArmMotor.spin(reverse);
  ArmMotor2.spin(forward);
  waitUntil(!Controller1.ButtonR1.pressing());
  ArmMotor.stop();
  ArmMotor2.stop();
}

void whenControllerR2Pressed() {
  ArmMotor.spin(forward);
  ArmMotor2.spin(reverse);
  waitUntil(!Controller1.ButtonR2.pressing());
  ArmMotor.stop();
  ArmMotor2.stop();
}


int main() {
  double x=0.3;
  double y=0.5;
  int a=1;
  int b=1;
    Brain.Screen.printAt( 10, 50, "Hello V5" );
    ArmMotor.setStopping(hold);
    ArmMotor2.setStopping(hold);
    ClawMotor.setStopping(hold);
    ClawMotor2.setStopping(hold);
    ArmMotor.setVelocity(30, percent);
    ArmMotor2.setVelocity(30, percent);
    ClawMotor.setVelocity(90, percent);
    ClawMotor2.setVelocity(60, percent);
    Controller1.ButtonR1.pressed(whenControllerR1Pressed);
    Controller1.ButtonR2.pressed(whenControllerR2Pressed);
    while(1) {
      int V = Controller1.Axis3.position();
      int Vr= Controller1.Axis1.position(); 
      int v1=(V+Vr*y)*x;
      int v2=(V-Vr*y)*x;
      Leftmotor1.setVelocity(v1, percent);
      Leftmotor2.setVelocity(v1, percent);
      Rightmotor1.setVelocity(v2, percent);
      Rightmotor2.setVelocity(v2, percent);
        Leftmotor1.spin(reverse);
        Leftmotor2.spin(reverse);
        Rightmotor1.spin(forward);
        Rightmotor2.spin(forward);
  if (Controller1.ButtonX.pressing()) {
      ClawMotor.spin(reverse);
   }
    if (Controller1.ButtonY.pressing()) {
      ClawMotor.stop();
      }
    if (Controller1.ButtonA.pressing()) {
      ClawMotor2.spin(reverse);
      }
    if (Controller1.ButtonB.pressing()) {
      ClawMotor2.stop();
      }
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
