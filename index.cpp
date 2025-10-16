#include<iostream>
#include<cmath>
using namespace std;

// Function declarations for treasure box
void printSpaces(int count) {
    for(int i = 0; i < count; i++) cout << " ";
}

void printStars(int count) {
    for(int i = 0; i < count; i++) cout << "*";
}

void drawTopPerspective(int depth, int width) {
    for(int d = depth; d > 0; d--) {
        printSpaces(d);
        printStars(width);
        cout << endl;
    }
}

void drawJewelPattern(int width) {
    cout << "*";
    for(int j = 0; j < width-2; j++) {
        if(j % 4 == 0) cout << "$";
        else if(j % 2 == 0) cout << "@";
        else cout << " ";
    }
    cout << "*";
}

void drawMiddlePattern(int width) {
    cout << "*";
    for(int j = 0; j < width-2; j++) {
        if(j % 3 == 0) cout << "#";
        else cout << " ";
    }
    cout << "*";
}

void drawBottomPattern(int width) {
    cout << "*";
    for(int j = 0; j < width-2; j++) {
        cout << (j % 2 == 0 ? "=" : "-");
    }
    cout << "*";
}

void drawSidePerspective(int depth, bool isEdge) {
    for(int d = 0; d < depth; d++) {
        cout << (isEdge ? "*" : " ");
    }
    cout << "*";
}

void drawTreasureBox() {
    const int height = 8;
    const int width = 20;
    const int depth = 4;
    
    cout << "\n=== Treasure Box ===\n\n";
    
    drawTopPerspective(depth, width);
    
    for(int i = 0; i < height; i++) {
        if(i < 2) drawJewelPattern(width);
        else if(i < height-1) drawMiddlePattern(width);
        else drawBottomPattern(width);
        
        drawSidePerspective(depth, (i == 0 || i == height-1));
        cout << endl;
    }
    cout << endl;
}

void checkEvenOdd() {
    int number;
    cout << "\n=== Even/Odd Checker ===\n";
    cout << "Enter a number: ";
    cin >> number;
    cout << "The number is " << (number % 2 == 0 ? "even" : "odd") << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Draw Treasure Box\n";
        cout << "2. Check Even/Odd\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch(choice) {
            case 1:
                drawTreasureBox();
                break;
            case 2:
                checkEvenOdd();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 3);

    return 0;
}