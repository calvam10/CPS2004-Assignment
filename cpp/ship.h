#ifndef SHIP_H
#define SHIP_H

#include "transport.h"
#include <iostream>
#include <string>

using namespace std;

class Ship : public Transport {
private:
    string route;


public:
    //Getter
    string getRoute() const;


    //Methods
    Ship(string m,double n, double a,string x) : Transport(m,n,a),route(x){}
    void displayInfo(std::vector<Transport> list) const;
    void displayShipInfo() const;



};

#endif //   SHIP_H
