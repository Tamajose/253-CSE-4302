#include <iostream>
#include <string>
using namespace std;

// Base class for Vehicle
class Vehicle{
    protected:
        string licensePlate;
        string manufacturer;
        double carriageSizeLimit; // in kg

    public:
        Vehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit)
            : licensePlate(licensePlate), manufacturer(manufacturer), carriageSizeLimit(carriageSizeLimit){}
        Vehicle(){
            licensePlate = "";
            manufacturer = "";
            carriageSizeLimit = 0;
        }
        virtual ~Vehicle() = default;
        virtual void maintenance() = 0;
};

class GasolineVehicle: virtual public Vehicle{
    protected:
        double fuelTankCapacity; // in liters
        string fuelType; // e.g., petrol, octane

    public:
        GasolineVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                        double fuelTankCapacity, const string& fuelType)
            : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
            fuelTankCapacity(fuelTankCapacity), fuelType(fuelType) {}
        GasolineVehicle(){fuelTankCapacity = 0;fuelType = "petrol";}
        void maintenance() override{
            cout<<"GasolineVehicle - maintenance"<<endl;
        }
};

// Electric Vehicle (derived class)
class ElectricVehicle: virtual public Vehicle{
    protected:
        double batteryCapacity; // in KWh
        int chargingTime; // in minutes

    public:
        ElectricVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                        double batteryCapacity, int chargingTime)
            : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
            batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}
        ElectricVehicle(){batteryCapacity = 0; chargingTime = 0;}
        virtual void maintenance() override{
            cout<<"ElectricVehicle - maintenance"<<endl;
        }
};

// Hybrid Vehicle (derived class)
class HybridVehicle: public GasolineVehicle, public ElectricVehicle{
    private:
        double energyRegenerationEfficiency;

    public:
        HybridVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double fuelTankCapacity, const string& fuelType, double batteryCapacity, int chargingTime,
                    double energyRegenerationEfficiency)
            : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
            ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
            energyRegenerationEfficiency(energyRegenerationEfficiency) {}
        HybridVehicle(){}
        void maintenance() override{
            cout<<"HybridVehicle - maintenance"<<endl;
        }
};


// Motorcycle (derived from GasolineVehicle)
class Motorcycle : public GasolineVehicle {
    public:
        Motorcycle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                double fuelTankCapacity, const string& fuelType)
            : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType) {}
        Motorcycle(){}
        void maintenance() override{
            cout<<"Motorcycle - maintenance"<<endl;
        }
};

// Car (derived from GasolineVehicle)
class Car : public GasolineVehicle {
    private:
        int passengerCapacity;

    public:
        Car(const string& licensePlate, const string& manufacturer, double carriageSizeLimit, double fuelTankCapacity,
            const string& fuelType, int passengerCapacity)
            : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
            passengerCapacity(passengerCapacity) {}

        Car(){}
        void maintenance() override{
            cout<<"Car - maintenance"<<endl;
        }
};

// Truck (derived from GasolineVehicle)
class Truck : public GasolineVehicle {
private:
    double cargoCapacity;

public:
    Truck(const string& licensePlate, const string& manufacturer, double carriageSizeLimit, double fuelTankCapacity,
          const string& fuelType, double cargoCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          cargoCapacity(cargoCapacity) {}

    Truck(){}
    void maintenance() override{
        cout<<"Truck - maintenance"<<endl;
    }
};

// Employee Base Class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& name, int id) : name(name), id(id) {}
    Employee(){}
    virtual ~Employee() = default;
    virtual void introduce() = 0;
};

// Manager (derived from Employee)
class Manager : public Employee {
public:
    Manager(const string& name, int id) : Employee(name, id) {}
    Manager(){}

    void introduce() override{
        cout << "Mr. " << name << endl;
    }
};

// Driver (derived from Employee)
class Driver : public Employee {
public:
    Driver(const string& name, int id) : Employee(name, id) {}
    Driver(){}
    void introduce() override{
        cout << name << endl;
    }
};

// Branch class containing vehicles and employees
class Branch {
private:
    Vehicle* vehicles[30];
    Employee* employees[30];
    int vehicleCount;
    int employeeCount;

public:
    Branch() : vehicleCount(0), employeeCount(0){}

    ~Branch(){
        for(int i=0; i<vehicleCount; i++){
            delete vehicles[i];
        }
        for(int i=0; i<employeeCount; i++){
            delete employees[i];
        }
    }

    void addVehicle(Vehicle* v){
        if(vehicleCount<30)
            vehicles[vehicleCount++] = v;
        else
            cout << "Maximum number of vehicles for the branch reached" << endl;
    }

    void addEmployee(Employee* e){
        if(employeeCount<30)
            employees[employeeCount++] = e;
        else
            cout << "Maximum number of employees for the branch reached" << endl;
    }

    void maintenance_all_vehicle() const{
        for(int i=0; i<vehicleCount; i++){
            vehicles[i]->maintenance();
        }
    }

    void introduction_all_employees() const{
        for(int i=0; i<employeeCount; i++){
            employees[i]->introduce();
        }
    }
};

int main(){
    Branch dhaka;

    dhaka.addVehicle(new Motorcycle("M01", "Yamaha", 1, 2, "Petrol"));
    dhaka.addVehicle(new Car("C01", "Toyota", 3, 4, "Octane", 5));
    dhaka.addVehicle(new Truck("T01", "Tata", 6, 7, "Diesel", 8));
    dhaka.addVehicle(new ElectricVehicle("E01", "Tesla", 9, 10, 11));
    dhaka.addVehicle(new HybridVehicle("H01", "Hyundai", 12, 13, "Octane", 14, 15, 16));

    dhaka.addEmployee(new Manager("Person1", 17));
    dhaka.addEmployee(new Driver("Person2", 18));

    dhaka.maintenance_all_vehicle();
    dhaka.introduction_all_employees();
}
