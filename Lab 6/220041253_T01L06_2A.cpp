#include <iostream>
#include <string>
using namespace std;

class Cars{
    private:
        string make;
        string model;
        double fuelCapacity;
        double fuelLevel;

    public:
        Cars(){
            fuelLevel = 0;
        }
        Cars(string mk, string mdl, double fuelcap){
            make = mk;
            model = mdl;
            fuelCapacity = fuelcap;
            fuelLevel= 0;
        }
        void operator +(double amount){
            if(fuelLevel+amount>=fuelCapacity){
                fuelLevel = fuelCapacity;
                cout << "Max fuel capacity reached." << endl;
            }
            else fuelLevel += amount;
        }
        void operator -(double amount){
            if((fuelLevel-amount)<0){
                fuelLevel = 0;
                cout << "Fuel level is 0 now." << endl;
            }
            else fuelLevel -= amount;
        }
        void operator +=(double amount){
            if(fuelLevel+amount>=fuelCapacity){
                fuelLevel = fuelCapacity;
                cout << "Max fuel capacity reached." << endl;
            }
            else fuelLevel += amount;
        }
        Cars operator +(Cars &car){
            fuelCapacity += car.fuelCapacity;

        }
        bool operator ==(Cars &car){
            if(make==car.make && model==car.model && fuelCapacity==car.fuelCapacity)
                return true;
            else return false;
        }
        bool operator <(Cars &car){
            if(fuelLevel<car.fuelLevel)
                return true;
            else return false;
        }
        bool operator >(Cars &car){
            if(fuelLevel>car.fuelLevel)
                return true;
            else return false;
        }
        friend ostream &operator <<(ostream &out, Cars &car){
            out << "Make: " << car.make << endl;
            out << "Model: " << car.model << endl;
            out << "Fuel Capacity: " << car.fuelCapacity << endl;
            out << "Fuel Level: " << car.fuelLevel << endl;
        }
        friend istream &operator >>(istream &in, Cars &car){
            cout << "Make: ";
            in >> car.make;
            cout << "Model: ";
            in >> car.model;
            cout << "Fuel Capacity: ";
            in >> car.fuelCapacity;
            cout << "Fuel Level: ";
            in >> car.fuelLevel;
        }
};

int main(){
    Cars car[3];
    for(int i=0; i<3; i++){
        cin >> car[i];
    }
    car[0] + 3;
    car[1] += 3;
    car[1] - 2;
    if(car[0]==car[1])
        cout << "Car 1 = Car 2" << endl;
    else cout << "Car 1 != Car 2" << endl;
    if(car[0]<car[1])
        cout << "Car 1 < Car 2" << endl;
    if(car[0]>car[1])
        cout << "Car 1 > Car 2" << endl;
    for(int i=0; i<3; i++){
        cout << car[i];
    }
}
