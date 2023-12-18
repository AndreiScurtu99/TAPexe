#include <iostream>
#include "StivaStatica.h"

using namespace std;
int main()
{
	StivaStatica* s = nullptr;
	cout << "Dati marimea maxima a stivei : ";
	int n;
	cin >> n;
	s = new StivaStatica(n);
	try
	{
		s->push(1);
		s->push(2);
		s->push(3);
	}
	catch (const exception& e)
	{
		cout << "Exceptia: " << e.what() << endl;
	}
	s->print();
	cout << s->getTop();
	int v[100];
	for (int i = 0; i < s->getTop(); i++)
		v[i] = s->getData()[i];
	for (int i = 0; i < s->getTop(); i++)
		cout << v[i] << " ";

	delete s;
	system("pause");
	return 0;
}