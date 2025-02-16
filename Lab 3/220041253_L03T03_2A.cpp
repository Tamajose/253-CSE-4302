#include <iostream>
#include <string>
using namespace std;

enum AccType{
    Current,
    Saving
};

class BankAccount{
    private:
        string customername;
        string accountnumber;
        string accounttype;
        double balanceamount;
    public:
        void customerDetails(string name, string num){
            customername = name;
            accountnumber = num;
        }
        void accountType(int type){
            switch(type){
                case 0:
                {
                    accounttype = "Current";
                    break;
                }
                case 1:
                {
                    accounttype = "Saving";
                    break;
                }
            }
        }
        void balance(){
            cout << "Balance: " << balanceamount << endl;
        }
        void deposit(double amount){
            if(amount<0){
                cout << "Error: Deposit amount is negative." << endl;
            }
            else
                balanceamount += amount;
        }
        void withdraw(double amount){
            balanceamount -= amount;
            if(balanceamount<0){
                cout << "Balance is less than withdrawal amount. Money cannot be withdrawn." << endl;
                balanceamount += amount;
            }
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
    customer1.customerDetails("Tama", "253");
    customer1.accountType(0);
    customer1.deposit(1000);
    customer1.display();
    customer1.withdraw(300);
    customer1.display();
}