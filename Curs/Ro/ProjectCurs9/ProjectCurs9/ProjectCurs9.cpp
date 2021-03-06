// ProjectCourse8.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iostream>


using namespace std;


class Student {
private:
	//attributes
	int cod;
	char name[50];
	int * grades;
	int noGrades;
	char* faculty;

public:
	//constructor
	Student() {
		//cout << endl << "Default constructor";
		cod = 0;
		noGrades = 0;
		this->grades = NULL;
		strcpy(this->name, "John Doe");
		// DON'T this->faculty = "CSIE";
		this->faculty = new char[strlen("CSIE") + 1];
		strcpy(this->faculty, "CSIE");
	}

	//constructor with arguments
	Student(char* name, int code, char*faculty) {
		//cout << endl << "Constructor with arguments";
		//shadowing 
		//code = code
		this->cod = code;
		this->noGrades = 0;
		this->grades = NULL;
		strcpy(this->name, name);
		this->faculty =
			new char[strlen(faculty) + 1];
		strcpy(this->faculty, faculty);

	}

	~Student() {
		//cout << endl << "Destructor !!!!!";
		if (this->faculty != NULL)
			delete [] this->faculty;
		if (this->grades != NULL)
			delete [] grades;
	}

	//copy constructor
	Student(const Student& s) {

		//cout << endl << "Copy constructor";
		this->cod = s.cod;
		strcpy(this->name, s.name);

		this->faculty = NULL;
		this->setFaculty(s.faculty);

		//grades
		if (s.noGrades != 0) {
			this->grades = new int[s.noGrades];
			for (int i = 0; i < s.noGrades; i++)
				grades[i] = s.grades[i];
			this->noGrades = s.noGrades;
		}
		else
		{
			this->noGrades = 0;
			this->grades = NULL;
		}
	}

public:
	//accessor methods
	//for reading
	int getCode() {
		return this->cod;
	}

