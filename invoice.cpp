#include "invoice.h"

std::string Invoice::getId()
{
    return id;
}

time_t Invoice::getTimestamp() {
    return created_at;
}
float Invoice::getTax() {
    return tax;
}

std::string Invoice::getTime()
{
    return time;
}

//double Invoice::getProfit()
//{
//    return profit;
//}

std::vector<std::string> Invoice::get_list_of_product_ID()
{
    return list_of_product_ID;
}

unordered_map<string, struct ProductWithQuantity> Invoice::get_list_of_products()
{
    return list_of_products;
}

bool Invoice::checkIfProductExists(std::string id)
{
    for (auto pro_id : this->get_list_of_product_ID())
        if (pro_id == id)
            return true;
    return false;
}

void Invoice::setId(std::string id) { this->id = id; }

//void Invoice::updateProfit(double profit)
//{
//    this->profit += profit;
//}

void Invoice::addProduct(std::string id, Product &product, int quantity) {
    if (checkIfProductExists(id)) return;
    this->list_of_product_ID.push_back(id);
//    double profit = product.getUnitPrice() * quantity;//PQH
    ProductWithQuantity combined_product;
    combined_product.product = product;
    combined_product.quantiy = quantity;
//    this->updateProfit(profit);//PQH
    list_of_products[id] = combined_product;
}

void Invoice::removeProduct(string name) {
    for (int i = 0; i < list_of_product_ID.size(); i++)
        if (list_of_product_ID[i] == name)
        {
            list_of_product_ID.erase(list_of_product_ID.begin()+i);
            break;
        }
    list_of_products.erase(name);
}

double Invoice::calculateTotal() {
    double total = 0.0;
    for (auto i = list_of_products.begin(); i != list_of_products.end(); i++) {
        string name = i->first;
        int quantity = i->second.quantiy;
        double price = i->second.product.getUnitPrice();
        total += price * quantity;
    }
    return total;
}

void Invoice::setQuantity(std::string pro_id, int quantity)
{
    list_of_products[pro_id].quantiy = quantity;
}

void Invoice::setTime(std::string time)
{
    this->time = time;
}
