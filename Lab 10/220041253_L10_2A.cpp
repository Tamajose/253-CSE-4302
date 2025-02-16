#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class SellerActions{
    public:
        virtual void serveIceCream() = 0;
        virtual void specialOffer() = 0;
        virtual void displayStats() = 0;
};

class BaseSeller: public SellerActions{
    protected:
        string name;
        int stock;
        int sales;
        bool specialOfferReady;
        static int collectiveSales;
    public:
        BaseSeller(string n, int st) : name(n), stock(st), sales(0), specialOfferReady(false){}
        void serveIceCream() override{
            if(stock>0){
                stock--;
                int sales_points = rand()%23 + 8;
                sales += sales_points;
                collectiveSales += sales_points;
                cout << name << " served! Sales: " << sales_points << ". Total Sales: " << sales
                    << ", Stock: " << stock << endl;
                if (!sales%3)
                    specialOfferReady = true;
            }
        }
        bool checkSpecialOffer(){
            return specialOfferReady;
        }
        void displayStats() override{
            cout << "Name: " << name << endl << "Stock: " << stock << endl << "Sales: " << sales << endl;
            cout << "Special Offer Ready: ";
            if(specialOfferReady)
                cout << "Available" << endl;
            else cout << "Unavailable" << endl;
        }
        static int getCollectiveSales(){
            return collectiveSales;
        }
};

int BaseSeller::collectiveSales = 0;

class ConeMaster : public BaseSeller{
    public:
        ConeMaster() : BaseSeller("Cone Master", 20){}
        void ConeStackChallenge(){
            int scoopsStacked = rand()%10;
            int successRate = 100 - (scoopsStacked*10);
            int rnd = rand()%100;
            if(successRate>=rnd)
                serveIceCream();
            else{
                cout << "Cone Master failed the Cone Stack Challenge!" << endl;
                if(stock>0)
                    stock--;
            }
        }
        void specialOffer() override{
            if(specialOfferReady){
                cout << "Cone Master served a special offer! " << endl;
                for(int i=0; i<3; i++){
                    if(stock>0)
                        serveIceCream();
                    else break;
                }
                specialOfferReady = false;
            }
        }
    };

class SundaeWizard: public BaseSeller{
    public:
        SundaeWizard(): BaseSeller("Sundae Wizard", 15){}
        void LayeredSundaeBonus(int layers){
            if(stock>0){
                int bonus = layers*(rand()%23 + 8);
                sales += bonus;
                collectiveSales += bonus;
                stock--;
            }
        }
        void specialOffer() override{
            if(specialOfferReady){
                cout << "Sundae Wizard served a special offer! " << endl;
                sales *= 2;
                collectiveSales += sales;
                specialOfferReady = false;
            }
        }
    };

class IceCreamTruckDriver: public BaseSeller{
    public:
        IceCreamTruckDriver() : BaseSeller("Ice Cream Truck Driver", 30) {}
        void specialOffer() override{
            if(specialOfferReady){
                stock += 10;
                cout << "Ice Cream Truck Driver served a special offer! " << endl;
                specialOfferReady = false;
            }
        }
    };

class SimulationEngine{
    protected:
        vector<BaseSeller*> sellers;
        int customerPatience;
        int salesGoal;
    public:
        SimulationEngine(): customerPatience(200), salesGoal(300){}
        void addSeller(BaseSeller* seller){
            sellers.push_back(seller);
        }
        void runSimulation(){
            for(int turn=1; turn<=10; turn++){
                cout << endl << "Turn " << turn << ":" << endl;
                for(auto seller : sellers){
                    seller->serveIceCream();
                    if(seller->checkSpecialOffer())
                        seller->specialOffer();
                    cout << "Collective totalSales: " << seller->getCollectiveSales() << endl;
                }
                customerPatience -= rand()%31 + 20;
                if (customerPatience <= 0) {
                    cout << "Customer Rush not satisfied! Sellers lose!" << endl;
                    return;
                }
                if(BaseSeller::getCollectiveSales()>=salesGoal){
                    cout << "Customer Rush satisfied! Sellers win!" << endl;
                    return;
                }
            }
            cout << "Customer Rush not satisfied. Sellers lose" << endl;
        }
};

int main(){
    srand(time(0));
    ConeMaster seller1;
    SundaeWizard seller2;
    IceCreamTruckDriver seller3;
    SimulationEngine engine;
    engine.addSeller(&seller1);
    engine.addSeller(&seller2);
    engine.addSeller(&seller3);
    engine.runSimulation();
}
