// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Descend.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Descend::Descend(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::climber.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Descend::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Descend::Execute() {
	Robot::climber->Set(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool Descend::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Descend::End() {
	Robot::climber->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Descend::Interrupted() {
	Descend::End();
}
