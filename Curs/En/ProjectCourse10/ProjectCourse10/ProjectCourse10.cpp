// ProjectCourse10.cpp : Defines the entry point for the console application.
//


// ProjectCourse8.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <fstream>

using namespace std;


class Student {
protected:
	//attributes
	int cod;
	char name[50];
	int * grades;
	int noGrades;
	char* faculty;


public:
	//constructor
	//Student() {
	//	//cout << endl << "Default constructor";
	//	cod = 0;
	//	noGrades = 0;
	//	this->grades = NULL;
	//	strcpy(this->name, "John Doe");
	//	// DON'T this->faculty = "CSIE";
	//	this->faculty = new char[strlen("CSIE") + 1];
	//	strcpy(this->faculty, "CSIE");
	//}

	//constructor with arguments
	Student(char* name, int code, char*faculty) {

		cout << endl << "******** Student constructor";
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

	void setGrades(int* grades, int n) {
		if (this->grades != NULL)
			delete [] this->grades;
		//this->grades = grades; DON'T
		this->grades = new int[n];
		for (int i = 0; i < n; i++)
			this->grades[i] = grades[i];
		this->noGrades = n;

	}


	void operator=(const Student& s2) {

		if (this == &s2)
			return;

		delete [] this->grades;
		delete [] this->faculty;

		cout << endl << "Operator = called";
		this->cod = s2.cod;
		strcpy(this->name, s2.name);

		this->faculty = NULL;
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

	//a method for serializing the object
	void write2File(ofstream& file) {
		if (file.is_open()) {
			//write the code
			file.write((char*) &this->cod, sizeof(int));
			//write the name
			file.write(this->name, sizeof(Student::name));
			//write the number of grades
			file.write((char*) &this->noGrades, sizeof(int));
			//write the grades
			for (int i = 0; i < this->noGrades; i++) {
				file.write((char*) &this->grades[i], sizeof(int));
			}
			//write the faculty - option 1
			char buffer[100];
			strcpy(buffer, this->faculty);
			file.write(buffer, sizeof(buffer));

			//write the faculty - option 2
			//write the faculty value size
			int facultySize = strlen(this->faculty) + 1;
			file.write((char*) &facultySize, sizeof(int));
			file.write(this->faculty, facultySize * sizeof(char));


		}
	}

	void display() {
		cout << endl << "Numele studentului este "
			<< this->getName() << ", are codul "
			<< this->getCode() << " si este la facultatea "
			<< this->getFaculty();
		cout << endl << "Note:";
		for (int i = 0; i < this->getNoGrades(); i++)
			cout << " " << this->grades[i];
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

enum GenderType { FEMALE=1, MALE };

//inheritance - expanding
class MasterStudent: public Student {
	char masterName[100];
	char gender;
public:

	MasterStudent():Student("Alice",1,"CSIE") {
		this->gender = 'F';
		strcpy(this->masterName, "");
	}

	MasterStudent(char *Name, int Code, char* Faculty,
		GenderType Gender, char* Master):Student(Name,Code,Faculty) {

		cout << endl << "******** MasterStudent constructor";

		this->setGender(Gender);
		strcpy(this->masterName, Master);
	}

	char getGender() {
		return this->gender;
	}
	void setGender(GenderType type) {
		switch (type) {
		case GenderType::FEMALE:
			this->gender = 'F';
			break;
		case GenderType::MALE:
			this->gender = 'M';
		}
	}
	//overriding
	void display() {
		cout << endl << "Numele masterandului este "
			<< this->getName() << ", are codul "
			<< this->getCode() << " si este la masteratul "
			<< this->masterName;
		cout << endl << "Note:";
		for (int i = 0; i < this->getNoGrades(); i++)
			cout << " " << this->grades[i];
	}

};


int main()
{
	Student s1("John", 23, "CSIE");
	Student s2("Ionel", 22, "MK");

	s1 += 10;
	s1 += 9;
	
	MasterStudent ms1;
	//cout << ms1;
	//ms1.Student::display();	//calling the parent version
	ms1.display();
	MasterStudent ms2("David", 2, "MK", GenderType::MALE, "Info");



	ms1.setGender(GenderType::MALE);
	cout << ms2;

	Student list[] = { s1,s2,ms1 };

}

