#include "Aircraft.h"
#include <iostream>
#include <string>

using namespace std;

string Aircraft::getRoute() const{
    return route;
}


void Aircraft::displayInfo(std::vector<Transport> list) const  {
    Transport::displayInfo(list);
    cout << ", Route: " << route << "\n";

}

void Aircraft::displayAircraftInfo() const {
    cout << "Route: " << route << "\n";
}
