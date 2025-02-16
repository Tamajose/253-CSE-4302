#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <string>
using namespace std;

class Products{
    private:
        string name;
        string category;
        string description;
        int amount;
        float regularprice;
        float discountrate;

    public:
        Products(){
            name = "N/A";
            category = "N/A";
            description = "N/A";
            amount = 0;
            regularprice = 0.0;
            discountrate = 0.0;
        }
        void setname(const string &s);
        void setcategory(const string &s);
        void setdescription(const string &s);
        void setamount(int n);
        void setregular(float n);
        void setdiscount(float n);
        string getname();        
        string getcategory();
        string getdescription();
        int getamount();
        float getregular();
        float getdiscount();
        void PurchaseProducts(int n);
        void RestockProduct(int n);
        double calculateDiscount(int n);
        float netTotal(int amountofProducts);
};

void EditInformationByKeyboard(Products &p);
string generateRandomString(int length);
int randomInRange(int min, int max);
double randomInRange(double min, double max);
void generateInformationRandom(Products &p);
void ShowAllDiscount(Products ar[]);
void grossTotal(Products ar[]);

#endif