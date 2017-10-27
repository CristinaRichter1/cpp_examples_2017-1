#include <iostream>
using namespace std;

class Student{
private:
	char* name;
	char faculty[10];
	int* grades;
	int noGrades;
	char gender;
public:
	
	Student(){
		cout<<endl<<"The default constructor";
		//this->name = new char[strlen("John"+1)];
		this->name = new char[strlen("John")+1];
		strcpy(this->name,"John");
		strcpy(this->faculty,"ASE");
		this->noGrades = 0;
		this->grades = NULL;
		this->gender = 'N';
	}
	
	Student(char* name, char* faculty, char gender){
		this->gender = gender;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		strcpy(this->faculty,faculty);
		this->noGrades = 0;
		this->grades = NULL;
	}
	
	void display(){
		cout<<endl<<"The faculty"<<this->faculty;
		cout<<endl<<"The name:"<<this->name;
		cout<<endl<<"The gender:"<<this->gender;
		if(this->grades!=NULL){
			cout<<endl<<"The grades:";
			for(int i=0;i<this->noGrades;i++)
				cout<<" "<<this->grades[i];
		}
	}

	char* getName(){
		return this->name;
	}

};

void main(){
	Student student;
	cout<<endl<<"The name is "<<
		student.getName();
	student.display();

	Student	student2("Alice","MK",'F');
	student2.display();
		
}


