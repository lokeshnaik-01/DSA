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
    int floors;
    int rows;
    int spotsPerRow;

public:
    ParkingLot(int floors, int rows, int spotsPerRow) {
        this->floors = floors;
        this->rows = rows;
        this->spotsPerRow = spotsPerRow;
        spots.resize(floors); // Resize the floors
        for (int i = 0; i < floors; i++) {
            spots[i].resize(rows); // Resize the rows
            for (int j = 0; j < rows; j++) {
                spots[i][j].resize(spotsPerRow); // Resize the spots per row
            }
        }
    }

    bool park(Vehicle* v, int floor, int row, int spot) {
        if (spots[floor][row][spot] == nullptr) {
            spots[floor][row][spot] = v; // Park the vehicle
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
                    if (spots[i][j][k] == v){
                        double hours = calculateHoursParked(spots[i][j][k]);
                        double cost = spots[i][j][k]->calculateCost(hours);
                        spots[i][j][k] = nullptr;
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

    int handicappedSpots(int floor) {
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < spotsPerRow; j++) {
                if (spots[floor][i][j] != nullptr && spots[floor][i][j]->isHandicapped()) {
                    count++;
                }
            }
        }
        return count;
    }

    double calculateHoursParked(Vehicle* v) {
        auto now = chrono::system_clock::now(); // Get current time
        auto parkedTime = spots[0][0][0]->getParkedTime(); // Get parked time of any vehicle (assuming it's valid)
        auto duration = now - parkedTime; // Calculate duration
        return chrono::duration_cast<chrono::duration<double>>(duration).count() / 3600.0; // Convert to hours
    }
};

int main() {
    ParkingLot lot(3, 10, 20); // Create a parking lot with 3 floors, 10 rows per floor, and 20 spots per row
    Car car1, car2; // Create car objects
    Bike bike1, bike2; // Create bike objects
    HandicappedVehicle hv1; // Create handicapped vehicle object

    car1.setParkedTime(); // Set parked time for car1
    lot.park(&car1, 0, 0, 0); // Park car1 at floor 0, row 0, spot 0
    car2.setParkedTime(); // Set parked time for car2
    lot.park(&car2, 0, 0, 1); // Park car2 at floor 0, row 0, spot 1
    bike1.setParkedTime(); // Set parked time for bike1
    lot.park(&bike1, 0, 0, 2); // Park bike1 at floor 0, row 0, spot 2
    hv1.setParkedTime(); // Set parked time for hv1
    lot.park(&hv1, 2, 9, 19); // Park hv1 at floor 2, row 9, spot 19

    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;
    cout << "Handicapped spots on floor 2: " << lot.handicappedSpots(2) << endl;

    lot.leave(&car1);
    lot.leave(&bike2);

    cout << "Available spots on floor 0: " << lot.availableSpots(0) << endl;

    return 0;
}
