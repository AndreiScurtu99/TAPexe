#include <iostream>
#include <vector>
#include "ActoriFilm.h"
using namespace std;
int main()
{
	Film film("Home Alone", 150000);
	Film film2("Baltagul", 1500);
	Actor a("McCaulkey", 13, 2);
	Actor a2("Brat Pit", 40, 25);
	Actor a3("Porumbelul", 5, 5);
	film.adaugareActor(a);
	film.adaugareActor(a2);
	film.adaugareActor(a3);
	film2.adaugareActor(a3);
	cout << film;
	Actor a4(a2);
	film.scoateActor(a4);
	cout << film;
	cout << film2;
	vector<Film> filme;
	filme.push_back(film);
	filme.push_back(film2);
	cout << endl << "PENTRU SORTARE :" << endl;
	for (Film f : filme)
		cout << f;
	sortareBuget(filme);
	cout << endl << "SORTAT: " << endl;
	for (Film f : filme)
		cout << f;

	
	actoriComuni(film, film2);
	//Verificare mesaj actor negasit
	//film.scoateActor(a2);
	return 0;
}