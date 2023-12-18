#include "contBancar.h"
#include <iostream>
#include <exception>
using namespace std;
Banca::Banca(string codBanca, unsigned nrClienti, Client** listClienti)
{
	this->codBanca = codBanca;
	this->nrClienti = nrClienti;
	this->listClienti = new Client * [nrClienti];
	for (int i = 0; i < nrClienti; i++)
		this->listClienti[i] = listClienti[i];
}
Banca::Banca(const Banca& other)
{
	this->codBanca = other.codBanca;
	this->nrClienti = other.nrClienti;
	for (int i = 0; i < nrClienti; i++)
		this->listClienti[i] = other.listClienti[i];
}
Banca::~Banca()
{
	delete listClienti;
}
Banca& Banca::operator=(const Banca& other)
{
	this->codBanca = other.codBanca;
	this->nrClienti = other.nrClienti;
	for (int i = 0; i < nrClienti; i++)
		this->listClienti[i] = other.listClienti[i];
	return *this;
}
string Banca::getCodBanca()
{
	return codBanca;
}
unsigned Banca::getNrClienti()
{
	return nrClienti;
}
Client* Banca::getListClienti()
{
	return *listClienti;
}
void Banca::setCodBanca(string codBanca)
{
	this->codBanca = codBanca;
}
void Banca::setNrClienti(unsigned nrClienti)
{
	this->nrClienti = nrClienti;
}
void Banca::setListClienti(Client** list)
{
	for (int i = 0; i++; i < this->nrClienti)
	{
		this->listClienti[i] = list[i];
	}
}
void Banca::AfisareBanca()
{
	cout << "Cod Banca :" << this->codBanca << endl;
	for (int i = 0; i < this->nrClienti; i++)
		listClienti[i]->afisareClient();

}