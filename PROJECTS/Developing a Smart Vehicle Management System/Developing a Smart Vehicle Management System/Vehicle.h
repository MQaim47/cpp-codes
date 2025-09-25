#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
	string vehicleID;
	double mileage;

public:
	Vehicle(string ID, double mil);
	virtual void displayDetails() = 0; 
	virtual ~Vehicle();

	string getVehicleID() const;
};

#endif