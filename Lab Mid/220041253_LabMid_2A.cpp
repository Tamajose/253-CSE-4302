#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Motorbike{
    private:
        string modelno;
        double price;
        string manufacturer;
    public:
        Motorbike(){
            modelno = "N/A";
            price = 0.00;
            manufacturer = "N/A";
        }
        string getModelNo(){
            return modelno;
        }
        void display(){
            cout << "Model No.: " << modelno << endl;
            cout << "Price: " << price << endl;
            cout << "Manufacturer: " << manufacturer << endl;
        }
        friend istream &operator >>(istream &in, Motorbike &mb){
            cout << "Enter model no.: ";
            cin >> mb.modelno;
            cout << "Enter price: ";
            cin >> mb.price;
            cout << "Enter manufacturer name: ";
            cin >> mb.manufacturer;
        }
};

// bool compfunc(Motorbike &mb1, Motorbike &mb2){
//     return (mb1.manufacturer<mb2.manufacturer);
// }
// void sortbymanufacturer(Motorbike mb[]){
//     sort(mb, mb+10, compfunc());
// }

void searchByModelNo(Motorbike mb[], string s){
    for(int i=0; i<10; i++){
        if(s==mb[i].getModelNo()){
            mb[i].display();
        }
    }
}



int main(){
    Motorbike mb[10];
    cout << "Enter motorbike details: " << endl;
    for(int i=0; i<10; i++){
        cin >> mb[i];
    }
    string s;
    cout << "Model no. to search for: ";
    cin >> s;
    searchByModelNo(mb, s);
}