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
    time_t returnTime;

public:
    Vehicle(int vehicleId, const string& vehicleMake, const string& vehicleModel, int vehicleYear)
        : id(vehicleId), make(vehicleMake), model(vehicleModel), year(vehicleYear), available(true), returnTime(0) {}

    // Rent the vehicle to a customer with a specified return date
    virtual void rentVehicle(const string& customerName, time_t returnTime) {
        if (available) {
            available = false;
            rentalStartTime = time(nullptr);
            renterName = customerName;
            this->returnTime = returnTime;
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
            double rentalDuration = difftime(currentTime, rentalStartTime) / (3600.0 * 24.0);
            double totalCost = calculateRentalCost(rentalDuration);
            cout << "Vehicle returned by " << renterName << endl;
            cout << "Rental Duration: " << fixed << setprecision(2) << rentalDuration << " days" << endl;
            cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
            renterName = "";
        } else {
            cout << "Vehicle is already available" << endl;
        }
    }

    bool isAvailable() const {
        return available;
    }

    virtual string getVehicleDetails() const {
        return make + " " + model + " (" + to_string(year) + ")";
    }

    virtual double calculateRentalCost(double rentalDuration) const = 0;
};

// Derived class representing a Car
class Car : public Vehicle {
private:
    int seatingCapacity;

public:
    Car(int carId, const string& carMake, const string& carModel, int carYear, int capacity)
        : Vehicle(carId, carMake, carModel, carYear), seatingCapacity(capacity) {}

    void rentVehicle(const string& customerName, time_t returnTime) override {
        Vehicle::rentVehicle(customerName, returnTime);
    }

    void returnVehicle() override {
        Vehicle::returnVehicle();
    }

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

    string getVehicleDetails() const override {
        return to_string(seatingCapacity) + "-Seater " + Vehicle::getVehicleDetails();
    }
};

// Derived class representing a Bike
class Bike : public Vehicle {
private:
    int seatingCapacity;

public:
    Bike(int bikeId, const string& bikeMake, const string& bikeModel, int bikeYear, int capacity)
        : Vehicle(bikeId, bikeMake, bikeModel, bikeYear), seatingCapacity(capacity) {}

    void rentVehicle(const string& customerName, time_t returnTime) override {
        Vehicle::rentVehicle(customerName, returnTime);
    }

    void returnVehicle() override {
        Vehicle::returnVehicle();
    }

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

    string getVehicleDetails() const override {
        return to_string(seatingCapacity) + "-Seater Bike " + Vehicle::getVehicleDetails();
    }
};

// Class representing a Rental System
class RentalSystem {
private:
    unordered_map<int, vector<Vehicle*>> vehiclesByCapacity;

public:
    void addVehicle(int vehicleId, const string& vehicleType, const string& vehicleMake,
                    const string& vehicleModel, int vehicleYear, int seatingCapacity) {
        if (vehicleType == "Car") {
            vehiclesByCapacity[seatingCapacity].push_back(new Car(vehicleId, vehicleMake, vehicleModel, vehicleYear, seatingCapacity));
        } else if (vehicleType == "Bike") {
            vehiclesByCapacity[seatingCapacity].push_back(new Bike(vehicleId, vehicleMake, vehicleModel, vehicleYear, seatingCapacity));
        }
    }

    void bookVehicle(int seatingCapacity, const string& customerName, time_t returnTime) {
        if (vehiclesByCapacity.count(seatingCapacity) && !vehiclesByCapacity[seatingCapacity].empty()) {
            Vehicle* vehicle = nullptr;
            for (auto v : vehiclesByCapacity[seatingCapacity]) {
                if (v->isAvailable()) {
                    vehicle = v;
                    break;
                }
            }
            if (vehicle) {
                vehicle->rentVehicle(customerName, returnTime);
            } else {
                cout << "No available " << seatingCapacity << "-Seater vehicle" << endl;
            }
        } else {
            cout << "No " << seatingCapacity << "-Seater vehicle available" << endl;
        }
    }

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

    void returnVehicle(Vehicle* vehicle) {
        vehicle->returnVehicle();
    }
};

int main() {
    RentalSystem rentalSystem;

    // Add vehicles
    rentalSystem.addVehicle(1, "Car", "Toyota", "Corolla", 2021, 2);   // Two-Seater Car
    rentalSystem.addVehicle(2, "Car", "Honda", "Civic", 2020, 5);      // Five-Seater Car
    rentalSystem.addVehicle(3, "Car", "Chevrolet", "Suburban", 2019, 7); // Seven-Seater Car
    rentalSystem.addVehicle(4, "Bike", "Harley-Davidson", "Sportster", 2022, 1);  // One-Seater Bike
    rentalSystem.addVehicle(5, "Bike", "Honda", "CBR", 2021, 2);                  // Two-Seater Bike
    rentalSystem.addVehicle(6, "Bike", "Kawasaki", "Ninja", 2020, 3);              // Three-Seater Bike

    // Display available vehicles
    rentalSystem.displayAvailableVehicles();

    // Book vehicles for immediate use
    time_t currentTime = time(nullptr);
    time_t returnTime;

    cout << "Enter the number of days for the rental period: ";
    int rentalDays;
    cin >> rentalDays;
    returnTime = currentTime + (rentalDays * 24 * 3600); // Calculate return time

    rentalSystem.bookVehicle(2, "John Doe", returnTime); // Book a Two-Seater Car
    rentalSystem.bookVehicle(1, "Alice Smith", returnTime); // Book a One-Seater Bike

    // Book vehicles for a future date
    cout << "Enter the number of days to wait before renting again: ";
    int daysToWait;
    cin >> daysToWait;
    time_t futureReturnTime = currentTime + (daysToWait * 24 * 3600) + (7 * 24 * 3600); // Days to wait + one week
    rentalSystem.bookVehicle(5, "Bob Johnson", futureReturnTime); // Book a Five-Seater Car
    rentalSystem.bookVehicle(3, "Eve Wong", futureReturnTime); // Book a Three-Seater Bike

    // Display available vehicles after bookings
    rentalSystem.displayAvailableVehicles();

    return 0;
}
