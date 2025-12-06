#include<iostream>
using namespace std;

class MyClass {
    int data;
    public:
    MyClass(int d = 0) {
        data = d;
        cout << "Constructor called: data = " << data << "\n";
    }
    
    ~MyClass() {
        cout << "Destructor called: data = " << data << "\n";
    }
    
    void* operator new(size_t size) {
        cout << "Custom new called, size = " << size << "\n";
        return malloc(size);
    }
    
    void operator delete(void *ptr) {
        cout << "Custom delete called\n";
        free(ptr);
    }
    
    void display() {
        cout << "Data: " << data << "\n";
    }
};

int main() {
    cout << "Creating object using new:\n";
    MyClass *obj1 = new MyClass(10);
    obj1->display();
    
    cout << "\nCreating another object:\n";
    MyClass *obj2 = new MyClass(20);
    obj2->display();
    
    cout << "\nDeleting obj1:\n";
    delete obj1;
    
    cout << "\nDeleting obj2:\n";
    delete obj2;
    
    return 0;
}