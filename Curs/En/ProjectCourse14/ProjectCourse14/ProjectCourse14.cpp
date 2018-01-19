// ProjectCourse14.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main()
{


#define VERSION1 1

#ifdef VERSION1

	cout << endl << "Version 1 of the solution";
	cout << endl << "Using vectors";
#else
	cout << endl << "Version 2 of the solution";
	cout << endl << "Using lists";

#endif // VERSION1


	//char * name;

	string Name;
	Name = "John";
	Name = Name + " Doe ";
	cout << endl << "The name is :" << Name;

	Name = "Alice";
	string Name2 = Name;

	cout << endl << "The name is :" << Name2;

	int * values;
	int n;

	vector<int> values2;
	values2.push_back(10);
	values2.push_back(20);
	values2.push_back(30);

	cout << endl << "Vector values:";
	for (int i = 0; i < values2.size(); i++)
		cout << " " << values2[i];
	values2.clear();
	cout << endl << "Vector values:";
	for (int i = 0; i < values2.size(); i++)
		cout << " " << values2[i];

	map<int, string> students;
	students.insert(make_pair<int, string>(1, "John"));
	students.insert(make_pair<int, string>(25, "Alice"));
	students.insert(make_pair<int, string>(23, "Bob"));

	string studentName = students[23];
	if (!studentName.empty())
		cout << "The student is " << studentName;
}

