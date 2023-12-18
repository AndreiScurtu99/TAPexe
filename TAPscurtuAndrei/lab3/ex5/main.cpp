#include <iostream>
#include "Complex.h"
using namespace std;
int main()
{
    Complex z(3.0, 4.0);

    double mod = modul(z);
    Complex con = conjugat(z);

    std::cout << "Modulul numarului complex: " << mod << std::endl;
    std::cout << "Conjugatul numarului complex: " << z.getRe()<< " "<<z.getIm() << std::endl;

    return 0;
}