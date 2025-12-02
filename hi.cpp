#include<iostream>
using namespace std;

class Shape {
    public:
    virtual void draw() = 0;
    virtual void calculateArea() = 0;
    virtual ~Shape() {
        cout << "Shape Destructor Called\n";
    }
};

class Circle : public Shape {
    private:
    double radius;
    int *data;
    
    public:
    Circle(double r) {
        radius = r;
        data = new int[100];
        cout << "Circle Constructor - Memory Allocated\n";
    }
    
    ~Circle() {
        delete[] data;
        cout << "Circle Destructor Called - Memory Freed\n";
    }
    
    void draw() {
        cout << "Drawing Circle...\n";
    }
    
    void calculateArea() {
        double area = 3.14 * radius * radius;
        cout << "Circle Area: " << area << "\n";
    }
};

class Rectangle : public Shape {
    private:
    double length, width;
    int *data;
    
    public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
        data = new int[100];
        cout << "Rectangle Constructor - Memory Allocated\n";
    }
    
    ~Rectangle() {
        delete[] data;
        cout << "Rectangle Destructor Called - Memory Freed\n";
    }
    
    void draw() {
        cout << "Drawing Rectangle...\n";
    }
    
    void calculateArea() {
        double area = length * width;
        cout << "Rectangle Area: " << area << "\n";
    }
};

class Triangle : public Shape {
    private:
    double base, height;
    int *data;
    
    public:
    Triangle(double b, double h) {
        base = b;
        height = h;
        data = new int[100];
        cout << "Triangle Constructor - Memory Allocated\n";
    }
    
    ~Triangle() {
        delete[] data;
        cout << "Triangle Destructor Called - Memory Freed\n";
    }
    
    void draw() {
        cout << "Drawing Triangle...\n";
    }
    
    void calculateArea() {
        double area = (base * height) / 2;
        cout << "Triangle Area: " << area << "\n";
    }
};

int main() {
    cout << "=== Creating Shapes ===\n";
    Shape *shape1 = new Circle(5);
    Shape *shape2 = new Rectangle(10, 20);
    Shape *shape3 = new Triangle(8, 12);
    
    cout << "\n=== Circle ===\n";
    shape1->draw();
    shape1->calculateArea();
    
    cout << "\n=== Rectangle ===\n";
    shape2->draw();
    shape2->calculateArea();
    
    cout << "\n=== Triangle ===\n";
    shape3->draw();
    shape3->calculateArea();
    
    cout << "\n=== Deleting Shapes ===\n";
    delete shape1;
    delete shape2;
    delete shape3;
    
    cout << "\n=== All Cleaned Up ===\n";
    
    return 0;
}