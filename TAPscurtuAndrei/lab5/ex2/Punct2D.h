#pragma once
#ifndef PUNCT2D_H
#define PUNCT2D_H

#include <iostream>
using namespace std;
class Punct2D {
private:
    double x;
    double y;

public:
    Punct2D();
    Punct2D(double x, double y);
    Punct2D(const Punct2D& other);
    ~Punct2D();
    
    Punct2D operator+(const Punct2D& other) const;
    Punct2D operator-(const Punct2D& other) const;
    Punct2D operator*(const Punct2D& other) const;
    Punct2D operator/(const Punct2D& other) const;
    bool operator<(const Punct2D& other) const;
    bool operator>(const Punct2D& other) const;
    bool operator<=(const Punct2D& other) const;
    bool operator>=(const Punct2D& other) const;
    bool operator!=(const Punct2D& other) const;
    bool operator==(const Punct2D& other) const;
    Punct2D& operator=(const Punct2D& other);
    inline double getX() const{ return x; }
    inline double getY() const{ return y; }
    double distanta(const Punct2D& other) const;
    Punct2D& operator+=(const Punct2D& other);
    Punct2D& operator-=(const Punct2D& other);
    Punct2D& operator*=(const Punct2D& other);
    Punct2D& operator/=(const Punct2D& other);
    Punct2D& operator++();
    Punct2D& operator--();

    friend istream& operator>>(istream& is, Punct2D& punct);
    friend ostream& operator<<(ostream& os, const Punct2D& punct);
};

#endif