#include "SpinUp.h"

SpinUp::SpinUp(double timeout, double rate) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_timeout = timeout;
	m_rate = rate;
	SetTimeout(m_timeout);
	Requires(Robot::tempShooter.get());
}

// Called just before this Command runs the first time
void SpinUp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute() {
	Robot::tempShooter->SetSpinner(m_rate);
}

// Make this return true when this Command no longer needs to run execute()
bool SpinUp::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void SpinUp::End() {
	Robot::tempShooter->SetSpinner(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUp::Interrupted() {
	SpinUp::End();
}
