// ProjectLaborator5.cpp : Defines the entry point for the console application.
//

#include<iostream>
using namespace std;



enum TipMotor {DIESEL=10,BENZINA,
	HIBRID=21,ELECTRIC,GPL,NIMIC=90};

class Auto {
	char* model;
	int kmParcursi;
	const TipMotor tip;
	static int LIMITA_KM;

	Auto() :tip(TipMotor::NIMIC) {
		this->model = NULL;
		this->kmParcursi = 0;
	}
public:


	Auto(char* model, TipMotor Tip, int Km):tip(Tip) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1,model);
		this->kmParcursi = Km;
	}

	void afisare() {
		if(this->model!=NULL)
			cout << endl << "Model " << this->model;
		cout << endl << "Tip motor " << this->tip;
		cout << endl << "Kilometraj " << this->kmParcursi;
	}

	//interfata publica
	//acces in mod citire
	char* getModel() {
		return this->model;
	}
	int getKm() {
		return this->kmParcursi;
	}

	bool esteUzata() {
		if (this->kmParcursi > LIMITA_KM)
			return true;
		else
			return false;
	 }

	//acces in mod scriere
	void setKm(int valoare) {
		if (this->kmParcursi < valoare)
			this->kmParcursi = valoare;
		else
			throw exception("Valoare gresita");
	}
};

int Auto::LIMITA_KM = 3000;

void main()
{

	int ceva;
	//Auto auto1;
	//auto1.afisare();

	//Auto listaAuto[10];
	//Auto * lista = new Auto[10];

	Auto auto2("Dacia", TipMotor::BENZINA, 4500);
	Auto *pAuto2 = new Auto("Renault", TipMotor::HIBRID, 1000);

	auto2.afisare();
	pAuto2->afisare();

	if (auto2.esteUzata()) {
		cout << endl << "Auto 2 are multi km parcursi";
	}

	if (pAuto2->esteUzata()) {
		cout << endl << "Auto 2 are multi km parcursi";
	}

	auto2.setKm(10000);
	auto2.afisare();
}

