#include <iostream>
#include "coadaStatica.h"

using namespace std;
int main()
{
	coadaStatica* c=nullptr;
	cout << "Dati marimea maxima a stivei : ";
	int n;
	cin >> n;
	c = new coadaStatica(n);
	try
	{
		c->enQueue(1);
		c->enQueue(2);
		c->enQueue(3);
	}
		catch(const exception& e)
	{
			cout << "Exceptia: " << e.what()<<endl;
	}
	c->print();
	delete c;
	return 0;
}