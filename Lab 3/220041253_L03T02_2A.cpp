#include <iostream>
using namespace std;

class RationalNumber{
    private:
        int numerator;
        int denominator;
    public:
        void assign(int numer, int denom){
            if(denom==0){
                cout << "You can not assign 0 as denominator." << endl;
            }
            else{
                numerator = numer;
                denominator = denom;
            }
        }
        double convert(){
            double num = numerator;
            double den = denominator;
            double decimal = num / den;
            return decimal;
        }
        void invert(){
            if(numerator==0){
                cout << "You can not assign 0 as denominator." << endl << "Inversion failed." << endl;
            }
            else{
                int temp = denominator;
                denominator = numerator;
                numerator = temp;
            }
        }
        void print(){
            cout << "The Rational Number is " << numerator << "/" << denominator << endl;
        }
};

int main(){
    RationalNumber num1, num2, num3;

    num1.assign(3,4);
    num1.print();
    cout << "The decimal equivalent is: " << num1.convert() << endl;
    num1.invert();
    num1.print();
    
    num2.assign(1,0);
    num2.print();

    num3.assign(0,4);
    num3.print();
    cout << "The decimal equivalent is: " << num3.convert() << endl;
    num3.invert();
}