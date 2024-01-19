#include <iostream>
#include "products.h"
#include "transport.h"
#include "packaging.h"
#include "shipment.h"
#include "customer.h"
#include <string.h>
#include "stock.h"
#include "book.h"
#include "clothing.h"
#include "computergames.h"
#include "electronics.h"
#include "furniture.h"
#include "jewelry.h"
#include "truck.h"
#include "ship.h"
#include "aircraft.h"


using namespace std;

void menu();
void menuProducts();
void menuProducts();
void menuMeansTransport();
void menuPackaging();
void menuShipments();
void menuCustomers();
void calculateTotalPriceShipment();
void save_restore();
void menuTypeProducts();
void menuTransports();

std::vector<Product> list;
std::vector<Transport> transports;
std::vector<packaging> packagings;
std::vector<customer> customers;
std::vector<shipment> shipments;
stock stock(list);

int main(int, char**){

    while(true){
        menu();
    }
    return 0;

}


void menu(){
    string option;
    int aux;
    do{
        cout << "------------------LOGISTIC MANAGEMENT APPLICATION------------------\n";

        cout << "1-Create/Read/Update/Delete Products\n";
        cout << "2-Create/Read/Update/Delete Means of Transport\n";
        cout << "3-Create/Read/Update/Delelte Packaging\n";
        cout << "4-Create/Read/Update/Cancel Shipments\n";
        cout << "5-Create a new Customer\n";
        cout << "6-Calculate total price for a shipment\n";
        cout << "7-Save/Restore application\n";
        cout << "8-Exit\n";


        cout << "Please, enter the desired value: ";

        try{

            getline(cin, option);

            if (option.empty()) {
                cout << "Error: Please enter a valid number!!\n\n";
                break;
            }

            aux = stoi(option);

            switch (aux){

            case 1:
                cout << "\033[2J\033[H";
                cout << "Introduced option 1: Managing Products\n";
                menuProducts();
                break;

            case 2:           
                cout << "\033[2J\033[H";
                cout << "Introduced option 2: Managing Means of Transport\n";
                menuMeansTransport();
                break;

            case 3:
                cout << "\033[2J\033[H";
                cout << "Introduced option 3: Managing Packaging\n";
                menuPackaging();
                break;

            case 4:
                cout << "\033[2J\033[H";
                cout << "Introduced option 4: Managing Shipments\n";
                menuShipments();
                break;

            case 5:
                cout << "\033[2J\033[H";
                cout << "Introduced option 5: Create a new Customer\n";
                menuCustomers();
                break;

            case 6:
                cout << "\033[2J\033[H";
                cout << "Introduced option 6: Calculate Total Price for a Shipment\n";
                calculateTotalPriceShipment();
                break;

            case 7:
                cout << "\033[2J\033[H";
                cout << "Introduced option 7: Save/Restore Application State\n";

                break;
            case 8:
                cout << "\033[2J\033[H";
                cout << "Entered exit value, good bye!\n";
                exit(0);
                break;
                break;
            default:
                cout << "The value entered does not correspond to any function in the menu, try again\n\n";
            }
        }catch(invalid_argument const& e){
            cout << "Introduce a valid number!!\n\n";
            aux = 0;
        }
    }while(aux!=8);



}

