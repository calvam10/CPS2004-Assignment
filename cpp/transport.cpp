#include <iostream>
#include <string>
#include "Transport.h"

using namespace std;

Transport::Transport(){

}

Transport::Transport(string name,double speed, double cost){
    this->name = name;
    this->speed = speed;
    this->cost = cost;
}

Transport::~Transport(){

}

string Transport::getName() const{
    return name;
}
double Transport::getSpeed() const{
    return speed;
}

double Transport::getCost() const{
    return cost;
}

void Transport::setName(string name){
    this->name = name;
}

void Transport::setSpeed(double speed){
    this->speed = speed;
}

void Transport::setCost(double cost){
    this->cost = cost;
}


void Transport::displayInfo(std::vector<Transport> list) const {
    for(int i=0;i<(int)list.size();i++){
        cout << "Name: " << name << ", Speed: " << speed << ", Cost: " << cost << "\n";
    }
}

double Transport::deliveryCost(double distance) const{
    return distance*this->cost;
}

void Transport::addTransport(const Transport& transport,std::vector<Transport> &array){

    array.push_back(transport);

}

void Transport::deleteTransport(std::vector<Transport> &array,int pos){
    array.erase(array.begin()+pos);
}
