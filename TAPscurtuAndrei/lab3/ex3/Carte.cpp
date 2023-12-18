#include "Carte.h"
#include <iostream>
#include <vector>
using namespace std;

int Carte::nrInstante = 0;
vector <Carte*> Carte::instante;

Carte::Carte(string autor, string titlu, string ISBN, double pret) : autor(autor), titlu(titlu), ISBN(ISBN), pret(pret) {
    ++nrInstante;
    adaugaInstanta(this);
}

Carte::Carte(string, string, string, double, int)
{
    this->autor = autor;
    this->titlu = titlu;
    this->ISBN = ISBN;
    this->pret = pret;
}

Carte::Carte(const Carte& other)
{
    this->autor = other.autor;
    this->titlu = other.titlu;
    this->ISBN = other.ISBN;
    this->pret = other.pret;
}

Carte::~Carte()
{
    for (int i = 0; i < nrInstante; ++i);
    nrInstante--;
}

    void Carte::adaugaInstanta(Carte * carte) {
        instante.push_back(carte);
    }

    void Carte::afisareCartiAutor(const string & autorCautat) {
        cout << "Cartile autorului " << autorCautat << " sunt:" << endl;
        for (const auto& carte : instante) {
            if (carte->getAutor() == autorCautat) {
                cout << "Titlu: " << carte->getTitlu() << ", ISBN: " << carte->getISBN()
                    << ", Pret: " << carte->getPret() << endl;
            }
        }
    }
