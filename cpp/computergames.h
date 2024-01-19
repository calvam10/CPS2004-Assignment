#ifndef COMPUTERGAMES_H
#define COMPUTERGAMES_H

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

class ComputerGames : public Product {
private:
    string company;
    string console;
    int minimumAge;


public:
    //Getters & Setters
    string getCompany() const;
    string getConsole() const;
    int getMinimumAge() const;

    void setCompany(string company);
    void setConsole(string console);
    void setMinimumAge(int age);

    //Methods
    ComputerGames(const string& n, double a, const string& m, int x, const string& company, const string& console, int age) : Product(n,a,m,x), company(company), console(console), minimumAge(age){}
    void displayInfo() const override;
    void displayComputerGamesInfo() const;

    double calculateDiscount(int quantity, int month) const;



};

#endif //   COMPUTERGAMES_H