void menuProducts(){
    cout << "1-Create a new Product\n";
    cout << "2-Read Products\n";
    cout << "3-Update a Product\n";
    cout << "4-Delete a Product\n";
    cout << "Please, enter the desired value: ";

    string option;
    int aux =0;
    getline(cin, option);

    if (option.empty()) {
        cout << "Error: Please enter a valid number!!\n\n";
    }
    aux = stoi(option);
    switch (aux){

    case 1:{    //Create
        string name;
        string supplier;
        double price;
        int quantity;
        cout << "\nIntroduce the name of the Product: ";
        getline(cin, name);
        cout << "\nEnter the price of the product ";
        cin >> price;
        cout << "\nEnter the supplier: ";
        cin.ignore();
        getline(cin,supplier);

        cout << "\nEnter the quantity of the new product created: ";
        cin >> quantity;

        menuTypeProducts();
        string type;
        cout << "Select the type of the product: ";
        cin >> type;

        switch(stoi(type)){
        case 1:{
            string author, genre;
            int year;

            cout << "\nEnter the author of the book: ";
            cin.ignore();
            getline(cin, author);

            cout << "\nEnter the genre of the book: ";
            getline(cin,genre);

            cout << "\nEnter the year of the publication of the book: ";
            cin >> year;


            Books book(name,price,supplier,quantity,author,genre,year);
            book.displayInfo();
            stock.addProduct(book,list);
            stock.displayStock(list);
            break;
        }
        case 2:{
            string brand, color;
            char size;

            cout << "\nEnter the brand of the cloth: ";
            cin.ignore();
            getline(cin,brand);

            cout << "\nEnter the size of the cloth: ";
            cin >> size;

            cout << "\nEnter the color of the cloth: ";
            cin.ignore();
            getline(cin,color);

            Clothing clothing(name,price,supplier,quantity,brand,size,color);
            clothing.displayInfo();
            stock.addProduct(clothing,list);
            break;

        }
        case 3:{

            string company,console;
            int age;

            cout << "\nEnter the company of the computer game: ";
            cin.ignore();
            getline(cin,company);

            cout << "\nEnter the console of the computer game: ";
            getline(cin,console);

            cout << "\nEnter the minimum age to play this game: ";
            cin >> age;

            ComputerGames computer_games(name,price,supplier,quantity,company,console,age);
            computer_games.displayInfo();
            stock.addProduct(computer_games,list);
            stock.displayStock(list);
            break;

        }
        case 4:{
            string brand,placeOfManufacture;
            int power;

            cout << "\nEnter the brand of the electronic: ";
            cin.ignore();
            getline(cin,brand);

            cout << "\nEnter the place of manufacture of the electronic: ";
            getline(cin,placeOfManufacture);

            cout << "\nEnter the power of the electronic: ";
            cin >> power;

            Electronics electronic(name,price,supplier,quantity,brand,placeOfManufacture,power);
            electronic.displayInfo();
            stock.addProduct(electronic,list);
            stock.displayStock(list);
            break;

        }
        case 5:{

            string material,dimensions, style;

            cout << "\nEnter the material of the furniture: ";
            cin.ignore();
            getline(cin,material);

            cout << "\nEnter the dimensions of the furniture: ";
            getline(cin,dimensions);

            cout << "\nEnter the style of the furniture: ";
            getline(cin,style);

            Furniture furniture(name,price,supplier,quantity,material,dimensions,style);
            furniture.displayInfo();
            stock.addProduct(furniture,list);
            stock.displayStock(list);

            break;

        }
        case 6:{
            string material,gemstone, design;

            cout << "\nEnter the material of the furniture: ";
            cin.ignore();
            getline(cin,material);

            cout << "\nEnter the dimensions of the furniture: ";
            getline(cin,gemstone);

            cout << "\nEnter the style of the furniture: ";
            getline(cin,design);

            Jewelry jewelry(name,price,supplier,quantity,material,gemstone,design);
            jewelry.displayInfo();
            stock.addProduct(jewelry,list);
            stock.displayStock(list);
            break;

        }

            default:
            cout << "Input not valid, reseting menu\n\n\n";
            break;

        }


    }
    case 2: //Read
        stock.displayStock(list);

        break;
    case 3:{    //Update

        if(list.empty()){
            cout << "--------------PRODUCTS IN STOCK!--------------\n";
            cout << "There is no products to modify!\n\n";
        }else{
            int p;
            stock.displayStock(list);
            cout <<"Please, enter the number of the product to modify: ";
            cin >> p;
            string a, b;
            double c;
            int d;
            cout << "\nIntroduce the name of the Product: ";
            cin >> a;
            cout << "\nEnter the price of the product ";
            cin >> c;
            cin.ignore();
            cout << "\nEnter the supplier: ";
            cin >> b;
            cout << "\nEnter the quantity of the new product created: ";
            cin >> d;

            list[p-1].setName(a);
            list[p-1].setPrice(c);
            list[p-1].setSupplier(b);
            list[p-1].setPackagingUnits(d);

            cout << "\n\n\n\n STOCK MODIFIED CORRECTYLY!\n";
            stock.displayStock(list);
        }


        break;
    }
    case 4: //Delete
        if(list.empty()){
            cout << "\n--------------PRODUCTS IN STOCK!--------------\n";
            cout << "There is no products created, so we can not delete one!\n";
        }else{
            int p;
            stock.displayStock(list);
            cout <<"\n\n\nPlease, enter the number of the product to modify: ";
            cin >> p;
            int rest;
            cout << "\nEnter the number of units to be reduced from the object: ";
            cin >> rest;
            stock.deleteProduct(p-1,rest,list);

            stock.displayStock(list);
        }

        break;
    default:
        cout << "Value enered not valid\n";
        break;
    }
}

