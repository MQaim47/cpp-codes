#include<iostream>
#include<string>
using namespace std;
class Vehicle{
protected:
	string vehicleID;
	double mileage;
public:
	Vehicle(string ID, double mil) :vehicleID(ID), mileage(mil){}
	virtual void displayDetails(){
		cout << "Vehicle Id is:" << vehicleID << endl
			<< "Mileage covered:" << mileage << endl;
	}
	virtual ~Vehicle(){}
	string getVehicleID() const {
		return vehicleID;
	}

};
class FuelBasedVehicle : public Vehicle {
public:
	FuelBasedVehicle(string ID, double mil) : Vehicle(ID, mil) {}

	virtual void displayDetails(){};
};
class Truck :public FuelBasedVehicle{
protected:
	double loadCapacity;
public:
	Truck(double cap, string ID, double mil) :loadCapacity(cap), FuelBasedVehicle(ID, mil){}



	void displayDetails()override{
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
	virtual ~Truck(){}

};
class Car :public FuelBasedVehicle{
protected:
	int passengerCapacity;
public:
	Car(int passengerCap, string ID, double mil) :passengerCapacity(passengerCap), FuelBasedVehicle(ID, mil){}
	void displayDetails()override{
		if (passengerCapacity < 0)
		{
			cout << "Enter Valid Passenger Capacity..." << endl;
		}
		else{
			cout << "Passenger Capacity is:" << passengerCapacity<< " kg" << endl;
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
	virtual ~Car(){}
};
class ElectricCar :public Car{
protected:
	double batteryCapacity;
public:
	ElectricCar(double battery,int passengerCap, string ID, double mil) :batteryCapacity(battery),Car(passengerCap,ID,mil){}
	void displayDetails()override{
		if (batteryCapacity < 0)
		{
			cout << "Enter Valid Battery Capacity..." << endl;
		}
		else{
			cout << "Battery Capacity is:" <<batteryCapacity<< "km/charge" << endl;
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
	virtual ~ElectricCar(){}
};
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


int main(){
	Vehicle* vehicles[3];
	vehicles[0] = new Truck(5000,"Mazda", 8.5);
	vehicles[1] = new Car(4,"Honda", -12.3);   
	vehicles[2] = new ElectricCar(350,5,"Tesla", 10.2); 


	for (int i = 0; i < 3; ++i) {
			vehicles[i]->displayDetails();
		}

	
	for (int i = 0; i < 3; ++i) {
		delete vehicles[i];
	}



	return 0;
}