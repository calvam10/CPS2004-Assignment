#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

class Electronics : public Product {
private:
    string brand;
    string placeOfManufacture;
    int power;


public:
    //Getters & Setters
    string getBrand() const;
    string getPlaceOfManufacture() const;
    int getPower() const;

    void setBrand(string brand);
    void setPlaceOfManufacture(string place);
    void setPower(int power);

    //Methods
    Electronics(const string& n, double a, const string& m,int x, const string& brand, const string& place, int power) : Product(n,a,m,x), brand(brand), placeOfManufacture(place), power(power){}
    void displayInfo() const override;
    void displayElectronicsInfo() const;

    double calculateDiscount(int quantity, int month) const;



};

#endif //   ELECTRONICS_H