void menuMeansTransport(){
    cout << "1-Create a new Mean of Transport\n";
    cout << "2-Read Means of Transport\n";
    cout << "3-Update a Mean of Transport\n";
    cout << "4-Delete a Mean of Transport\n";

    cout << "Please, enter the desired value: ";
    string option;
    int aux =0;
    getline(cin, option);

    if (option.empty()) {
        cout << "Error: Please enter a valid number!!\n\n";

    }
    aux = stoi(option);
    switch (aux){

    case 1:{    //Create
        string name;
        double speed;
        double cost;
        cout << "\nEnter the name of the new Mean of Transport: ";
        getline(cin, name);
        cout << "\nEnter the speed of the new Mean of Transport in km/h: ";
        cin >> speed;
        cout << "\nEnter the cost of the new Mean of Transport in euro per km: ";
        cin >> cost;

        menuTransports();

        string type;
        cout << "Select the type of the transport: ";
        cin >> type;

        switch(stoi(type)){
        case 1:{ //Truck
            Truck truck(name,speed,cost,"National Route");
            truck.displayTruckInfo();
            truck.addTransport(truck,transports);
            cout << "Added Correctly!\n";
            break;
        }
        case 2:{ //Ship
            Ship ship(name,speed,cost,"Mediterranean Route");
            ship.displayShipInfo();
            ship.addTransport(ship,transports);
            cout << "Added Correctly!\n";
            break;
        }

        case 3:{//Aicraft
            Aircraft aircraft(name,speed,cost,"International Route");
            aircraft.addTransport(aircraft,transports);
            aircraft.displayAircraftInfo();
            cout << "Added Correctly!\n";
            break;
        }
        default:
            cout << "Input not valid, reseting menu\n\n\n";
            break;
        }
        break;
    }

    case 2: //Read2
        cout << "\n------------------------MEANS OF TRANSPORT------------------------\n";
        if(transports.empty()){
            cout << "There is no means of transport created!\n";
        }else{
            for(int i=0;i<(int)transports.size();i++){
                cout << "Transport " << i+1 << ":";
                transports[i].displayInfo(transports);
                cout << "Route: ";
                cout << transports[i].getRoute();
                cout << "\n";
            }
        }


        break;
    case 3:{ //Update
        cout << "\n------------------------MEANS OF TRANSPORT------------------------\n";
        if(transports.empty()){
            cout << "There is no means of transport to modify!\n\n";
        }else{
            int p;
                for(int i=0;i<(int)transports.size();i++){
                    cout << "Transport " << i+1 << ":";
                    transports[i].displayInfo(transports);
                    cout << "Route: ";
                    cout << transports[i].getRoute();
                    cout << "\n";
                }

            cout <<"Please, enter the number of the mean of transport to modify: ";
            cin >> p;
            string a;
            double b,c;
            cout << "\nIntroduce the name of the mean of transport: ";
            cin >> a;
            cout << "\nEnter the speed of the mean of transport: ";
            cin >> b;
            cout << "\nEnter the cost of the mean of transport: ";
            cin >> c;

            transports[p-1].setName(a);
            transports[p-1].setSpeed(b);
            transports[p-1].setCost(c);

            cout << "\n\n\n\n MEAN OF TRANSPORT MODIFIED CORRECTYLY!\n";
            cout << "\n------------------------MEANS OF TRANSPORT------------------------\n";
            for(int i=0;i<(int)transports.size();i++){
                cout << "Transport " << i+1 << ":";
                transports[i].displayInfo(transports);
            }
        }


        break;
    }
    case 4: //Delete

        cout << "\n------------------------MEANS OF TRANSPORT------------------------\n";
        if(transports.empty()){
            cout << "There is no means of transport created, so we can not delete one!\n";
            break;
        }else{
            for(int i=0;i<(int)transports.size();i++){
                cout << "Transport " << i+1 << ":";
                transports[i].displayInfo(transports);
                cout << "Route: ";
                cout << transports[i].getRoute();
                cout << "\n";
            }
            int p;
            cout <<"Please, enter the number of the mean of transport to delete: ";
            cin >> p;
            transports[p-1].deleteTransport(transports,p);
        }
        break;
    default:
        cout << "Value enered not valid\n";
        break;
    }
}

