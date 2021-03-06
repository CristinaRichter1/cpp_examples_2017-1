// ProjectLab14.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

//define a macro symbol
#define STATIC_VER
#define MAX 3
#define SUM(X,Y) X+Y

int min(int* v, int n) {
	if (v != NULL && n > 0) {
		int minimum = v[0];
		for (int i = 1; i < n; i++)
			if (minimum > v[i])
				minimum = v[i];
		return minimum;
	}
	throw new exception();
}

void test(float vb) {

}


template <typename T,typename R>
class Box {
	float price;
	T content;
	R color;
public:
	Box(T Content, R Color, float Price) {
		this->price = Price;
		this->content = Content;
		this->color = Color;
	}

	void display() {
		cout << endl << "Box color " << this->color;
		cout << endl << "Box price " << this->price;
		cout << endl << "Box content " << this->content;
	}
};

int main()
{

#ifdef STATIC_VER
	int array[MAX];
	array[0] = 5;
	array[1] = 1;
	array[2] = 50;
#else
	int *array = new int[MAX];
	array[0] = 50;
	array[1] = 10;
	array[2] = 500;
#endif // DEBUG
	cout << endl << "The minimum is "
		<< min(array, 3);

	int vb1 = 10;
	int vb2 = 20;

	int result = SUM(vb1, vb2);
	//int result = vb1 + vb2;

#ifdef STATIC_VER
	cout << endl << "The static version was used";
#endif


	//STL
	string name = "John";
	cout << endl << "The name is " << name;
	name = name + " Doe";
	name = "Alice";

	//lists: list, vector, queue, stack 
	//vector<int> values(10);
	vector<int> values;
	values.push_back(10);
	values.push_back(20);
	values.push_back(10);
	values.push_back(40);

	values.pop_back();

	cout << endl << "The size of the vector is "
		<< values.size();

	cout << endl << "The vector values are: ";
	for (int i = 0; i < values.size(); i++)
		cout << " " << values[i];

	vector<int>::iterator it;
	it = values.begin();
	while (it != values.end()) {
		cout << endl << "Current value " << *it;
		it++;
	}

	it = values.begin();
	for (;it!=values.end();++it) {
		cout << endl << "Current value " << *it;
	}

	for (vector<int>::iterator iter = values.begin();
		iter != values.end(); ++iter) {
		cout << endl << "Current value " << *iter;
	}

	//SETs;
	set<string> names;
	names.insert("John");
	names.insert("John");
	names.insert("John");
	names.insert("Alice");

	cout << endl << "Names: ";

	set<string>::iterator et = names.begin();
	for (; et != names.end(); et++)
		cout << " " << *et;

	//map
	float vb = 100.0f;
	vb += 56.7888f;
	test(56.88888f);

	map<string,float> persons;
	persons.insert(make_pair("John",1900.0));
	persons.insert(make_pair("John", 2900.0));
	persons.insert(make_pair("Alice", 900.0));
	persons.insert(make_pair("Bob", 800.0));

	persons["Vader"] = 999.9;

	float JohnSalary = persons["Vader"];
	cout << endl << "John's salary is "
		<< JohnSalary;


	//template class
	Box<string, string> box1("toy", "blue", 123);
	Box<string, const char*> box1("toy", "blue", 123);

    return 0;
}

