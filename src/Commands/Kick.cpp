#include "Kick.h"

Kick::Kick(double timeout, double rate) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	SetTimeout(timeout);
	m_rate = rate;
	m_timeout = timeout;
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void Kick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Kick::Execute() {
	Robot::shooter->SetKicker(m_rate);
}

// Make this return true when this Command no longer needs to run execute()
bool Kick::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Kick::End() {
	Robot::shooter->StopKicker();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Kick::Interrupted() {
	Kick::End();
}
