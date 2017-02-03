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
std::shared_ptr<SpeedController> RobotMap::shooterKicker;
std::shared_ptr<SpeedController> RobotMap::shooterSpinner;
std::shared_ptr<SpeedController> RobotMap::driveTrainFrontLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainBackLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainFrontRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainBackRight;
std::shared_ptr<RobotDrive> RobotMap::driveTrainRobotDrive41;
std::shared_ptr<ADXRS450_Gyro> RobotMap::driveTrainGyro;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    shooterKicker.reset(new Spark(4));
    lw->AddActuator("Shooter", "Kicker", std::static_pointer_cast<Spark>(shooterKicker));
    
    shooterSpinner.reset(new Spark(5));
    lw->AddActuator("Shooter", "Spinner", std::static_pointer_cast<Spark>(shooterSpinner));
    
    driveTrainFrontLeft.reset(new Spark(0));
    lw->AddActuator("DriveTrain", "Front Left", std::static_pointer_cast<Spark>(driveTrainFrontLeft));
    
    driveTrainBackLeft.reset(new Spark(1));
    lw->AddActuator("DriveTrain", "Back Left", std::static_pointer_cast<Spark>(driveTrainBackLeft));
    
    driveTrainFrontRight.reset(new Spark(2));
    lw->AddActuator("DriveTrain", "Front Right", std::static_pointer_cast<Spark>(driveTrainFrontRight));
    
    driveTrainBackRight.reset(new Spark(3));
    lw->AddActuator("DriveTrain", "Back Right", std::static_pointer_cast<Spark>(driveTrainBackRight));
    
    driveTrainRobotDrive41.reset(new RobotDrive(driveTrainFrontLeft, driveTrainBackLeft,
              driveTrainFrontRight, driveTrainBackRight));
    driveTrainGyro.reset(new ADXRS450_Gyro);
    driveTrainRobotDrive41->SetSafetyEnabled(true);
        driveTrainRobotDrive41->SetExpiration(0.1);
        driveTrainRobotDrive41->SetSensitivity(0.5);
        driveTrainRobotDrive41->SetMaxOutput(1.0);

        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kRearRightMotor, true);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
