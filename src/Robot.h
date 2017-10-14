// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/TempShooter.h"
#include "Subsystems/VisionHandler.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"
#include "Subsystems/VisionHandler.h"
#include "Subsystems/ArduinoComm.h"
#include "Subsystems/Gear.h"
class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<Drivetrain> drivetrain;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<Climber> climber;
    static std::shared_ptr<Intake> intake;
    static std::shared_ptr<TempShooter> tempShooter;
    static std::shared_ptr<VisionHandler> visionHandler;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<ArduinoComm> arduinoComm;
    static std::shared_ptr<Gear> gear;
    static DriverStation::Alliance allianceColor;
    static double shooterSpeed;

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

	frc::SendableChooser<frc::Command*> chooser;
	frc::SendableChooser<DriverStation::Alliance> allianceChooser;
	static bool isDemoMode;
};
#endif
