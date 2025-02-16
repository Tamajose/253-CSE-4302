#include "Products.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateRandomString(int length){
    string randomString;
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < length; ++i){
        randomString += alphabet[rand() % alphabetSize];
    }
    return randomString;
}

int randomInRange(int min, int max){
    if(min>max){
        swap(min, max);
    }
    return rand()%(max-min+1)+min;
}

double randomInRange(double min, double max){
    if(min>max){
        swap(min, max);
    }
    double randomFraction = static_cast<double>(rand())/RAND_MAX;
    return min+randomFraction*(max-min);
}

void generateInformationRandom(Products &p){
    p.setname(generateRandomString(randomInRange(3,7)));
    p.setcategory(generateRandomString(randomInRange(3,7)));
    p.setdescription(generateRandomString(randomInRange(3,7)));
    p.setamount(randomInRange(0,100));
    p.setregular(randomInRange(0.00, 99.99));
    p.setdiscount(randomInRange(3.00, 14.99));
}

void Products::setname(const string &s){
    name = s;
}

void Products::setcategory(const string &s){
    category = s;
}

void Products::setdescription(const string &s){
    description = s;
}

void Products::setamount(int n){
    amount = n;
}

void Products::setregular(float n){
    regularprice = n;
}

void Products::setdiscount(float n){
    discountrate = n;
}

void EditInformationByKeyboard(Products &p){
    string name, category, description;
    int amount;
    float regular, discount;
    cout << "Product Name: ";
    cin.ignore();
    getline(cin, name);
    p.setname(name);
    cout << "Product Category: ";
    cin.ignore();
    getline(cin, category);
    p.setcategory(category);
    cout << "Product Description: ";
    cin.ignore();
    getline(cin, description);
    p.setdescription(description);
    cout << "Product Amount: ";
    cin >> amount;
    p.setamount(amount);
    cout << "Regular Price: ";
    cin >> regular;
    p.setregular(regular);
    cout << "Discount Rate: ";
    cin >> discount;
    p.setdiscount(discount);
}

string Products::getname(){
    return name;
}

string Products::getcategory(){
    return category;
}

string Products::getdescription(){
    return description;
}

int Products::getamount(){
    return amount;
}

float Products::getregular(){
    return regularprice;
}

float Products::getdiscount(){
    return discountrate;
}

void Products::PurchaseProducts(int n){
    if(amount<n){
        amount = 0;
    }
    else amount -= n;
}

void Products::RestockProduct(int n){
    amount += n;
}

double Products::calculateDiscount(int n){
    double total;
    if(n>=amount)
        n = amount;
    if(n>=10){
        total = ((discountrate+3)/100) * regularprice * n;
        return total;

    }
    else if(n>=5){
        total = (discountrate/100) * regularprice * n;
        return total;
    }
    return 0;
}

float Products::netTotal(int amountofProducts){
    float net;
    if(amountofProducts>=amount)
        amountofProducts = amount;
    net = amountofProducts*regularprice - calculateDiscount(amountofProducts);
    PurchaseProducts(amountofProducts);
    return net;
}

void ShowAllDiscount(Products ar[]){
    for(int i=0; i<100; i++){
        cout << "Product Name: " << ar[i].getname() << endl;
        cout << "Product Discount: " << ar[i].getdiscount() << endl;
    }
}

void grossTotal(Products ar[]){
    for(int i=0; i<100; i++){
        cout << "Product Name: " << ar[i].getname() << endl;
        cout << "Product Gross Total: " << ar[i].getregular() * ar[i].getamount() << endl;
    }
}

