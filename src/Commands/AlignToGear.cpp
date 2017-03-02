// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AlignToGear.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AlignToGear::AlignToGear(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::visionHandler.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::arduinoComm.get());
	Requires(Robot::drivetrain.get());
	isFinished = false;
	//visionTable = NetworkTable::GetTable("vision");
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AlignToGear::Initialize() {
	Robot::visionHandler->setMode(VisionHandler::Mode::kGear);
	Robot::arduinoComm->WriteTest("Oc");
	previousValue = Robot::arduinoComm->GetAngle();
}

// Called repeatedly when this Command is scheduled to run
void AlignToGear::Execute() {
	isFinished=false;
	Robot::arduinoComm->ReadData();
	//double CV = visionTable->GetNumber("gearCV",-999);
	std::cout << "angle: " << Robot::arduinoComm->GetAngle() << std::endl;
	if(Robot::arduinoComm->GetAngle() != -999 && std::fabs(Robot::arduinoComm->GetAngle() - previousValue) < 10) {
		if(Robot::arduinoComm->GetAngle() > 5){
			double turnVal = (Robot::arduinoComm->GetAngle() - 2) * 0.1; //  scales the values down as we get closer.
			if (turnVal > 0.4){
				Robot::drivetrain->Turn(-0.4);
			} else {
				Robot::drivetrain->Turn(-turnVal);
			}
		} else if(Robot::arduinoComm->GetAngle() < -5){
			double turnVal = (Robot::arduinoComm->GetAngle() + 2) * 0.1; //  scales the values down as we get closer.
			if (turnVal < -0.4){
				Robot::drivetrain->Turn(0.4);
			} else {
				Robot::drivetrain->Turn(-turnVal);
			}
		} else {
			Robot::visionHandler->readGearValues();
			VisionData = Robot::visionHandler->getCurrentTuple();
			std::cout << "lateral: " << VisionData->getGearCenter() << std::endl;
			if(VisionData->getGearCenter() != -999) {
				if(VisionData->getGearCenter() > 1.5 && Robot::arduinoComm->GetDistance() > 36){
					double val = (VisionData->getGearCenter() - .25) * 0.3; //  scales the values down as we get closer.
					if (val > 0.7){
						Robot::drivetrain->Strafe(0.7);
					} else {
						Robot::drivetrain->Strafe(val);
					}
				} else if(VisionData->getGearCenter() < -1.5 && Robot::arduinoComm->GetDistance() > 36){
					double val = (VisionData->getGearCenter() + .25) * 0.3; //  scales the values down as we get closer.
					if (val < -0.7){
						Robot::drivetrain->Strafe(-0.7);
					} else {
						Robot::drivetrain->Strafe(val);
					}
				} else {
					std::cout << "distance: " << Robot::arduinoComm->GetDistance() << std::endl;
					if(Robot::arduinoComm->GetDistance() > 9){
					Robot::drivetrain->Forward(0.6);
					} else {
					isFinished=true;
					}
				}
			}
		}
	}
	previousValue = Robot::arduinoComm->GetAngle();
}

// Make this return true when this Command no longer needs to run execute()
bool AlignToGear::IsFinished() {
    return isFinished;
}

// Called once after isFinished returns true
void AlignToGear::End() {
	Robot::drivetrain->Stop();
	Robot::arduinoComm->WriteTest("w");
	if (Robot::allianceColor == DriverStation::Alliance::kBlue){
		Robot::arduinoComm->WriteTest("B"); // Will use color blue for animations on LEDS.
	} else if (Robot::allianceColor == DriverStation::Alliance::kRed) {
		Robot::arduinoComm->WriteTest("R"); // Will use red color.
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignToGear::Interrupted() {
	AlignToGear::End();
}