void menuPackaging(){
    cout << "1-Create a new Packaging\n";
    cout << "2-Read Packagings\n";
    cout << "3-Update a Packaging\n";
    cout << "4-Delete a Packaging\n";

    cout << "Please, enter the desired value: ";
    string option;
    int aux = 0;
    getline(cin, option);

    if (option.empty()) {
        cout << "Error: Please enter a valid number!!\n\n";
    }
    aux = stoi(option);
    switch (aux){

    case 1:{    //Create

        string packing;
        double cost;
        int capacity;
        cout << "\nEnter the name of the new Packing: ";
        getline(cin, packing);

        cout << "\nEnter the cost of the new Packing: ";
        cin >> cost;

        cout << "\nEnter the capacity in terms of 'packaging units': ";
        cin >> capacity;

        packaging packaging(packing,cost,capacity);
        packaging.addPackaging(packaging,packagings);


        break;
    }

    case 2: //Read
        cout << "\n------------------------PACKAGING------------------------\n";
        if(packagings.empty()){
            cout << "There is no packagings created!\n";
        }else{
            for(int i=0;i<(int)packagings.size();i++){
                cout << "Packaging " << i+1 << ":  Name: " << packagings[i].getPacking() << ", Id: " << packagings[i].getId() << ", Cost: " << packagings[i].getCost() << ", Capacity: " << packagings[i].getCapacity() << "\n";
            }
        }

        break;
    case 3:{
        //Update
        cout << "\n------------------------PACKAGING------------------------\n";
        if(packagings.empty()){
            cout << "There is no packagings to modify!\n\n";
        }else{

            for(int i=0;i<(int)packagings.size();i++){
                cout << "Packaging " << i+1 << ":  Name: " << packagings[i].getPacking() << ", Id: " << packagings[i].getId() << ", Cost: " << packagings[i].getCost() << ", Capacity: " << packagings[i].getCapacity() << "\n";
            }

            int p;
            cout <<"Please, enter the number of the packaging to modify: ";
            cin >> p;
            string x;
            double b;
            int c;

            cout << "\nEnter the cost of the packaging: ";
            cin >> b;

            cout << "\nEnter the capacity of the packaging: ";
            cin >> c;

            cout << "\nEnter the name of the new Packing: ";
            cin >> x;

            packagings[p-1].setCost(b);
            packagings[p-1].setCapacity(c);
            packagings[p-1].setPacking(x);

            cout << "\n------------------------PACKAGING------------------------\n";
            for(int i=0;i<(int)packagings.size();i++){
                cout << "Packaging " << i+1 << ":  Name: " << packagings[i].getPacking() << ", Id: " << packagings[i].getId() << ", Cost: " << packagings[i].getCost() << ", Capacity: " << packagings[i].getCapacity() << "\n";
            }

        }

        break;
    }

    case 4:
        //Delete

        cout << "\n------------------------PACKAGING------------------------\n";
        if(packagings.empty()){
            cout << "There is no packagings created,so we can not delete one!\n";
            break;
        }else{
            for(int i=0;i<(int)packagings.size();i++){
                cout << "Packaging " << i+1 << ":  Name: " << packagings[i].getPacking() << ", Id: " << packagings[i].getId() << ", Cost: " << packagings[i].getCost() << ", Capacity: " << packagings[i].getCapacity() << "\n";
            }
            int p;
            cout <<"Please, enter the number of the mean of transport to delete: ";
            cin >> p;
            packagings[p-1].deletePackaging(packagings,p);
        }

        break;
    default:
        cout << "Value enered not valid\n";
        break;
    }
}

