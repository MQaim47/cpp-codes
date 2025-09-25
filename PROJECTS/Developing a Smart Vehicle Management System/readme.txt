🚗 Vehicle Management System (C++ OOP)

This project demonstrates a C++ object-oriented design for managing different types of vehicles using inheritance, polymorphism, virtual functions, and dynamic memory management.

📦 Classes Implemented
🚘 Vehicle (Base Class)

Stores common attributes like vehicleID and mileage.

Provides a virtual method displayDetails() for polymorphic behavior.

⛽ FuelBasedVehicle (Abstract Class)

Inherits from Vehicle.

Serves as a base for fuel-dependent vehicles like Truck and Car.

🚛 Truck

Inherits from FuelBasedVehicle.

Adds loadCapacity with validation.

Overrides displayDetails().

🚙 Car

Inherits from FuelBasedVehicle.

Adds passengerCapacity with validation.

Customizes displayDetails().

🔋 ElectricCar

Inherits from Car.

Adds batteryCapacity.

Overrides displayDetails() for complete reporting.

✨ Features

Polymorphism via base class pointers (Vehicle*).

Dynamic Memory Allocation (new / delete).

Vehicle Search by vehicleID.

Input Validation (no negative values, no empty strings).

Extensible Design → easy to add more vehicle types.