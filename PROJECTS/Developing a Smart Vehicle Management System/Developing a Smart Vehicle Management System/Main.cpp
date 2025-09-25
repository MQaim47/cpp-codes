#include "Trucks.h"
#include "Car.h"
#include "ElectricCar.h"

void searchVehicle(Vehicle* vehicles[], int size, const string& searchID) {
	for (int i = 0; i < size; ++i) {
		if (vehicles[i]->getVehicleID() == searchID) {
			cout << "Vehicle Found:" << endl;
			vehicles[i]->displayDetails();
			return;
		}
	}
	cout << "Vehicle with ID '" << searchID << "' not found." << endl;
}

int main() {
	Vehicle* vehicles[3];

	
	vehicles[0] = new Truck(5000, "Mazda", 8.5);
	vehicles[1] = new Car(4, " ", -12.3);
	vehicles[2] = new ElectricCar(350, 5, "Tesla", 10.2);

	
	for (int i = 0; i < 3; ++i) {
		vehicles[i]->displayDetails();
		cout << endl << endl;
	}

	
	//cout << "Enter Vehicle ID to search: ";
	//string searchID;
	//cin >> searchID;
	//searchVehicle(vehicles, 3, searchID);


	for (int i = 0; i < 3; ++i) {
		delete vehicles[i];
	}

	return 0;
}