void menuShipments(){
    std::vector<Product> productsShipment;
    cout << "1-Create a new Shipment\n";
    cout << "2-Read Shipments\n";
    cout << "3-Update a Shipment\n";
    cout << "4-Cancel a Shipment\n";

    cout << "Please, enter the desired value: ";

    string option;
    int aux;
    getline(cin, option);

    if (option.empty()) {
        cout << "Error: Please enter a valid number!!\n\n";
    }
    aux = stoi(option);
    switch (aux){

    case 1:{
        // Create
        if (customers.empty()) {
            cout << "There is not a customer created, so we cannot associate a shipment with a customer!\n";
        } else {
            for (int i = 0; i < (int)customers.size(); i++) {
                customers[i].displayInfo(customers);
            }

            int s;
            cout << "\n\nSelect the customer of the shipment: ";
            cin >> s;

            int x;
            int y;

            if (list.empty()) {
                cout << "There are no products in the stock, so we cannot add products to the shipment\n";
            } else {
                do {
                    stock.displayStock(list);
                    cout << "\nEnter the product for the shipment. Type 0 to stop adding products to the shipment: ";
                    cin >> x;

                    if (x == 0) {
                        break;
                    } else {
                        cout << "\nEnter the desired quantity of products for the shipment: ";
                        cin >> y;

                        if (y > list[x - 1].getPackagingUnits()) {
                            cout << "\nThe value entered is greater than the number of product quantities, please try again.";
                            break;
                        } else {

                            Product selectedProducts = list[x-1];
                            Product productstoAdd(selectedProducts.getName(),selectedProducts.getPrice(),selectedProducts.getSupplier(),y);
                            productsShipment.push_back(productstoAdd);
                            stock.deleteProduct(x - 1, y, list);
                        }
                    }
                } while (x != 0);

                cout << "\n------------------------PACKAGING------------------------\n";
                double test = 0;

                if (packagings.empty()) {
                    cout << "There are no packagings, so we cannot associate one to a shipment!\n";
                } else {
                    int capacity = 0;

                    for (int i = 0; i < (int)productsShipment.size(); i++) {
                        capacity += productsShipment[i].getPackagingUnits();
                    }

                    int control = 0;

                    do {
                        int h;

                        for (int i = 0; i < (int)packagings.size(); i++) {
                            cout << "Packaging " << i + 1 << ":  Name: " << packagings[i].getPacking() << ", Id: " << packagings[i].getId() << ", Cost: " << packagings[i].getCost() << ", Capacity: " << packagings[i].getCapacity() << "\n";
                        }

                        cout << "\nEnter the packaging for the shipment. Make sure to pack all the products!\n\n Remaining products to be packed: " << capacity << "\n";
                        cin >> h;

                        control += packagings[h - 1].getCapacity();
                        test += packagings[h - 1].getCapacity() * packagings[h - 1].getCost();

                        if (capacity > control) {
                            cout << "It iterates again because it doesn't reach, but subtracts";
                            capacity -= packagings[h - 1].getCapacity();
                        } else {
                            // It has passed/reached 0, so we set it to 0 and finish the packaging.
                            capacity = 0;
                        }
                    } while (capacity != 0);

                    if (transports.empty()) {
                        cout << "There is no means of transport created, so we cannot associate one to a shipment!\n";
                    } else {
                        cout << "\n------------------------MEANS OF TRANSPORT EXISTING------------------------\n";

                        for (int i = 0; i < (int)transports.size(); i++) {
                            cout << "Transport " << i + 1 << ":";
                            transports[i].displayInfo(transports);
                            cout << "Route: " << transports[i].getRoute() << "\n\n";
                        }

                        int n;
                        cout << "\nEnter the means of transport: ";
                        cin >> n;

                        shipment shipment(customers[s - 1], transports[n - 1], productsShipment);
                        shipment.setTotalUnits(test);
                        shipments.push_back(shipment);
                        break;
                    }
                }
            }
        }

        break;
    }

    case 2:
        //Read
        cout << "--------------SHIPMENT INFORMATION--------------\n";
        if(shipments.empty()){
            cout << "There is no shipments!\n";
        }else{
            for(int i=0;i<(int)shipments.size();i++){
                shipments[i].displayInfo();
            }
        }

        break;
    case 3:
        //Update
        cout << "----------SHIPMENT INFORMATION----------\n";
        if(shipments.empty()){
            cout << "There is not a shipment to modify!\n\n";
        }else{

            for(int i=0;i<(int)shipments.size();i++){
                cout << "--------------SHIPMENT " << (i+1) <<"--------------\n";
                shipments[i].displayInfo();
            }

            int s;
            cout << "Select the shipment to modify: ";
            cin >> s;

            for (int i =0;i<(int)customers.size();i++){
                customers[i].displayInfo(customers);
            }

            cout << "\n\nSelect the customer of the shipment: ";
            int x;
            cin >> x;

            cout << "\n------------------------MEANS OF TRANSPORT EXISTING------------------------\n";
            for(int i=0;i<(int)transports.size();i++){
                cout << "Transport " << i+1 << ":";
                transports[i].displayInfo(transports);
                cout << "Route: " << transports[i].getRoute() << "\n\n";
            }
            int n;
            cout << "\nEnter the mean of transport: ";

            cin >> n;

            int y;
            int z;
            if(list.empty()){
                cout << "There are no products in the stock, so we cannot add products to the shipment\n";
            }else{
                do{
                    stock.displayStock(list);
                    cout << "\nEnter the product for the shipment. Type 0 to stop adding products to the shipment: ";
                    cin >> z;

                    if(z==0){
                        break;
                    }else{
                        cout << "\nEnter the desired quantity of products for the shipment: ";
                        cin >> y;

                        if(y > list[z-1].getPackagingUnits()){
                            cout << "\nThe value entered is greater than the number of products quantiites, please try again.";
                            break;
                        }else{
                            Product selectedProducts = list[x-1];
                            Product productstoAdd(selectedProducts.getName(),selectedProducts.getPrice(), selectedProducts.getSupplier(),y);
                            productsShipment.push_back(productstoAdd);
                            stock.deleteProduct(z-1,y,list);
                            shipments[s-1].addProduct(productstoAdd);
                        }
                    }

                }while(z!=0);
                shipments[s-1].setCustomer(customers[x-1]);
                shipments[s-1].setTransport(transports[n-1]);
            }

        }

        break;
    case 4:{
        //Cancel
        cout << "--------------SHIPMENT INFORMATION--------------\n";
        if(shipments.empty()){
            cout << "There is no shipments!\n";
        }else{
            for(int i=0;i<(int)shipments.size();i++){
                shipments[i].displayInfo();
            }
            cout << "\nSelect the shipment to cancel: ";
            int pos;
            cin >> pos;

            if(shipments[pos-1].isDispatched()){
                cout << "The shipment is already dispatched\n\n";
            }else{
                shipments.erase(shipments.begin()+pos);
                cout << "Shipment cancel!\n\n";
            }
        }

        break;
    }
    default:
        cout << "Value enered not valid\n";
        break;
    }
}


