#include "shipment.h"



shipment::shipment()
{

}

shipment::shipment(customer cust,Transport transport,std::vector<Product> productsPackaged){
    this->cust = cust;
    this->transport = transport;
    this->productsPackaged = productsPackaged;
    this->dispatchDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 2);
    this->deliveryDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 2 * (int)calculateDeliveryTime());
    this->status = "Dispatching";

}
shipment::~shipment(void){

}

customer shipment::getCustomer() const{
    return cust;
}

Transport shipment::getTransport() const{
    return transport;
}

double shipment::getTotalUnits() const{
    return totalUnits;
}

void shipment::setCustomer(customer cust){
    this->cust = cust;
}

void shipment::setTransport(Transport transport){
    this->transport = transport;
}

void shipment::setTotalUnits(double units){
    this->totalUnits = units;
}

void shipment::addShipment(const shipment& shipments, std::vector<shipment> &array){
    array.push_back(shipments);
}

void shipment::deleteShipment(std::vector<shipment> &array,int pos){
    array.erase(array.begin()+pos);
}

void shipment::displayInfo(){

    cout <<  "Customer: " << cust.getName() << ", Transport : " << transport.getName() << "\n";
    cout << "List of Products: \n";
    for(Product products : this->productsPackaged){
        products.displayInfo();
        cout << "\n";
    }
    cout << "Total price of the products: " << calculateProductsPrice() << "\n";
    cout << "Total price of the transport: " << calculateTransportCost() << "\n";
    cout << "Total price of the packagings: " << getTotalUnits() << "\n";

    std::time_t dispatchDate_t = std::chrono::system_clock::to_time_t(dispatchDate);
    std::tm* printedDispatchDate= std::localtime(&dispatchDate_t);

    std::time_t deliveryDate_t = std::chrono::system_clock::to_time_t(deliveryDate);
    std::tm* printedDeliveryDate= std::localtime(&deliveryDate_t);

    cout << "Expected Date of Distatch: " << std::put_time(printedDispatchDate, "%Y-%m-%d %H:%M:%S");
    cout << "  -  Expected Time of Delivery: " << std::put_time(printedDeliveryDate, "%Y-%m-%d %H:%M:%S");

    cout << "\n\nStatus: " << status << "\n";
}

void shipment::addProduct(const Product product){
    bool added = false;
    if(this->productsPackaged.empty()){
        this->productsPackaged.push_back(product);
        added = true;
    }else{
        for(int i=0;i<(int)this->productsPackaged.size();i++){
            if(this->productsPackaged[i].equals(product)){
                this->productsPackaged[i].setPackagingUnits(this->productsPackaged[i].getPackagingUnits()+product.getPackagingUnits());
                added = true;
                break;
            }
        }
        if(!added){
            this->productsPackaged.push_back(product);
        }
    }
}

bool shipment::isDispatched(){

    auto currentTime = std::chrono::system_clock::now();


    return (currentTime > this->dispatchDate);
}

void shipment::cancel(){


}

double shipment::calculateProductsPrice(){
    double total =0;
    for(Product products : this->productsPackaged){
        total +=products.getPrice()*products.getPackagingUnits();
    }

    return total;

}

double shipment::calculateDeliveryTime(){
    return this->cust.getDistance() / this->transport.getSpeed();
}

double shipment::calculateTransportCost(){
    return this->cust.getDistance() * this->transport.getCost();
}

int shipment::calculateProductsQuantity(){
    int total = 0;

    for(Product products : this->productsPackaged){
        total +=products.getPackagingUnits();
    }

    return total;
}
