/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       CMDY                                                      */
/*    Created:      11/17/2023, 8:06:43 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here
vex::motor ClawMotor(9);
vex::motor ClawMotor2(19);
vex::motor ArmMotor(2);
vex::motor ArmMotor2(12);
vex::motor Leftmotor1(0,true);
vex::motor Leftmotor2(4,true);
vex::motor Rightmotor1(10,false);
vex::motor Rightmotor2(14,false);
motor_group LeftMotorGroup = motor_group(Leftmotor1, Leftmotor2);
motor_group RightMotorGroup = motor_group(Rightmotor1, Rightmotor2);
//gps GPS8 = gps(20, 0.00, -240.00, mm, 180);
drivetrain Drivetrain = drivetrain(LeftMotorGroup, RightMotorGroup, 319.19, 295, 40, mm, 1);
//数据从左往右依次为车轮周长，轮距，前后轴距，单位，传动比
bumper BumperA = bumper(Brain.ThreeWirePort.A);//保险杠，也许可以检测碰撞,示例BumperA.pressed(next);
vex::controller Controller1(primary);

double a=1.7;
int b=1;
void plus()
{
  a++;

}
void pluss()
{
  b++;
}

void movingto(void)
{
  Drivetrain.setDriveVelocity(20*a, percent);//设定速度
  Drivetrain.driveFor(-950,mm);
  wait(0.1, seconds);
  Drivetrain.setTurnVelocity(20*a, percent);
  Drivetrain.turnFor(left, 95, degrees);
  wait(0.1, seconds);
  Drivetrain.driveFor(70,mm);
  Drivetrain.stop();//setStopping brake
}
void movingback(void)
{
  Drivetrain.setDriveVelocity(20*a, percent);//设定速度
  Drivetrain.driveFor(-70,mm);
  wait(0.1, seconds);
  Drivetrain.setTurnVelocity(20*a, percent);
  Drivetrain.turnFor(right, 95, degrees);
  wait(0.1, seconds);
  Drivetrain.driveFor(950,mm);
  Drivetrain.stop();//setStopping brake
}
void next(void)
{
    wait(5, msec);
    Drivetrain.turnFor(left, 80, degrees);
    wait(0.1, seconds);
        Drivetrain.driveFor(120,mm);
        wait(0.1, seconds);
    Drivetrain.turnFor(left, 20, degrees);
    wait(0.1, seconds);
    Drivetrain.driveFor(1700,mm);
    //Drivetrain.setDriveVelocity(-5, percent);
    wait(0.1, seconds);
    Drivetrain.driveFor(-10,mm);
    wait(0.1, seconds);
    Drivetrain.turnFor(left, 95, degrees);
    wait(0.1, seconds);

    Drivetrain.driveFor(100,mm);
Drivetrain.stop();
    
}
void test()
{
      repeat(4)
    {
     movingto();
     wait(5, msec);
     movingback();
     wait(5, msec);
    }
}
int main() {
  
    Brain.Screen.printAt( 10, 50, "Hello V5" );
    Controller1.ButtonX.pressed(movingback);
    Controller1.ButtonA.pressed(movingto);
    Controller1.ButtonB.pressed(next);

    //next()

    /*while(1) {
    repeat(4)
    {
     movingto();
     wait(5, msec);
     movingback();
     wait(5, msec);
    }
    repeat(2)
    {
      wait(0.1, seconds);
      Drivetrain.driveFor(200,mm);
      Drivetrain.driveFor(-200,mm);
    }
    }*/
}
