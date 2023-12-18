#include "ActoriFilm.h";
#include <iostream>
#include <vector>
using namespace std;

Actor::Actor(string nume,int varsta, int aniExperienta): 
	nume(nume), varsta(varsta),aniExperienta(aniExperienta){}
Actor::Actor(const Actor& other) :
	nume(other.nume), varsta(other.varsta), aniExperienta(other.aniExperienta){}
Actor::~Actor(){}
Actor& Actor::operator=(const Actor& other)
{
	this->nume = other.nume;
	this->varsta = other.varsta;
	this->aniExperienta = other.aniExperienta;
	return *this;
}
ostream& operator<<(ostream& os, const Actor& actor)
{
	os << "Nume actor: " << actor.nume << " ,Varsta: " << actor.varsta <<
		" ,Ani de experienta: " << actor.aniExperienta<<endl;
	return os;
}
Film::Film(string nume,double buget,vector<Actor> listaActori): 
	nume(nume),buget(buget),listaActori(listaActori){}
Film::Film(string nume, double buget) : nume(nume), buget(buget){}
Film::Film(const Film& other) : nume(other.nume), buget(other.buget),
listaActori(other.listaActori){}
Film::~Film(){}
Film& Film::operator=(const Film& other)
{
	this->nume = other.nume;
	this->buget = other.buget;
	this->listaActori = other.listaActori;
	return *this;
}
ostream& operator<<(ostream& os, const Film& film)
{
	os <<endl<< "Nume Film: " << film.nume << " ,Buget: " << film.buget << endl << "Cu "<<
		film.listaActori.size()<<" actori:" << endl;
	for (Actor a : film.listaActori)
		cout << a;
	return os;
}
void Film::adaugareActor(Actor a)
{
	listaActori.push_back(a);
}
void Film::scoateActor(Actor a)
{
	for (auto it=listaActori.begin();it!=listaActori.end();++it)
	{
		if (it->getNume() == a.getNume() && it->getVarsta() == a.getVarsta()
			&& it->getAniExperienta() == a.getAniExperienta())
		{
			listaActori.erase(it);
			return;
		}
	}
	cout << "Actorul nu este in lista noasta." << endl;
}
bool comparareBugetCrescator(const Film& film1, const Film& film2)
{
	return film1.buget > film2.buget;
}
bool comparareNrAngajatiCrescator(const Film& film1, const Film& film2)
{
	return film1.listaActori.size() > film2.listaActori.size();
}
void sortareBuget(vector<Film>& filme)
{
	for (size_t i = 0; i < filme.size()-1; ++i)
		for (size_t j = i + 1; j < filme.size(); ++j)
			if (comparareBugetCrescator(filme[i], filme[j]))
				swap(filme[i], filme[j]);
}
void sortareNrAngajati(vector<Film>& filme)
{
	for (size_t i = 0; i < filme.size() - 1; ++i)
		for (size_t j = i + 1; j < filme.size(); ++j)
			if (comparareNrAngajatiCrescator(filme[i], filme[j]))
				swap(filme[i], filme[j]);
}
void actoriComuni(const Film& film1, const Film& film2)
{
	cout << endl << "Actorii comuni din " << film1.nume << " si " << film2.nume << " :" << endl;
	for (Actor a : film1.listaActori)
		for (Actor a2 : film2.listaActori)
			if (a.getNume() == a2.getNume() && a.getVarsta() == a2.getVarsta()
				&& a.getAniExperienta() == a2.getAniExperienta())
					cout << a;
}