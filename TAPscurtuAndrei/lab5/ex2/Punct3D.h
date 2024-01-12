#pragma once
#ifndef PUNCT3D_H
#define PUNCT3D_H

#include "Punct2D.h"

class Punct3D : public Punct2D {
private:
    double z;

public:
    Punct3D();
    Punct3D(double x, double y, double z);
    ~Punct3D();
    double distanta(const Punct3D& other) const;
    //restul copy paste de la 2D doar ca este un z in plus
    
};

#endif