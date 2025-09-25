#ifndef FUELBASEDVEHICLE_H
#define FUELBASEDVEHICLE_H

#include "Vehicle.h"

class FuelBasedVehicle : public Vehicle {
public:
	FuelBasedVehicle(string ID, double mil);
	virtual void displayDetails() = 0; 
	virtual ~FuelBasedVehicle() {}
};

#endif