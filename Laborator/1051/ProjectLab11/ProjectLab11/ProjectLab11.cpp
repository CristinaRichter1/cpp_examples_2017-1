// ProjectLab11.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class Employee {
protected:
	char name[50];
	int age;
	float salary;
public:
	Employee() {
		strcpy(this->name, "");
		this->age = 0;
		this->salary = 0;
	}
	Employee(const char* Name, int Age, float Salary) {
		strcpy(this->name, Name);
		this->age = Age;
		this->salary = Salary;
	}

	virtual void display() {
		cout << endl << this->name << "( " <<
			this->age << " ) has a salary of "
			<< this->salary;
	}

	float getSalary() {
		return this->salary;
	}

	float getCost() {
		return this->salary*1.42;
	}

	char* getName() {
		return this->name;
	}
};

class Manager :public Employee {
	char department[50];
	int bonus;
public:
	Manager(const char* Name, int Age, float Salary,
		const char* Department, int Bonus)
		:Employee(Name,Age,Salary){
		strcpy(this->department, Department);
		this->bonus = Bonus;
	}
	void display() {
		this->Employee::display();
		cout << endl << "It's managing the "
			<< this->department << " department";
	}
};

class Freelancer:public Employee {
	char project[50];
	Manager *manager;
public:
	Freelancer(const char* Name, int Age, float Salary,
		const char *Project, Manager* pManager)
	:Employee(Name,Age,Salary){
		strcpy(this->project, Project);
		this->manager = pManager;
	}

	void display() {
		this->Employee::display();
		cout << endl << "Works on the " << this->project;
		cout << endl << "It's boss is "
			<< this->manager->getName();
	}

	~Freelancer() {
		//DON'T DO IT
		//delete manager;
	}
};


int main()
{
	Employee emp1("John", 22, 500);
	Manager m1("Vader", 40, 1500, "Automotive", 10);
	Freelancer f1(
		"Alice", 22, 1000, "Self Driving", &m1);

	emp1.display();
	m1.display();
	f1.display();

	//arrays of objects
	Employee employees[5];
	Employee * employees2 = new Employee[5];

	employees[0] = emp1;
	employees[1] = m1;
	employees[2] = f1;
	employees[3] =
		Freelancer("Bob", 24, 1000, 
			"Smart Braking", &m1);
	employees[4] = Manager("Bianca", 33, 1500,
		"Financial", 5);

	cout << endl << "****** Array of objects";
	for (int i = 0; i < 5; i++) {
		employees[i].display();
	}

	//arrays of pointers
	Employee* list[5];
	Employee* *list2 = new Employee*[5];

	list[0] = &emp1;
	list[1] = &m1;
	list[2] = &f1;
	list[3] = new Freelancer("Bob", 24, 1000,
		"Smart Braking", &m1);
	list[4] = new Manager("Bianca", 33, 1500,
		"Financial", 5);

	cout << endl << "****** Array of pointers";
	for (int i = 0; i < 5; i++) {
		list[i]->display();
	}



}

