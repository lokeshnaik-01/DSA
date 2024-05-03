#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of Customer class
class Customer;

// Subject Interface
class StockInventory {
private:
    string stockName;
    int quantity;
    vector<Customer*> customers;

public:
    StockInventory(const string& name, int initialQuantity)
        : stockName(name), quantity(initialQuantity) {}

    void addObserver(Customer* customer) {
        customers.push_back(customer);
    }

    void removeObserver(Customer* customer) {
        // Find and remove the customer
        for (auto it = customers.begin(); it != customers.end(); ++it) {
            if (*it == customer) {
                customers.erase(it);
                break;
            }
        }
    }

    void notifyObservers() {
        for (Customer* customer : customers) {
            customer->update(stockName, quantity);
        }
    }

    void setQuantity(int newQuantity) {
        if (newQuantity != quantity) {
            quantity = newQuantity;
            notifyObservers();
        }
    }

    const string& getStockName() const {
        return stockName;
    }

    int getQuantity() const {
        return quantity;
    }
};

// Observer Interface
class Customer {
public:
    virtual void update(const string& stockName, int quantity) = 0;
};

// ConcreteObserver Class - Retail Customer
class RetailCustomer : public Customer {
private:
    string name;

public:
    RetailCustomer(const string& customerName)
        : name(customerName) {}

    void update(const string& stockName, int quantity) override {
        cout << "Notification for " << name << ": Stock '" << stockName << "' quantity is now " << quantity << endl;
        // Additional logic specific to retail customer (if needed)
    }
};

// ConcreteObserver Class - Email Alert
class EmailAlert : public Customer {
private:
    string email;

public:
    EmailAlert(const string& emailAddress)
        : email(emailAddress) {}

    void update(const string& stockName, int quantity) override {
        cout << "Sending email to " << email << ": Stock '" << stockName << "' quantity is now " << quantity << endl;
        // Additional logic specific to email alert (e.g., send email)
    }
};

// ConcreteObserver Class - Mobile Alert
class MobileAlert : public Customer {
private:
    string phoneNumber;

public:
    MobileAlert(const string& mobileNumber)
        : phoneNumber(mobileNumber) {}

    void update(const string& stockName, int quantity) override {
        cout << "Sending mobile alert to " << phoneNumber << ": Stock '" << stockName << "' quantity is now " << quantity << endl;
        // Additional logic specific to mobile alert (e.g., send SMS)
    }
};

// Usage Class
int main() {
    // Create StockInventory
    StockInventory stock("ABC", 100);

    // Create Customers (Observers)
    Customer* retailCustomer1 = new RetailCustomer("Alice");
    Customer* retailCustomer2 = new RetailCustomer("Bob");
    Customer* emailAlertCustomer = new EmailAlert("alice@example.com");
    Customer* mobileAlertCustomer = new MobileAlert("+1234567890");

    // Register Customers as Observers
    stock.addObserver(retailCustomer1);
    stock.addObserver(retailCustomer2);
    stock.addObserver(emailAlertCustomer);
    stock.addObserver(mobileAlertCustomer);

    // Simulate stock quantity changes
    stock.setQuantity(80); // Notify customers about the change

    // Output:
    // Notification for Alice: Stock 'ABC' quantity is now 80
    // Notification for Bob: Stock 'ABC' quantity is now 80
    // Sending email to alice@example.com: Stock 'ABC' quantity is now 80
    // Sending mobile alert to +1234567890: Stock 'ABC' quantity is now 80

    // Clean up memory (optional)
    delete retailCustomer1;
    delete retailCustomer2;
    delete emailAlertCustomer;
    delete mobileAlertCustomer;

    return 0;
}
