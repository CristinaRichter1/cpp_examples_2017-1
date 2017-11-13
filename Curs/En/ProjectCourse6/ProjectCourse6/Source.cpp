#include<iostream>
using namespace std;


class Student {
private:
	char* name;
	int age;
	const int id;

	static int noStudents;
	static int MIN_AGE;

	Student() :id(1) {
		Student::noStudents += 1;
		this->age = 18;
		this->name = new char[strlen("John") + 1];
		strcpy(this->name, "John");
	}
public:
	Student(char*name, int age, int Id) :id(Id){
		Student::noStudents += 1;
		//if (age > MIN_AGE)
		//	this->age = age;
		//else
		//	//cout << endl << "The value is wrong";
		//	throw exception("The value is wrong");
		this->setAge(age);

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Student(char*name, int age) :id(Student::noStudents) {
		Student::noStudents += 1;
		this->age = age;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}


	//public interface
	void display() {
		cout << endl << "Name " << this->name <<
			" age " << this->age << " id " << this->id;
	}

	//accessor functions
	int getId() {
		return this->id;
	}

	int getAge() {
		return this->age;
	}

	char* getName() {
		return this->name;
	}

	void setName(char* Name) {
		if (strlen(Name) < 2)
			throw exception();
		else
		{
			//if(this->name != NULL)
				delete [] this->name;
			this->name = new char[strlen(Name) + 1];
			strcpy(this->name, Name);
		}
	}

	void setAge(int value) {
		if (value > MIN_AGE)
			this->age = value;
		else
			//cout << endl << "The value is wrong";
			throw exception("The value is wrong");
	}

	//copy constructor
	//Student(Student* existingObject) {

	//}

	Student(const Student& existingObject):id(Student::noStudents) {
		Student::noStudents++;
		this->name = NULL;
		this->setName(existingObject.name);
		this->setAge(existingObject.age);
		//existingObject.setAge(this->age);
	}

	Student operator=(Student& existingObject) {
		this->setName(existingObject.name);
		this->setAge(existingObject.age);
		return existingObject;
	}


	~Student() {
		delete [] this->name;
	}
};

int Student::noStudents = 0;
int Student::MIN_AGE = 18;


void main() {
	//Student student;
	Student *pStudent;
	//pStudent = &student;
	//pStudent = new Student();
	//pStudent = new Student[1];

	//student.id = 100;

	//Student list[10];



	Student student1("Alice", 19, 1);
	Student *pStudent1 = new Student("Bob", 19, 2);

	student1.display();
	pStudent1->display();

	//Student student2("Alice", 19, 1);
	Student student2 = student1;
	Student *pStudent2 = pStudent1;



	student2.display();
	pStudent2->display();

	cout << endl << "Id: " << student2.getId();
	int vb = -34;
	if(vb > 14)
		student2.setAge(vb);

	//student2.setAge(-34);
	//int vb;
	//cin >> vb;
	//student2.setAge(vb);
	//student2.display();

	//Student student3("Vader", -23, 3);

	student2.setName("Bianca");

	student2.display();
	student1.display();

	Student student3("John", 23, 6);
	student3 = student2;
	//operator=(student3, student2);
	//student3.operator=(student2);

	pStudent2 = pStudent1;
	student2.display();
	student1.display();

	for (;;) {
		Student *pStudent1 = new Student("Bob", 19, 2);
		delete pStudent1;
	}
}
