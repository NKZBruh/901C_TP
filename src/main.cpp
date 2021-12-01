/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 5, 9, 7, 1   
// Lift                 motor_group   10, 11          
// BackLift             motor         20              
// RingIntake           motor         19              
// Controller1          controller  
// Pneumatic1           pneumatic     A
// Pneumatic2           pneumatic     B
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void make_button(int x, int y, int tx, int ty, char* title, vex::color c, int w = 80, int h = 40) {
    Brain.Screen.drawRectangle(x,y,w,h,c);
    Brain.Screen.setFillColor(c);
    Brain.Screen.printAt(x+tx,y+ty,title);
}

bool is_clicked(int bx, int by, int w = 80, int h = 40) {
    int x = Brain.Screen.xPosition();
    int y = Brain.Screen.yPosition();
    int rx = x - bx;
    int ry = y - by;
    return rx >  0 && rx < w && ry >  0 && ry < h;
}

// global variable
bool isBuleSide = false; // true = blue
bool isFarField = false; // true = far field
bool isAutoEnable = true; // true = enable

void disabled(){
    while (!Competition.isEnabled()) {
        Brain.Screen.setFillColor(color::black);
        Brain.Screen.printAt(10,45,"Color:");
        Brain.Screen.printAt(10,95,"Side:");
        Brain.Screen.printAt(50,140,"Skip auton");
        if (isBuleSide) {
            make_button(80,20,25,27,(char*)"RED",color::red);
        } 
        
        else {
            make_button(80,20,20,27,(char*)"BLUE",color::blue);
        }
        if (isFarField) {
            make_button(80,70,25,27,(char*)"LEFT",color::orange);
        } 
        
        else {
            make_button(80,70,20,27,(char*)"RIGHT",color::purple);
        }
        if (isAutoEnable) {
            make_button(10,120,15,15,(char*)"",color::black,30,30);
        } 
        
        else {
            make_button(10,120,15,15,(char*)"",color::green,30,30);
            Brain.Screen.setFillColor(color::white);
            Brain.Screen.drawLine(80,20,160,60);
            Brain.Screen.drawLine(80,70,160,110);
        }
        while (!Brain.Screen.pressing() && !Competition.isEnabled()) task::sleep(50);
        while (Brain.Screen.pressing() && !Competition.isEnabled()) task::sleep(50);
        if (Competition.isEnabled()) break;
        
        if (is_clicked(10,120,120)) {
          
            isAutoEnable = !isAutoEnable;
        }else if (is_clicked(80,20) && isAutoEnable) {
            isBuleSide = !isBuleSide;
        } else if (is_clicked(80,70) && isAutoEnable) {
            isFarField = !isFarField;
        }
    }
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    // wait(100, msec);
    while(Competition.isEnabled()) vex::task::sleep(50);
        disabled();
        Brain.Screen.clearScreen();
  }
}
