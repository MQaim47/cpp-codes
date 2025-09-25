#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
private:
	double batteryCapacity;

public:
	ElectricCar(double battery, int passengerCap, string ID, double mil);
	void displayDetails() override;
	~ElectricCar();
};

#endif // ELECTRICCAR_
