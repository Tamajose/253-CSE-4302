#include <iostream>
using namespace std;

enum etype{
    laborer, secretary, manager, accountant, executive, researcher
};

int main(){
    char input1;
    int input2;
    cout << "Enter employee type (first letter only): ";
    cin >> input1;
    switch(input1){
        case 'l':{
            input2 = laborer;
            break;
        }
        case 's':{
            input2 = secretary;
            break;
        }
        case 'm':{
            input2 = manager;
            break;
        }
        case 'a':{
            input2 = accountant;
            break;
        }
        case 'e':{
            input2 = executive;
            break;
        }
        case 'r':{
            input2 = researcher;
            break;
        }
    }
    switch(input2){
        case laborer:{
            cout << "Employee type is laborer.";
            break;
        }
        case secretary:{
            cout << "Employee type is secretary.";
            break;
        }
        case manager:{
            cout << "Employee type is manager.";
            break;
        }
        case accountant:{
            cout << "Employee type is accountant.";
            break;
        }
        case executive:{
            cout << "Employee type is executive.";
            break;
        }
        case researcher:{
            cout<< "Employee type is researcher.";
            break;
        }
    }
}