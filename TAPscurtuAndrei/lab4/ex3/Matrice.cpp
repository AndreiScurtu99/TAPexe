#include "Matrice.h"
#include <iostream>
using namespace std;
Matrice::Matrice(int nrLinii, int nrColoane) : nrLinii(nrLinii), nrColoane(nrColoane) {
    vectorBidimensional = new int* [nrLinii];
    for (int i = 0; i < nrLinii; ++i) {
        vectorBidimensional[i] = new int[nrColoane];
    }
}

Matrice::Matrice(const Matrice& other) : nrLinii(other.nrLinii), nrColoane(other.nrColoane) {
    vectorBidimensional = new int* [nrLinii];
    for (int i = 0; i < nrLinii; ++i) {
        vectorBidimensional[i] = new int[nrColoane];
        for (int j = 0; j < nrColoane; ++j) {
            vectorBidimensional[i][j] = other.vectorBidimensional[i][j];
        }
    }
}

Matrice::~Matrice() {
    for (int i = 0; i < nrLinii; ++i) {
        delete[] vectorBidimensional[i];
    }
    delete[] vectorBidimensional;
}
Matrice Matrice::operator+(const Matrice& other) const {
    if (nrLinii != other.nrLinii || nrColoane != other.nrColoane) {
        cout << "Dimensiunile matricelor nu sunt compatibile pentru adunare.\n";
        exit(EXIT_FAILURE);
    }
    Matrice rezultat(nrLinii, nrColoane);
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            rezultat.vectorBidimensional[i][j] = vectorBidimensional[i][j] + other.vectorBidimensional[i][j];
        }
    }
    return rezultat;
}
Matrice Matrice::operator-(const Matrice& other) const {
    if (nrLinii != other.nrLinii || nrColoane != other.nrColoane) {
        cout << "Dimensiunile matricelor nu sunt compatibile pentru scadere.\n";
        exit(EXIT_FAILURE);
    }
    Matrice rezultat(nrLinii, nrColoane);
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            rezultat.vectorBidimensional[i][j] = vectorBidimensional[i][j] - other.vectorBidimensional[i][j];
        }
    }
    return rezultat;
}
Matrice Matrice::operator*(const Matrice& other) const {
    if (nrColoane != other.nrLinii) {
        cout << "Numarul de coloane al primei matrici nu este egal cu numarul de linii al celei de-a doua matrici.\n";
        exit(EXIT_FAILURE);
    }
    Matrice rezultat(nrLinii, other.nrColoane);
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < other.nrColoane; ++j) {
            for (int k = 0; k < nrColoane; ++k) {
                rezultat.vectorBidimensional[i][j] += vectorBidimensional[i][k] * other.vectorBidimensional[k][j];
            }
        }
    }

    return rezultat;
}
Matrice Matrice::operator/(const Matrice& other) const {
    if (other.nrLinii != other.nrColoane || other.nrLinii != 1 || other.nrColoane != 1) {
        cout << "Matricea pentru împartire trebuie sa fie o matrice 1x1 (scalar).\n";
        exit(EXIT_FAILURE);
    }
    Matrice rezultat(nrLinii, nrColoane);
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            rezultat.vectorBidimensional[i][j] = vectorBidimensional[i][j] / other.vectorBidimensional[0][0];
        }
    }

    return rezultat;
}
Matrice& Matrice::operator=(const Matrice& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < nrLinii; ++i) {
        delete[] vectorBidimensional[i];
    }
    delete[] vectorBidimensional;
    nrLinii = other.nrLinii;
    nrColoane = other.nrColoane;
    vectorBidimensional = new int* [nrLinii];
    for (int i = 0; i < nrLinii; ++i) {
        vectorBidimensional[i] = new int[nrColoane];
        for (int j = 0; j < nrColoane; ++j) {
            vectorBidimensional[i][j] = other.vectorBidimensional[i][j];
        }
    }
    return *this;
}
int Matrice::sumaElemente() const {
    int suma = 0;
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            suma += vectorBidimensional[i][j];
        }
    }
    return suma;
}
int* Matrice::operator[](int index)
{
    return nullptr;
}
bool Matrice::operator<(const Matrice& other) const {
    return sumaElemente() < other.sumaElemente();
}
bool Matrice::operator>(const Matrice& other) const {
    return sumaElemente() > other.sumaElemente();
}
bool Matrice::operator<=(const Matrice& other) const {
    return sumaElemente() <= other.sumaElemente();
}
bool Matrice::operator>=(const Matrice& other) const {
    return sumaElemente() >= other.sumaElemente();
}
bool Matrice::operator==(const Matrice& other) const {
    if (nrLinii != other.nrLinii || nrColoane != other.nrColoane) {
        return false; 
    }
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            if (vectorBidimensional[i][j] != other.vectorBidimensional[i][j]) {
                return false; 
            }
        }
    }
    return true; 
}

bool Matrice::operator!=(const Matrice& other) const {
    return !(*this == other); // neg rez op ==
}
Matrice& Matrice::operator+=(const Matrice& other) {
    if (nrLinii != other.nrLinii || nrColoane != other.nrColoane) {
        cout << "Dimensiunile matricelor nu sunt compatibile pentru adunare.\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            vectorBidimensional[i][j] += other.vectorBidimensional[i][j];
        }
    }

    return *this;
}
Matrice& Matrice::operator-=(const Matrice& other) {
    if (nrLinii != other.nrLinii || nrColoane != other.nrColoane) {
        cout << "Dimensiunile matricelor nu sunt compatibile pentru scadere.\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            vectorBidimensional[i][j] -= other.vectorBidimensional[i][j];
        }
    }

    return *this;
}
Matrice Matrice::creareMatriceI(const Matrice& matrice) {
    Matrice identica(matrice.nrLinii, matrice.nrColoane);

    for (int i = 0; i < matrice.nrLinii; ++i) {
        for (int j = 0; j < matrice.nrColoane; ++j) {
            identica.vectorBidimensional[i][j] = 1; // Elementul matricei identice
        }
    }

    return identica;
}
Matrice& Matrice::operator++() {
    Matrice identica = creareMatriceI(*this);
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            vectorBidimensional[i][j] += identica.vectorBidimensional[i][j];
        }
    }
    return *this;
}
Matrice& Matrice::operator--() {
    Matrice identica = creareMatriceI(*this);
    for (int i = 0; i < nrLinii; ++i) {
        for (int j = 0; j < nrColoane; ++j) {
            vectorBidimensional[i][j] -= identica.vectorBidimensional[i][j];
        }
    }
    return *this;
}
Matrice& Matrice::operator*=(const Matrice& other)
{
    
}
Matrice& Matrice::operator/=(const Matrice& other)
{
    
}
ostream& operator<<(ostream& os, const Matrice& matrice) {
    for (int i = 0; i < matrice.nrLinii; ++i) {
        for (int j = 0; j < matrice.nrColoane; ++j) {
            os << matrice.vectorBidimensional[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}
istream& operator>>(istream& is, Matrice& matrice) {
    for (int i = 0; i < matrice.nrLinii; ++i) {
        for (int j = 0; j < matrice.nrColoane; ++j) {
            is >> matrice.vectorBidimensional[i][j];
        }
    }
    return is;
}