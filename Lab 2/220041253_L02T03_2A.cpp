#include <iostream>
using namespace std;

struct fraction{
    int numerator;
    int denominator;
};

int main(){
    fraction fraction1, fraction2, fraction3;
    char dummychar;
    cout << "Enter first fraction: ";
    cin >> fraction1.numerator >> dummychar >> fraction1.denominator;
    cout << "Enter second fraction: ";
    cin >> fraction2.numerator >> dummychar >> fraction2.denominator;
    fraction3.numerator = fraction1.numerator*fraction2.denominator + fraction2.numerator*fraction1.denominator;
    fraction3.denominator = fraction1.denominator*fraction2.denominator;
    cout << "Sum = " << fraction3.numerator << "/" << fraction3.denominator << endl;
}