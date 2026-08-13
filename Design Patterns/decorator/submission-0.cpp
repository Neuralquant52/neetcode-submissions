class Coffee {
public:
    virtual double getCost() = 0; // Pure virtual function makes this class abstract
};

class SimpleCoffee : public Coffee {
public:
    double getCost() override {
        return 1.1;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator() = default;
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    double getCost() override {
        return decoratedCoffee->getCost();
    }
};

class MilkDecorator : public CoffeeDecorator {
protected:
    Coffee* decoratedCoffee;
public:
    MilkDecorator() = delete;
    MilkDecorator(Coffee* coffee) : decoratedCoffee(coffee) {};

    double getCost() override {
        return decoratedCoffee->getCost() + 0.5;
    }
    // Implement the Milk decorator
};

class SugarDecorator : public CoffeeDecorator {
protected:
    Coffee* decoratedCoffee;
public:
    SugarDecorator() = delete;
    SugarDecorator(Coffee* coffee) : decoratedCoffee(coffee) {};

    double getCost() override {
        return decoratedCoffee->getCost() + 0.2;
    }
    // Implement the Sugar decorator
};

class CreamDecorator : public CoffeeDecorator {
protected:
    Coffee* decoratedCoffee;
public:
    CreamDecorator() = delete;
    CreamDecorator(Coffee* coffee) : decoratedCoffee(coffee) {};

    double getCost() override {
        return decoratedCoffee->getCost() + 0.7;
    }
    // Implement the Cream decorator
};
