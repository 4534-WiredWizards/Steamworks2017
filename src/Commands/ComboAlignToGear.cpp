#include "ComboAlignToGear.h"

ComboAlignToGear::ComboAlignToGear() : Command() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::visionHandler.get());
	Requires(Robot::arduinoComm.get());
	Requires(Robot::drivetrain.get());
	isAngleCorrect = false;
	isLateralCorrect = false;
	isDistanceCorrect = false;
	rotate = 0.0;
	strafe = 0.0;
	forward = 0.0;
}

// Called just before this Command runs the first time
void ComboAlignToGear::Initialize() {
	Robot::arduinoComm->WriteTest("Og");
	//previousValue = Robot::arduinoComm->GetAngle();
}

// Called repeatedly when this Command is scheduled to run
void ComboAlignToGear::Execute() {

	Robot::arduinoComm->ReadData();
	Robot::visionHandler->updateSubsystem();
	VisionData = Robot::visionHandler->getCurrentTuple();

	//rotation
	if (Robot::arduinoComm->GetAngle() == -999) {
		//bad value, aimlessly spin slowly.
		isAngleCorrect = false;
		rotate = 0.3;
	} else if (Robot::arduinoComm->GetAngle() < -5) {
		isAngleCorrect = false;
		rotate = (Robot::arduinoComm->GetAngle() + 2) * -0.1; //  scales the values down as we get closer.
		if (rotate > 0.7) {
			rotate = 0.7; // constrain value to 0.7
		}
	} else if (Robot::arduinoComm->GetAngle() > 5) {
		isAngleCorrect = false;
		rotate = (Robot::arduinoComm->GetAngle() - 2) * -0.1; //  scales the values down as we get closer.
		if (rotate < -0.7) {
			rotate = -0.7; // constrain value to -0.7
		}
	} else {
		isAngleCorrect = true;
		rotate = 0.0;
	}

	//strafing
	if (Robot::arduinoComm->GetDistance() < 36 && Robot::arduinoComm->GetDistance() != -999) {
		// too close, don't trust camera.
		isLateralCorrect = true;
		strafe = 0.0;
	} else if (VisionData->getCenter() == -999) {
		//bad value, hope other movement gets us in view.
		isLateralCorrect = false;
		strafe = 0.0;
	} else if (VisionData->getCenter() < -1.5) {
		isLateralCorrect = false;
		strafe = (VisionData->getCenter() + .25) * 0.3; //  scales the values down as we get closer.
		if (strafe < -0.7) {
			strafe = -0.7; // constrain value to -0.7
		}
	} else if (VisionData->getCenter() > 1.5) {
		isLateralCorrect = false;
		strafe = (VisionData->getCenter() - .25) * 0.3; //  scales the values down as we get closer.
		if (strafe > 0.7) {
			strafe = 0.7; // constrain value to 0.7
		}
	} else {
		isLateralCorrect = true;
		strafe = 0.0;
	}

	//distance
	if (Robot::arduinoComm->GetAngle() == -999) {
		//bad value on angle, wait.
		isDistanceCorrect = false;
		forward = 0.0;
	} else if (Robot::arduinoComm->GetDistance() > 42) {
		isDistanceCorrect = false;
		forward = 0.5;
	} else if (isLateralCorrect && isAngleCorrect && Robot::arduinoComm->GetDistance() > 9) {
		isDistanceCorrect = false;
		forward = Robot::arduinoComm->GetDistance() * .04;
		if (forward > 0.8) {
			forward = 0.8;
		}
	} else if ((!isLateralCorrect || !isAngleCorrect) && Robot::arduinoComm->GetDistance() <= 42) {
		// other data incorrect, back up and fix
		isDistanceCorrect = false;
		forward = -0.4;
	} else {
		isDistanceCorrect = true;
		forward = 0.0;
	}

	Robot::drivetrain->Cartesian(strafe, forward, rotate, false); //drive using combined input.
}

// Make this return true when this Command no longer needs to run execute()
bool ComboAlignToGear::IsFinished() {
	return isAngleCorrect && isLateralCorrect && isDistanceCorrect;
}

// Called once after isFinished returns true
void ComboAlignToGear::End() {
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
void ComboAlignToGear::Interrupted() {
	ComboAlignToGear::End();
}
