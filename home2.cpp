#include<iostream>
using namespace std;

void india() {
cout << "India is my country" << endl;
return;
}

int main() {
    india();
    int i;
    float f;
    double d;   
    printf("Size of int: %zu bytes\n", sizeof(i));
    printf("Size of float: %zu bytes\n", sizeof(f));    
    for (i = 1; i <= 10; i++) {
        cout << "Hello, World!" << endl;
    }
    return 0;
}