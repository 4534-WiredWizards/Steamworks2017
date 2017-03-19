#ifndef DriveCartesian_H
#define DriveCartesian_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveCartesian : public Command {
public:
	DriveCartesian(double x, double y, double turn, bool isFieldOriented, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_x;
	double m_y;
	double m_turn;
	bool m_isFieldOriented;
};

#endif  // DriveCartesian_H
