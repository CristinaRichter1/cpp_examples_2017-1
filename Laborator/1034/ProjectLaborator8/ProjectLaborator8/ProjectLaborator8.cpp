// ProjectLaborator8.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
using namespace std;

class Meteo;

class StatieMeteo {
	char localitate[50];
	float temperaturi[24];
	int oraCurenta;
public:
	StatieMeteo() {
		strcpy(this->localitate, "Nicaieri");
		this->oraCurenta = 0;
		for (int i = 0; i < 24; i++) {
			this->temperaturi[i] = INT32_MAX;
		}
	}

	StatieMeteo(char* localitate) {
		strcpy(this->localitate, localitate);
		this->oraCurenta = 0;
		for (int i = 0; i < 24; i++) {
			this->temperaturi[i] = INT32_MAX;
		}
	}

	float operator[](int ora) {
		if (ora >= 0 && ora < this->oraCurenta) {
			return this->temperaturi[ora];
		}
		else
			throw exception();
	}

	void setTemperatura(int ora, float temp) {
		if (ora >= 0 && ora < 24) {
			if (temp > -200 && temp < 1000) {
				this->temperaturi[ora] = temp;
				if(ora > this->oraCurenta)
					this->oraCurenta = ora;
			}
			else
				throw exception();
		}
		else
			throw exception();
	}

	char* getLocalitate() {
		return this->localitate;
	}


	friend void generareRaport(Meteo meteo, char* numeRaport);
	friend ostream& operator<<(ostream& consola, StatieMeteo& statie);
};

ostream& operator<<(ostream& consola, StatieMeteo& statie) {
	consola << endl << "Locatie: " << statie.localitate;
	consola << endl << "Temperaturi:";
	for (int i = 0; i <= statie.oraCurenta; i++)
		if (statie.temperaturi[i] == INT32_MAX)
			consola << " - ";
		else
			consola << " " << statie.temperaturi[i];
	return consola;
}

class Meteo {
public:
	StatieMeteo statii[100];
	int nrStatii;
	char tara[50];
};

void generareRaport(Meteo meteo, char* numeRaport) {
	ofstream raport;
	raport.open(numeRaport, ios::out | ios::app);
	if (raport.is_open()) {
		raport << "\t\t Raport meteo";
		raport << endl << "Lista orase";
		for (int i = 0; i < meteo.nrStatii; i++) {
			raport << endl << meteo.statii[i].getLocalitate();
		}
		raport << endl << "Info";
		for (int i = 0; i < meteo.nrStatii; i++) {
			raport << meteo.statii[i];
		}
	}
	raport.close();
}

int main()
{
	StatieMeteo statie1("Bucuresti");
	StatieMeteo statie2("Ploiesti");

	statie1.setTemperatura(7, 10.56);
	statie1.setTemperatura(10, 14.2);

	statie2.setTemperatura(9, 12.9);
	statie1.setTemperatura(3, 6.2);

	cout << statie1 << statie2;

	Meteo meteo;
	meteo.nrStatii = 2;
	meteo.statii[0] = statie1;
	meteo.statii[1] = statie2;
	strcpy(meteo.tara, "Romania");

	generareRaport(meteo, "Temperaturi Romania.txt");

}

