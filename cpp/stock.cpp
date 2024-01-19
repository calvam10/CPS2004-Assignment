#include <iostream>
#include <string>
#include "stock.h"

using namespace std;
stock::stock()
{

}
stock::stock(std::vector<Product>& list){
    this->list = list;
}

stock::~stock(){

}

bool stock::addProduct(const Product product,std::vector<Product> &array){

    bool added = false;
    if(array.empty()){
        array.push_back(product);
        added = true;
    }else{
        for(int i=0;i<(int)array.size();i++){
            if(array[i].equals(product)){
                array[i].setPackagingUnits(array[i].getPackagingUnits()+product.getPackagingUnits());
                added = true;
                break;
            }
        }
        if(!added){
            array.push_back(product);
        }
    }
    return added;
}

bool stock::deleteProduct(int pos, int quantity,std::vector<Product> &array){
    bool deleted = false;
    if(!array.empty()){
        for(int i=0;i<(int)array.size();i++){
            if(array[i].getName() == array[pos].getName()){
                if(array[i].getPackagingUnits() > quantity){
                    array[i].setPackagingUnits(array[i].getPackagingUnits()-quantity);
                    cout << "Reduce the quantity of the Product selectioned\n";
                }else{
                    array.erase(list.begin()+i);
                    deleted = true;
                }
            }else{
                cout <<"The product is not in the stock\n";
            }
        }
    }

    return deleted;
}

void stock::displayStock(std::vector<Product>& array){
    cout << "--------------PRODUCTS IN STOCK!--------------\n";
    if(!array.empty()){
        for(int i = 0;i<(int)array.size();i++){
            cout << "Product " << i+1 << ": ";
            array[i].displayInfo();
        }
    }else{
        cout << "The stock is empty\n\n";
    }
}

