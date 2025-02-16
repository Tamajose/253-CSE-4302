#include <iostream>
using namespace std;

int year = 2024;

enum status{
    low, moderate, high
};

class Employee{
    private:
        string EmpName;
        int ID;
        double BaseSalary;
        int JoiningYear;
        
        double calculateTotalSalary(){
            int diff = year - JoiningYear;
            double newSalary = BaseSalary;
            while(diff--){
                newSalary = newSalary*1.03;
            }
            double totalsalary;
            totalsalary = newSalary + 0.1*newSalary + 0.3*newSalary + 0.1*newSalary;
            return totalsalary;
        }
        int getStatus(){
            int age = year - JoiningYear;
            status stat;
            if(age<=25 && calculateTotalSalary()<=20000)
                stat = low;
            else if(age<=25 && calculateTotalSalary()>20000)
                stat =  moderate;
            else if(age>25 && calculateTotalSalary()<=21000)
                stat = low;
            else if(age>25 && (calculateTotalSalary()>21000 && calculateTotalSalary()<=60000))
                stat = moderate;
            else if(age>25 && calculateTotalSalary()>60000)
                stat = high;
            return stat;
        }
        double calculateBonus(){
            double bonus;
            if(getStatus()==low)
                bonus = 0.05*calculateTotalSalary();
            else if(getStatus()==moderate)
                bonus = 0.1*calculateTotalSalary();
            else if(getStatus()==high)
                bonus = 0.15*calculateTotalSalary();
            return bonus;
        }

        public:
            void FeedInfo(string name, int id, double base, int year){
                EmpName = name;
                ID = id;
                BaseSalary = base;
                JoiningYear = year;
            }
            void ShowInfo(){
                cout << "Name: " << EmpName << endl;
                cout << "ID: " << ID << endl;
                cout << "Total Salary: " << calculateTotalSalary() << endl;
                cout << "Eligible Bonus: " << calculateBonus() << endl;
                cout << "Joining Year: " << JoiningYear << endl;
            }
};

int main(){
    Employee emp1;
    emp1.FeedInfo("Tama", 253, 100, 2012);
    emp1.ShowInfo();
}