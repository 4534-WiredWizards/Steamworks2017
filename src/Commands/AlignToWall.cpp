#include "AlignToWall.h"
#define TARGET_DISTANCE 7 //in inches, from wall
#define TOLERANCE 1 // allowable range in inches from target

AlignToWall::AlignToWall() : Command() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arduinoComm.get());
	Requires(Robot::drivetrain.get());
	rotate = 0.0;
	strafe = 0.0;
	forward = 0.0;
}

// Called just before this Command runs the first time
void AlignToWall::Initialize() {
	Robot::arduinoComm->WriteTest("4");
	//previousValue = Robot::arduinoComm->GetAngle();
}

// Called repeatedly when this Command is scheduled to run
void AlignToWall::Execute() {

	Robot::arduinoComm->ReadData();

	//rotation
	if (Robot::arduinoComm->GetAngle() == -999) {
		//bad value, pass.
		rotate = 0.0;
	} else if (Robot::arduinoComm->GetAngle() == -777) {
		//one sensor broken, don't use angle.
		rotate = 0.0;
	} else if (Robot::arduinoComm->GetAngle() == -555) {
		//both sensors broken, pass.
		Robot::arduinoComm->WriteTest("bO");
		rotate = 0.0;
	} else if (Robot::arduinoComm->GetAngle() < -5) {
		rotate = (Robot::arduinoComm->GetAngle() + 2) * -0.1; //  scales the values down as we get closer.
		if (rotate > 0.7) {
			rotate = 0.7; // constrain value to 0.7
		}
	} else if (Robot::arduinoComm->GetAngle() > 5) {
		rotate = (Robot::arduinoComm->GetAngle() - 2) * -0.1; //  scales the values down as we get closer.
		if (rotate < -0.7) {
			rotate = -0.7; // constrain value to -0.7
		}
	} else {
		rotate = 0.0;
		// at desisred angle, do not turn.
	}

	//strafing
	strafe = Robot::oi->getJoystick1()->GetRawAxis(1);
	if (strafe < 0.2 && strafe > -0.2) {
		strafe = 0; //adds a dead zone.
	}

	//distance
	if (Robot::arduinoComm->GetAngle() == -999) {
		//bad value on angle, wait.
		forward = 0.0;
	} else if (Robot::arduinoComm->GetAngle() == -555) {
		//both sensors broken, pass.
		forward = 0.0;
	} else if (Robot::arduinoComm->GetDistance() > TARGET_DISTANCE + TOLERANCE) {
		forward = ((Robot::arduinoComm->GetDistance() - TARGET_DISTANCE) / 30) + 0.3; //for smooth motion
	} else if (Robot::arduinoComm->GetDistance() < TARGET_DISTANCE - TOLERANCE) {
		forward = ((Robot::arduinoComm->GetDistance() - TARGET_DISTANCE) / 30) - 0.3;
	} else {
		forward = 0.0;
	}

	Robot::drivetrain->Cartesian(strafe, forward, rotate, false); //drive using combined input.
}

// Make this return true when this Command no longer needs to run execute()
bool AlignToWall::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AlignToWall::End() {
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
void AlignToWall::Interrupted() {
	AlignToWall::End();
}
