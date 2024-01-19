#ifndef BOOKS_H
#define BOOKS_H

#include "Products.h"
#include <iostream>
#include <string>

using namespace std;

class Books : public Product {
private:

    string author;
    string genre;
    int yearOfPublication;


public:
    //Getters & Setters
    string getGenre() const;
    string getAuthor() const;
    int getYearOfPublication() const;

    void setGenre(string genre);
    void setAuthor(string author);
    void setYearOfPublication(int year);

    //Methods
    Books(const string& n, double a, const string& m, int x, const string& author, const string& genre, int year) : Product(n,a,m,x), author(author), genre(genre), yearOfPublication(year){}
    void displayInfo() const override;
    void displayBookInfo() const;

    double calculateDiscount(int quantity, int month) const;



};

#endif //   BOOKS_H
