#include"Trucks.h"

Truck::Truck(double cap, string ID, double mil) : FuelBasedVehicle(ID, mil), loadCapacity(cap) {}

void Truck::displayDetails() {
	if (loadCapacity < 0)
	{
		cout << "Enter Valid Load Capacity..." << endl;
	}
	else{
		cout << "load Capacity is:" << loadCapacity << " kg" << endl;
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

Truck::~Truck() {}
