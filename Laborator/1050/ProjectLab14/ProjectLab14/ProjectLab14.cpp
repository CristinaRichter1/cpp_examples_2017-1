// ProjectLab14.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;

#define SUM(X,Y) X+Y
#define NMAX 100
#define NO_DEBUG

int sumF(int a, int b) {
	return a + b;
}

int main()
{
	int array[NMAX];

	int vb1 = 10;
	int vb2 = 20;
	int sum = vb1 + vb2;
#ifdef DO_DEBUG
	cout << endl << "Computing the sum";
#endif // DO_DEBUG

	sum = SUM(vb1, vb2);
	sum = SUM(vb1, vb2)+10; //vb1+vb2+10;

	+45;

	cout << endl << "The result is " << sum;

	//use STL
	//vector of prices
	vector<float> prices;
	prices.push_back(23.5);
	prices.push_back(2.5);
	prices.push_back(67.4);
	prices.push_back(67.4);

	prices[0] = 100;

	cout << endl << "Prices are:";
	for (int i = 0; i < prices.size(); i++)
		cout << " " << prices[i];

	vector<float>::iterator it = prices.begin();
	while (it != prices.end()) {
		cout << endl << "current value is " << *it;
		++it;
	}

	cout << endl << "A different aproach";
	for (vector<float>::iterator it = prices.begin();
		it != prices.end(); it++) {
		cout << endl << "current value is " << *it;
	}


	//int vb = 10;

	//{
	//	int vb = 100;
	//}

	//set
	set<string> names;
	names.insert("John");
	names.insert("John");
	names.insert("Alice");
	names.insert("Bob");

	cout << endl << "The no of names is " << names.size();

	set<string>::iterator itNames = names.begin();
	for (;itNames!=names.end();itNames++) {
		cout << " " << *itNames;
	}

	map<string, float> products;
	products.insert(make_pair("Pepsi", 2.5));
	products.insert(make_pair("Fanta", 2.7));
	products.insert(make_pair("Water", 3));

	float price = products["Pepsi"];
	cout << endl << "The price is " << price;

    return 0;
}

