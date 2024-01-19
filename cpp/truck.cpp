#include "truck.h"
#include <iostream>
#include <string>

using namespace std;



string Truck::getRoute() const{
    return route;
}


void Truck::displayInfo(std::vector<Transport> list) const  {
    Transport::displayInfo(list);
    cout << ", Route: " << route << "\n";

}

void Truck::displayTruckInfo() const {
    cout << "Route: " << route << "\n";
}
