#include <iostream>
#include <vector>
using namespace std;

vector<class Product> inventory;

class Product{
    private:
        string name;
        string id;
        double price;
        int quantity;
        int maxamount;
    public:
        Product(string str1, string str2, double pr, int quant, int max){
            name = str1;
            id = str2;
            price = pr;
            quantity = quant;
            maxamount = max;
            if(quantity>maxamount)
                quantity = maxamount;
        }
        void addToInventory(int addedQuantity){
            quantity += addedQuantity;
            if(quantity>maxamount)
                quantity = maxamount;
        }
        int isAvailable(){
            if(quantity>0)
                return 1;
            else return 0;
        }
        void purchase(int purchasedQuantity){
            quantity -= purchasedQuantity;
            if(quantity<0)
                quantity = 0;
        }
        void updatePrice(double discountPercent){
            price = price * (1-(discountPercent/100.0));
        }
        void displayInventoryValue(){
            cout << "Inventory Value: " << quantity*price << endl;
        }
        void displayDetails(){
            cout << "Product Name: " << name << endl << "Product ID: " << id << endl;
            cout << "Product Price: " << price << endl << "Product Quantity: " << quantity << endl;
            cout << "Product Availability: ";
            if(isAvailable())
                cout << "Available";
            else cout << "Unavailable";
            cout << endl;
            displayInventoryValue();
        }
        static void displayTotalInventoryValue(){
            double total = 0;
            for(auto itr: inventory){
                total += itr.price*itr.quantity;
            }
            cout << "Total Inventory Value: " << total << endl;
        }
};

int main(){
    Product p1("Oil", "A098", 8, 20, 100);
    p1.addToInventory(50);
    p1.purchase(20);
    p1.updatePrice(5);
    p1.displayDetails();
    inventory.push_back(p1);

    Product p2("Vinegar", "B002", 10, 15, 60);
    p2.addToInventory(20);
    p2.purchase(5);
    p2.updatePrice(10);
    p2.displayDetails();
    inventory.push_back(p2);

    Product p3("Ketchup", "C113", 15, 8, 20);
    p3.addToInventory(15);
    p3.updatePrice(15);
    p3.purchase(25);
    p3.displayDetails();
    inventory.push_back(p3);
    
    Product::displayTotalInventoryValue();
}