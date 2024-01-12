#include "Matrice.h"
#include <iostream>
using namespace std;
int main() {
    Matrice matrice1(3, 3);
    Matrice matrice2(3, 3);
    cout << "Introduceti elementele pentru matricea 1 (3,3):\n";
    cin >> matrice1;

    cout << "Introduceti elementele pentru matricea 2(3,3):\n";
    cin >> matrice2;
    Matrice rezultatAdunare = matrice1 + matrice2;
    Matrice rezultatScadere = matrice1 - matrice2;
    Matrice rezultatInmultire = matrice1 * matrice2;
    Matrice rezultatImpartire = matrice1 / matrice2;
    cout << "Rezultat adunare:\n" << rezultatAdunare;
    cout << "Rezultat scadere:\n" << rezultatScadere;
    cout << "Rezultat inmultire:\n" << rezultatInmultire;
    cout << "Rezultat impartire:\n" << rezultatImpartire;
    return 0;
}