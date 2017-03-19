#ifndef Kick_H
#define Kick_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Kick : public Command {
public:
	Kick(double timeout, double rate);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_timeout;
	double m_rate;
};

#endif  // Kick_H
