#ifndef PACKAGING_H
#define PACKAGING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class packaging {

private:
    string packing;
    string id;
    double cost;
    int capacity;


public:
    packaging();
    packaging(string packing,double cost, int capacity);
    ~packaging(void);



    //Getters & Setters
    string getPacking() const;
    string getId() const;
    double getCost() const;
    int getCapacity() const;

    void setPacking(string packing);
    void setId(string id);
    void setCost(double cost);
    void setCapacity(int capacity);

    string generateUniqueID();
    void addPackaging(const packaging& packagings,std::vector<packaging> &array);
    void deletePackaging(std::vector<packaging> &array,int pos);


};

#endif // PACKAGING_H
