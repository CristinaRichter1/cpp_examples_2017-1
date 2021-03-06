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
	Student s1("Gigel", 23, "CSIE");
	Student s2("Ionel", 22, "MK");

	s1 += 10;
	s1 += 9;


	cout << s1 << s2;

	//char nume1[100];
	//char nume2[100];

	//cout << endl << "Nume1:";
	//cin.getline(nume1, 50);
	//int vb;
	//cout << endl << "Varsta:";
	//cin >> vb;
	//cout << endl << "Nume2:";
	//cin >> nume2;

	//cout << endl << nume1 << "**" << vb << " * " << nume2;

	//generare raport
	ofstream raportStudenti;
	raportStudenti.open(
		"Raport studenti.txt", ios::out | ios::trunc);
	if (raportStudenti.is_open()) {
		raportStudenti << "Lista studenti" << endl;
		raportStudenti << s1.getName() << endl;
		raportStudenti << s2.getName() << endl;
		raportStudenti << "Date studenti" << endl;
		raportStudenti << s1;
		raportStudenti << s2;
	}
	else
		cout << endl << "Probleme deschidere fisier";

}
