#include "product.h"

Product::Product()
{

}

Product::Product(std::string _id, std::string _name, double _price)
{
    name_of_product = _name;
    unit_price = _price;
    id = _id;
}

std::string Product::getProduceName()
{
    return name_of_product;
}

double Product::getUnitPrice()
{
    return unit_price;
}

std::string Product::getID()
{
    return id;
}

void Product::setName(std::string _name)
{
    name_of_product = _name;
}

void Product::setUnitPrice(double _unit_price)
{
    unit_price = _unit_price;
}

