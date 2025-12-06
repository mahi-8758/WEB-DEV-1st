#include<iostream>
using namespace std;
class Matrix {
    int rows, cols;
    int **data;
    public:
    Matrix(int r = 2, int c = 2) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for(int i = 0; i < rows; i++)
            data[i] = new int[cols];
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                data[i][j] = (i+1)*(j+1);}
    ~Matrix() {
        for(int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;}
    Matrix(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;
        data = new int*[rows];
        for(int i = 0; i < rows; i++)
            data[i] = new int[cols];
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                data[i][j] = m.data[i][j]; }
    Matrix& operator=(const Matrix &m) {
        if(this == &m) return *this;
        for(int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
        rows = m.rows;
        cols = m.cols;
        data = new int*[rows];
        for(int i = 0; i < rows; i++)
            data[i] = new int[cols];
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                data[i][j] = m.data[i][j];
        return *this;}
    void display() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << "\n";} }
};
int main() {
    Matrix m1(2, 2);
    cout << "-----Matrix 1:-----\n";
    m1.display();  
    Matrix m2 = m1;
    cout << "-----Copy Constructor (m2 = m1):-----\n";
    m2.display();
    Matrix m3(2, 2);
    cout << "-----Matrix 3:-----\n";
    m3.display();
    m1 = m3;
    cout << "-----Assignment Operator (m1 = m3):-----\n";
    m1.display();
    return 0;
}