#include<iostream>
using namespace std;

class Student {
private:
	char* nume;
	int varsta;
	const int cod;
	//const int cod2;
	//Student() :cod(0),cod2(0)

	Student():cod(0) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->varsta = 18;
	}

public:
	Student(char* nume, int varsta, int Cod):cod(Cod) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
	}


	void afisare() {
		cout << endl << this->nume << " - " << this->varsta;

	}

	//interfata clasei
	//pentru citire
	int getVarsta() {
		return this->varsta;
	}

	//pentru modificari
	void setVarsta(int valoare) {
		if (valoare > 14)
			this->varsta = valoare;
		else
			throw exception("Valoare gresita");
	}
};

void main() {
	//Student student;
	//Student* pStudent;
	//pStudent = &student;
	//pStudent = new Student();

	//student.afisare();
	//pStudent->afisare();

	//int varstaStudent = student.getVarsta();
	//student.varsta = 21;
	//student.setVarsta(-23);
	//student.setVarsta(23);

	Student student2("Gigel", 21,1);
	Student* pStudent2 = new Student("Ana", 22,2);

	student2.afisare();
	pStudent2->afisare();

	//Student lista[10];
	Student student3 = student2;
	Student* pStudent3 = pStudent2;


	student3.afisare();
	pStudent3->afisare();
}

