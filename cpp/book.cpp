#include "Book.h"
#include <iostream>
#include <string>

using namespace std;



string Books::getAuthor() const{
    return author;
}

string Books::getGenre() const{
    return genre;
}

int Books::getYearOfPublication() const{
    return yearOfPublication;
}

void Books::setAuthor(string author){
    this->author = author;
}

void Books::setGenre(string genre){
    this->genre = genre;
}

void Books::setYearOfPublication(int year){
    this->yearOfPublication = year;
}


void Books::displayInfo() const  {
    Product::displayInfo();
    cout << ", Author: " << author << ", Genre: " << genre << ", Year of Publication: " << yearOfPublication << "\n";
}

void Books::displayBookInfo() const {
    cout << ", Author: " << author << ", Genre: " << genre << ", Year of Publication: " << yearOfPublication << "\n";
}

double Books::calculateDiscount(int quantity, int month) const{
    if(quantity>10){
        return quantity * month * 0.6;
    }else{
        return quantity * month * 0.8;
    }
}

