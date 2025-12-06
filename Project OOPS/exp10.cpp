#include<bits/stdc++.h>
using namespace std;
class Complex {
    double real, imag;
    public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(const Complex &c) {
        return Complex(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
    }
    Complex operator/(const Complex &c) {
        double denom = c.real*c.real + c.imag*c.imag;
        return Complex((real*c.real + imag*c.imag)/denom, (imag*c.real - real*c.imag)/denom);
    }
    void display(ostream &out) {
        if(imag >= 0)
            out << "(" << real << " + " << imag << "i)";
        else
            out << "(" << real << " - " << -imag << "i)";
    }
};

int main() {
    srand(time(0));
    ofstream file("complex.txt");
    char ops[] = {'+', '-', '*', '/'};
    for(int i = 0; i < 5; i++) {
        Complex c1(rand()%10, rand()%10);
        Complex c2(rand()%10, rand()%10);
        char op = ops[rand()%4];
        c1.display(file);
        file << " " << op << " ";
        c2.display(file);
        file << "\n";
    }
    file.close();
    cout << "Complex numbers written to complex.txt\n";
    ifstream infile("complex.txt");
    string line;
    cout << "\nFile Contents:\n";
    while(getline(infile, line))
        cout << line << "\n";
    infile.close();
    return 0;
}