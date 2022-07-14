// CORE APP - Dang Hoang Lan
#ifndef OUTCOMING_FOREIGN_H
#define OUTCOMING_FOREIGN_H

#include "invoice.h"
class Outcoming_Foreign : public Invoice
{
public:
    Outcoming_Foreign(string id, time_t timestamp) : Invoice(id, timestamp) {
        tax = 0.15;
    }
    bool isDomestic();
    bool isIncoming();
    string getTypeAsStr();
};

#endif // OUTCOMING_FOREIGN_H
