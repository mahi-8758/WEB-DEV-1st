#include<iostream>
using namespace std;

class Vehicle {
    protected:
    string name;
    public:
    Vehicle(string n = "Vehicle") {
        name = n;
    }
    virtual void display() {
        cout << "Vehicle: " << name << "\n";
    }
};

class Car : public Vehicle {
    public:
    Car(string n = "Car") : Vehicle(n) {}
    void display() {
        cout << "Car: " << name << "\n";
    }
};

class Bike : public Vehicle {
    public:
    Bike(string n = "Bike") : Vehicle(n) {}
    void display() {
        cout << "Bike: " << name << "\n";
    }
};

class Engine {
    protected:
    int power;
    public:
    Engine(int p = 100) {
        power = p;
    }
    void showPower() {
        cout << "Power: " << power << " hp\n";
    }
};

class SportsCar : public Car, public Engine {
    public:
    SportsCar(string n, int p) : Car(n), Engine(p) {}
    void display() {
        cout << "Sports Car: " << name << ", ";
        showPower();
    }
};

int main() {
    cout << "=== Single Inheritance ===\n";
    Car c("Tesla");
    c.display();
    
    Bike b("Honda");
    b.display();
    
    cout << "\n=== Multiple Inheritance ===\n";
    SportsCar sc("Ferrari", 800);
    sc.display();
    
    cout << "\n=== Polymorphism ===\n";
    Vehicle *v1 = new Car("BMW");
    Vehicle *v2 = new Bike("Yamaha");
    v1->display();
    v2->display();
    
    return 0;
}