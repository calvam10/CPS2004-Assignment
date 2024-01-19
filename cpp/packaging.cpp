#include <string>
#include "packaging.h"
#include <vector>

using namespace std;

packaging::packaging(){

}

packaging::packaging(string packing,double cost, int capacity){
    this->packing = packing;
    this->id = generateUniqueID();
    this->cost = cost;
    this->capacity = capacity;
}

packaging::~packaging(){

}

string packaging::getPacking() const{
    return packing;
}

string packaging::getId() const{
    return id;
}

double packaging::getCost() const{
    return cost;
}

int packaging::getCapacity() const{
    return capacity;
}

void packaging::setPacking(string packaging){
    this->packing = packaging;
}
void packaging::setId(string id){
    this->id = id;
}
void packaging::setCost(double cost){
    this->cost = cost;
}
void packaging::setCapacity(int capacity){
    this->capacity = capacity;
}

string packaging::generateUniqueID(){
    const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string id;
    std::srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        char x = characters[rand() % characters.length()-1];
        id += x;
    }
    return id;
}

void packaging::addPackaging(const packaging& packagings,std::vector<packaging> &array){

    array.push_back(packagings);
}

void packaging::deletePackaging(std::vector<packaging> &array,int pos){
    array.erase(array.begin()+pos);

}

