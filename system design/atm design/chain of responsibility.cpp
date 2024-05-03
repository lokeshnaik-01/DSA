#include <iostream>
#include <string>

using namespace std;

// Forward declaration of ATM class
class ATM;

// ATMHandler abstract base class
class ATMHandler {
protected:
    ATMHandler* nextHandler;

public:
    ATMHandler() : nextHandler(nullptr) {}

    // Set the next handler in the chain
    void setNextHandler(ATMHandler* handler) {
        nextHandler = handler;
    }

    // Handle the request or pass it to the next handler
    virtual void handle(string request, ATM* atm) {
        if (nextHandler != nullptr) {
            nextHandler->handle(request, atm);
        } else {
            cout << "Request cannot be handled." << endl;
        }
    }
};

// ATM class representing the ATM machine
class ATM {
private:
    ATMHandler* handler;
    double balance;

public:
    ATM() : handler(nullptr), balance(0.0) {}

    // Set the first handler in the chain
    void setHandler(ATMHandler* handler) {
        this->handler = handler;
    }

    // Method to handle user input
    void handleRequest(string request) {
        if (handler != nullptr) {
            handler->handle(request, this);
        } else {
            cout << "No handler available to process the request." << endl;
        }
    }

    // Get the current balance
    double getBalance() const {
        return balance;
    }

    // Set the balance
    void setBalance(double amount) {
        balance = amount;
    }
};

// Concrete class representing the card insertion handler
class CardInsertionHandler : public ATMHandler {
public:
    void handle(string request, ATM* atm) override {
        if (request == "insert_card") {
            cout << "Card inserted." << endl;
        } else {
            ATMHandler::handle(request, atm);
        }
    }
};

// Concrete class representing the PIN entry handler
class PinEntryHandler : public ATMHandler {
public:
    void handle(string request, ATM* atm) override {
        if (request == "enter_pin") {
            cout << "PIN entered." << endl;
        } else {
            ATMHandler::handle(request, atm);
        }
    }
};

// Concrete class representing the cash withdrawal handler
class CashWithdrawalHandler : public ATMHandler {
public:
    void handle(string request, ATM* atm) override {
        if (request == "withdraw_cash") {
            cout << "Cash withdrawn." << endl;
        } else {
            ATMHandler::handle(request, atm);
        }
    }
};

// Concrete class representing the cash deposit handler
class CashDepositHandler : public ATMHandler {
public:
    void handle(string request, ATM* atm) override {
        if (request == "deposit_cash") {
            cout << "Cash deposited." << endl;
        } else {
            ATMHandler::handle(request, atm);
        }
    }
};

// Concrete class representing the balance checking handler
class BalanceCheckHandler : public ATMHandler {
public:
    void handle(string request, ATM* atm) override {
        if (request == "check_balance") {
            cout << "Current Balance: $" << atm->getBalance() << endl;
        } else {
            ATMHandler::handle(request, atm);
        }
    }
};

int main() {
    ATM atm;

    // Create and set up the chain of responsibility
    CardInsertionHandler cardHandler;
    PinEntryHandler pinHandler;
    CashWithdrawalHandler cashHandler;
    CashDepositHandler depositHandler;
    BalanceCheckHandler balanceHandler;

    cardHandler.setNextHandler(&pinHandler);
    pinHandler.setNextHandler(&cashHandler);
    cashHandler.setNextHandler(&depositHandler);
    depositHandler.setNextHandler(&balanceHandler);

    atm.setHandler(&cardHandler);

    // Simulate ATM operations
    atm.handleRequest("insert_card");
    atm.handleRequest("enter_pin");
    atm.handleRequest("withdraw_cash");
    atm.handleRequest("deposit_cash");
    atm.setBalance(1000.0); // Set balance to $1000 for demonstration
    atm.handleRequest("check_balance");
    atm.handleRequest("invalid_request");

    return 0;
}
