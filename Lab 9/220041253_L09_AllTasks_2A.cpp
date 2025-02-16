#include <iostream>
#include <algorithm>
using namespace std;

enum modeTypes{
    cooling,
    heating,
    fan_only
};

enum resTypes{
    res_1080p,
    res_4k
};

class SmartDevice{
    protected:
        string deviceID;
        string name;
        double powerRating;
    public:
        SmartDevice(string s1, string s2, double p): deviceID(s1), name(s2), powerRating(p){}
        virtual void diagnose() = 0;
        double getPowerRating(){
            return powerRating;
        }
};

class ThermostatDevice: virtual public SmartDevice{
    protected:
        double temperatureRange[2];
        modeTypes mode;
    public:
        ThermostatDevice(string s1, string s2, double p, double min, double max, modeTypes m): SmartDevice(s1, s2, p), mode(m){
            temperatureRange[0] = min;
            temperatureRange[1] = max;
        }
        virtual double calculatePowerConsumption(double hours){
            return powerRating*hours;
        }
        void diagnose() override{
            cout << "Device ID: " << deviceID << endl;
            cout << "Name: " << name << endl;
            cout << "Power Rating: "  << powerRating << endl;
            cout << "Temperature Range: " << temperatureRange[0] << "-" << temperatureRange[1] << endl;
            cout << "Mode: ";
            switch(mode){
                case cooling:{
                    cout << "Cooling" << endl;
                    break;
                }
                case heating:{
                    cout << "Heating" << endl;
                    break;
                }
                case fan_only:{
                    cout << "Fan-only" << endl;
                    break;
                }
            }
        }
};

class SecurityCameraDevice: virtual public SmartDevice{
    protected:
        resTypes resolution;
        double recording_hours;
    public:
        SecurityCameraDevice(string s1, string s2, double p, resTypes r, double h): SmartDevice(s1, s2, p), resolution(r), recording_hours(h){}
        virtual double calculateDataUsage(double days){
            return powerRating*recording_hours*days;
        }
        void diagnose() override{
            cout << "Device ID: " << deviceID << endl;
            cout << "Name: " << name << endl;
            cout << "Power Rating: " << endl;
            cout << "Resolution: " << powerRating << endl;
            switch(resolution){
                case res_1080p:{
                    cout << "1080p" << endl;
                    break;
                }
                case res_4k:{
                    cout << "4K" << endl;
                    break;
                }
            }
            cout << "Recording hours(per day): " << recording_hours << endl;
        }
};

class SmartThermostat: public ThermostatDevice{
    private:
        bool remoteControlEnabled;
    public:
        SmartThermostat(string s1, string s2, double p, double min, double max, modeTypes m, bool r): SmartDevice(s1, s2, p), ThermostatDevice(s1, s2, p, min, max, m), remoteControlEnabled(r){}
        void diagnose() override{
            ThermostatDevice::diagnose();
            cout << "Remote Control: ";
            if(remoteControlEnabled)
                cout << "Enabled" << endl;
            else cout << "Disabled" << endl;
        }
};

class HybridThermostat: public ThermostatDevice, public SecurityCameraDevice{
    private:
    double energySavingEfficiency;
    public:
        HybridThermostat(string s1, string s2, double p, double min, double max, modeTypes m, resTypes res, bool r, double h, double e): SmartDevice(s1, s2, p), ThermostatDevice(s1, s2, p, min, max, m), SecurityCameraDevice(s1, s2, p, res, h), energySavingEfficiency(e){}
        double calculatePowerConsumption(double hours){
            double efficiencyFactor = 1.0 - (energySavingEfficiency/100.0);
            return powerRating*hours*efficiencyFactor;
        }
        void diagnose(){
            ThermostatDevice::diagnose();
            SecurityCameraDevice::diagnose();
            cout << "Energy Saving Efficiency: " << energySavingEfficiency << endl;
        }
};

void sort_devices_by_power(SmartDevice **devices, int n){
    sort(devices, devices+n, [](SmartDevice *a, SmartDevice *b){return a->getPowerRating()>b->getPowerRating();});
}

int main()
{
    SmartDevice *ptr1 = new ThermostatDevice("T01", "Philips", 15.0, 0, 70, cooling);
    SmartDevice *ptr2 = new SecurityCameraDevice("C01", "Rapoo", 10.0, res_1080p, 20.0);
    SmartDevice *ptr3 = new SmartThermostat("T02", "Samsung", 20.0, 10, 60, heating, true);
    SmartDevice *ptr4 = new HybridThermostat("T03", "Xiaomi", 25.0, 15.0, 30.0, cooling, res_4k, true, 8.0, 20.0);
    SmartDevice *devices[] = {ptr1, ptr2, ptr3, ptr4};
    int n = sizeof(devices)/sizeof(SmartDevice*);
    sort_devices_by_power(devices, n);
    for (int i=0; i<n; i++){
        devices[i]->diagnose();
        cout << endl;
    }
    cout << endl;
    ptr4->diagnose();
    cout << endl;
}
