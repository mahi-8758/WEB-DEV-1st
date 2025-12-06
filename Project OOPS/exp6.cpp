#include<iostream>
#include<typeinfo>
using namespace std;

class Shape {
    public:
    virtual void draw() {
        cout << "Drawing Shape\n";
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
    public:
    void draw() {
        cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
    public:
    void draw() {
        cout << "Drawing Square\n";
    }
};

class Triangle : public Shape {
    public:
    void draw() {
        cout << "Drawing Triangle\n";
    }
};

int main() {
    Shape *shapes[3];
    shapes[0] = new Circle();
    shapes[1] = new Square();
    shapes[2] = new Triangle();
    
    cout << "=== Dynamic Polymorphism ===\n";
    for(int i = 0; i < 3; i++)
        shapes[i]->draw();
    
    cout << "\n=== RTTI (Runtime Type Information) ===\n";
    for(int i = 0; i < 3; i++) {
        cout << "Type: " << typeid(*shapes[i]).name() << "\n";
        
        Circle *c = dynamic_cast<Circle*>(shapes[i]);
        Square *s = dynamic_cast<Square*>(shapes[i]);
        Triangle *t = dynamic_cast<Triangle*>(shapes[i]);
        
        if(c) cout << "It's a Circle\n";
        if(s) cout << "It's a Square\n";
        if(t) cout << "It's a Triangle\n";
    }
    
    return 0;
}