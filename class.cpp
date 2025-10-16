#include<iostream> // Include the iostream library for input/output
using namespace std; // Use the standard namespace

// Define a class named myClass
class myClass{
public:
    // Define a public method inside the class
    void myMethod()
    {
        cout << "Hello World"; // Print Hello World to the console
    }
};

int main()
{
    myClass obj; // Create an object of myClass
    obj.myMethod(); // Call the method of the object
    return 0; // End of the program
}