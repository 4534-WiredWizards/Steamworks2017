#ifndef SpinUp_H
#define SpinUp_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SpinUp : public Command {
public:
	SpinUp(double timeout, double rate);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_timeout;
	double m_rate;
};

#endif  // SpinUp_H
