// ATM, logger, Vending machine
// we send request and we don't care which receiver handles the request we just execute
#include <iostream>
#include <string>

using namespace std;

// Abstract base class for handling requests
class Handler {
public:
    virtual ~Handler() {}
    virtual void handleRequest(const string& request) = 0;
    void setNext(Handler* next) { nextHandler = next; }
    Handler* getNext() const { return nextHandler; }

private:
    Handler* nextHandler = nullptr;
};

// Concrete handler 1: Handles requests starting with 'A'
class ConcreteHandler1 : public Handler {
public:
    void handleRequest(const string& request) override {
        if (request[0] == 'A') {
            cout << "ConcreteHandler1 handled the request: " << request << endl;
        } else if (getNext() != nullptr) {
            getNext()->handleRequest(request);
        }
    }
};

// Concrete handler 2: Handles requests starting with 'B'
class ConcreteHandler2 : public Handler {
public:
    void handleRequest(const string& request) override {
        if (request[0] == 'B') {
            cout << "ConcreteHandler2 handled the request: " << request << endl;
        } else if (getNext() != nullptr) {
            getNext()->handleRequest(request);
        }
    }
};

// Client
int main() {
    // Create chain of handlers
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();
    handler1->setNext(handler2);

    // Send requests
    handler1->handleRequest("Apple");
    handler1->handleRequest("Banana");
    handler1->handleRequest("Orange");

    // Clean up
    delete handler1;
    delete handler2;

    return 0;
}
