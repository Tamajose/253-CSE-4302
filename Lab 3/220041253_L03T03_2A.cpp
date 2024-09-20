#include <iostream>
#include <string>
using namespace std;

class BankAccount{
    private:
        string customername;
        int accountnumber;
        string accounttype;
        double balanceamount;
    public:
        void customerDetails(string name, int num){
            customername = name;
            accountnumber = num;
        }
        void accountType(string type){
            accounttype = type;
        }
        void balance(){
            cout << "Balance: " << balanceamount << endl;
        }
        void deposit(double amount){
            balanceamount += amount;
        }
        void withdraw(double amount){
            balanceamount -= amount;
        }
        void display(){
            cout << "Customer Name: " << customername << endl;
            cout << "Account Number: " << accountnumber << endl;
            cout << "Account Type: " << accounttype << endl;
            cout << "Account Balance: " << balanceamount << endl;
        }
};

int main(){
    BankAccount customer1;
    customer1.customerDetails("Tama", 253);
    customer1.accountType("Saving");
    customer1.deposit(1000);
    customer1.display();
    customer1.withdraw(300);
    customer1.display();
}