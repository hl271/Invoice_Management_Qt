// CORE APP - Dang Hoang Lan
#include "incoming_foreign.h"

bool Incoming_Foreign::isDomestic() { return false; }
bool Incoming_Foreign::isIncoming() { return true; }

std::string Incoming_Foreign::getTypeAsStr() { return "Incoming Foreign"; }
