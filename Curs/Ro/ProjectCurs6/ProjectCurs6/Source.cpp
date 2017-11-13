#include<iostream>
using namespace std;

//fara variabile globale
//int contor = 0;

class Student {
private:
	char* nume;
	int varsta;
	const int cod;
	static int contor;
	static int VARSTA_MINIMA;

	//const int cod2;
	//Student() :cod(0),cod2(0)

	Student() :cod(0) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->varsta = 18;
	}

public:
	Student(char* nume, int varsta, int Cod) :cod(Cod) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
	}

	//copy constructor
	Student(const Student& existent):cod(Student::contor) {
		Student::contor +=1;
		//if (existent.varsta > VARSTA_MINIMA)
		//	this->varsta = existent.varsta;
		//else
		//	throw exception("Valoare gresita");

		//existent.varsta = 34;

		this->setVarsta(existent.varsta);

		this->nume = NULL;
		this->setNume(existent.nume);

		/*this->nume = new char[strlen(existent.nume) + 1];
		strcpy(this->nume, existent.nume);*/
	}


	void afisare() {
		cout << endl << this->nume << " - " << this->varsta <<
			" cod "<<this->cod;

	}

	//interfata clasei
	//pentru citire
	int getVarsta() {
		return this->varsta;
	}

	//pentru modificari
	void setVarsta(int valoare) {
		if (valoare > VARSTA_MINIMA)
			this->varsta = valoare;
		else
			throw exception("Valoare gresita");
	}

	char* getNume() {
		return this->nume;
	}
	void setNume(char* Nume) {
		if (strlen(Nume) < 3)
			throw exception("Numele este prea scurt");
		if(this->nume!=NULL)
			delete [] this->nume;
		this->nume = new char[strlen(Nume) + 1];
		strcpy(this->nume, Nume);
	}

	Student& operator=(Student& s2) {
		this->setVarsta(s2.varsta);
		this->setNume(s2.nume);
		return s2;
	}
};

int Student::contor = 1000;
int Student::VARSTA_MINIMA = 10;

void faceNimic1(Student* s) {
	s->setNume("Nimic");
}

void faceNimic2(Student& s) {
	s.setNume("Nimic");
}

void faceNimic(Student s) {
	s.setNume("Nimic");
}

Student faceNimic3() {
	Student s("Gigel", 21, 1);
	return s;
}



void main() {

	//int contor = 0;

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

	Student student2("Gigel", 21, 1);
	Student* pStudent2 = new Student("Ana", 22, 2);

	student2.afisare();
	pStudent2->afisare();

	//Student lista[10];
	Student student3 = student2;
	Student* pStudent3 = pStudent2;

	student3.afisare();
	pStudent3->afisare();

	student3.setNume("Ionel");

	student2.afisare();
	student3.afisare();

	pStudent3->setNume("Bianca");
	pStudent2->afisare();
	pStudent3->afisare();

	//faceNimic(student2);
	//faceNimic2(student2);

	//student2.afisare();

	Student student4("test", 1, 1);
	//
	///
	student4 = student3;
	student2 = student4 = student3;
	//operator=(student4, student3);
	//student4.operator=(student3);

	//int vb2 = 2 + 3;
	//int vb2 = operator+(2, 3);

}

