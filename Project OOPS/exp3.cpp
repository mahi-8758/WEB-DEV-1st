#include<iostream>
#include<cmath>
using namespace std;
class Complex {
    double real, imag;
    public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(const Complex &c) {
        return Complex(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
    }
    operator double() {
        return sqrt(real*real + imag*imag);
    }
    void display() {
        if(imag >= 0)
            cout << real << " + " << imag << "i\n";
        else
            cout << real << " - " << -imag << "i\n";
    }
};
int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);  
    cout << "Complex 1: ";
    c1.display();
    cout << "Complex 2: ";
    c2.display();
    Complex c3 = c1 + c2;
    cout << "\nAddition: ";
    c3.display();
    Complex c4 = c1 - c2;
    cout << "Subtraction: ";
    c4.display();
    Complex c5 = c1 * c2;
    cout << "Multiplication: ";
    c5.display();
    double mag = (double)c1;
    cout << "\nMagnitude of c1: " << mag << "\n";
    Complex c6 = 5;
    cout << "Integer to Complex (5): ";
    c6.display();
    Complex c7 = 3.5;
    cout << "Double to Complex (3.5): ";
    c7.display();
    return 0;
}