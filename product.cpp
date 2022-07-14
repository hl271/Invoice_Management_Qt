// CORE APP - Dang Hoang Lan
#include "product.h"

Product::Product()
{

}

Product::Product(std::string _id, double _price)
{
    unit_price = _price;
    id = _id;
}

double Product::getUnitPrice()
{
    return unit_price;
}

std::string Product::getID()
{
    return id;
}

void Product::setUnitPrice(double _unit_price)
{
    unit_price = _unit_price;
}

void Product::setID(std::string ID)
{
    this->id = ID;
}

