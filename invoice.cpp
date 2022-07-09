#include "invoice.h"

time_t Invoice::getTimestamp() {
    return created_at;
}
float Invoice::getTax() {
    return tax;
}

double Invoice::getProfit()
{
    return profit;
}

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
    std::vector<std::string>::iterator it = std::find(list_of_product_ID.begin(), list_of_product_ID.end(), id);
    if (it != list_of_product_ID.end()) return false;
    else return true;
}

void Invoice::setId(std::string id) { this->id = id; }

void Invoice::updateProfit(double profit)
{
    this->profit += profit;
}

void Invoice::addProduct(std::string id, Product &product, int quantity) {
    if (checkIfProductExists(id)) return;
    list_of_product_ID.push_back(id);
    double profit = product.getUnitPrice() * quantity;//PQH
    ProductWithQuantity combined_product;
    combined_product.product = product;
    combined_product.quantiy = quantity;
    this->updateProfit(profit);//PQH
    list_of_products[id] = combined_product;
}

void Invoice::removeProduct(string name) {
    list_of_products.erase(name);
}

string getTimestampAsStr() {
    struct tm *ltm = localtime(&created_at);
    char buffer[50];
    strftime(buffer, 50, "%Y-%m-%d %H:%M:%S", ltm);
    string s(buffer);
    return s;
}

//double Invoice::calculateTotal() {
//    double total = 0.0;
//    for (auto i = list_of_products.begin(); i != list_of_products.end(); i++) {
//        string name = i->first;
//        int quantity = i->second.quantiy;
//        double price = i->second.product.getUnitPrice();
//        total += price * quantity;
//    }
//    return total;
//}


