// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::drivetrainfrontLeft;
std::shared_ptr<SpeedController> RobotMap::drivetrainfrontRight;
std::shared_ptr<SpeedController> RobotMap::drivetrainrearLeft;
std::shared_ptr<SpeedController> RobotMap::drivetrainrearRight;
std::shared_ptr<RobotDrive> RobotMap::drivetrainRobotDrive;
std::shared_ptr<SpeedController> RobotMap::shooterKicker;
std::shared_ptr<SpeedController> RobotMap::climberClimbMotor;
std::shared_ptr<SpeedController> RobotMap::intakeIntakeMotor;
std::shared_ptr<SpeedController> RobotMap::tempShooterSpinner;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<ADXRS450_Gyro> RobotMap::drivetrainGyro;
std::shared_ptr<VisionHandler::VisionTuple> RobotMap::visionTuple;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    drivetrainfrontLeft.reset(new Spark(0));
    lw->AddActuator("Drivetrain", "frontLeft", std::static_pointer_cast<Spark>(drivetrainfrontLeft));
    
    drivetrainfrontRight.reset(new Spark(1));
    lw->AddActuator("Drivetrain", "frontRight", std::static_pointer_cast<Spark>(drivetrainfrontRight));
    
    drivetrainrearLeft.reset(new Spark(2));
    lw->AddActuator("Drivetrain", "rearLeft", std::static_pointer_cast<Spark>(drivetrainrearLeft));
    
    drivetrainrearRight.reset(new Spark(3));
    lw->AddActuator("Drivetrain", "rearRight", std::static_pointer_cast<Spark>(drivetrainrearRight));
    
    drivetrainRobotDrive.reset(new RobotDrive(drivetrainfrontLeft, drivetrainrearLeft,
              drivetrainfrontRight, drivetrainrearRight));
    
    drivetrainRobotDrive->SetSafetyEnabled(true);
        drivetrainRobotDrive->SetExpiration(0.1);
        drivetrainRobotDrive->SetSensitivity(0.5);
        drivetrainRobotDrive->SetMaxOutput(1.0);

        drivetrainRobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        drivetrainRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
    shooterKicker.reset(new Spark(4));
    lw->AddActuator("Shooter", "Kicker", std::static_pointer_cast<Spark>(shooterKicker));
    
    climberClimbMotor.reset(new Spark(6));
    lw->AddActuator("Climber", "ClimbMotor", std::static_pointer_cast<Spark>(climberClimbMotor));
    
    intakeIntakeMotor.reset(new Spark(7));
    lw->AddActuator("Intake", "IntakeMotor", std::static_pointer_cast<Spark>(intakeIntakeMotor));
    
    tempShooterSpinner.reset(new Spark(5));
    lw->AddActuator("TempShooter", "Spinner", std::static_pointer_cast<Spark>(tempShooterSpinner));
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    drivetrainGyro.reset(new ADXRS450_Gyro);
    lw->AddActuator("Drivetrain", "gyro", std::static_pointer_cast<ADXRS450_Gyro>(drivetrainGyro));

    visionTuple.reset(new VisionHandler::VisionTuple(-999, -999, -999));

}
