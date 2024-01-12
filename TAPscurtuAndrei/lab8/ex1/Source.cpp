#include <iostream>
#include <set>
#include <fstream>
#include <string>
using namespace std;



int main()
{

	ifstream fin("in.txt");
	if (!fin.is_open())
	{
		cout << "Erroare la deschiderea fisierului pentru citire!";
		return -1;
	}
	set<string> s;
	string cuvant;
	while (fin >> cuvant)
	{
		s.insert(cuvant);
	}
	fin.close();
	ofstream fout("out.txt");
	if (!fout.is_open())
	{
		cout << "Erroare la deschiderea fisierului pentru scriere!";
		return -2;
	}
	set<string>::iterator itS;
	for (itS = s.begin(); itS != s.end(); ++itS)
		fout << *itS<<" ";
	return 0;
}