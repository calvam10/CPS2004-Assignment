#ifndef FURNITURE_H
#define FURNITURE_H

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

class Furniture : public Product {
private:
    string material;
    string dimensions;
    string style;


public:
    //Getters & Setters
    string getMaterial() const;
    string getDimensions() const;
    string getStyle() const;

    void setMaterial(string material);
    void setDimensions(string dimensions);
    void setStyle(string style);

    //Methods
    Furniture(const string& n, double a, const string& m,int x, const string& material, const string& dimensions, const string& style) : Product(n,a,m,x), material(material), dimensions(dimensions), style(style){}
    void displayInfo() const override;
    void displayFurnitureInfo() const;

    double calculateDiscount(int quantity, int month) const;



};

#endif //   FURNITURE_H
