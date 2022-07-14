// CORE APP - Dang Hoang Lan
#ifndef INVOICE_H
#define INVOICE_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <unordered_map>
#include <algorithm>
#include "product.h"
//#include "uuid.h"

using namespace std;
enum InvoiceType {
    INCOMING_DOMESTIC, INCOMING_FOREIGN, OUTCOMING_DOMESTIC, OUTCOMING_FOREIGN
};

struct ProductWithQuantity {
    Product product;
    int quantiy;
};

class Invoice {
protected:
    string id;
    //string type="";
    unordered_map<string, struct ProductWithQuantity> list_of_products;
    std::vector<std::string> list_of_product_ID;//PQH
    //double Total = 0;
//    double profit = 0.0;//PQH
    float tax = 0;
    time_t created_at;
    std::string time;
public:
    Invoice(string sid, std::time_t time) :id(sid), created_at(time){}
    virtual ~Invoice() = default;
    //Accessing
    string getId();
    virtual string getTypeAsStr()=0;
    float getTax();
    double getProfit();//PQH
    virtual bool isIncoming()=0;
    virtual bool isDomestic()=0;
    std::time_t getTimestamp();
    string getTimestampAsStr();
    bool checkIfProductExists(std::string);//PQH
    std::vector<std::string> get_list_of_product_ID();//PQH
    unordered_map<string, struct ProductWithQuantity> get_list_of_products();//PQH
    std::string getTime();
    //Modify
    void setId(string id);
    void setTime(time_t time);
//    void updateProfit(double);//PQH
    void addProduct(string id, Product& product, int quantity);//PQH change
    void removeProduct(string id);
    void setType(InvoiceType type);
    void deleteInvoice();
    void setTotal();
    void setQuantity(std::string pro_id, int quantity);
    void setTime(std::string);
    //Searching
    //Helper
    InvoiceType convertStrToType(string type_as_str);
    double calculateTotal();
};

#endif // INVOICE_H
