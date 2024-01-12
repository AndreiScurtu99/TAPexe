#include "Punct3D.h"
#include <cmath>
using namespace std;
Punct3D::Punct3D() : Punct2D(), z(0.0) {}
Punct3D::Punct3D(double x, double y, double z) : Punct2D(x, y), z(z) {}
Punct3D::~Punct3D(){}
double Punct3D::distanta(const Punct3D& other) const {
    double deltaX = getX() - other.getX();  
    double deltaY = getY() - other.getY();;  
    double deltaZ = this->z - other.z;  
    return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}