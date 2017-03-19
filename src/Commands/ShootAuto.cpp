#include "ShootAuto.h"
#include "TurnToAngle.h"
#include "DriveStraight.h"
#include "SpinUp.h"
#include "DriveCartesian.h"
#include "Kick.h"


#define SHOOTER_POWER .7

ShootAuto::ShootAuto() {
	if (Robot::allianceColor == DriverStation::Alliance::kBlue){
		AddParallel(new TurnToAngle(-90));
	} else if (Robot::allianceColor == DriverStation::Alliance::kRed) {
		AddParallel(new TurnToAngle(90));
	}
	AddSequential(new SpinUp(3, -SHOOTER_POWER));
	AddParallel(new Kick(7, -.5));
	AddSequential(new SpinUp(7, -SHOOTER_POWER));
	if (Robot::allianceColor == DriverStation::Alliance::kBlue){
		AddSequential(new DriveCartesian(0, .5, .3, true, 1.5));
		AddSequential(new TurnToAngle(-60));
		AddSequential(new DriveStraight(.7, .5));
	} else if (Robot::allianceColor == DriverStation::Alliance::kRed) {
			AddSequential(new DriveCartesian(0, .5, -.3, true, 1.5));
			AddSequential(new TurnToAngle(60));
			AddSequential(new DriveStraight(.7, .5));
	}




}
