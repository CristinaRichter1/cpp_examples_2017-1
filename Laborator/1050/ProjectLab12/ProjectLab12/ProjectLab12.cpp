// ProjectLab12.cpp : Defines the entry point for the console application.
//
#include<iostream>
using namespace std;

//abtract class for simulating an Active Directory
class ActiveDirectoryItem {
protected:
	int id;
	static int idGenerator;
public:
	virtual void getItemDescription() = 0;
	virtual void getItemName() = 0;
	int getId() {
		return id;
	}

	ActiveDirectoryItem() {
		this->id = ++ActiveDirectoryItem::idGenerator;
	}

};

int ActiveDirectoryItem::idGenerator = 0;

class HRItem {
public:
	virtual void getEmployeeName() = 0;
};

class Computer:public ActiveDirectoryItem {
	char model[50];
	char processorFamily[50];
public:
	Computer(const char*Model,
		const char* Processor) {
		strcpy(this->model,Model);
		strcpy(this->processorFamily, Processor);
	}

	//override parent class method
	void getItemDescription() {
		cout << endl << "It's a machine";
	}

	void getItemName() {
		cout << endl << model << " with id " << this->id;
	}
};


class Person: public ActiveDirectoryItem,public HRItem {
	char* name[3];
	int age;

private:
	static char* copyString(const char* value) {
		char* newValue = new char[strlen(value) + 1];
		strcpy(newValue, value);
		return newValue;
	}

public:
	Person(const char* FirstName,
		const char* MiddleName,
		const char* LastName,
		int Age) {
		//first name
		this->name[0] = copyString(FirstName);
		this->name[1] = copyString(MiddleName);
		this->name[2] = copyString(LastName);
		this->age = Age;
	}

	~Person() {
		delete [] this->name[0];
		delete [] this->name[1];
		delete [] this->name[2];
	}

	//override parent class method
	void getItemDescription() {
		cout << endl << "It's a user";
	}

	void getItemName() {
		cout << endl << this->name[2]
			<<" "<<this->name[1]  
			<<" "<<this->name[0]
			<< " with id " << this->id;
	}

	void getEmployeeName() {
		cout << endl << this->name[2]
			<< " " << this->name[1]
			<< " " << this->name[0];
	}
};

int main()
{
	//Computer c1("Dell", "Intel I7");
	//Person p1("Popescu", "", "Alex", 22);
	
	//ActiveDirectorItem item;

	//use an abstract class like a pointer type

	Person p1("Popescu", "", "Ion", 21);
	Person p2("Gates", "John", "Bill", 21);

	ActiveDirectoryItem *pItem = NULL;
	ActiveDirectoryItem **items =
		new ActiveDirectoryItem*[4];
	items[0] = &p1;
	items[1] = &p2;
	items[2] = new Computer("Dell laptop", "Intel I5");
	items[3] = new Computer("IBM Dsk", "Intel I7");

	for (int i = 0; i < 4; i++) {
		items[i]->getItemDescription();
		items[i]->getItemName();
	}

	HRItem** employees = new HRItem*[2];
	employees[0] = &p1;
	employees[1] = &p2;

	for (int i = 0; i < 2; i++) {
		employees[i]->getEmployeeName();
	}
}

