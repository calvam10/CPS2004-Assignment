#ifndef STOCK_H
#define STOCK_H
#include <vector>
#include "products.h"


class stock {


private:
    std::vector<Product> list;


public:
    stock();
    stock(std::vector<Product>& list);
    ~stock(void);

    bool addProduct(const Product product,std::vector<Product>& array);
    bool deleteProduct(int pos, int quantity,std::vector<Product> &array);
    void displayStock(std::vector<Product>& array);

};

#endif // STOCK_H
