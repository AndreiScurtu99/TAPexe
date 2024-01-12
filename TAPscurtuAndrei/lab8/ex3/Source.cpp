#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
int main()
{
	unsigned countLinii = 1;
	map<unsigned, map<string,unsigned>> m;
	map<unsigned, map<string, unsigned>>::iterator itM	;
	map<string, unsigned>::iterator itM2;
	string cuvant;
	string linie;
	ifstream fin("in.txt");
	if (!fin.is_open())
	{
		cout << "Eroare la deschiderea fisierului!";
		return -1;
	}

	while (getline(fin,linie))
	{
		map<string, unsigned> cuvLinie;
		stringstream stream(linie);
		while(stream>>cuvant)
		{
			
			pair<map<string, unsigned>::iterator, bool> ret;
			ret = cuvLinie.insert(pair<string, unsigned>(cuvant, 1));
			if (ret.second == false)
				ret.first->second++;
		}
		m.insert(pair<unsigned, map<string, unsigned>>(countLinii, cuvLinie));

	}
	fin.close();
	ofstream fout("out.txt");
	for (itM = m.begin(); itM != m.end(); ++itM)
	{
		fout << itM->first << " ";
		for (itM2 = itM->second.begin(); itM2 != itM->second.end(); itM2++)
			fout << itM2->first << " " << itM2->second << endl;
		fout << endl;
	}
	
	fout.close();

	return 0;


}	