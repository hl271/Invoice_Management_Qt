#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
//#include "uuid.h"

class Product
{
private:
    std::string name_of_product;
    int unit_price;
    std::string id;
public:
    Product();
    Product(std::string _id, std::string _name, double _price);
    // Accessing
    std::string getProduceName();
    double getUnitPrice();
    std::string getID();
    // Modify
    void setName(std::string);
    void setUnitPrice(double);
};

#endif // PRODUCT_H
