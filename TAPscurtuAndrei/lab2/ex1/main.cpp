#include <iostream>
#include "fractie.h"
using namespace std;
int main()
{
	Fractie f(0, 1);
	f.print();
	f.adunare(15, 20);
	f.print();
	f.scadere(5, 20);
	f.print();
	f.simplificare();
	f.print();
	f.imultire(2, 3);
	f.print();
	f.impartire(2, 3);
	f.print();
	f.simplificare();
	f.print();
}