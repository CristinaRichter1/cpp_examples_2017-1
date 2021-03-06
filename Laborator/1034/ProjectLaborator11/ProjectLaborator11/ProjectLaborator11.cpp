// ProjectLaborator11.cpp : Defines the entry point for the console application.
//
#include <iostream>;
using namespace std;

class Adresa {
	char strada[50];
	int nr;
	char localitate[50];
public:
	Adresa(const char* Strada, int Nr, 
		const char* Localitate) {
		strcpy(this->strada, Strada);
		strcpy(this->localitate, Localitate);
		this->nr = Nr;
	}

	void getAdresa() {
		cout << endl << this->strada << ", "
			<< this->nr << ", " << this->localitate;
	}
};

class Angajat {
protected:
	Adresa adresa;	//compunere
	char nume[50];
	float salariu;

public:
	Angajat():adresa("Necunoscuta", 0, "") {
		strcpy(this->nume, "Anonim");
		this->salariu = 0;
	}

	Angajat(const char* Strada,
		int Nr, const char* Localitate,
		const char* Nume, float Salariu)
		:adresa(Strada,Nr,Localitate) {
		strcpy(this->nume, Nume);
		this->salariu = Salariu;
	}

	void afisare() {
		cout << endl << this->nume << " are salariu net de "
			<< this->salariu;
		this->adresa.getAdresa();
	}

	float getCostFirma() {
		return this->salariu*1.42;
	}

	char* getNume() {
		return this->nume;
	}
};


class Manager :public Angajat {
	char departament[50];
public:
	Manager() {
		strcpy(this->departament, "");
	}

	Manager(const char* Strada,
		int Nr, const char* Localitate,
		const char* Nume, float Salariu,
		const char* Departament)
	:Angajat(Strada,Nr,Localitate,Nume,Salariu){
		strcpy(this->departament, Departament);
	}

	//supradefinire metoda din parinte
	void afisare() {
		this->Angajat::afisare();
		cout << endl << "Gestioneaza departamentul "
			<< this->departament;
	}
};

class Programator :public Angajat {
	char proiect[50];
	Manager* manager;
public:
	Programator(const char* Strada,
		int Nr, const char* Localitate,
		const char* Nume, float Salariu,
		const char* Proiect, Manager* pm)
		:Angajat(Strada, Nr, Localitate, Nume, Salariu) {
		strcpy(this->proiect, Proiect);
		manager = pm;
	}

	~Programator()
	{
		//NU TREBUIE
		//delete manager;
	}

	//supradefinire metoda din parinte
	void afisare() {
		this->Angajat::afisare();
		cout << endl << "Lucreaza la proiectul " 
			<< this->proiect;
		cout << endl << "Seful direct este " 
			<< this->manager->getNume();
	}
};


void main(int n, char* valori[])
{
	cout << endl << "Argument 0 " << valori[0];

	if (n == 3)
	{
		cout << endl << "Fisier 1 primit " << valori[1];
		cout << endl << "Fisier 2 primit " << valori[2];
	}

	//obiecte
	Angajat a1("Piata Romana", 2, "Bucuresti", "Gigel", 1000);
	Manager m1("Calea Dorobanti", 16, "Bucuresti", 
		"Ionel", 2000, "ERP");
	Programator p1("Lacul Tei", 36, "Bucuresti", "Ana",
		1500, "Rapoarte salarii", &m1);

	a1.afisare();
	m1.afisare();
	p1.afisare();
}

