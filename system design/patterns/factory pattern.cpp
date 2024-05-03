/* when ever object is created but on the basis of some condition based on cond1 we create obj1, on cond2 we create obj2*/
/*
+-----------------+       +-------------------+
|   ParkingLot    |       |   ParkingSpace    |
+-----------------+       +-------------------+
| - totalSpaces    |       | - spaceId         |
| - availableSpaces|-------| - occupied        |
| - parkingSpaces[]|       |                   |
| + parkVehicle() |       |                   |
| + removeVehicle()|       +-------------------+
+-----------------+       |      Vehicle      |
                          +-------------------+
                          | - licensePlate     |
                          | - vehicleType      |
                          | - entryTimestamp   |
                          | - exitTimestamp    |
                          +-------------------+
                          |      Ticket       |
                          +-------------------+
                          | - ticketId         |
                          | - vehicle          |
                          | - parkingSpace     |
                          | - entryTimestamp   |
                          +-------------------+

*/
#include <iostream>
#include <memory>

// Product Interface
class Product {
public:
    virtual void use() const = 0;
    virtual ~Product() {}
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void use() const override {
        std::cout << "Using Product A" << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void use() const override {
        std::cout << "Using Product B" << std::endl;
    }
};

// Factory Interface
class Factory {
public:
    virtual std::shared_ptr<Product> createProduct() const = 0;
};

// Concrete Factory for Product A
class ConcreteFactoryA : public Factory {
public:
    std::shared_ptr<Product> createProduct() const override {
        return std::make_shared<ConcreteProductA>();
    }
};

// Concrete Factory for Product B
class ConcreteFactoryB : public Factory {
public:
    std::shared_ptr<Product> createProduct() const override {
        return std::make_shared<ConcreteProductB>();
    }
};

int main() {
    // Create Factory A and use it to create Product A
    std::unique_ptr<Factory> factoryA = std::make_unique<ConcreteFactoryA>();
    auto productA = factoryA->createProduct();
    productA->use(); // Output: Using Product A

    // Create Factory B and use it to create Product B
    std::unique_ptr<Factory> factoryB = std::make_unique<ConcreteFactoryB>();
    auto productB = factoryB->createProduct();
    productB->use(); // Output: Using Product B

    return 0;
}
