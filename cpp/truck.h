#ifndef TRUCK_H
#define TRUCK_H

#include "transport.h"
#include <iostream>
#include <string>

using namespace std;

class Truck : public Transport {
private:
    string route;


public:
    //Getter
    string getRoute() const;


    //Methods
    Truck(string m,double n, double a,string x) : Transport(m,n,a),route(x){}
    void displayInfo(std::vector<Transport> list) const;
    void displayTruckInfo() const;



};

#endif //   TRUCK_H
