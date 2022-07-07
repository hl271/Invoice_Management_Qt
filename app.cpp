#include "app.h"

App::App() {
    std::cout << "CoreApp starts...."  <<std::endl;
    //std::cout << time(0) << std::endl;
}
std::string App::addNewInvoiceToDb(std::string type, std::string code) {
    time_t now = time(0);
    std::string id = type + to_string(now) + code;
    if (type == "ID") {
        DB_INVOICE[id] = new Incoming_Domestic(id, now);
    }
    else if (type == "IF") {
        DB_INVOICE[id] = new Incoming_Foreign(id, now);

    }
    else if (type == "OD") {
        DB_INVOICE[id] = new Outcoming_Domestic(id, now);

    }
    else if (type == "OF") {
        DB_INVOICE[id] = new Outcoming_Foreign(id, now);
    }

    IDS_INVOICE.push_back(id);

    return id;
}

App::~App() {
    std::cout <<"Core App closed!"<<std::endl;
}

void App::addExistingInvoiceToDb(string id, string strtime) {
    string type = id.substr(0, 2);
    time_t timestamp = convertStringTimeFormat1(strtime);
    if (type == "ID") {
        DB_INVOICE[id] = new Incoming_Domestic(id, timestamp);
    }
    else if (type == "IF") {
        DB_INVOICE[id] = new Incoming_Foreign(id, timestamp);
    }
    else if (type == "OD") {
        DB_INVOICE[id] = new Outcoming_Domestic(id, timestamp);
    }
    else if (type == "OF") {
        DB_INVOICE[id] = new Outcoming_Foreign(id, timestamp);
    }
    else return;
    IDS_INVOICE.push_back(id);
}

void App::addNewProductToDb(std::string id, string name, double price) {
    DB_PRODUCT[id] = Product(id, name, price);
    IDS_PRODUCT.push_back(id);
}

void App::addExistingProductToDb(string id, string name, double price) {
    DB_PRODUCT[id] = Product(id, name, price);
    IDS_PRODUCT.push_back(id);
}

bool App::addProductToInvoice(string inv_id, string product_id, int quantity){
    if (DB_INVOICE.find(inv_id) == DB_INVOICE.end()) {
//        cout << "Invoice id " << inv_id << "not found!" << endl;
        return false;
    }
    else {
        Product found_product = DB_PRODUCT[product_id];
        DB_INVOICE[inv_id]->addProduct(product_id, found_product, quantity);
        return true;
    }
}

bool App::editProductInInvoice(string inv_id, string product_id, int quantity) {
    if (DB_INVOICE.find(inv_id) == DB_INVOICE.end()) {
//        cout << "Invoice id " << inv_id << "not found!" << endl;
        return false;
    }
    else {
        Product found_product = DB_PRODUCT[product_id];
        DB_INVOICE[inv_id]->addProduct(product_id, found_product, quantity);
        return true;
    }
}

bool App::removeProductFromInvoice(string inv_id, string product_id){
    if (DB_INVOICE.find(inv_id) == DB_INVOICE.end()) {
        cout << "Invoice id " << inv_id << "not found!" << endl;
        return false;
    }
    else {
        DB_INVOICE[inv_id]->removeProduct(product_id);
        return true;
    }
}
bool App::removeInvoice(string inv_id) {
    if (DB_INVOICE.find(inv_id) == DB_INVOICE.end()) {
        cout << "No invoice found!";
        return false;
    }
    else {
        delete DB_INVOICE[inv_id];
        DB_INVOICE.erase(inv_id);
        vector<string>::iterator itr;
        itr = std::find(IDS_INVOICE.begin(), IDS_INVOICE.end(), inv_id);
        if (itr != IDS_INVOICE.end()) itr = IDS_INVOICE.erase(itr);
        return true;
    }
}

string App::searchByInvoiceCode(string inv_id){
    if (DB_INVOICE.find(inv_id) == DB_INVOICE.end()) {
//        cout << "Invoice id " << inv_id << "not found!" << endl;
        return "";
    }
    else {
        return inv_id;
    }
}

