#include "Vehicle.h"

Vehicle::Vehicle(string ID, double mil) : vehicleID(ID), mileage(mil) {}

Vehicle::~Vehicle() {}

string Vehicle::getVehicleID() const {
	return vehicleID;
}
