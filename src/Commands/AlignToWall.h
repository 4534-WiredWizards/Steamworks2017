#ifndef AlignToWall_H
#define AlignToWall_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AlignToWall : public Command {
public:
	AlignToWall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double rotate;
	double strafe;
	double forward;
	//double previousValue;
};

#endif  // AlignToWall_H
