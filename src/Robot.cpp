// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "Commands/RightGearAuto.h"
#include "Commands/CenterGearAuto.h"
#include "Commands/FarShootAuto.h"
#include "Commands/NearShootAuto.h"
#include "Commands/LeftGearAuto.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<TempShooter> Robot::tempShooter;
std::shared_ptr<VisionHandler> Robot::visionHandler;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<ArduinoComm> Robot::arduinoComm;
DriverStation::Alliance Robot::allianceColor;

double Robot::shooterSpeed;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    drivetrain.reset(new Drivetrain());
    shooter.reset(new Shooter());
    climber.reset(new Climber());
    intake.reset(new Intake());
    tempShooter.reset(new TempShooter());
    visionHandler.reset(new VisionHandler());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    visionHandler.reset(new VisionHandler());
    shooterSpeed = 0.5;
    arduinoComm.reset(new ArduinoComm());
    arduinoComm->SetTimeout(0.05);
    allianceColor = DriverStation::GetInstance().GetAlliance();
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	// autonomousCommand.reset(new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	chooser.AddObject("Left Gear", new (LeftGearAuto));
	chooser.AddObject("Right Gear", new (RightGearAuto));
	chooser.AddObject("Near Shoot Auto", new (NearShootAuto));
	chooser.AddObject("Far Shoot Auto", new (FarShootAuto));
	chooser.AddDefault("Center Gear", new (CenterGearAuto));
	SmartDashboard::PutData("Autonomous Modes", &chooser);
	arduinoComm->WriteTest("4");
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	arduinoComm->WriteTest("5");
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.release();
	autonomousCommand.reset((Command *)chooser.GetSelected());
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
	arduinoComm->WriteTest("Gg");
	Robot::drivetrain->ResetGyro();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	if (allianceColor == DriverStation::Alliance::kBlue){
		arduinoComm->WriteTest("B"); // Will use color blue for animations on LEDS.
	} else if (allianceColor == DriverStation::Alliance::kRed) {
		arduinoComm->WriteTest("R"); // Will use red color.
	}
	arduinoComm->WriteTest("w");
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	std::shared_ptr<Joystick> joystick1 = oi->getJoystick1();
	if(joystick1->GetRawButton(7)) {
		RobotMap::drivetrainGyro->Reset();
	}

	//std::cout << joystick1->GetTwist() << std::endl;
	//visionHandler->updateSubsystem();

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