void menuCustomers(){
    string name;
    int age, distance;

    cout << "\n\nEnter the name of the new customer: ";
    cin.ignore();
    getline(cin,name);

    cout << "\nEnter the age of the customer: ";
    cin >> age;

    cout << "\nEnter the distance of the customer: ";
    cin >> distance;

    customer customer(name,age,distance);

    customers.push_back(customer);
}

void calculateTotalPriceShipment(){
    cout << "----------SHIPMENT INFORMATION----------\n";
    if(shipments.empty()){
        cout << "There is not a shipment created, so we cannot calculate its price!\n";
    }else{
        for(int i=0;i<(int)shipments.size();i++){
            cout << "-------SHIPMENT " << i+1 << "-------\n";
            shipments[i].displayInfo();
        }

        cout << "\nSelect the shipment to calculate its final price: ";
        int s;
        cin >> s;

        double totalPrice = 0;

        totalPrice = shipments[s-1].calculateProductsPrice() + shipments[s-1].calculateTransportCost() + shipments[s-1].getTotalUnits();

        cout << "The total price of the shipment is: " << totalPrice << "\n";
    }

}

void save_restore(){


}

void menuTypeProducts(){
    cout << "1-Book\n";
    cout << "2-Clothing\n";
    cout << "3-Computer Games\n";
    cout << "4-Electronics\n";
    cout << "5-Furniture\n";
    cout << "6-Jewelry\n";
}

void menuTransports(){
    cout << "1-Truck\n";
    cout << "2-Ship\n";
    cout << "3-Aircraft\n";
}
