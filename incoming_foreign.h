// CORE APP - Dang Hoang Lan
#ifndef INCOMING_FOREIGN_H
#define INCOMING_FOREIGN_H

#include "invoice.h"
class Incoming_Foreign : public Invoice
{
public:
    Incoming_Foreign(std::string id, time_t timestamp) : Invoice(id, timestamp) {
        tax = 0.15;
    }
    bool isDomestic();
    bool isIncoming();
    std::string getTypeAsStr();
};

#endif // INCOMING_FOREIGN_H
