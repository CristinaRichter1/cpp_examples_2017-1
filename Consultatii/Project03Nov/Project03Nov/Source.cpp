#include<iostream>
using namespace std;

class Test{
	int valoare;
	char* nume;
public:
	Test(int valoare, char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->valoare = valoare;
	}

	Test(const Test& existent) {
		//existent.valoare = this->valoare;
	}



	void afisare() {
		cout << endl << this->nume << " " << this->valoare;
	}

	void setNume(char* numeNou) {
		delete [] this->nume;
		this->nume = new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);
	}

	int getValoare() {
		return this->valoare;
	}

	char* getNume() {
		return this->nume;
	}

};


void citire1() {
	int variabila;
	cout << endl << "Valoare noua:";
	cin >> variabila;
}

int citire2() {
	int variabila;
	cout << endl << "Valoare noua:";
	cin >> variabila;
	return variabila;
}


void citire3(int* adresaVariabila ) {
	int variabila;
	cout << endl << "Valoare noua:";
	cin >> variabila;
	*adresaVariabila = variabila;
}

void citire4(int& adresaVariabila) {
	int variabila;
	cout << endl << "Valoare noua:";
	cin >> variabila;
	adresaVariabila = variabila;
}

void ceva(Test t) {

}

void ceva(int t) {

}

Test ceva2() {
	Test t(2,"Nimic");
	return t;
}

ostream& operator<<(ostream& consola, Test* t) {
	consola << t->getNume();
	consola << " si valoarea " << t->getValoare();
	return consola;
}

void main() {
	//int variabila = 10;
	//cout << endl << "Valoare : " << variabila;
	//citire1();
	//cout << endl << "Valoare : " << variabila;
	//variabila = citire2();
	//cout << endl << "Valoare : " << variabila;
	//citire3(&variabila);
	//cout << endl << "Valoare : " << variabila;
	//citire4(variabila);
	//cout << endl << "Valoare : " << variabila;


	Test t1(1,"Gigel");
	Test t2(2, "Ana");
	//t1.setNume("Ana");
	//t1.afisare();
	//Test t2 = t1;

	//ceva(t1);

	//t1.afisare();
	//t2.afisare();

	//t1.setNume("Bianca");
	//t1.afisare();
	//t2.afisare();

	cout << t1; //operator<<(cout, t1);
	cout << t1 << t2;

}