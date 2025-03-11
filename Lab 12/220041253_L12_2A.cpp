#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Creature{
    private:
        string name;
        string species;
        int id;
    public:
        Creature(string n, string s, int i){
            this->name = n;
            this->species = s;
            this->id = i;
        }

        string getName(){
            return name;
        }

        string getSpecies(){
            return species;
        }

        int getID(){
            return id;
        }

        virtual void display(){
            cout << "Name: " << name << endl;
            cout << "Species: " << species << endl;
            cout << "ID: " << id << endl;
        }
};

class ActiveCreature: public Creature{
    private:
        string healthStatus;
        vector<string> dailyActivities;
    public:
        ActiveCreature(string n, string s, int i): Creature(n, s, i){
            this->healthStatus = "Healthy";
        }

        void setHealthStatus(string hs){
            healthStatus = hs;
        }

        void setDailyActivities(string da){
            dailyActivities.push_back(da);
        }

        void display() override{
            Creature::display();
            cout << "Daily Activities: ";
            for(int i=0; i<dailyActivities.size(); i++){
                cout << dailyActivities[i] << " ";
            }
        }
};

class RecoveringCreature: public Creature{
    private:
        set<string> recoveryStatus;
    public:
        RecoveringCreature(string n, string s, int i): Creature(n, s, i){};

        void addRecoveryStatus(string status){
            recoveryStatus.insert(status);
        }

        void removeRecoveryStatus(string status){
            recoveryStatus.erase(status);
        }

        void display(){
            Creature::display();
            cout << "Recovery Statuses: ";
            for(auto itr=recoveryStatus.begin(); itr!=recoveryStatus.end(); itr++){
                cout << *itr << " ";
            }
        }
};

map<int, ActiveCreature*> activeCreaturesMap;
map<int, RecoveringCreature*> recoveringCreaturesMap;
int id = 1;

void addCreature(){
    string name, species, healthStatus, dailyActivities;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter species: ";
    cin >> species;
    ActiveCreature* cr = new ActiveCreature(name, species, id);
    activeCreaturesMap[id] = cr;
    id++;
}

void sendtoRecovery(){
    int id;
    cout << "Enter creature ID:";
    cin >> id;
    if(!activeCreaturesMap.count(id)){
        cout << "Creature not found" << endl;
        return;
    }
    else{
        ActiveCreature* cr = activeCreaturesMap[id];
        if(cr->setHealthStatus()!="Healthy")
    }
}

void performDailyActivity(){
    static int count = 0;

}




