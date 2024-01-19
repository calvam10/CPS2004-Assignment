#include "ComputerGames.h"
#include <iostream>
#include <string>

using namespace std;



string ComputerGames::getCompany() const{
    return company;
}

string ComputerGames::getConsole() const{
    return console;
}

int ComputerGames::getMinimumAge() const{
    return minimumAge;
}

void ComputerGames::setCompany(string company){
    this->company = company;
}

void ComputerGames::setConsole(string console){
    this->console = console;
}

void ComputerGames::setMinimumAge(int age){
    this->minimumAge = age;
}


void ComputerGames::displayInfo() const  {
    Product::displayInfo();
    cout << ", Company: " << company << ", Console: " << console << ", Minimum Age: " << minimumAge << "\n";
}

void ComputerGames::displayComputerGamesInfo() const {
    cout << ", Company: " << company << ", Console: " << console << ", Minimum Age: " << minimumAge << "\n";
}

double ComputerGames::calculateDiscount(int quantity, int month) const{
    if(quantity>3){
        return quantity * month * 0.15;
    }else{
        return quantity * month * 0.90;
    }
}
