// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AlignToBoiler.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AlignToBoiler::AlignToBoiler(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.getBoiler());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::visionHandler.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain.get());
	targetdistance = 120;
	VisionData = Robot::visionHandler->getCurrentTuple();
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AlignToBoiler::Initialize() {
	Robot::visionHandler->setMode(VisionHandler::Mode::kGear);
}

// Called repeatedly when this Command is scheduled to run
void AlignToBoiler::Execute() {
	isFinished=false;
	Robot::visionHandler->readBoilerValues();
		if(VisionData->getBoilerAngle() > 5){
			Robot::drivetrain->Turn(0.5);
		} else if(VisionData->getBoilerAngle() < -5){
			Robot::drivetrain->Turn(-0.5);
	    } else if(VisionData->getBoilerDistance() < targetdistance-4){
			Robot::drivetrain->Forward(-0.5);
		}  else if(VisionData->getBoilerDistance() > targetdistance+4){
			Robot::drivetrain->Forward(0.5);
		} else {
			isFinished=true;
		}
}

// Make this return true when this Command no longer needs to run execute()
bool AlignToBoiler::IsFinished() {
    return isFinished;
}

// Called once after isFinished returns true
void AlignToBoiler::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignToBoiler::Interrupted() {
	AlignToBoiler::End();
}
