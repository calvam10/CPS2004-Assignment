#include "customer.h"
#include <iostream>
#include <string>
using namespace std;

customer::customer()
{

}

customer::customer(string name,int age,int distance){
    this->name = name;
    this->age = age;
    this->id = generateUniqueID();
    this->distance = distance;

}

customer::~customer(){

}

string customer::getName() const{
    return name;
}

int customer::getAge() const{
    return age;
}

string customer::getId() const{
    return id;
}

int customer::getDistance() const{
    return distance;
}

void customer::setName(string name){
    this->name = name;
}

void customer::setId(string id){
    this->id = id;
}

void customer::setAge(int age){
    this->age = age;
}

void customer::setDistance(int distance){
    this->distance = distance;
}

string customer::generateUniqueID(){
    const string characters = "0123456789";
    string id;
    std::srand(time(NULL));
    for (int i = 0; i < 8; ++i) {
        char x = characters[rand() % characters.length()-1];
        id += x;
    }
    return id;
}

void customer::displayInfo(std::vector<customer> &array){
    for(int i=0;i<(int)array.size();i++){
        cout << "Customer " << i+1 << ": " << "Name: " << array[i].getName() << ", Age: " << array[i].getAge() << ", Id: " << array[i].getId() << "\n";
    }
}
