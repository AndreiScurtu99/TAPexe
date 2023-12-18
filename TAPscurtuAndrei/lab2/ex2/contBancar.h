#pragma once
#ifndef CONTBANCAR_H
#define CONTBANCAR_H
#include <iostream>
#include <string>
using namespace std;
class Operatiuni {
public:
	virtual float getSumaTotala() = 0;
	virtual float getDobanda() = 0;
	virtual void depunere(float) = 0;
	virtual void extragere(float) = 0;
class FondInsufException : public exception {
	public:
		const char* what() const noexcept override {
			return "Fonduri insuficiente!";
		}
	};
class MonedaException : public exception {
public:
	const char* what() const noexcept override {
		return "Moneda Invalida!";
	}
};
class TransferException : public exception {
public:
	const char* what() const noexcept override {
		return "Conturi necompatibile";
	}
};
};
class ContBancar :Operatiuni {
private:
	string numarCont;
	float suma;
	string moneda;
public:
	ContBancar(string, float, string);
	ContBancar(const ContBancar&);
	~ContBancar();
	ContBancar& operator=(const ContBancar&);
	float getSumaTotala();
	float getDobanda();
	void depunere(float);
	void extragere(float);
	void transfer(ContBancar&, float);
	string getNumarCont();
	float getSuma();
	string getMoneda();
	void setNumarCont(string);
	void setSuma(float);
	void setMoneda(string);
	void AfisareContBancar();
};
class Client{
private:
	string nume;
	string prenume;
	string adresa;
	unsigned nrConturi;
	ContBancar** listaConturi;
public:
	Client(string, string, string, unsigned, ContBancar**);
	Client(const Client&);
	~Client();
	Client& operator=(const Client&);
	string getNume();
	string getPrenume();
	string getAdresa();
	unsigned getNrContruri();
	ContBancar** getListaConturi();
	void setNume(string);
	void setPrenume(string);
	void setAdresa(string);
	void setNrConturi(unsigned);
	void setListaConturi(ContBancar**);
	void afisareClient();
};
class Banca  {
private :
	string codBanca;
	unsigned nrClienti;
	Client** listClienti;
public:
	Banca(string, unsigned, Client**);
	Banca(const Banca&);
	~Banca();
	Banca& operator=(const Banca&);
	string getCodBanca();
	unsigned getNrClienti();
	Client* getListClienti();
	void setCodBanca(string);
	void setNrClienti(unsigned);
	void setListClienti(Client**);
	void AfisareBanca();
};





#endif CONTBANCAR_H
