/* it is a factory of factory*/
#include <iostream>

// Abstract Product A
class AbstractProductA {
public:
    virtual void use() const = 0;
    virtual ~AbstractProductA() {}
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void use() const override {
        std::cout << "Using Product A1" << std::endl;
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void use() const override {
        std::cout << "Using Product A2" << std::endl;
    }
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void consume() const = 0;
    virtual ~AbstractProductB() {}
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void consume() const override {
        std::cout << "Consuming Product B1" << std::endl;
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void consume() const override {
        std::cout << "Consuming Product B2" << std::endl;
    }
};

// Abstract Factory
class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB2();
    }
};

int main() {
    // Create Factory 1 and use it to create Product A1 and Product B1
    ConcreteFactory1 factory1;
    AbstractProductA* productA1 = factory1.createProductA();
    AbstractProductB* productB1 = factory1.createProductB();
    productA1->use(); // Output: Using Product A1
    productB1->consume(); // Output: Consuming Product B1

    // Create Factory 2 and use it to create Product A2 and Product B2
    ConcreteFactory2 factory2;
    AbstractProductA* productA2 = factory2.createProductA();
    AbstractProductB* productB2 = factory2.createProductB();
    productA2->use(); // Output: Using Product A2
    productB2->consume(); // Output: Consuming Product B2

    // Clean up: Remember to manually delete the created objects
    delete productA1;
    delete productB1;
    delete productA2;
    delete productB2;

    return 0;
}
