#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3, den1, den2, den3;
    char dummychar;
    cout << "Enter first fraction: ";
    cin >> num1 >> dummychar >> den1;
    cout << "Enter second fraction: ";
    cin >> num2 >> dummychar >> den2;
    num3 = num1*den2 + num2*den1;
    den3 = den1*den2;
    cout << "Sum = " << num3 << "/" << den3 << endl;
}