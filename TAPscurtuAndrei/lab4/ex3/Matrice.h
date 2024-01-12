#pragma once
#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>

class Matrice {
private:
    int nrLinii;
    int nrColoane;
    int** vectorBidimensional;

public:
    Matrice(int nrLinii, int nrColoane);
    Matrice(const Matrice& other);
    ~Matrice();
    Matrice operator+(const Matrice& other) const;
    Matrice operator-(const Matrice& other) const;
    Matrice operator*(const Matrice& other) const;
    Matrice operator/(const Matrice& other) const;
    bool operator<(const Matrice& other) const;
    bool operator>(const Matrice& other) const;
    bool operator<=(const Matrice& other) const;
    bool operator>=(const Matrice& other) const;
    bool operator!=(const Matrice& other) const;
    bool operator==(const Matrice& other) const;
    Matrice& operator=(const Matrice& other);
    Matrice& operator+=(const Matrice& other);
    Matrice& operator-=(const Matrice& other);
    Matrice& operator*=(const Matrice& other);
    Matrice& operator/=(const Matrice& other);
    Matrice& operator++();
    Matrice& operator--();
    int sumaElemente() const;
    Matrice creareMatriceI(const Matrice& matrice);
    int* operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, const Matrice& matrice);
    friend std::istream& operator>>(std::istream& is, Matrice& matrice);
};
#endif