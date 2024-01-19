#ifndef CLOTHING_H
#define CLOTHING_H

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

class Clothing : public Product {
private:
    string brand;
    char size;
    string color;


public:
    //Getters & Setters
    string getBrand() const;
    char getSize() const;
    string getColor() const;

    void setBrand(string brand);
    void setSize(char size);
    void setColor(string color);

    //Methods
    Clothing(const string& n, double a, const string& m, int x, const string& brand, const char& size, const string& color) : Product(n,a,m,x), brand(brand), size(size), color(color){}
    void displayInfo() const override;
    void displayClothingInfo() const;

    double calculateDiscount(int quantity, int month) const;
    //Clothing copy();



};
#endif //   CLOTHING_H
