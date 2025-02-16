#include <iostream>
using namespace std;

class Celsius;
class Fahrenheit;
class Kelvin;

class Celsius{
    private:
        double temperature;
    public:
        Celsius(){
            temperature = 0;
        }
        Celsius(double temp){
            if(temp<-273.15)
                temperature = -273.15;
            else temperature = temp;
        }
        void assign(double temp){
            if(temp<-273.15)
                temperature = -273.15;
            else temperature = temp;
        }
        void display(){
            cout << "Temperature in Celsius is: " << temperature << endl;
        }
        operator Fahrenheit();
        operator Kelvin();

};

class Fahrenheit{
    private:
        double temperature;
    public:
        Fahrenheit(){
            temperature = 0;
        }
        Fahrenheit(double temp){
            if(temp<-460)
                temperature = -460;
            else temperature = temp;
        }
        void assign(double temp){
            if(temp<-460)
                temperature = -460;
            else temperature = temp;
        }
        void display(){
            cout << "Temperature in Fahrenheit is: " << temperature << endl;
        }
        operator Celsius();
        operator Kelvin();
};

class Kelvin{
    private:
        double temperature;
    public:
        Kelvin(){
            temperature = 0;
        }
        Kelvin(double temp){
            if(temp<0)
                temperature = 0;
            else temperature = temp;
        }
        void assign(double temp){
            if(temp<0)
                temperature = 0;
            else temperature = temp;
        }
        void display(){
            cout << "Temperature in Kelvin is: " << temperature << endl;
        }
        operator Celsius();
        operator Fahrenheit();
};

Celsius::operator Fahrenheit(){
    return Fahrenheit(temperature * 9/5 + 32);
}
Celsius::operator Kelvin(){
    return Kelvin(temperature + 273.15);
}
Fahrenheit::operator Celsius(){
    return Celsius((temperature - 32) * 5/9);
}
Fahrenheit::operator Kelvin(){
    return Kelvin((temperature + 459.67) * 5/9);
}
Kelvin::operator Celsius(){
    return Celsius(temperature - 273.15);
}
Kelvin::operator Fahrenheit(){
    return Fahrenheit(1.8 * (temperature - 273.15) + 32);
}

int main(){
    Celsius temp1;
    temp1.assign(100);
    Fahrenheit temp2 = temp1;
    Kelvin temp3 = temp2;
    temp1.display();
    temp2.display();
    temp3.display();
}