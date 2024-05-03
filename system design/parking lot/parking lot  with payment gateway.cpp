#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Enum representing vehicle types
enum class VehicleType {
    Car,
    Bike
};

// Vehicle class
class Vehicle {
private:
    string licensePlate;
    VehicleType type;
    time_t entryTime;

public:
    Vehicle(const string& plate, VehicleType vehicleType)
        : licensePlate(plate), type(vehicleType) {
        entryTime = time(nullptr); // Initialize entry time to current time
    }

    const string& getLicensePlate() const {
        return licensePlate;
    }

    VehicleType getType() const {
        return type;
    }

    time_t getEntryTime() const {
        return entryTime;
    }
};

// ParkingSpace class
class ParkingSpace {
private:
    bool occupied;
    Vehicle* parkedVehicle;

public:
    ParkingSpace() : occupied(false), parkedVehicle(nullptr) {}

    bool isOccupied() const {
        return occupied;
    }

    void parkVehicle(Vehicle* vehicle) {
        occupied = true;
        parkedVehicle = vehicle;
    }

    void removeVehicle() {
        occupied = false;
        parkedVehicle = nullptr;
    }

    Vehicle* getParkedVehicle() const {
        return parkedVehicle;
    }
};

// ParkingLot class
class ParkingLot {
private:
    vector<ParkingSpace> spaces;

public:
    ParkingLot(int numSpaces) {
        spaces.resize(numSpaces);
    }

    int findAvailableSpace() const {
        for (size_t i = 0; i < spaces.size(); ++i) {
            if (!spaces[i].isOccupied()) {
                return i;
            }
        }
        return -1; // No available space found
    }

    bool parkVehicle(Vehicle* vehicle) {
        int index = findAvailableSpace();
        if (index != -1) {
            spaces[index].parkVehicle(vehicle);
            return true;
        }
        return false; // Parking lot is full
    }

    bool exitVehicle(const string& licensePlate) {
        for (auto& space : spaces) {
            if (space.isOccupied() && space.getParkedVehicle()->getLicensePlate() == licensePlate) {
                space.removeVehicle();
                return true;
            }
        }
        return false; // Vehicle not found or parking space empty
    }

    double calculateParkingFee(const Vehicle* vehicle) const {
        double ratePerHour = (vehicle->getType() == VehicleType::Car) ? 5.0 : 3.0; // Rate per hour based on vehicle type
        time_t currentTime = time(nullptr);
        double durationHours = difftime(currentTime, vehicle->getEntryTime()) / 3600.0;
        return durationHours * ratePerHour;
    }
};

// PaymentGateway class
class PaymentGateway {
public:
    bool processPayment(double amount) {
        // Simulate payment processing (e.g., credit card, UPI)
        // For this example, assume payment is always successful
        cout << "Processing payment of $" << amount << " via Payment Gateway..." << endl;
        return true;
    }
};

int main() {
    // Create a parking lot with 10 parking spaces
    ParkingLot parkingLot(10);

    // Create a payment gateway instance
    PaymentGateway paymentGateway;

    // Simulate car entry and parking
    Vehicle car("ABC123", VehicleType::Car);
    if (parkingLot.parkVehicle(&car)) {
        cout << "Car with license plate " << car.getLicensePlate() << " parked successfully." << endl;

        // Simulate car exit and payment
        if (parkingLot.exitVehicle(car.getLicensePlate())) {
            double parkingFee = parkingLot.calculateParkingFee(&car);

            // Process payment for parking fee
            if (paymentGateway.processPayment(parkingFee)) {
                cout << "Payment of $" << parkingFee << " for car parking fee successful." << endl;
            } else {
                cout << "Payment for car parking fee failed." << endl;
            }
        } else {
            cout << "Car with license plate " << car.getLicensePlate() << " not found in parking lot." << endl;
        }
    } else {
        cout << "Parking lot is full. Car with license plate " << car.getLicensePlate() << " cannot park." << endl;
    }

    // Simulate bike entry and parking
    Vehicle bike("XYZ456", VehicleType::Bike);
    if (parkingLot.parkVehicle(&bike)) {
        cout << "Bike with license plate " << bike.getLicensePlate() << " parked successfully." << endl;

        // Simulate bike exit and payment
        if (parkingLot.exitVehicle(bike.getLicensePlate())) {
            double parkingFee = parkingLot.calculateParkingFee(&bike);

            // Process payment for parking fee
            if (paymentGateway.processPayment(parkingFee)) {
                cout << "Payment of $" << parkingFee << " for bike parking fee successful." << endl;
            } else {
                cout << "Payment for bike parking fee failed." << endl;
            }
        } else {
            cout << "Bike with license plate " << bike.getLicensePlate() << " not found in parking lot." << endl;
        }
    } else {
        cout << "Parking lot is full. Bike with license plate " << bike.getLicensePlate() << " cannot park." << endl;
    }

    return 0;
}
