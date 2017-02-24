#ifndef ComboAlignToGear_H
#define ComboAlignToGear_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ComboAlignToGear : public Command {
public:
	ComboAlignToGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<VisionHandler::VisionTuple> VisionData;
	bool isDistanceCorrect;
	bool isAngleCorrect;
	bool isLateralCorrect;
	double rotate;
	double strafe;
	double forward;
	//double previousValue;
};

#endif  // ComboAlignToGear_H
