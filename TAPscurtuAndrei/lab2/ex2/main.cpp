#include <iostream>
#include "contBancar.h"
using namespace std;
int main()
{
	ContBancar *cont = new ContBancar("77761223", 500, "EUR");
	ContBancar *cont2 = new ContBancar("77765222", 500, "RON");
	ContBancar** conturi = new ContBancar*[2];
	conturi[0] = cont;
	conturi[1] = cont2;
	Client* client1 = new Client("Bogdan", "Marcel", "PetruMaior", 2, conturi);
	Client** clienti = new Client * [1];
	clienti[0] = client1;
	Banca* banca = new Banca("4761", 1, clienti);
	banca->AfisareBanca();
	return 0;
}