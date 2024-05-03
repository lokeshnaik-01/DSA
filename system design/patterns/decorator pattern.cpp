#include <iostream>
#include <string>

using namespace std;

// Component Interface (Base class)
class Coffee {
public:
    virtual ~Coffee() {}
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    string getDescription() const override {
        return "Simple Coffee";
    }

    double getCost() const override {
        return 1.0; // Cost of simple coffee
    }
};

// Decorator Base Class
class CoffeeDecorator : public Coffee {
protected:
    Coffee& coffee;

public:
    CoffeeDecorator(Coffee& baseCoffee)
        : coffee(baseCoffee) {}

    string getDescription() const override {
        return coffee.getDescription();
    }

    double getCost() const override {
        return coffee.getCost();
    }
};

// Concrete Decorator - Milk
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee& baseCoffee)
        : CoffeeDecorator(baseCoffee) {}

    string getDescription() const override {
        return coffee.getDescription() + ", with Milk";
    }

    double getCost() const override {
        return coffee.getCost() + 0.5; // Additional cost for milk
    }
};

// Concrete Decorator - Sugar
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee& baseCoffee)
        : CoffeeDecorator(baseCoffee) {}

    string getDescription() const override {
        return coffee.getDescription() + ", with Sugar";
    }

    double getCost() const override {
        return coffee.getCost() + 0.2; // Additional cost for sugar
    }
};

// Usage Example
int main() {
    // Create a simple coffee
    SimpleCoffee simpleCoffee;

    // Decorate the coffee with Milk
    MilkDecorator milkCoffee(simpleCoffee);

    // Decorate the milk coffee with Sugar
    SugarDecorator sugarMilkCoffee(milkCoffee);

    // Get final description and cost
    cout << "Description: " << sugarMilkCoffee.getDescription() << endl;
    cout << "Cost: $" << sugarMilkCoffee.getCost() << endl;

    return 0;
}