	char* getFaculty() {
		return this->faculty;
	}
	char* getName() {
		return this->name;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	//write access
	void setFaculty(char* newFaculty) {
		//validating the input
		if (strlen(newFaculty) >= 2) {

			//this->faculty = newFaculty; DON'T
			if (this->faculty != NULL)
				delete [] this->faculty;
			this->faculty = new char[strlen(newFaculty) + 1];
			strcpy(this->faculty, newFaculty);
		}
		else {
			throw exception("The name is too short!");
		}

	}

	void setCod(int cod) {
		this->cod = cod;
	}

	void setNote(int nrNote, int* note) {
		if (this->grades != NULL)
			delete [] this->grades;
		if (nrNote == 0) {
			this->grades = NULL;
			this->noGrades = 0;
		}
		else {
			this->grades = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
				this->grades[i] = note[i];
			this->noGrades = nrNote;
		}
	}

	void setNume(char* nume) {
		strcpy(this->name, nume);
	}


	void operator=(const Student& s2) {

		if (this == &s2)
			return;

		delete [] this->grades;
		delete [] this->faculty;

		cout << endl << "Operator = called";
		this->cod = s2.cod;
		strcpy(this->name, s2.name);

		this->setFaculty(s2.faculty);


		//grades
		if (s2.noGrades != 0) {
			if (this->grades != NULL)
				delete [] this->grades;
			this->grades = new int[s2.noGrades];
			for (int i = 0; i < s2.noGrades; i++)
				grades[i] = s2.grades[i];
			this->noGrades = s2.noGrades;
		}
		else
		{
			this->noGrades = 0;
			this->grades = NULL;
		}
	}


	int& operator[](int index) {
		if (index >= 0 && index < this->noGrades) {
			return this->grades[index];
		}
		else
			throw exception();
	}

	void operator+=(int newGrade) {
		int* newGradesArray = new int[this->noGrades + 1];
		for (int i = 0; i < this->noGrades; i++)
			newGradesArray[i] = this->grades[i];
		newGradesArray[this->noGrades] = newGrade;
		delete [] this->grades;
		this->grades = newGradesArray;
		this->noGrades += 1;
	}

	//metoda pentru serializare obiect
	void serializare(ofstream& fisier) {
		if (fisier.is_open()) {
			//scriem codul
			fisier.write((char*) &this->cod,
				sizeof(int));
			//scriem numele
			fisier.write(this->name,
				sizeof(Student::name));
			//scriem numarul de note
			fisier.write((char*) &this->noGrades,
				sizeof(int));
			//scriem notele
			for (int i = 0; i < this->noGrades; i++) {
				fisier.write((char*) &this->grades[i],
					sizeof(int));
			}
			////scriem facultatea - solutia 1
			//char buffer[1000];
			//strcpy(buffer, this->faculty);
			//fisier.write(buffer, sizeof(buffer));

			//scriem facultatea - solutia 2
			int dim = strlen(this->faculty) + 1;
			fisier.write((char*) &dim, sizeof(int));
			fisier.write(this->faculty,
				dim * sizeof(char));
		}
		else
		{
			cout << endl << "Probleme deschidere fisier";
			throw exception();
		}
	}

};


ostream& operator<<(ostream& console, Student& s) {
	console << endl << "Numele studentului este "
		<< s.getName() << ", are codul "
		<< s.getCode() << " si este la facultatea "
		<< s.getFaculty();
	console << endl << "Note:";
	for (int i = 0; i < s.getNoGrades(); i++)
		console << " " << s[i];
	return console;
}

void main() {
	//Student s1("Gigel", 23, "CSIE");
	//Student s2("Ionel", 22, "MK");

	//s1 += 10;
	//s1 += 9;


	//cout << s1 << s2;

	////char nume1[100];
	////char nume2[100];

	////cout << endl << "Nume1:";
	////cin.getline(nume1, 50);
	////int vb;
	////cout << endl << "Varsta:";
	////cin >> vb;
	////cout << endl << "Nume2:";
	////cin >> nume2;

	////cout << endl << nume1 << "**" << vb << " * " << nume2;

	////generare raport
	//ofstream raportStudenti;
	//raportStudenti.open(
	//	"Raport studenti.txt", ios::out | ios::trunc);
	//if (raportStudenti.is_open()) {
	//	raportStudenti << "Lista studenti" << endl;
	//	raportStudenti << s1.getName() << endl;
	//	raportStudenti << s2.getName() << endl;
	//	raportStudenti << "Date studenti" << endl;
	//	raportStudenti << s1;
	//	raportStudenti << s2;
	//}
	//else
	//	cout << endl << "Probleme deschidere fisier";

	//Student* lista=NULL;
	//int nrStudenti=0;
	//ifstream dateStudenti;
	//dateStudenti.open("Studenti.txt", ios::in);
	//if (dateStudenti.is_open()) {
	//	dateStudenti >> nrStudenti;
	//	lista = new Student[nrStudenti];
	//	for (int i = 0; i < nrStudenti; i++) {
	//		int cod;
	//		dateStudenti >> cod;
	//		char nume[100];
	//		dateStudenti >> nume;
	//		int nrNote;
	//		dateStudenti >> nrNote;
	//		int * note = new int[nrNote];
	//		for (int j = 0; j < nrNote; j++) {
	//			dateStudenti >> note[j];
	//		}
	//		char facultate[100];
	//		dateStudenti >> facultate;

	//		lista[i].setCod(cod);
	//		lista[i].setFaculty(facultate);
	//		lista[i].setNume(nume);
	//		lista[i].setNote(nrNote, note);
	//	}

	//	dateStudenti.close();

	//}
	//else
	//	cout << endl << "Nu am putut deschide fisierul";

	//cout << endl << "date fisier:";
	//for (int i = 0; i < nrStudenti; i++)
	//	cout << lista[i];

	////lucrul cu fisiere binare
	////serializare

	////salvare date in fisier binar
	//ofstream backup;

	////NU ASA

	////backup.open("Studenti.dat", 
	////	ios::out | ios::binary | ios::trunc);
	////if (backup.is_open()) {
	////	//scriu nr studenti
	////	//backup << nrStudenti; NU MERGE
	////	backup.write((char*) &nrStudenti, sizeof(int));
	////	//salvez studentii
	////	for (int i = 0; i < nrStudenti; i++) {
	////		NU ASA
	////		backup.write((char*) &lista[i], sizeof(Student));
	////	}
	////}
	////backup.close();

	////NU ASA
	//////restauram datele salvate in fisier
	////Student *lista2 = NULL;
	////int nrStudenti2 = 0;
	////ifstream date;
	////date.open("Studenti.dat", ios::in | ios::binary);
	////if (date.is_open()) {
	////	date.read((char*) &nrStudenti2, sizeof(int));
	////	lista2 = new Student[nrStudenti2];
	////	for (int i = 0; i < nrStudenti2; i++) {
	////		date.read((char*) &lista2[i], sizeof(Student));
	////	}
	////	date.close();
	////}
	////cout << endl << "**************************";
	////for (int i = 0; i < nrStudenti2; i++)
	////	cout << lista2[i];


	////lucrul cu fisiere binare
	////serializare

	//backup.open("Studenti.dat", 
	//	ios::out | ios::binary | ios::trunc);
	//if (backup.is_open()) {
	//	//scriem numarul de studenti
	//	backup.write((char*) &nrStudenti,
	//		sizeof(int));
	//	for (int i = 0; i < nrStudenti; i++) {
	//		lista[i].serializare(backup);
	//	}
	//	backup.close();
	//}


	//restauram datele salvate in fisier
	Student *lista2 = NULL;
	int nrStudenti2 = 0;
	ifstream date;
	date.open("Studenti.dat", ios::in | ios::binary);
	if (date.is_open()) {
		//citim numarul de studenti
		date.read((char*) &nrStudenti2,
			sizeof(int));
		lista2 = new Student[nrStudenti2];
		for (int i = 0; i < nrStudenti2; i++) {
			int cod;
			date.read((char*) &cod, sizeof(int));
			char nume[50];
			date.read(nume, sizeof(nume));
			int nrNote;
			date.read((char*) &nrNote, sizeof(int));
			int* note = new int[nrNote];
			for (int j = 0; j < nrNote; j++) {
				date.read((char*) &note[j],
					sizeof(int));
			}
			//citim numele facultatii - solutia 2
			int dimensiune;
			date.read((char*) &dimensiune,
				sizeof(int));
			char* facultate = new char[dimensiune];
			date.read(facultate, 
				dimensiune * sizeof(char));

			lista2[i].setCod(cod);
			lista2[i].setFaculty(facultate);
			lista2[i].setNote(nrNote, note);
			lista2[i].setNume(nume);

		}//de la for
		date.close();
	}

	cout << endl << "*********************Dupa load";
	for (int i = 0; i < nrStudenti2; i++)
		cout << endl << lista2[i];


	cout << endl << "THE END";
}
