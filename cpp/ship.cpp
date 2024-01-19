#include "ship.h"
#include <iostream>
#include <string>

using namespace std;



string Ship::getRoute() const{
    return route;
}


void Ship::displayInfo(std::vector<Transport> list) const  {
    Transport::displayInfo(list);
    cout << ", Route: " << route << "\n";

}

void Ship::displayShipInfo() const {
    cout << "Route: " << route << "\n";
}
