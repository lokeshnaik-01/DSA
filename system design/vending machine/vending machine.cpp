// this is state design pattern
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Item structure representing each item in the vending machine
struct Item {
    string name;
    double price;
    int quantity;
};

// VendingMachine class representing the vending machine
class VendingMachine {
private:
    enum State { IDLE, PROCESSING }; // Vending machine states

    map<int, Item> items; // Map to store items with their IDs
    State state;           // Current state of the vending machine
    double balance;        // Current balance of coins inserted

public:
    // Constructor to initialize the vending machine
    VendingMachine() : state(IDLE), balance(0.0) {}

    // Method to add an item to the vending machine
    void addItem(int id, string name, double price, int quantity) {
        items[id] = {name, price, quantity};
    }

    // Method to display available items in the vending machine
    void displayItems() {
        cout << "Available Items:" << endl;
        for (const auto& pair : items) {
            cout << "ID: " << pair.first << ", Name: " << pair.second.name << ", Price: $" << pair.second.price
                 << ", Quantity: " << pair.second.quantity << endl;
        }
    }

    // Method to add coins to the vending machine
    void addCoins(double amount) {
        balance += amount;
        cout << "Added $" << amount << " to balance. Total balance: $" << balance << endl;
    }

    // Method to choose a product for purchase
    bool chooseProduct(int id) {
        if (state != IDLE) {
            cout << "Cannot choose product while processing another transaction." << endl;
            return false;
        }

        if (items.find(id) == items.end()) {
            cout << "Item with ID " << id << " not found." << endl;
            return false;
        }

        if (items[id].quantity <= 0) {
            cout << "Sorry, item is out of stock." << endl;
            return false;
        }

        cout << "Selected product: " << items[id].name << " for $" << items[id].price << endl;
        state = PROCESSING;
        return true;
    }

    // Method to process the transaction
    bool processTransaction() {
        if (state != PROCESSING) {
            cout << "No transaction in progress." << endl;
            return false;
        }

        if (balance < items.begin()->second.price) {
            cout << "Insufficient balance to purchase the selected item." << endl;
            return false;
        }

        balance -= items.begin()->second.price;
        items.begin()->second.quantity--;
        cout << "Transaction completed. Enjoy your " << items.begin()->second.name << "!" << endl;
        state = IDLE;
        return true;
    }

    // Method to cancel the transaction and get a refund
    bool cancelTransaction() {
        if (state != PROCESSING) {
            cout << "No transaction in progress." << endl;
            return false;
        }

        cout << "Transaction canceled. Refunding $" << balance << endl;
        balance = 0.0;
        state = IDLE;
        return true;
    }

    // Method to get a refund of the remaining balance
    void refund() {
        cout << "Refunding $" << balance << endl;
        balance = 0.0;
    }
};

int main() {
    // Create a vending machine object
    VendingMachine vendingMachine;

    // Add items to the vending machine
    vendingMachine.addItem(1, "Coke", 1.5, 10);
    vendingMachine.addItem(2, "Chips", 1.0, 5);
    vendingMachine.addItem(3, "Water", 1.0, 7);

    // Display available items
    vendingMachine.displayItems();

    // Add coins to the vending machine
    vendingMachine.addCoins(2.0);

    // Choose a product
    vendingMachine.chooseProduct(1);

    // Process the transaction
    vendingMachine.processTransaction();

    // Add more coins and choose another product
    vendingMachine.addCoins(1.0);
    vendingMachine.chooseProduct(2);
    vendingMachine.processTransaction();

    // Try to choose a product while processing another transaction
    vendingMachine.chooseProduct(3);

    // Cancel the transaction and get a refund
    vendingMachine.cancelTransaction();

    // Display updated available items
    vendingMachine.displayItems();

    // Add coins and get a refund
    vendingMachine.addCoins(1.0);
    vendingMachine.refund();

    return 0;
}
