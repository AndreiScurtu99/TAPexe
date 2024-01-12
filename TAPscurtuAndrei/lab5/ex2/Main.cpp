#include "Punct2D.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Introduceti numarul de puncte: ";
    cin >> n;

    vector<Punct2D> puncte;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cout << "Introduceti coordonatele punctului :";
        cin >> x >> y;
        puncte.push_back(Punct2D(x, y));
    }

    cout << "Coordonatele punctelor create:" << std::endl;
    for (Punct2D punct : puncte) {
        cout << punct << endl;
    }
}