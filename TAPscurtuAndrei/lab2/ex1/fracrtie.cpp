#include <iostream>
#include "fractie.h"
using namespace std;

Fractie::Fractie(int numarator, int numitor)
{
	this->numarator = numarator;
	this->numitor = numitor;
}
Fractie::Fractie(const Fractie& other)
{
	this->numarator = other.numarator;
	this->numitor = other.numitor;
}
Fractie& Fractie::operator=(const Fractie& other)
{
	this->numarator = other.numarator;
	this->numitor = other.numitor;
	return *this;
}
Fractie::~Fractie()
{

}
void Fractie::adunare(int numa, int numi)
{
	if (this->numitor == numi)
		this->numarator += numa;
	else
	{
		int aux1 = this->numitor;
		int aux2 = numi;
		this->numitor = numitor * numi;
		this->numarator = this->numarator * aux2 + numa * aux1;
	}
}
void Fractie::scadere(int numa, int numi)
{
	if (this->numitor == numi)
		this->numarator -= numa;
	else
	{
		int aux1 = this->numitor;
		int aux2 = numi;
		this->numitor = numitor * numi;
		this->numarator = this->numarator * aux2 - numa * aux1;
	}
}
void Fractie::imultire(int numa, int numi)
{
	this->numarator *= numa;
	this->numitor *= numi;
}
void Fractie::impartire(int numa, int numi)
{
	this->numarator *= numi;
	this->numitor *= numa;
}
int Fractie::cmmdc(int nr1, int nr2)
{
	while (nr1 != nr2)
	{
		if (nr1 > nr2)
			nr1 = nr1 - nr2;
		else
			nr2 = nr2 - nr1;
	}
	return nr1;
}
void Fractie::simplificare()
{
	int tmp = cmmdc(this->numarator, this->numitor);
	this->numarator /= tmp;
	this->numitor /= tmp;
}
Fractie Fractie::reciproc()
{
	if (this->numarator = 0)
	{
		Fractie f(0,1);
		return f;
	}
	else
	{
		Fractie f(this->numitor, this->numarator);
		return f;
	}
	
}
bool Fractie::egal(const Fractie& other)
{
	return (this->numarator == other.numarator) && (this->numitor == other.numitor);
}
void Fractie::print()
{
	cout << "\t " << this->numarator << endl;
	cout << "\t" << "----" << endl;
	cout << "\t " << this->numitor << endl<<endl<<endl;
}
