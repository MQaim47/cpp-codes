#ifndef CAR_H
#define CAR_H

#include "FuelBase.h"

class Car : public FuelBasedVehicle {
protected:
	int passengerCapacity;

public:
	Car(int passengerCap, string ID, double mil);
	void displayDetails() override;
	~Car();
};

#endif 