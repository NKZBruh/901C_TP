using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern motor BackLift;
extern motor RingIntake;
extern motor_group Lift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );