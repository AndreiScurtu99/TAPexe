#include "Punct.h"
#include <cmath>
int Punct::punctePeDreapta = 0;
int Punct::semiplanPozitiv = 0;
int Punct::semiplanNegativ = 0;
Dreapta dreapta(2, 1);
Punct::Punct() : x(0), y(0) {}

Punct::Punct(double abs, double ord) : x(abs), y(ord) {
    if (dreapta.getPanta() * abs + dreapta.getOrdonata() == ord)
        punctePeDreapta++;
    else if (dreapta.getPanta() * abs + dreapta.getOrdonata() - ord > 0)
        semiplanPozitiv++;
    else
        semiplanNegativ++;
}

Punct::Punct(const Punct& other) : x(other.x), y(other.y) {}

Punct::~Punct() {
    // am folosit clasa vector si destructorul imi sabota afisarea.
    /*if (dreapta.getPanta() * x + dreapta.getOrdonata() == y)
        punctePeDreapta--;
    else if (dreapta.getPanta() * x + dreapta.getOrdonata() - y > 0)
        semiplanPozitiv--;
    else
        semiplanNegativ--;*/
}

double distanta(const Punct& p1, const Punct& p2) {
    double deltaX = p2.x - p1.x;
    double deltaY = p2.y - p1.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}



