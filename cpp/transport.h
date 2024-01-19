#ifndef TRANSPORT_h
#define TRANSPORT_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transport{
protected:
    string name;
    double speed;
    double cost;


public:
    Transport();
    Transport(string name,double speed, double cost);
    ~Transport(void);

    //Setters & Getters
    string getName() const;
    double getSpeed() const;
    double getCost() const;

    void setName(string name);
    void setSpeed(double speed);
    void setCost(double cost);

    //Methods

    virtual void displayInfo(std::vector<Transport> list) const;
    virtual double deliveryCost(double distance) const;
    virtual string getRoute() const{
        return "";
    }
    void addTransport(const Transport& transport,std::vector<Transport> &array);
    void deleteTransport(std::vector<Transport> &array,int pos);




};

#endif //   TRANSPORT_h