vector<string> App::searchByInvoiceType(string type){
    vector<string> results;
    // 8 types: "ID", "IF", "OD", "OF", "I", "O", "D", "F"
    for (auto i = IDS_INVOICE.begin(); i != IDS_INVOICE.end(); i++) {
        string id = *i;
        Invoice* inv = DB_INVOICE[id];
        if (type == "ID") {
            if (inv->isDomestic() && inv->isIncoming()) results.push_back(id);
        }
        else if (type == "IF") {
            if (!inv->isDomestic() && inv->isIncoming()) results.push_back(id);
        }
        else if (type == "OD") {
            if (!inv->isDomestic() && !inv->isIncoming()) results.push_back(id);
        }
        else if (type == "OF") {
            if (!inv->isDomestic() && !inv->isIncoming()) results.push_back(id);
        }
        else if (type == "I") {
            if (inv->isIncoming()) results.push_back(id);
        }
        else if (type == "O") {
            if (!inv->isIncoming()) results.push_back(id);
        }
        else if (type == "D") {
            if (inv->isDomestic()) results.push_back(id);
        }
        else if (type == "F") {
            if (!inv->isDomestic()) results.push_back(id);
        }

    }
    return results;
}

vector<string> App::searchByInvoiceItems(string name_of_product){
    vector <string> results;
    if (DB_PRODUCT.find(name_of_product) == DB_PRODUCT.end()) {
        cout << "No product with given name found!" << endl;
    }
    else {
        for (auto i = IDS_INVOICE.begin(); i != IDS_INVOICE.end(); i++) {
            string id = *i;
            Invoice* inv = DB_INVOICE[id];
            if (inv->checkIfProductExists(name_of_product)) {
                results.push_back(id);
            }
        }

    }
    return results;
}

vector<string> App::searchByTimeRange(string start_day, string end_day) {
    vector<string> results;
    time_t from_time = convertStringTimeFormat2(start_day);
    time_t to_time = convertStringTimeFormat2(end_day);
    for (auto i = IDS_INVOICE.begin(); i != IDS_INVOICE.end(); i++) {
        string id = *i;
        time_t inv_time = DB_INVOICE[id]->getTimestamp();
        if (difftime(inv_time, from_time) > 0 && difftime(to_time, inv_time) > 0) {
            results.push_back(id);
        }
    }
    return results;

}

double App::calculateProfitByTimeRange(string start_day, string end_day) {
    double profit =0.0;
    vector<string> filtered_invs = searchByTimeRange(start_day, end_day);
    for (auto i = filtered_invs.begin(); i != filtered_invs.end(); i++) {
        Invoice* inv = DB_INVOICE[*i];
        double total = inv->getProfit();//PQH
        double tax_payment = total * inv->getTax();
        if (inv->isIncoming()) {
            profit += total - tax_payment;
        }
        else {
            profit += -total - tax_payment;
        }
    }
    return profit;
}

time_t App::convertStringTimeFormat1(string strtime) {
    //strtime has format %Y-%m-%d %H:%M:%S
    int year, mon, day, hour, min, sec;
    char c;
    sscanf(strtime.c_str(), "%4d%1s%2d%1s%2d %2d%1s%2d%1s%2d", &year, &c, &mon, &c, &day, &hour, &c, &min, &c, &sec);
    struct tm tm;
    tm.tm_year = year - 1900;
    tm.tm_mon = mon - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = min;
    tm.tm_sec = sec;
    time_t timestamp = mktime(&tm);
    return timestamp;
}

time_t App::convertStringTimeFormat2(string strtime) {
    //strtime has format %Y-%m-%d
    int year, mon, day;
    char c;
    sscanf(strtime.c_str(), "%4d%1s%2d%1s%2d", &year, &c, &mon, &c, &day);
    struct tm tm;
    tm.tm_year = year - 1900;
    tm.tm_mon = mon - 1;
    tm.tm_mday = day;
    time_t timestamp = mktime(&tm);
    return timestamp;
}

void App::printAllInvoices() {
    for (auto i = IDS_INVOICE.begin(); i != IDS_INVOICE.end(); i++) {
        string id = *i;
        Invoice* inv = DB_INVOICE[id];
        printf("------------------------------------------------------------\n");
        printf("            Invoice No. %s \n", id.c_str());
        printf("Invoice type: %s \n", inv->getTypeAsStr().c_str());
        time_t timestamp = inv->getTimestamp();
        char* strtime = ctime(&timestamp);
        printf("Created at: %s \n", strtime);
    }
}
