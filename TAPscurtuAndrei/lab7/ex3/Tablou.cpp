#include "Tablou.h"
#include <cstring>

using namespace std;
template <typename T>
Tablou<T>::Tablou(int initialSize) : size(initialSize), array(new T[initialSize]) {}


template <typename T>
Tablou<T>::Tablou(const Tablou& other) : size(other.size), array(new T[other.size]) {
    for (int i = 0; i < size; ++i)
        array[i] = other.array[i];
}

template <typename T>
Tablou<T>::~Tablou() {
    delete[] array;
}

template <typename T>
Tablou<T>& Tablou<T>::operator=(const Tablou& other) {
    if (this != &other) {
        delete[] array;
        size = other.size;
        array = new T[size];
        for (int i = 0; i < size; ++i)
            array[i] = other.array[i];
    }
    return *this;
}

template <typename T>
T& Tablou<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        return array[index];
    }
    else {
        //exceptia pentru indexul inafara spatiului alocat
        throw out_of_range("Index out of bounds");
    }
}


template <typename U>
ostream& operator<<(ostream& os, const Tablou<U>& arr) {
    for (int i = 0; i < arr.size; ++i) {
        os << arr.array[i] << " ";
    }
    return os;
}


template <typename U>
istream& operator>>(istream& is, Tablou<U>& arr) {
    for (int i = 0; i < arr.size; ++i) {
        is >> arr.array[i];
    }
    return is;
}

template class Tablou<char>;