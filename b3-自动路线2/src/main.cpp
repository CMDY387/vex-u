/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       CMDY                                                      */
/*    Created:      12/14/2023, 3:38:56 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::inertial IN(19);
vex::distance DIS(20);
vex::brain Brain;
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
drivetrain Drivetrain = drivetrain(LeftMotorGroup, RightMotorGroup, 319.19, 295, 40, mm, 1);
vex::controller Controller1(primary);
// define your global instances of motors and other devices here
void a1(){
//第一部分
Drivetrain.setDriveVelocity(30, percent);
Drivetrain.driveFor(1000,mm);
wait(0.1, seconds);    
Drivetrain.turnFor(left, 60, degrees);
wait(0.1, seconds);
                   //展开
Drivetrain.setDriveVelocity(20, percent);
Drivetrain.driveFor(-400,mm);//定时后停止，防止卡死
wait(0.1, seconds);
Drivetrain.driveFor(500,mm);//多退，防止撞杆和干扰
wait(0.1, seconds);    
Drivetrain.turnFor(right, 60, degrees);
wait(0.1, seconds);
Drivetrain.setDriveVelocity(30, percent);
Drivetrain.driveFor(-1000,mm);//少走，留出空间转向
wait(0.1, seconds);
//第二部分
 Drivetrain.turnFor(right, 64, degrees);//转90度
wait(0.1, seconds); 
//吸球开动？
Drivetrain.driveFor(1300,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 32, degrees);
wait(0.1, seconds); 
Drivetrain.driveFor(500,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 25, degrees);
wait(0.1, seconds); 
Drivetrain.driveFor(50,mm);
wait(0.1, seconds); 
//第三部分
Drivetrain.driveFor(-50,mm);
wait(0.1, seconds);
Drivetrain.turnFor(right, 32, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(-220,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 66, degrees);
wait(0.1, seconds);
//抬臂吸球
Drivetrain.driveFor(-160,mm);
wait(0.1, seconds); 
//第四部分
Drivetrain.driveFor(100,mm);
wait(0.1, seconds);
Drivetrain.turnFor(right, 132, degrees);//单侧转
wait(0.1, seconds);
//吸球
Drivetrain.driveFor(50,mm);
wait(0.1, seconds);
Drivetrain.driveFor(-50,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 64, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(220,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 32, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(130,mm);
wait(0.1, seconds);
//第五部分
Drivetrain.turnFor(right, 32, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(-700,mm);
wait(0.1, seconds);
Drivetrain.turnFor(right, 32, degrees);
wait(0.1, seconds);
//抬大臂
Drivetrain.driveFor(-400,mm);
wait(0.1, seconds);
}
void a2(){
Drivetrain.driveFor(100,mm);
wait(0.1, seconds);
Drivetrain.turnFor(right, 132, degrees);//单侧转
wait(0.1, seconds);
//吸球
Drivetrain.driveFor(50,mm);
wait(0.1, seconds);
Drivetrain.driveFor(-50,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 64, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(220,mm);
wait(0.1, seconds);
Drivetrain.turnFor(left, 32, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(130,mm);
wait(0.1, seconds);
}
void a3(){
Drivetrain.turnFor(right, 32, degrees);
wait(0.1, seconds);
Drivetrain.driveFor(-700,mm);
wait(0.1, seconds);
Drivetrain.turnFor(right, 32, degrees);
wait(0.1, seconds);
//抬大臂
Drivetrain.driveFor(-400,mm);
wait(0.1, seconds);
}
int main() {

    Brain.Screen.printAt( 10, 50, "Hello 2023" );
    Controller1.ButtonX.pressed(a1);
    Controller1.ButtonA.pressed(a2);
    Controller1.ButtonB.pressed(a3);
    while(1) {
this_thread::sleep_for(10);
}
}
