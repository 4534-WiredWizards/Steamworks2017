#include "VisionHandler.h"
#include "../RobotMap.h"

VisionHandler::VisionHandler() : Subsystem("VisionHandler") {
	visionTable = NetworkTable::GetTable("vision");
	missedCount = 0;
	visionTuple = RobotMap::visionTuple;
}

void VisionHandler::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

}

std::shared_ptr<VisionHandler::VisionTuple> VisionHandler::getCurrentTuple() {
	return visionTuple;
}

void VisionHandler::updateSubsystem() {
	static std::shared_ptr<VisionHandler::VisionTuple> newTuple;
	newTuple.reset(new VisionHandler::VisionTuple(-999, -999, -999));
	newTuple->setAngle(visionTable->GetNumber("gearAngle", -999));
	newTuple->setDistance(visionTable->GetNumber("gearDistance", -999));
	newTuple->setCenter(visionTable->GetNumber("gearCV",-999));
	if(newTuple->isDefault()) {
		missedCount++;
	} else {
		this->visionTuple = newTuple;
	}
	if(missedCount > CACHE_MISSED_NUM) {
		missedCount = 0;
		this->visionTuple = newTuple;
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
