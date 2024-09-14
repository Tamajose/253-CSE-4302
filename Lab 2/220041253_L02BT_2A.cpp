#include <iostream>
#include <string>
using namespace std;

struct car{
    string brand;
    string model;
    int year;
    string fueltype;
    int mileage;
};

int main(){
    int n;
    float distance, petrolprice, dieselprice, hybridprice, cost;
    car cars[10];
    cout << "Enter number of cars: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Enter car details (Brand, Model, Year, Fuel Type, Mileage) (Press Enter after each entry): ";
        cin >> cars[i].brand >> cars[i].model >> cars[i].year >> cars[i].fueltype >> cars[i].mileage;
    }
    cout << "Enter required distance: ";
    cin >> distance;
    cout << "Enter fuel price per liter for petrol: ";
    cin >> petrolprice;
    cout << "Enter fuel price per liter for diesel: ";
    cin >> dieselprice;
    cout << "Enter fuel price per liter for hybrid: ";
    cin >> hybridprice;
    for(int i=0; i<n; i++){
        cout << "Car " << i+1 << ':' << endl;
        cout << "Brand: " << cars[i].brand << endl;
        cout << "Model: " << cars[i].model << endl;
        cout << "Year: " << cars[i].year << endl;
        cout << "Fuel Type: " << cars[i].fueltype << endl;
        cout << "Mileage: " << cars[i].mileage << " km/l" << endl;
        if(cars[i].fueltype=="Electric"){
            cout << "This car is electric, efficiency measured in km/charge." << endl << "This car is not fuel-efficient." << endl;
            continue; 
        }
        else{
            if(cars[i].mileage>15){
                cout << "This car is fuel-efficient." << endl;
            }
            else{
                cout << "This car is not fuel-efficient." << endl;
            }
            if(cars[i].fueltype=="Petrol"){
                cost = petrolprice*(distance/cars[i].mileage);
                cout << "Estimated fuel cost for " << distance << " km: $" << cost<< endl; 
            }
            if(cars[i].fueltype=="Diesel"){
                cost = dieselprice*(distance/cars[i].mileage);
                cout << "Estimated fuel cost for " << distance << " km: $" << cost << endl; 
            }
            if(cars[i].fueltype=="Hybrid"){
                cost = hybridprice*(distance/cars[i].mileage);
                cout << "Estimated fuel cost for " << distance << " km: $" << cost << endl; 
            }
        }
    }
}