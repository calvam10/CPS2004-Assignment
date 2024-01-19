#include <iostream>
#include <string>
#include "Products.h"


using namespace std;

Product::Product(){

}

Product::Product(string name, double price, string supplier, int packagingUnits){
    this->name = name;
    this->price = price;
    this->supplier = supplier;
    this->packagingUnits = packagingUnits;
}

Product::~Product(){

}

string Product::getName() const{
    return name;
}

double Product::getPrice() const{
    return price;
}

string Product::getSupplier() const {
    return supplier;
}

int Product::getPackagingUnits() const{
    return packagingUnits;
}

void Product::setName(string name){
    this->name = name;
}

void Product::setPrice(double price){
    this->price = price;
}

void Product::setSupplier(string supplier){
    this->supplier = supplier;
}

void Product::setPackagingUnits(int units){
    this->packagingUnits = units;
}

void Product::displayInfo() const {
    cout << "\nName: " << name << ", Price: " << price << ", Supplier: " << supplier << ", Units: " << packagingUnits << "\n";
}

double Product::calculate_discount(int quantity,int month){
    return quantity*month;

}

bool Product::equals(Product product){
    if(this->name == product.getName() && this->price == product.getPrice() && this->supplier == product.getSupplier()){
        return true;
    }
    return false;
}
