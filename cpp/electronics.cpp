#include "electronics.h"
#include <iostream>
#include <string>

using namespace std;



string Electronics::getBrand() const{
    return brand;
}

string Electronics::getPlaceOfManufacture() const{
    return placeOfManufacture;
}

int Electronics::getPower() const {
    return power;
}

void Electronics::setBrand(string brand){
    this->brand = brand;
}

void Electronics::setPlaceOfManufacture(string place){
    this->placeOfManufacture = place;
}

void Electronics::setPower(int power){
    this->power = power;
}


void Electronics::displayInfo() const  {
    Product::displayInfo();
    cout << ", Brand: " << brand << ", Place of Manufacture: " << placeOfManufacture << ", Power: " << power << "W" << "\n";
}

void Electronics::displayElectronicsInfo() const {
    cout << ", Brand: " << brand << ", Place of Manufacture: " << placeOfManufacture << ", Power: " << power << "W" << "\n";
}

double Electronics::calculateDiscount(int quantity, int month) const{
    if(quantity>6){
        return quantity * month * 0.1;
    }else{
        return quantity * month * 0.75;
    }
}
