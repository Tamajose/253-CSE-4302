#include "Products.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Products p[100];
    EditInformationByKeyboard(p[0]);
    EditInformationByKeyboard(p[1]);
    for(int i=2; i<100; i++){
        generateInformationRandom(p[i]);
    }
    for(int i=0; i<100; i++){
        cout << p[i].getname() << " - " << p[i].getamount() << endl;
    }
}