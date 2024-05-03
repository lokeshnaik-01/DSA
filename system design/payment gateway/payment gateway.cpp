
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// BankAccount class to store account details
class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    BankAccount(const string& holderName, const string& number, double initialBalance)
        : accountHolderName(holderName), accountNumber(number), balance(initialBalance) {}

    const string& getAccountHolderName() const {
        return accountHolderName;
    }

    const string& getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    bool deductAmount(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            cout << "Insufficient balance in account " << accountNumber << endl;
            return false;
        }
    }

    void addMoney(double amount) {
        balance += amount;
    }
};

// Abstract base class for PaymentMethod
class PaymentMethod {
public:
    virtual ~PaymentMethod() {}
    virtual bool processPayment(double amount) = 0;
};

// Concrete implementation of PaymentMethod for UPI
class UPI : public PaymentMethod {
private:
    string upiId;
    BankAccount& bankAccount; // Reference to BankAccount object

public:
    UPI(const string& upiId, BankAccount& account) : upiId(upiId), bankAccount(account) {}

    bool processPayment(double amount) override {
        // Validate UPI ID before processing payment
        if (!isValidUpiId(upiId)) {
            cout << "Invalid UPI ID" << endl;
            return false;
        }

        // Process payment using the associated bank account
        if (bankAccount.deductAmount(amount)) {
            cout << "UPI payment of $" << amount << " processed successfully for UPI ID: " << upiId << endl;
            cout << "Remaining balance in account " << bankAccount.getAccountNumber() << ": $" << bankAccount.getBalance() << endl;
            return true;
        } else {
            cout << "UPI payment failed" << endl;
            return false;
        }
    }

private:
    bool isValidUpiId(const string& upiId) const {
        // Simulated UPI ID validation logic (e.g., length check, format check)
        return !upiId.empty() && upiId.length() >= 5; // Placeholder validation logic
    }
};

// Concrete implementation of PaymentMethod for Debit Card
class DebitCard : public PaymentMethod {
private:
    string cardNumber;
    string pin;
    BankAccount& bankAccount; // Reference to BankAccount object

public:
    DebitCard(const string& cardNumber, const string& pin, BankAccount& account)
        : cardNumber(cardNumber), pin(pin), bankAccount(account) {}

    bool processPayment(double amount) override {
        // Simulate checking bank balance before processing debit card payment
        if (bankAccount.deductAmount(amount)) {
            cout << "Debit card payment of $" << amount << " processed successfully for card number: " << cardNumber << endl;
            cout << "Remaining balance in account " << bankAccount.getAccountNumber() << ": $" << bankAccount.getBalance() << endl;
            return true;
        } else {
            cout << "Insufficient balance for debit card payment" << endl;
            return false;
        }
    }
};

// Concrete implementation of PaymentMethod for Credit Card
class CreditCard : public PaymentMethod {
private:
    string cardNumber;
    string expiryDate;
    string cvv;
    double totalSpent; // Track total amount spent using the credit card

public:
    CreditCard(const string& cardNumber, const string& expiryDate, const string& cvv)
        : cardNumber(cardNumber), expiryDate(expiryDate), cvv(cvv), totalSpent(0.0) {}

    bool processPayment(double amount) override {
        // Simulate credit card processing without balance check
        cout << "Credit card payment of $" << amount << " processed successfully for card number: " << cardNumber << endl;
        totalSpent += amount; // Update total amount spent
        cout << "Total amount spent using this credit card: $" << totalSpent << endl;
        return true;
    }
};

// Payment class responsible for processing payments using a selected payment method
class Payment {
private:
    PaymentMethod& paymentMethod; // Reference to PaymentMethod object

public:
    Payment(PaymentMethod& method) : paymentMethod(method) {}

    bool process(double amount) {
        // Validate payment amount
        if (amount <= 0) {
            cout << "Invalid payment amount" << endl;
            return false;
        }

        // Process payment using the selected payment method
        return paymentMethod.processPayment(amount);
    }
};

int main() {
    // Create bank accounts for payment methods
    BankAccount upiAccount("John Doe", "1234567890", 500.0);
    BankAccount debitCardAccount("John Doe", "9876543210", 1000.0);

    // Add money to UPI account
    upiAccount.addMoney(100000.0);
    cout << "Balance in UPI account: $" << upiAccount.getBalance() << endl;

    // Example usage of UPI payment
    UPI upiPayment("john@upi", upiAccount);
    Payment upiTransaction(upiPayment);
    double upiAmount = 200.0;
    upiTransaction.process(upiAmount);

    // Example usage of Debit Card payment
    DebitCard debitCardPayment("1234567890123456", "4567", debitCardAccount);
    Payment debitCardTransaction(debitCardPayment);
    double debitCardAmount = 300.0;
    debitCardTransaction.process(debitCardAmount);

    // Example usage of Credit Card payment
    CreditCard creditCardPayment("9876543210987654", "12/23", "123");
    Payment creditCardTransaction(creditCardPayment);
    double creditCardAmount = 150.0;
    creditCardTransaction.process(creditCardAmount);

    return 0;
}