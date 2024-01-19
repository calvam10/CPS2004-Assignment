#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <vector>
#include "products.h"
#include "transport.h"
#include "customer.h"
#include <chrono>
#include <ctime>
#include <iomanip>

class shipment{

private:

    customer cust;
    Transport transport;
    std::vector<Product> productsPackaged;
    std::chrono::system_clock::time_point dispatchDate;
    std::chrono::system_clock::time_point deliveryDate;
    string status;
    double totalUnits;


public:
    shipment();
    shipment(customer cust,Transport transport,std::vector<Product> productsPackaged);
    ~shipment(void);



    //Getters&Setters
    customer getCustomer() const;
    Transport getTransport() const;
    double getTotalUnits() const;

    void setCustomer(customer cust);
    void setTransport(Transport transport);
    void setTotalUnits(double units);

    //Other Methods
    void addShipment(const shipment& shipments, std::vector<shipment> &array);
    void deleteShipment(std::vector<shipment> &array,int pos);
    void displayInfo();

    void addProduct(const Product product);
    bool isDispatched();
    void cancel();
    double calculateProductsPrice();
    double calculateDeliveryTime();
    double calculateTransportCost();
    double calculatePackagingPrice();
    int calculateProductsQuantity();


};

#endif // SHIPMENT_H
