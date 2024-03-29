#include "vex.h"
//#include "robot-config.cpp"

extern vex::motor leftMotorA;
extern vex::motor leftMotorB; 
extern vex::motor_group LeftDriveSmart;
extern vex::motor rightMotorA; 
extern vex::motor rightMotorB;
extern vex::motor_group RightDriveSmart;
extern vex::controller Controller1;
extern vex::pneumatics pneumatic1;
extern vex::pneumatics pneumatic2;
extern vex::smartdrive Drivetrain;

void turn(double degrees){
  Drivetrain.turnFor(degrees, vex::rotationUnits::deg, 300, vex::velocityUnits::rpm, true);
  //Drivetrain.stop(vex::brakeType::brake);
}

void driveForward( double inches ) {
    float inchesPerDegree = 1.6666666666666667 / 360;
    float degrees = inches / inchesPerDegree;

    Drivetrain.driveFor(inches, vex::distanceUnits::in, 300, vex::velocityUnits::rpm);
    
    //turn(540);
    //Drivetrain.drive(vex::directionType::fwd, 300, vex::velocityUnits::rpm);

    /*
    // startRotate doesn't wait for completion
    // this way, the other wheel can turn at same time
    leftMotorA.startRotateFor(
        degrees * 1.6666666666666667, vex::rotationUnits::deg, 
        80, vex::velocityUnits::pct
    );
    leftMotorB.startRotateFor(
        degrees * 1.6666666666666667, vex::rotationUnits::deg,
        80, vex::velocityUnits::pct
    );
    rightMotorA.startRotateFor(
        degrees * 1.6666666666666667, vex::rotationUnits::deg, 
        80, vex::velocityUnits::pct
    );
    rightMotorB.startRotateFor(
        degrees * 1.6666666666666667, vex::rotationUnits::deg,
        80, vex::velocityUnits::pct
    );*/
}

