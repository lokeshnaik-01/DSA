#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>
#include <iomanip>
using namespace std;

// Base class representing a Vehicle
class Vehicle {
protected:
    int id;
    string make;
    string model;
    int year;
    bool available;
    time_t rentalStartTime;
    string renterName;
    time_t returnTime; // Added return time for booking

public:
    Vehicle(int vehicleId, const string& vehicleMake, const string& vehicleModel, int vehicleYear)
        : id(vehicleId), make(vehicleMake), model(vehicleModel), year(vehicleYear), available(true), returnTime(0) {}

    // Rent the vehicle to a customer with a specified return date
    virtual void rentVehicle(const string& customerName, time_t returnTime) {
        if (available) {
            available = false;
            rentalStartTime = time(nullptr); // Record rental start time
            renterName = customerName;
            this->returnTime = returnTime; // Set return time for booking
            cout << "Vehicle rented to " << customerName << " until " << ctime(&returnTime);
        } else {
            cout << "Vehicle is not available for rent" << endl;
        }
    }

    // Return the vehicle and calculate rental cost
    virtual void returnVehicle() {
        if (!available) {
            available = true;
            time_t currentTime = time(nullptr);
            double rentalDuration = difftime(currentTime, rentalStartTime) / (3600.0 * 24.0); // Rental duration in days
            double totalCost = calculateRentalCost(rentalDuration);
            cout << "Vehicle returned by " << renterName << endl;
            cout << "Rental Duration: " << fixed << setprecision(2) << rentalDuration << " days" << endl;
            cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
            renterName = "";
        } else {
            cout << "Vehicle is already available" << endl;
        }
    }

    // Check if the vehicle is available for rent
    bool isAvailable() const {
        return available;
    }

    // Get vehicle details
    virtual string getVehicleDetails() const {
        return make + " " + model + " (" + to_string(year) + ")";
    }

    // Calculate rental cost based on rental duration (in days)
    virtual double calculateRentalCost(double rentalDuration) const = 0;

    // Virtual function to get the seating capacity
    virtual int getSeatingCapacity() const = 0;
};

// Derived class representing a Car
class Car : public Vehicle {
private:
    int seatingCapacity;

public:
    Car(int carId, const string& carMake, const string& carModel, int carYear, int capacity)
        : Vehicle(carId, carMake, carModel, carYear), seatingCapacity(capacity) {}

    // Rent the car to a customer with a specified return date
    void rentVehicle(const string& customerName, time_t returnTime) override {
        Vehicle::rentVehicle(customerName, returnTime);
    }

    // Return the car and calculate rental cost
    void returnVehicle() override {
        Vehicle::returnVehicle();
    }

    // Calculate rental cost based on rental duration (in days) and seating capacity
    double calculateRentalCost(double rentalDuration) const override {
        if (seatingCapacity == 2) {
            return 10.0 * rentalDuration;
        } else if (seatingCapacity == 5) {
            return 20.0 * rentalDuration;
        } else if (seatingCapacity == 7) {
            return 30.0 * rentalDuration;
        }
        return 0.0; // Invalid seating capacity
    }

    // Get car details including seating capacity
    string getVehicleDetails() const override {
        return to_string(seatingCapacity) + "-Seater " + Vehicle::getVehicleDetails();
    }

    // Get the seating capacity of the car
    int getSeatingCapacity() const override {
        return seatingCapacity;
    }
};

// Derived class representing a Bike
class Bike : public Vehicle {
private:
    int seatingCapacity;

public:
    Bike(int bikeId, const string& bikeMake, const string& bikeModel, int bikeYear, int capacity)
        : Vehicle(bikeId, bikeMake, bikeModel, bikeYear), seatingCapacity(capacity) {}

    // Rent the bike to a customer with a specified return date
    void rentVehicle(const string& customerName, time_t returnTime) override {
        Vehicle::rentVehicle(customerName, returnTime);
    }

    // Return the bike and calculate rental cost
    void returnVehicle() override {
        Vehicle::returnVehicle();
    }

