#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <packaging.h>

using namespace std;

class Product {

protected:
    string name;
    double price;
    string supplier;
    int packagingUnits;



public:

    Product();
    Product(string name, double price,string supplier,int packagingUnits);
    ~Product(void);

    //Setters & Getters
    string getName() const;
    double getPrice() const;
    string getSupplier() const;
    int getPackagingUnits() const;

    void setName(string name);
    void setPrice(double price);
    void setSupplier(string supplier);
    void setPackagingUnits(int units);

    //Methods
    virtual void displayInfo() const;
    virtual double calculate_discount(int quantity, int month);
    bool equals(Product product);


};



#endif //PRODUCT_H
