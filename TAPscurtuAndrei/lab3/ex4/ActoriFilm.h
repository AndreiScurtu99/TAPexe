#pragma once
#ifndef ACTORIFILM_H
#define ACTORIFILM_H
#include <iostream>
#include <vector>
using namespace std;

class Actor {
private:
	string nume;
	int varsta;
	int aniExperienta;
public:
	Actor(string,int,int);
	Actor(const Actor&);
	~Actor();
	Actor& operator=(const Actor&);
	inline string getNume() { return nume; }
	inline int getVarsta() { return varsta; }
	inline int getAniExperienta() { return aniExperienta; }
	inline void setNume(string nume) { this->nume=nume; }
	inline void setVarsta(int varsta) { this->varsta=varsta; }
	inline void setAniExperienta(int aniExperienta) { this->aniExperienta= aniExperienta; }
	friend ostream& operator<<(ostream&, const Actor&);
};
class Film {
private:
	string nume;
	double buget;
	vector<Actor> listaActori;
public:
	Film(string,double);
	Film(string, double, vector<Actor>);
	Film(const Film&);
	~Film();
	Film& operator=(const Film&);
	void adaugareActor(Actor);
	void scoateActor(Actor);
	inline double getBuget() { return buget; }
	inline int getNumarActori() { return listaActori.size(); }
	friend ostream& operator<<(ostream&, const Film&);
	friend void sortareBuget(vector<Film>&);
	friend void sortareNrAngajati(vector<Film>&);
	friend bool comparareBugetCrescator(const Film&, const Film&);
	friend bool comparareNrAngajatiCrescator(const Film&,const Film&);
	friend void actoriComuni(const Film&, const Film&);
};
class ActorNegasitException : public exception {
public:
	const char* what() const noexcept override {
		return "Actorul nu este in lista.";
	}
};
#endif
