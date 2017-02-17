#ifndef VisionHandler_H
#define VisionHandler_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <ntcore.h>
#include <tables/ITable.h>


class VisionHandler : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static const int CACHE_MISSED_NUM = 3;
	//ITable table;
	std::shared_ptr<NetworkTable> visionTable;
	int missedCount;

public:
	VisionHandler();
	class VisionTuple {
		public:
			double getDistance();
			void setDistance(double distance) {
			this->distance = distance;
			}

			double getCenter() {
				return center;
			}

			void setCenter(double center) {
				this->center = center;
			}

			double getAngle() {
				return angle;
			}

			void setAngle(double angle) {
				this->angle = angle;
			}

			VisionTuple(double x, double theta, double center) {
				this->distance = x;
				this->angle = theta;
				this->center = center;
			}

			std::string toString() {
				return "(" + std::to_string(this->distance) + "," + std::to_string(this->angle) + "," + std::to_string(this->center) + ")";
			}

			bool isDefault() {
				return this->distance == -999 && this->angle == -999 && this->center == -999;
			}

			void update(double x, double theta, double center) {
				this->distance = x;
				this->angle = theta;
				this->center = center;
			}
		private:
			double distance;
			double angle;
			double center;

		};

	std::shared_ptr<VisionHandler::VisionTuple> visionTuple;
	std::shared_ptr<VisionHandler::VisionTuple> getCurrentTuple();

	void updateSubsystem();

	void InitDefaultCommand();
/*
	void initTable(ITable subtable) {
		this->table = subtable;
		updateTable();
	}

	ITable getTable() {
		return table;
	}

	void updateTable() {
		if (table) {
			table.PutString("Current Tuple", this->visionTuple.toString());
		}
	}
*/
	void startLiveWindowMode() {
		// TODO Auto-generated method stub
	}
	void stopLiveWindowMode() {
		// TODO Auto-generated method stub
	}
};

#endif  // VisionHandler_H