    // Calculate rental cost based on rental duration (in days) and seating capacity
    double calculateRentalCost(double rentalDuration) const override {
        if (seatingCapacity == 1) {
            return 10.0 * rentalDuration;
        } else if (seatingCapacity == 2) {
            return 20.0 * rentalDuration;
        } else if (seatingCapacity == 3) {
            return 30.0 * rentalDuration;
        }
        return 0.0; // Invalid seating capacity
    }

    // Get bike details including seating capacity
    string getVehicleDetails() const override {
        return to_string(seatingCapacity) + "-Seater Bike " + Vehicle::getVehicleDetails();
    }

    // Get the seating capacity of the bike
    int getSeatingCapacity() const override {
        return seatingCapacity;
    }
};

// Class representing a Rental System
class RentalSystem {
private:
    unordered_map<int, vector<Vehicle*>> vehiclesByCapacity;
    vector<string> customers;

public:
    // Add vehicles (cars or bikes) to the rental system
    void addVehicle(int vehicleId, const string& vehicleType, const string& vehicleMake,
                    const string& vehicleModel, int vehicleYear, int seatingCapacity) {
        if (vehicleType == "Car") {
            vehiclesByCapacity[seatingCapacity].push_back(new Car(vehicleId, vehicleMake, vehicleModel, vehicleYear, seatingCapacity));
        } else if (vehicleType == "Bike") {
            vehiclesByCapacity[seatingCapacity].push_back(new Bike(vehicleId, vehicleMake, vehicleModel, vehicleYear, seatingCapacity));
        }
    }

    // Book a vehicle for future rental with a specified return date
    void bookVehicle(int seatingCapacity, time_t returnTime) {
        if (vehiclesByCapacity.count(seatingCapacity) && !vehiclesByCapacity[seatingCapacity].empty()) {
            Vehicle* vehicle = vehiclesByCapacity[seatingCapacity].back();
            if (vehicle->isAvailable()) {
                vehicle->rentVehicle("Booked", returnTime);
            } else {
                cout << "No available " << seatingCapacity << "-Seater vehicle" << endl;
            }
        } else {
            cout << "No " << seatingCapacity << "-Seater vehicle available" << endl;
        }
    }

    // Display available vehicles grouped by seating capacity
    void displayAvailableVehicles() const {
        cout << "Available Vehicles:" << endl;
        for (const auto& entry : vehiclesByCapacity) {
            int seatingCapacity = entry.first;
            const vector<Vehicle*>& vehicles = entry.second;
            cout << seatingCapacity << "-Seater Vehicles:" << endl;
            for (const Vehicle* vehicle : vehicles) {
                if (vehicle->isAvailable()) {
                    cout << "ID: " << vehicle->getVehicleDetails() << endl;
                }
            }
        }
    }

    // Return a rented vehicle and calculate rental cost
    void returnVehicle(Vehicle* vehicle) {
        vehicle->returnVehicle();
        vehiclesByCapacity[vehicle->getSeatingCapacity()].push_back(vehicle); // Add returned vehicle back to inventory
    }
};

int main() {
    RentalSystem rentalSystem;

    // Add cars and bikes with different seating capacities
    rentalSystem.addVehicle(1, "Car", "Toyota", "Corolla", 2021, 2);   // Two-Seater Car
    rentalSystem.addVehicle(2, "Car", "Honda", "Civic", 2020, 5);      // Five-Seater Car
    rentalSystem.addVehicle(3, "Car", "Chevrolet", "Suburban", 2019, 7); // Seven-Seater Car
    rentalSystem.addVehicle(4, "Bike", "Harley-Davidson", "Sportster", 2022, 1);  // One-Seater Bike
    rentalSystem.addVehicle(5, "Bike", "Honda", "CBR", 2021, 2);                  // Two-Seater Bike
    rentalSystem.addVehicle(6, "Bike", "Kawasaki", "Ninja", 2020, 3);              // Three-Seater Bike

    // Display available vehicles
    rentalSystem.displayAvailableVehicles();

    // Book vehicles for future use with specified return dates
    time_t returnTime = time(nullptr) + (7 * 24 * 3600); // One week from now
    rentalSystem.bookVehicle(2, returnTime); // Book a Two-Seater Car
    rentalSystem.bookVehicle(1, returnTime); // Book a One-Seater Bike

    // Display available vehicles after booking
    rentalSystem.displayAvailableVehicles();

    return 0;
}