#include<iostream>
using namespace std;
class Matrix {
    int mat[2][2];
    static int count;
    public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
        count++;
    }
    void display() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
    void multiply(Matrix &m) {
        int res[2][2] = {0};
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    res[i][j] += mat[i][k] * m.mat[k][j];
        cout << "Result:\n";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                cout << res[i][j] << " ";
            cout << "\n";
        }
    }
    static void getCount() {
        cout << "Total Matrices: " << count << "\n";
    }
};
int Matrix::count = 0;
int main() {
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);
    
    cout << "-----Matrix 1:-----\n";
    m1.display();
    cout << "-----Matrix 2:-----\n";
    m2.display();
    cout << "\n-----Multiplication:-----\n";
    m1.multiply(m2);
    
    Matrix::getCount();
    return 0;
}