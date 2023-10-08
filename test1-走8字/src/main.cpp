/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       CMDY                                                      */
/*    Created:      9/27/2023, 7:59:20 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
#define d 440//车宽
#define r 50//轮半径
#define m 1//初始值
int main()
{
    vex::motor motor1(0);
    vex::motor motor2(9);
    int R = 500;//转弯半径
    int w = m;//角速度
    int x = 4//降速;
    double v1, v2;
    double t;
    //t=2*R/((w*R+(w+a*b)*R)*(b+1)/2);
    t=2*R/(w*R)*x/1.345;
            v1 = (w * R + w * d / 2) * 60 / x / r;
            v2 = (w * R - w * d / 2) * 60 / x / r;
            motor1.spin(vex::directionType::fwd, v1, vex::velocityUnits::rpm);
            motor2.spin(vex::directionType::rev, v2, vex::velocityUnits::rpm);
            vex::task::sleep(t*1000);
            v1 = (w * R - w * d / 2) * 60 / x / r;
            v2 = (w * R + w * d / 2) * 60 / x / r;
            motor1.spin(vex::directionType::fwd, v1 , vex::velocityUnits::rpm);
            motor2.spin(vex::directionType::rev, v2 , vex::velocityUnits::rpm);
            vex::task::sleep(t*1000);
            motor1.spin(vex::directionType::fwd, 0, vex::velocityUnits::rpm);
            motor2.spin(vex::directionType::rev,0, vex::velocityUnits::rpm);
    
   

    return 0;
}

//rev反向

















