#include "DriveCartesian.h"

DriveCartesian::DriveCartesian(double x, double y, double turn, bool isFieldOriented, double timeout) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_x = x;
	m_y = y;
	m_turn = turn;
	m_isFieldOriented = isFieldOriented;
	SetTimeout(timeout);
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveCartesian::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveCartesian::Execute() {
	Robot::drivetrain->Cartesian(m_x, m_y, m_turn, m_isFieldOriented);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCartesian::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveCartesian::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCartesian::Interrupted() {
	DriveCartesian::End();
}
