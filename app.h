#ifndef APP_H
#define APP_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <time.h>
#include <algorithm>
#include "invoice.h"
#include "product.h"
#include "incoming_domestic.h"
#include "incoming_foreign.h"
#include "outcoming_domestic.h"
#include "outcoming_foreign.h"

struct CombinedId {
    std::string id;
    time_t timestamp;
};
class App
{
public:
    std::unordered_map<std::string, Invoice*> DB_INVOICE;
    //unordered_map<string, Invoice*> DB_INVOICE_IF;
    //unordered_map<string, Invoice*> DB_INVOICE_OD;
    //unordered_map<string, Invoice*> DB_INVOICE_OF;
    std::unordered_map<std::string, Product> DB_PRODUCT;
    std::vector<std::string> IDS_INVOICE;
    std::vector<std::string> IDS_PRODUCT;
    App();
    ~App();
    //Product
    void addNewProductToDb(std::string id, std::string name, double price);
    void addExistingProductToDb(std::string id, std::string name, double price);

    // Invoices
    std::string addNewInvoiceToDb(std::string type_as_str, std::string code);
    // strtime has format %Y-%m-%d %H:%M:%S
    void addExistingInvoiceToDb(std::string id, std::string time);
    bool addProductToInvoice(std::string inv_id, std::string product_id, int quantity);
    bool editProductInInvoice(std::string inv_id, std::string product_id, int quantity);
    bool removeProductFromInvoice(std::string inv_id, std::string product_id);
    bool removeInvoice(std::string inv_id);

    //Search
    std::string searchByInvoiceCode(std::string inv_id);
    std::vector<std::string> searchByInvoiceType(std::string type);
    std::vector<std::string> searchByInvoiceItems(std::string name_of_product);
    //time has format %Y-%m-%d
    std::vector<std::string> searchByTimeRange(std::string start_day, std::string end_day);//PQH change

    //Calulate profit by time range
    double calculateProfitByTimeRange(std::string start_day, std::string end_day);

    //Helper methods
    time_t convertStringTimeFormat1(std::string strtime);
    time_t convertStringTimeFormat2(std::string strtime);
    void printAllInvoices();


};
#endif // APP_H
