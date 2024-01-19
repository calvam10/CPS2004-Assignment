#ifndef JEWELRY_H
#define JEWELRY_H

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

class Jewelry : public Product {
private:
    string material;
    string gemstone;
    string design;


public:
    //Getters & Setters
    string getMaterial() const;
    string getGemstone() const;
    string getDesign() const;

    void setMaterial(string material);
    void setGemstone(string gemstone);
    void setDesign(string design);

    //Methods
    Jewelry(const string& n, double a, const string& m, int x, const string& material, const string& gemstone, const string& design) : Product(n,a,m,x), material(material), gemstone(gemstone), design(design){}
    void displayInfo() const override;
    void displayJewelryInfo() const;

    double calculateDiscount(int quantity, int month) const;


};

#endif //   JEWELRY_H
