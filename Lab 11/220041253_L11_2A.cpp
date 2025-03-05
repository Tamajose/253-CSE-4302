#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <fstream>
using namespace std;

class Creature{
    private:
        string name;
        string species;
        string healthStatus;
        string age;
    public:
        Creature(string n, string s, string hs, string a): 
        name(n), species(s), healthStatus(hs), age(a){}

        string getName() const{
            return name;
        }
        
        string getSpecies() const{
            return species;
        }

        string getHealthStatus() const{
            return healthStatus;
        }

        string getAge() const{
            return age;
        }

        void setHealthStatus(string hs){
            healthStatus = hs;
        }

        void displayDetails() const{
            cout << "Creature Name: " << name << endl;
            cout << "Species: " << species << endl;
            cout << "Health Status: " << healthStatus << endl;
            cout << "Age: " << age << endl;
        }
};

class Sanctuary{
    private:
        vector<Creature> inhabitants;
        deque<Creature> recoveryZone;
        list<Creature> releasedCreatures;
    public:
        void addCreature(){
            string n, s, hs, a;
            cout << "Enter creature name: ";
            cin >> n;
            cout << "Enter creature species: ";
            cin >> s;
            cout << "Enter creature health status: ";
            cin >> hs;
            cout << "Enter creature age: ";
            cin >> a;
            Creature c(n, s, hs, a);
            inhabitants.push_back(c);
        }

        void sendtoRecovery(){
            string n;
            cout << "Enter name of creature to send to recovery: ";
            cin >> n;
            for(auto itr=inhabitants.begin(); itr!=inhabitants.end(); itr++){
                if(itr->getName()==n){
                    if(itr->getHealthStatus()=="Injured" || itr->getHealthStatus()=="Resting"){
                        recoveryZone.push_back(*itr);
                        inhabitants.erase(itr);
                        cout << "Creature sent to recovery zone" << endl;
                        return;
                    }
                    else{
                        cout << "Creature is neither injured nor resting" << endl;
                        return;
                    }
                }
            }
            cout << "Creature not found" << endl;
        }

        void returnfromRecovery(){
            string n;
            cout << "Enter name of creature to return from recovery: ";
            cin >> n;
            for(auto itr=recoveryZone.begin(); itr!=recoveryZone.end(); itr++){
                if(itr->getName()==n){
                    itr->setHealthStatus("Healthy");
                    inhabitants.push_back(*itr);
                    recoveryZone.erase(itr);
                    cout << "Creature sent to recovery zone" << endl;
                    return;
                }
            }
            cout << "Creature not found" << endl;
        }

        void releasetoWild(){
            string n;
            cout << "Enter name of creature to return from recovery: ";
            cin >> n;
            for(auto itr=inhabitants.begin(); itr!=inhabitants.end(); itr++){
                if(itr->getName()==n){
                    if(itr->getHealthStatus()=="Healthy"){
                        inhabitants.erase(itr);
                        cout << "Creature released to wild" << endl;
                        return;
                    }
                    else{
                        cout << "Creature is not healthy" << endl;
                        return;
                    }
                }
            }
            cout << "Creature not found" << endl;
        }

        void displayCreatures(){
            cout << "CREATURES IN THE SANCTUARY:" << endl;
            for(const auto &itr: inhabitants){
                itr.displayDetails();
                cout << endl;
            }
            cout << "CREATURES IN THE RECOVERY ZONE:" << endl;
            for(const auto &itr: recoveryZone){
                itr.displayDetails();
                cout << endl;
            }
            cout << "CREATURES RELEASED TO WILD:" << endl;
            for(const auto &itr: releasedCreatures){
                itr.displayDetails();
                cout << endl;
            }
        }

        void saveData(){
            ofstream inhabitantsFile("inhabitants.txt");
            ofstream recoveryzoneFile("recovery.txt");
            ofstream releasedcreaturesFile("released.txt");
            if(!inhabitantsFile||!recoveryzoneFile||!releasedcreaturesFile){
                cout << "Error in opening file(s)" << endl;
                return;
            }
            for(const auto &itr: inhabitants){
                inhabitantsFile << itr.getName() << "," << itr.getSpecies() << "," 
                                << itr.getHealthStatus() << "," << itr.getAge() << endl;
            }
            for(const auto &itr: recoveryZone){
                recoveryzoneFile << itr.getName() << "," << itr.getSpecies() << "," 
                                << itr.getHealthStatus() << "," << itr.getAge() << endl;
            }
            for(const auto &itr: releasedCreatures){
                releasedcreaturesFile << itr.getName() << "," << itr.getSpecies() << "," 
                                << itr.getHealthStatus() << "," << itr.getAge() << endl;
            }
            cout << "Data saved" << endl;
        }

        void loadData(){
            ifstream inhabitantsFile("inhabitants.txt");
            ifstream recoveryzoneFile("recovery.txt");
            ifstream releasedcreaturesFile("released.txt");
            if(!inhabitantsFile||!recoveryzoneFile||!releasedcreaturesFile){
                cout << "Error in opening file(s)" << endl;
                return;
            }
            string line, name, species, healthStatus, age;
            while(getline(inhabitantsFile, line)){
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, species, ',');
                getline(ss, healthStatus, ',');
                getline(ss, age, ',');
                inhabitants.push_back(Creature(name, species, healthStatus, age));
            }
            while(getline(recoveryzoneFile, line)){
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, species, ',');
                getline(ss, healthStatus, ',');
                getline(ss, age, ',');
                recoveryZone.push_back(Creature(name, species, healthStatus, age));
            }
            while(getline(releasedcreaturesFile, line)){
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, species, ',');
                getline(ss, healthStatus, ',');
                getline(ss, age, ',');
                releasedCreatures.push_back(Creature(name, species, healthStatus, age));
            }
            cout << "Data loaded" << endl;
        }
};

int main(){
    Sanctuary area;
    int option;
    cout << "1. Add a new creature to sanctuary" << endl;
    cout << "2. Send a creature to recovery zone" << endl;
    cout << "3. Return a creature from recovery zone to sanctuary" << endl;
    cout << "4. Release a creature to the wild" << endl;
    cout << "5. Display all creature details" << endl;
    cout << "6. Save creature data" << endl;
    cout << "7. Load creature data" << endl;
    while(1){
        cin >> option;
        switch(option){
            case 1:{
                area.addCreature();
                break;
            }
            case 2:{
                area.sendtoRecovery();
                break;
            }
            case 3:{
                area.returnfromRecovery();
                break;
            }
            case 4:{
                area.releasetoWild();
                break;
            }
            case 5:{
                area.displayCreatures();
                break;
            }
            case 6:{
                area.saveData();
                break;
            }
            case 7:{
                area.loadData();
                break;
            }
            default:{
                break;
            }
        }
    }
}