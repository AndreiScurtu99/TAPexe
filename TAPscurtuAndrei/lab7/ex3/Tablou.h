#pragma once
#ifndef TABLOU_H
#define TABLOU_H

#include <iostream>
using namespace std;
template <typename T>
class Tablou {
private:
    T* array;
    int size;

public:
    Tablou(int initialSize);

    Tablou(const Tablou& other);

    ~Tablou();

    Tablou& operator=(const Tablou& other);

    T& operator[](int index);

    template <typename U>
    friend ostream& operator<<(ostream& os, const Tablou<U>& arr);

    template <typename U>
    friend istream& operator>>(istream& is, Tablou<U>& arr);
};

#endif
