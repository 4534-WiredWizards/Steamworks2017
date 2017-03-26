#include "Gear.h"
#include "../RobotMap.h"
#include "../Commands/GearCheck.h"

Gear::Gear() : Subsystem("Gear") {
	leftLimit = RobotMap::leftLimit;
	rightLimit = RobotMap::rightLimit;
}

void Gear::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GearCheck());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool Gear::readLimits() {
	std::cout << leftLimit->Get() << rightLimit->Get() << std::endl;
	if (leftLimit->Get() || rightLimit->Get()) {
		return true;
	}
	return false;
}

