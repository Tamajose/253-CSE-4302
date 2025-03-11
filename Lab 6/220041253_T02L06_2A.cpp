#include <iostream>
using namespace std;

class Matrix3D{
    private:
        int a1, a2, a3, b1, b2, b3, c1, c2, c3;
        int increment;

    public:
        Matrix3D(){
            a1 = a2 = a3 = b1 = b2 = b3 = c1 = c2 = c3 = 0;
            increment = 1;
        }

        Matrix3D(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int m9, int val){
            a1 = m1;    a2 = m2;    a3 = m3;
            b1 = m4;    b2 = m5;    b3 = m6;
            c1 = m7;    c2 = m8;    c3 = m9;
            if(val<0)
                increment = 1;
            else
                increment = val;
        }

        double det(){
            return a1*(b2*c3-b3*c2) - a2*(b1*c3-b3*c1) + a3*(b1*c2-b2*c1);
        }

        Matrix3D inverse(){
            Matrix3D inv;
            double d = det();
            if(d==0){
                cout << "Matrix is singular" << endl;
                return;
            }
            inv.a1 = (b2*c3-b3*c2);
            inv.a2 = -(a2*c3-a3*c2);
            inv.a3 = (a2*b3-a3*b2);
            inv.b1 = -(b1*c3-b3*c1);
            inv.b2 = (a1*c3-a3*c1);
            inv.b3 = -(a1*b3-a3*b1);
            inv.c1 = (b1*c2-b2*c1);
            inv.c2 = -(a1*c2-a2*c1);
            inv.c3 = (a1*b2-a2*b1);
            return inv;
        }

        void setIncrement(int val){
            if(val<0)
                return;
            else
                increment = val;
        }

        void getMatrix(){
            cout << a1 << " " << a2 << " " << a3 << endl;
            cout << b1 << " " << b2 << " " << b3 << endl;
            cout << c1 << " " << c2 << " " << c3 << endl;
        }

        void increment(){
            a1 += increment;    a2 += increment;    a3 += increment;
            b1 += increment;    b2 += increment;    b3 += increment;
            c1 += increment;    c2 += increment;    c3 += increment;
        }
        
        ~Matrix3D(){
            cout << "Matrix3D destroyed" << endl;
        }
};