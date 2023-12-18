#include "contBancar.h"
#include <iostream>
#include <exception>
using namespace std;
Client::Client(string nume, string prenume , string adresa , unsigned nrConturi, ContBancar** listaConturi)
{
	this->nume = nume;
	this->prenume = prenume;
	this->adresa = adresa;
	this->nrConturi = nrConturi;
	this->listaConturi = new ContBancar * [nrConturi];
	for (int i = 0; i < nrConturi; i++)
		this->listaConturi[i] = listaConturi[i];
}

Client::Client(const Client& other)
{
	this->nume = other.nume;
	this->prenume = other.prenume;
	this->adresa = other.adresa;
	this->nrConturi = other.nrConturi;
	this->listaConturi = new ContBancar * [nrConturi];
	for (int i = 0; i < other.nrConturi; i++)
		this->listaConturi[i] = other.listaConturi[i];
}

Client::~Client()
{
	for (int i = 0; i < this->nrConturi; i++)
		delete listaConturi[i];
	delete listaConturi;
}

Client& Client::operator=(const Client& other)
{
	this->nume = other.nume;
	this->prenume = other.prenume;
	this->adresa = other.adresa;
	this->nrConturi = other.nrConturi;
	this->listaConturi = new ContBancar * [nrConturi];
	for (int i = 0; i < other.nrConturi; i++)
		this->listaConturi[i] = other.listaConturi[i];
	return *this;
}

string Client::getNume()
{
	return nume;
}

string Client::getPrenume()
{
	return prenume;
}

string Client::getAdresa()
{
	return adresa;
}

unsigned Client::getNrContruri()
{
	return nrConturi;
}

ContBancar** Client::getListaConturi()
{
	return listaConturi;
}

void Client::setNume(string nume)
{
	this->nume = nume;
}

void Client::setPrenume(string prenume)
{
	this->prenume = prenume;
}

void Client::setAdresa(string adresa)
{
	this->adresa = adresa;
}

void Client::setNrConturi(unsigned nrConturi)
{
	this->nrConturi = nrConturi;
}

void Client::setListaConturi(ContBancar** listaConturi)
{
	this->listaConturi = listaConturi;
}
void Client::afisareClient()
{
	cout << "Client: Nume " << this->nume << " Prenume " << this->prenume << " Adresa ";
	cout << this->adresa << endl << "Cu conturile: ";
	for (int i = 0; i < this->nrConturi; i++)
		listaConturi[i]->AfisareContBancar();
}
