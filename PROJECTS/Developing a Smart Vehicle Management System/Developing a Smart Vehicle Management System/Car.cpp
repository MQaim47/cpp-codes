#include "Car.h"

Car::Car(int passengerCap, string ID, double mil) : FuelBasedVehicle(ID, mil), passengerCapacity(passengerCap) {}

void Car::displayDetails() {
	if (passengerCapacity < 0)
	{
		cout << "Enter Valid Passenger Capacity..." << endl;
	}
	else{
		cout << "Passenger Capacity is:" << passengerCapacity << " kg" << endl;
	}
	if (vehicleID.empty())
	{
		cout << "You must enter Vehicle ID..." << endl;
	}
	else{
		cout << "Vehicle Id is:" << vehicleID << endl;
	}

	if (mileage <= 0){
		cout << "enter valid mileage..." << endl;
	}
	else{

		cout << "Mileage covered:" << mileage << " km/litre" << endl;
	}
	cout << endl << endl;

}

Car::~Car() {}
