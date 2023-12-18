#include "Carte.h"
#include <iostream>
using namespace std;

int main() {
    Carte carte1("Barbu", "Titlu1", "ISBN1", 29.99);
    Carte carte2("Mihai", "Titlu2", "ISBN2", 19.99);
    Carte carte3("Bacovia", "Titlu3", "ISBN3", 40.99);
    
    cout << "Numarul de instante de Carte create este: " << Carte::getNrInstante() << endl;
    return 0;
}
