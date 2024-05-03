#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Abstract base class for payment calculation
class Payment {
public:
    virtual double calculateCost(double hours) = 0; // Pure virtual function for calculating cost
};

// Concrete classes for different types of payments
class CarPayment : public Payment {
public:
    double calculateCost(double hours) { return hours * 2; } // Car payment calculation
};

class BikePayment : public Payment {
public:
    double calculateCost(double hours) { return hours * 1; } // Bike payment calculation
};

class HandicappedPayment : public Payment {
public:
    double calculateCost(double hours) { return 0; } // Handicapped vehicle payment calculation (free)
};

// Abstract base class for vehicle
class Vehicle {
protected:
    Payment* payment; // Pointer to payment strategy
    chrono::time_point<chrono::system_clock> parkedTime; // Time when vehicle was parked

public:
    virtual string getType() = 0; // Pure virtual function to get vehicle type
    virtual double calculateCost(double hours) { // Virtual function to calculate parking cost
        return payment->calculateCost(hours); // Delegate calculation to payment strategy
    }

    void setParkedTime() {
        parkedTime = chrono::system_clock::now(); // Set current time as parked time
    }

    chrono::time_point<chrono::system_clock> getParkedTime() {
        return parkedTime; // Get parked time
    }

    virtual bool isHandicapped() const { // Virtual function to check if vehicle is handicapped
        return false; // Default implementation for non-handicapped vehicles
    }
};

// Concrete vehicle classes inheriting from Vehicle
class Car : public Vehicle {
public:
    Car() { payment = new CarPayment(); }
    string getType() { return "Car"; }
};

class Bike : public Vehicle {
public:
    Bike() { payment = new BikePayment(); }
    string getType() { return "Bike"; }
};

class HandicappedVehicle : public Vehicle {
public:
    HandicappedVehicle() { payment = new HandicappedPayment(); }
    string getType() { return "Handicapped"; }
    bool isHandicapped() const override { // Override to indicate that this is a handicapped vehicle
        return true;
    }
};

// Parking lot class to manage parking spaces
class ParkingLot {
private:
    vector<vector<vector<Vehicle*>>> spots; // 3D vector for parking spots
    vector<vector<bool>> handicappedSpots; // 2D vector to track handicapped spots
    int floors;
    int rows;
    int spotsPerRow;

public:
    ParkingLot(int floors, int rows, int spotsPerRow) {
        this->floors = floors;
        this->rows = rows;
        this->spotsPerRow = spotsPerRow;

        // Initialize spots and handicappedSpots vectors
        spots.resize(floors, vector<vector<Vehicle*>>(rows, vector<Vehicle*>(spotsPerRow, nullptr)));
        handicappedSpots.resize(floors, vector<bool>(rows * spotsPerRow, false));
    }

    bool park(Vehicle* v, int floor, int row, int spot) {
        if (spots[floor][row][spot] == nullptr) {
            spots[floor][row][spot] = v;
            if (v->isHandicapped()) {
                handicappedSpots[floor][row * spotsPerRow + spot] = true;
            }
            cout << v->getType() << " parked successfully at floor " << floor << ", row " << row << ", spot " << spot << "." << endl;
            return true;
        } else {
            cout << "Spot already occupied." << endl;
            return false;
        }
    }

    bool leave(Vehicle* v) {
        for (int i = 0; i < floors; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < spotsPerRow; k++) {
                    if (spots[i][j][k] == v) {
                        double hours = calculateHoursParked(v);
                        double cost = v->calculateCost(hours);
                        spots[i][j][k] = nullptr;
                        if (v->isHandicapped()) {
                            handicappedSpots[i][j * spotsPerRow + k] = false;
                        }
                        cout << v->getType() << " left successfully. Total cost: " << cost << endl;
                        return true;
                    }
                }
            }
        }
        cout << v->getType() << " not found." << endl;
        return false;
    }

    int availableSpots(int floor) {
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < spotsPerRow; j++) {
                if (spots[floor][i][j] == nullptr) {
                    count++;
                }
            }
        }
        return count;
    }

    int availableHandicappedSpots(int floor) {
        int count = 0;
        for (int j = 0; j < rows * spotsPerRow; j++) {
            if (handicappedSpots[floor][j] == false) {
                count++;
            }
        }
        return count;
    }

    double calculateHoursParked(Vehicle* v) {
        auto now = chrono::system_clock::now();
        auto parkedTime = v->getParkedTime();
        auto duration = now - parkedTime;
        return chrono::duration_cast<chrono::duration<double>>(duration).count() / 3600.0;
    }
};

int main() {
    ParkingLot lot(3, 10, 20);

    // Create vehicles
    Car car1, car2;
    Bike bike1, bike2;
    HandicappedVehicle hv1;

    // Park vehicles
    car1.setParkedTime();
    lot.park(&car1, 0, 0, 0);
    car2.setParkedTime();
    lot.park(&car2, 0, 0, 1);
    bike1.setParkedTime();
    lot.park(&bike1, 0, 0, 2);
    hv1.setParkedTime();
    lot.park(&hv1, 2, 9, 19);

    // Display available spots
    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;
    cout << "Available handicapped spots on floor 2: " << lot.availableHandicappedSpots(2) << endl;

    // Vehicles leave
    lot.leave(&car1);
    lot.leave(&bike2); // This will not be found since bike2 was never parked

    // Display available spots again
    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;

    return 0;
}
