#include "Punct2D.h"
#include <iostream>
#include <cmath>
using namespace std;
Punct2D::Punct2D() : x(0.0), y(0.0) {}
Punct2D::Punct2D(double x, double y) : x(x), y(y) {}
Punct2D::Punct2D(const Punct2D& other) : x(other.x), y(other.y) {}

Punct2D::~Punct2D() {}

Punct2D Punct2D::operator+(const Punct2D& other) const {
    return Punct2D(x + other.x, y + other.y);
}

Punct2D Punct2D::operator-(const Punct2D& other) const {
    return Punct2D(x - other.x, y - other.y);
}
Punct2D Punct2D::operator*(const Punct2D& other) const {
    return Punct2D(x * other.x, y * other.y);
}
Punct2D Punct2D::operator/(const Punct2D& other) const {
    return Punct2D(x / other.x, y / other.y);
}
bool Punct2D::operator>(const Punct2D& other) const {
    return (x > other.x) || ((x == other.x) && (y > other.y));
}
bool Punct2D::operator<(const Punct2D& other) const {
    return (x < other.x) || ((x == other.x) && (y < other.y));
}
bool Punct2D::operator<=(const Punct2D& other) const {
    return !(*this > other);
}

bool Punct2D::operator>=(const Punct2D& other) const {
    return !(*this < other);
}

bool Punct2D::operator==(const Punct2D& other) const {
    return (x == other.x) && (y == other.y);
}
bool Punct2D::operator!=(const Punct2D& other) const {
    return !(*this == other);
}
Punct2D& Punct2D::operator=(const Punct2D& other) {
   
    x = other.x;
    y = other.y;
  
    return *this;
}
Punct2D& Punct2D::operator+=(const Punct2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}
Punct2D& Punct2D::operator-=(const Punct2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
Punct2D& Punct2D::operator*=(const Punct2D& other) {
    x *= other.x;
    y *= other.y;
    return *this;
}
Punct2D& Punct2D::operator/=(const Punct2D& other) {
    x /= other.x;
    y /= other.y;
    return *this;
}


Punct2D& Punct2D::operator++() {
    ++x;
    ++y;
    return *this;
}


Punct2D& Punct2D::operator--() {
    --x;
    --y;
    return *this;
}


istream& operator>>(istream& is, Punct2D& punct) {
    is >> punct.x >> punct.y;
    return is;
}


ostream& operator<<(ostream& os, const Punct2D& punct) {
    os << "(" << punct.x << ", " << punct.y << ")";
    return os;
}
double Punct2D::distanta(const Punct2D& other) const {
    double deltaX = x - other.x;
    double deltaY = y - other.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}