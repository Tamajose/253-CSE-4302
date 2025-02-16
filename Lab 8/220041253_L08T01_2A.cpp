#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        string name;
    public:
        Person(string s): name(s){}
        virtual void display(){
            cout << "Name: " << name << endl;
        }
};

class Employee: public Person{
    private:
        int employeeID;
    protected:
        float salary;
    public:
        Employee(string s, int i, float f): Person(s), employeeID(i), salary(f){}
        void display(){
            Person::display();
            cout << "Employee ID: " << employeeID << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Intern: public Employee{
    private:
        string schoolname;
    public:
        Intern(string s, int i, float f, string ss): Employee(s, i, f), schoolname(ss){}
        void display(){
            Employee::display();
            cout << "School Name: " << schoolname << endl;
        }
};

class Manager: protected Employee{
    private:
        string department;
    public:
        Manager(string s, int i, float f, string ss): Employee(s, i, f), department(ss){}
        void display(){
            Employee::display();
            cout << "Department: " << department << endl;
        }
};

class Director: public Manager{
    private:
        float bonus;
    public:
        Director(string s, int i, float f, string ss, float b): Manager(s, i, f, ss), bonus(b){}
        void display(){
            Manager::display();
            cout << "Bonus: " << bonus << endl;
        }
};

int main(){
    Person* p = new Employee("Tama", 12, 1900);
    p->display();
    Manager* m = new Director("Mamo", 9, 2000, "Automation", 5.5);
    m->display();
}