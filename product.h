#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
//#include "uuid.h"

class Product
{
private:
    double unit_price;
    std::string id;
public:
    Product();
    Product(std::string _id, double _price);
    // Accessing
    double getUnitPrice();
    std::string getID();
    // Modify
    void setUnitPrice(double);
    void setID(std::string);
};

#endif // PRODUCT_H
