 Vehicle Management System in C++
This project demonstrates a C++ object-oriented design for managing different types of vehicles using inheritance, polymorphism, virtual functions, and dynamic memory management.

 Classes Implemented
Vehicle (Base Class)
Contains common vehicle attributes such as ID and mileage. Provides a virtual method to display details.

FuelBasedVehicle (Abstract Class)
Inherits from Vehicle and serves as a base class for fuel-dependent vehicles like Truck and Car.

Truck
Inherits from FuelBasedVehicle. Includes a loadCapacity attribute and overrides displayDetails() with validation.

Car
Inherits from FuelBasedVehicle. Adds passengerCapacity and custom validation.

ElectricCar
Inherits from Car. Adds batteryCapacity and overrides displayDetails() for full reporting.

Features
Polymorphism using base class pointers (Vehicle*)

Dynamic Memory Allocation and cleanup using delete

Vehicle Search Functionality based on vehicleID

Input Validation for negative values and empty strings

Extensible Design for future vehicle types

 Example Usage
In main():

A Truck, Car, and ElectricCar are created dynamically.

Their information is printed using polymorphic calls to displayDetails().

Vehicles are cleaned up using delete to prevent memory leaks.