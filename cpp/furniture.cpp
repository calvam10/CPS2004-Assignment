#include "furniture.h"
#include <iostream>
#include <string>

using namespace std;



string Furniture::getMaterial() const{
    return material;
}

string Furniture::getDimensions() const{
    return dimensions;
}

string Furniture::getStyle() const{
    return style;
}

void Furniture::setMaterial(string material){
    this->material = material;
}

void Furniture::setDimensions(string dimensions){
    this->dimensions = dimensions;
}

void Furniture::setStyle(string style){
    this->style = style;
}


void Furniture::displayInfo() const  {
    Product::displayInfo();
    cout << ", Material: " << material << ", Dimensions: " << dimensions << ", Style: " << style << "\n";
}

void Furniture::displayFurnitureInfo() const {
    cout << ", Material: " << material << ", Dimensions: " << dimensions << ", Style: " << style << "\n";
}

double Furniture::calculateDiscount(int quantity, int month) const{
    if(quantity>6){
        return quantity * month * 0.08;
    }else{
        return quantity * month * 0.62;
    }
}
