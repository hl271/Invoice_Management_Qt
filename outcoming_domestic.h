// CORE APP - Dang Hoang Lan
#ifndef OUTCOMING_DOMESTIC_H
#define OUTCOMING_DOMESTIC_H

#include "invoice.h"
class Outcoming_Domestic : public Invoice
{
public:
    Outcoming_Domestic(string id, time_t timestamp) : Invoice(id, timestamp) {
        tax = 0.10;
    }
    bool isDomestic();
    bool isIncoming();
    string getTypeAsStr();
};

#endif // OUTCOMING_DOMESTIC_H
