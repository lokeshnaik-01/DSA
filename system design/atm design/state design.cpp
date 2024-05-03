#include <iostream>
#include <string>

using namespace std;

// Forward declaration of ATMState class
class ATMState;

// ATM class representing the ATM machine
class ATM {
private:
    ATMState* currentState;

public:
    ATM();

    // Set current state of ATM
    void setCurrentState(ATMState* state);

    // Various operations supported by ATM
    void insertCard();
    void ejectCard();
    void insertPin(int pin);
    void withdrawCash(int amount);
};

// ATMState abstract base class
class ATMState {
protected:
    ATM* atm;

public:
    ATMState(ATM* atm) : atm(atm) {}

    virtual void insertCard() = 0;
    virtual void ejectCard() = 0;
    virtual void insertPin(int pin) = 0;
    virtual void withdrawCash(int amount) = 0;
};

// Concrete class representing ATM state when no card is inserted
class NoCardState : public ATMState {
public:
    NoCardState(ATM* atm) : ATMState(atm) {}

    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void withdrawCash(int amount) override;
};

// Concrete class representing ATM state when card is inserted
class CardInsertedState : public ATMState {
public:
    CardInsertedState(ATM* atm) : ATMState(atm) {}

    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void withdrawCash(int amount) override;
};

// Concrete class representing ATM state when pin is entered
class PinEnteredState : public ATMState {
public:
    PinEnteredState(ATM* atm) : ATMState(atm) {}

    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void withdrawCash(int amount) override;
};

// Concrete class representing ATM state when cash is being withdrawn
class CashWithdrawnState : public ATMState {
public:
    CashWithdrawnState(ATM* atm) : ATMState(atm) {}

    void insertCard() override;
    void ejectCard() override;
    void insertPin(int pin) override;
    void withdrawCash(int amount) override;
};

// Implementation of ATM methods

ATM::ATM() {
    currentState = new NoCardState(this);
}

void ATM::setCurrentState(ATMState* state) {
    currentState = state;
}

void ATM::insertCard() {
    currentState->insertCard();
}

void ATM::ejectCard() {
    currentState->ejectCard();
}

void ATM::insertPin(int pin) {
    currentState->insertPin(pin);
}

void ATM::withdrawCash(int amount) {
    currentState->withdrawCash(amount);
}

// Implementation of NoCardState methods

void NoCardState::insertCard() {
    cout << "Card inserted" << endl;
    atm->setCurrentState(new CardInsertedState(atm));
}

void NoCardState::ejectCard() {
    cout << "No card to eject" << endl;
}

void NoCardState::insertPin(int pin) {
    cout << "Please insert a card first" << endl;
}

void NoCardState::withdrawCash(int amount) {
    cout << "Please insert a card first" << endl;
}

// Implementation of CardInsertedState methods

void CardInsertedState::insertCard() {
    cout << "Card already inserted" << endl;
}

void CardInsertedState::ejectCard() {
    cout << "Card ejected" << endl;
    atm->setCurrentState(new NoCardState(atm));
}

void CardInsertedState::insertPin(int pin) {
    cout << "PIN entered: " << pin << endl;
    atm->setCurrentState(new PinEnteredState(atm));
}

void CardInsertedState::withdrawCash(int amount) {
    cout << "Please enter PIN first" << endl;
}

// Implementation of PinEnteredState methods

void PinEnteredState::insertCard() {
    cout << "Card already inserted" << endl;
}

void PinEnteredState::ejectCard() {
    cout << "Card ejected" << endl;
    atm->setCurrentState(new NoCardState(atm));
}

void PinEnteredState::insertPin(int pin) {
    cout << "PIN already entered" << endl;
}

void PinEnteredState::withdrawCash(int amount) {
    cout << "Cash withdrawn: $" << amount << endl;
    atm->setCurrentState(new CashWithdrawnState(atm));
}

// Implementation of CashWithdrawnState methods

void CashWithdrawnState::insertCard() {
    cout << "Transaction completed. Please take your card." << endl;
    atm->setCurrentState(new NoCardState(atm));
}

void CashWithdrawnState::ejectCard() {
    cout << "Transaction completed. Please take your card." << endl;
    atm->setCurrentState(new NoCardState(atm));
}

void CashWithdrawnState::insertPin(int pin) {
    cout << "Transaction completed. Please take your card." << endl;
    atm->setCurrentState(new NoCardState(atm));
}

void CashWithdrawnState::withdrawCash(int amount) {
    cout << "Transaction completed. Please take your card." << endl;
    atm->setCurrentState(new NoCardState(atm));
}

int main() {
    ATM atm;
    
    atm.insertCard();
    atm.ejectCard();
    atm.insertPin(1234);
    atm.withdrawCash(100);
    
    atm.insertCard();
    atm.insertCard();
    atm.ejectCard();
    
    atm.insertCard();
    atm.insertPin(1234);
    atm.insertPin(5678);
    atm.withdrawCash(200);
    
    return 0;
}
