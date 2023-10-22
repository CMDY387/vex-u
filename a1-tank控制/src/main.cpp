/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       CMDY                                                      */
/*    Created:      10/21/2023, 9:43:02 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
    int deadband = 5;
    double x=0.5;
    vex::motor Leftmotor1(16);
    vex::motor Leftmotor2(17);
    vex::motor Rightmotor1(18);
    vex::motor Rightmotor2(19);
    vex::controller Controller1(primary);
    Brain.Screen.printAt( 10, 50, "Hello V5" );
   // blank();
    while(1) 
    {
      int leftMotorSpeed = Controller1.Axis3.position();
      int rightMotorSpeed = Controller1.Axis2.position(); 
      if (abs(leftMotorSpeed) < deadband) 
      {
       Leftmotor1.setVelocity(0, percent);
       Leftmotor2.setVelocity(0, percent);
        //Leftmotor1.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
        //Leftmotor2.spin(vex::directionType::fwd, 0, vex::velocityUnits::pct);
      } else {
       Leftmotor1.setVelocity(-leftMotorSpeed*x, percent);
       Leftmotor2.setVelocity(-leftMotorSpeed*x, percent);
        //Leftmotor1.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
        //Leftmotor2.spin(vex::directionType::fwd, leftMotorSpeed, vex::velocityUnits::pct);
      }
      if (abs(rightMotorSpeed) < deadband) {
      Rightmotor1.setVelocity(0, percent);
      Rightmotor2.setVelocity(0, percent);
      } else {
      Rightmotor1.setVelocity(rightMotorSpeed*x, percent);
      Rightmotor2.setVelocity(rightMotorSpeed*x, percent);
      }  
        Leftmotor1.spin(forward);
        Leftmotor2.spin(forward);
        Rightmotor1.spin(forward);
        Rightmotor2.spin(forward);
         wait(25, msec);  
        //this_thread::sleep_for(10);
    }
}
//void blank(void)
//{}