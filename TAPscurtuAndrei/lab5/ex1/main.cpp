#include <iostream>
#include "Angajat.h";
using namespace std;
int main()
{
	Angajat* a = new Angajat(6, 10);
	cout<<"Detalii angajat : " << *a << " ,Salar " << a->getSalar() << endl;
	Angajat a2;
	cout<< a2;
	/*cin >> a2;
	cout << a2;*/



	return 0;

}