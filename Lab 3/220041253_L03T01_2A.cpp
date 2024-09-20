#include <iostream>
using namespace std;

class Temperature{
    private:
        float temp;
        float incrementstep;
    public:
        Temperature(){
            temp = 0;
            incrementstep = 0;
        }
        void setIncrementStep(float increment){
            incrementstep = increment;
        }
        float getTemperature(){
            return temp;
        }
        void increment(){
            temp += incrementstep;
        }
        void resetTemperature(){
            temp = 0;
        }
};

int main(){
    Temperature temp1;
    cout << "Current temp: " << temp1.getTemperature() << endl << "Current increment value: 0" << endl;
    temp1.resetTemperature();
    cout << "Current temperature: " << temp1.getTemperature() << endl;
    temp1.setIncrementStep(7.8);
    temp1.increment();
    cout << "Current temperature: " << temp1.getTemperature() << endl;
    temp1.resetTemperature();
    cout << "Current temperature: " << temp1.getTemperature() << endl;
}