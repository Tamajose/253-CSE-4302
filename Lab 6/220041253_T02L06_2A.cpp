#include <iostream>
using namespace std;

class Matrix{
    private:
        int a1, a2, a3, b1, b2, b3, c1, c2, c3;
        int increment;
    public:
        Matrix(){
            a1 = a2 = a3 = b1 = b2 = b3 = c1 = c2 = c3 = 0;
        }
        Matrix(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int m9){
            a1 = m1;
            a2 = m2;
            a3 = m3;
            b1 = m4;
            b2 = m5;
            a1 = m6;
            a1 = m7;
            a1 = m8;
            a1 = m9;
        }
        
        ~Matrix(){
            cout << "Matrix destroyed" << endl;
        }
};