#include "ElectricCar.h"

ElectricCar::ElectricCar(double battery, int passengerCap, string ID, double mil)
: Car(passengerCap, ID, mil), batteryCapacity(battery) {}

void ElectricCar::displayDetails() {
	if (batteryCapacity < 0)
	{
		cout << "Enter Valid Battery Capacity..." << endl;
	}
	else{
		cout << "Battery Capacity is:" << batteryCapacity << "km/charge" << endl;
	}

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

ElectricCar::~ElectricCar() {}
