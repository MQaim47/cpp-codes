#ifndef TRUCK_H
#define TRUCK_H
#include"FuelBase.h"

class Truck : public FuelBasedVehicle {
private:
	double loadCapacity;

public:
	Truck(double cap, string ID, double mil);
	void displayDetails() override;
	~Truck();
};

#endif 