#include "Clothing.h"
#include <iostream>
#include <string>

using namespace std;



string Clothing::getBrand() const{
    return brand;
}

char Clothing::getSize() const{
    return size;
}

string Clothing::getColor() const {
    return color;
}

void Clothing::setBrand(string brand){
    this->brand = brand;
}

void Clothing::setSize(char size){
    this->size = size;
}

void Clothing::setColor(string color){
    this->color = color;
}


void Clothing::displayInfo() const  {
    Product::displayInfo();
    cout << ", Brand: " << brand << ", Size: " << size << ", Color: " << color << "\n";
}

void Clothing::displayClothingInfo() const {
    cout << ", Brand: " << brand << ", Size: " << size << ", Color: " << color << "\n";
}

double Clothing::calculateDiscount(int quantity, int month) const{
    if(quantity>15){
        return quantity * month * 0.3;
    }else{
        return quantity * month * 0.5;
    }
}

/*Clothing Clothing::copy(){
    Clothing();
}*/
