#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;

class customer
{

private:
    string name;
    int age;
    string id;
    int distance;


public:
    customer();
    customer(string name,int age,int distance);
    ~customer(void);

    string getName() const;
    int getAge() const;
    string getId() const;
    int getDistance() const;

    void setName(string name);
    void setAge(int age);
    void setId(string id);
    void setDistance(int distance);

    string generateUniqueID();
    void displayInfo(std::vector<customer> &array);
};

#endif // CUSTOMER_H
