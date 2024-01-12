#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<string, unsigned> m;
	map<string, unsigned>::iterator itM;
	string cuvant;

	ifstream fin("in.txt");
	if (!fin.is_open())
	{
		cout << "Eroare la deschiderea fisierului!";
		return -1;
	}
	
	while (fin >> cuvant)
	{
		pair<map<string, unsigned>::iterator, bool> ret;
		ret = m.insert(pair<string, unsigned>(cuvant, 1));
		if (ret.second == false)
			ret.first->second++;
	}
	fin.close();
	ofstream fout("out.txt");
	for (itM = m.begin(); itM != m.end(); ++itM)
		fout << itM->first << " " << itM->second << endl;
	fout.close();

	return 0;


}