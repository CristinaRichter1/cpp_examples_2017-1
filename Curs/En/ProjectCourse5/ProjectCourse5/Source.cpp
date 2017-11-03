#include<iostream>
using namespace std;


class Student {
private:
	char* name;
	int age;
	const int id;
	const int personalID;

	static int noStudents;

	Student():id(1),personalID(0) {
		Student::noStudents += 1;
		this->age = 18;
		this->name = new char[strlen("John")+1];
		strcpy(this->name, "John");
	}
public:
	Student(char*name, int age, int Id):id(Id),personalID(0) {
		Student::noStudents += 1;
		this->age = age;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Student(char*name, int age) :id(Student::noStudents), personalID(0) {
		Student::noStudents += 1;
		this->age = age;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void display() {
		cout << endl << "Name " << this->name <<
			" age " << this->age<<" id "<<this->id;
	}

	//copy constructor
	Student(Student& stud):id(stud.id),personalID(0) {
		//
	}

};

int Student::noStudents = 0;


void main() {
	//Student student;
	Student *pStudent;
	//pStudent = &student;
	//pStudent = new Student();
	//pStudent = new Student[1];

	//student.id = 100;

	//Student list[10];

	

	Student student2("Alice", 19, 1);
	
	Student *pStudent2 = new Student("Bob",19,2);

	Student *pStudent3 = new Student("Bob", 19);
	Student *pStudent4 = new Student("Bob", 19);
	Student *pStudent5 = new Student("John", 19);

	student2.display();
	pStudent5->display();

	Student student3 = student2;
	Student *pStudent6 = pStudent5;

	student3.display();
	pStudent6->display();
}
