#include "fractie.h"
#include <iostream>
using namespace std;
int main()
{
	Fractie f1(4 , 3);
	cout << f1;
	f1 += (Fractie(1, 3));
	cout << f1;
	f1 -= (Fractie(2, 3));
	cout << f1;
	f1 *= (Fractie(2, 3));
	cout << f1;
	f1 /= (Fractie(3, 2));
	cout << f1;
	return 0;

}