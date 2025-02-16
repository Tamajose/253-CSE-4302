#include <iostream>
using namespace std;

enum AccType{
    SAVINGS,
    CURRENT
};

int createdaccounts=0, existingaccounts=0, totalsourcetax=0;

class BankAccount{
    private:
        string accountnumber;
        string holdername;
        AccType accounttype;
        double balance;
        double minbalance;
    public:
        BankAccount(string str1, string str2, int type, double num1, const double num2){
            accountnumber = str1;
            holdername = str2;
            switch(type){
                case 0:
                {
                    accounttype = SAVINGS;
                    break;
                }
                case 1:
                {
                    accounttype = CURRENT;
                    break;
                }
            }
            balance = num1;
            minbalance = num2;
            createdaccounts++;
            existingaccounts++;
        }
        void displayAccount() const{
            cout << "Account Number: " << accountnumber << endl;
            cout << "Account Holder Name: " << holdername << endl;
            cout << "Account Type: ";
            switch(accounttype){
                case 0:
                {
                    cout << "Savings" << endl;
                    break;
                }
                case 1:
                {
                    cout << "Current" << endl;
                    break;
                }
            }
            cout << "Account Balance: " << balance << endl; 
        }
        void showBalance() const{
            cout << "Current Balance: " << balance << endl;
        }
        const double getBalance() const{
            return balance;
        }
        void deposit(double amount){
            balance += amount;
        }
        void withdraw(double amount){
            if(amount>(balance-minbalance))
                cout << "Invalid amount." << endl;
            else balance -= amount;
        }
        void giveInterest(){
            double interest = 0.3*balance;
            double tax = 0.1*interest;
            double netinterest = interest - tax;
            balance += netinterest;
            totalsourcetax += tax;
        }
        ~BankAccount(){
            existingaccounts--;
            cout << "Account of Mr. " << holdername;
            cout << " with account no " << accountnumber;
            cout << " is destroyed with a balance BDT " << balance << endl;
        }
};

int display_stat(){
    cout << "Total number of accounts created: " << createdaccounts << endl;
    cout << "Total number of existing accounts: " << existingaccounts << endl;
    cout << "Total source tax collected: " << totalsourcetax << endl;
}

const BankAccount& Larger(const BankAccount &A, const BankAccount &B) {
    if(A.getBalance()>B.getBalance())
        return A;
    else return B;
}

int main(){
    BankAccount acc1("A01", "Tama", 0, 2000, 200);
    BankAccount acc2("A02", "Ayhai", 1, 1000, 100);
    acc1.deposit(3000);
    acc2.withdraw(500);
    acc1.giveInterest();
    acc2.giveInterest();
    acc1.displayAccount();
    acc2.displayAccount();
    display_stat();
    const BankAccount& HigherBalance = Larger(acc1, acc2);
    cout << "Account with higher balance: " << endl;
    HigherBalance.displayAccount();
}
