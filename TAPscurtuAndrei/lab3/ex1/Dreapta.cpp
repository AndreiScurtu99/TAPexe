
#include "Punct.h"

Dreapta::Dreapta() : m(2), n(1) {}

Dreapta::Dreapta(double panta, double ordonata) : m(panta), n(ordonata) {}

Dreapta::Dreapta(const Dreapta& other) : m(other.m), n(other.n) {}

Dreapta::~Dreapta() {}

