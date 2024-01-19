#include "Jewelry.h"
#include <iostream>
#include <string>

using namespace std;



string Jewelry::getMaterial() const{
    return material;
}

string Jewelry::getGemstone() const{
    return gemstone;
}

string Jewelry::getDesign() const{
    return design;
}

void Jewelry::setMaterial(string material){
    this->material = material;
}

void Jewelry::setGemstone(string gemstone){
    this->gemstone = gemstone;
}

void Jewelry::setDesign(string design){
    this->design = design;
}


void Jewelry::displayInfo() const{
    Product::displayInfo();
    cout << ", Material: " << material << ", Gemstone: " << gemstone << ", Design: " << design << "\n";
}

void Jewelry::displayJewelryInfo() const {
    cout << ", Material: " << material << ", Gemstone: " << gemstone << ", Design: " << design << "\n";
}

double Jewelry::calculateDiscount(int quantity, int month) const{
    if(quantity>2){
        return quantity * month * 0.15;
    }else{
        return quantity * month;
    }
}
