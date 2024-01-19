#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Transport.h"
#include <iostream>
#include <string>

using namespace std;

class Aircraft : public Transport {
private:
    string route;


public:
    //Getter
    string getRoute() const;


    //Methods
    Aircraft(string m,double n, double a,string x) : Transport(m,n,a),route(x){}
    void displayInfo(std::vector<Transport> list) const ;
    void displayAircraftInfo() const;



};

#endif //   AIRCRAFT_H
