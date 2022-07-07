#ifndef INCOMING_DOMESTIC_H
#define INCOMING_DOMESTIC_H

#include "invoice.h"
//#include "uuid.h"
class Incoming_Domestic : public Invoice
{
public:
    Incoming_Domestic(std::string id, time_t timestamp) : Invoice(id, timestamp) {
        tax = 0.10;
    }

    bool isDomestic();
    bool isIncoming();
    std::string getTypeAsStr();
};

#endif // INCOMING_DOMESTIC_H
