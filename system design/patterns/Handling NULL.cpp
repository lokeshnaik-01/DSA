/*
    we should try to avoid unnecessary NULL pointer check

- A NULL object replaces NULL return type
- Null object refelecrs do Nothing 
- NULL object does nothing default behaviour 
*/
#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class AbstractObject {
public:
    virtual ~AbstractObject() {}
    virtual void doSomething() = 0;
    virtual string getName() = 0;
    virtual int getValue() = 0;
};

// Concrete class 1
class ConcreteObject1 : public AbstractObject {
public:
    void doSomething() override {
        cout << "Doing something in ConcreteObject1" << endl;
    }

    string getName() override {
        return "ConcreteObject1";
    }

    int getValue() override {
        return 100;
    }
};

// Concrete class 2
class ConcreteObject2 : public AbstractObject {
public:
    void doSomething() override {
        cout << "Doing something in ConcreteObject2" << endl;
    }

    string getName() override {
        return "ConcreteObject2";
    }

    int getValue() override {
        return 200;
    }
};

// Null Object class
class NullObject : public AbstractObject {
public:
    void doSomething() override {
        // Do nothing
    }

    string getName() override {
        return "NullObject";
    }

    int getValue() override {
        return 0; // Default value for NullObject
    }
};

// Function to perform an action on an AbstractObject
void performAction(AbstractObject& obj) {
    obj.doSomething();
}

// Function to get the name of an AbstractObject
string getName(AbstractObject& obj) {
    return obj.getName();
}

// Function to get the value of an AbstractObject
int getValue(AbstractObject& obj) {
    return obj.getValue();
}

int main() {
    // Create instances of concrete classes
    ConcreteObject1 obj1;
    ConcreteObject2 obj2;

    // Use concrete objects
    performAction(obj1);
    cout << "Object 1 name: " << getName(obj1) << endl;
    cout << "Object 1 value: " << getValue(obj1) << endl;

    performAction(obj2);
    cout << "Object 2 name: " << getName(obj2) << endl;
    cout << "Object 2 value: " << getValue(obj2) << endl;

    // Use Null Object
    NullObject nullObj;
    performAction(nullObj); // Does nothing
    cout << "Null Object name: " << getName(nullObj) << endl;
    cout << "Null Object value: " << getValue(nullObj) << endl;

    return 0;
}


/*
In this example, AbstractObject is the base class defining the interface for all objects in the hierarchy. ConcreteObject1 and ConcreteObject2 are concrete implementations of AbstractObject, while NullObject is a specific implementation of AbstractObject which performs no operation in its methods.

This way, you can replace nullptr checks with checks for the Null Object, ensuring that your code is more robust and easier to maintain.
*/