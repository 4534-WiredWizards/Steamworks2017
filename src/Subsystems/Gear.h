#ifndef Gear_H
#define Gear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Gear : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<DigitalInput> leftLimit;
	std::shared_ptr<DigitalInput> rightLimit;

public:
	Gear();
	void InitDefaultCommand();
	bool readLimits();
};

#endif  // Gear_H
