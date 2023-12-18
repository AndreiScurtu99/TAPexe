#include <iostream>
#include <vector>

#include "Punct.h"
using namespace std;
Punct CentruGreutate(vector<Punct> &puncte)
{
    
    double sumaX = 0;
    double sumaY = 0;
    for (unsigned i = 0; i < puncte.size(); i++)
    {
        sumaX += puncte[i].getX();
        sumaY += puncte[i].getY();
    }
    Punct G(sumaX / puncte.size(), sumaY / puncte.size());
    return G;
}
int main() {
    Dreapta dreapta(2, 1); 
    int n;
    cout << "Introduceti numarul de puncte: ";
    cin >> n;
    vector<Punct> puncte;
    for (unsigned i = 0; i < n; ++i) {
        double abs, ord;
        cout << "Introduceti abscisa punctului " << i + 1 << ": ";
        cin >> abs;
        cout << "Introduceti ordonata punctului " << i + 1 << ": ";
        cin >> ord;

        Punct punct(abs, ord);
        puncte.push_back(punct);
    }
    cout << "Numarul de puncte pe dreapta: " << Punct::getPunctePeDreapta() << endl;
    cout << "Numarul de puncte in semiplanul pozitiv: " << Punct::getSemiplanPozitiv() << endl;
    cout << "Numarul de puncte in semiplanul negativ: " << Punct::getSemiplanNegativ() << endl;
    
    return 0;
}

