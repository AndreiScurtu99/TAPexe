#include "contBancar.h"
#include <iostream>
#include <exception>
using namespace std;

ContBancar::ContBancar(string numarCont, float suma, string moneda)
{
	this->numarCont = numarCont;
	this->suma = suma;
	this->moneda = moneda;
}
ContBancar::ContBancar(const ContBancar& other)
{
	this->numarCont = other.numarCont;
	this->suma = other.suma;
	this->moneda = other.moneda;
}
ContBancar& ContBancar::operator=(const ContBancar& other)
{
	this->numarCont = other.numarCont;
	this->suma = other.suma;
	this->moneda = other.moneda;
	return *this;
}
float ContBancar::getSumaTotala()
{
	return this->suma;
}
float ContBancar::getDobanda() 
{
	if (this->moneda != "RON" && this->moneda != "EUR")
		throw MonedaException();
	if (this->moneda == "RON" && this->suma < 500)
		return 0.3;
	if (this->moneda == "RON")
		return 0.8;
	if (this->moneda == "EUR")
		return 0.1;
	
}
void ContBancar::depunere(float suma)
{
	this->suma += suma;
}
void ContBancar::extragere(float suma)
{
	if (this->suma < suma)
		throw FondInsufException();
	this->suma -= suma;
}
void ContBancar::transfer(ContBancar& other, float suma)
{
	if (this->suma < suma)
		throw FondInsufException();
	if (this->moneda != other.moneda)
		throw TransferException();
	other.depunere((suma - suma*other.getDobanda()/100));
	this->suma -= suma;
}
string ContBancar::getNumarCont()
{
	return this->numarCont;
}
float ContBancar::getSuma()
{
	return this->suma;
}
string ContBancar::getMoneda()
{
	return this->moneda;
}
void ContBancar::setNumarCont(string numarCont)
{
	this->numarCont = numarCont;
}
void ContBancar::setSuma(float suma)
{
	this->suma = suma;
}
void ContBancar::setMoneda(string moneda)
{
	this->moneda = moneda;
}
ContBancar::~ContBancar(){}
void ContBancar::AfisareContBancar()
{
	cout << "Nr cont: " << this->numarCont << ", suma " << this->suma << ", moneda " << this->moneda<<endl;
}

