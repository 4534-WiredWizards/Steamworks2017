#include "ShootAuto.h"
#include "TurnToAngle.h"
#include "DriveStraight.h"
#include "SpinUp.h"
#include "DriveCartesian.h"
#include "Kick.h"

#define SHOOTER_POWER 0.7


ShootAuto::ShootAuto() {
	AddParallel(new DriveStraight(1.3,0.5));
	AddSequential(new SpinUp(1.3, -SHOOTER_POWER));

	if (Robot::allianceColor == DriverStation::Alliance::kBlue){
		AddParallel(new TurnToAngle(-90));
	} else if (Robot::allianceColor == DriverStation::Alliance::kRed) {
		AddParallel(new TurnToAngle(90));
	}
	AddSequential(new SpinUp(1.0, -SHOOTER_POWER));

	AddParallel(new Kick(7, -.5));
	AddSequential(new SpinUp(7, -SHOOTER_POWER));

	if (Robot::allianceColor == DriverStation::Alliance::kBlue){
		AddSequential(new TurnToAngle(-60));
		AddSequential(new DriveStraight(.7, .5));
	} else if (Robot::allianceColor == DriverStation::Alliance::kRed) {
		AddSequential(new TurnToAngle(60));
		AddSequential(new DriveStraight(.7, .5));
	}




}
