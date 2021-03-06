// ProjectLaborator14.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>

using namespace std;

#define NR_ELEMENTE 3
#define SUMA(X,Y) X+Y

#define NO_VERSIUNE_STATICA

int max(int* v, int n) {
	if (v != NULL && n > 0) {
		int maxim = v[0];
		for (int i = 1; i < n; i++)
			if (maxim < v[i])
				maxim = v[i];
		return maxim;
	}
	else
		throw new exception();
}


int main()
{
#ifdef VERSIUNE_STATICA
	int valori[NR_ELEMENTE];
	valori[0] = 1;
	valori[1] = 67;
	valori[2] = 5;

#else
	int *valori = new int[NR_ELEMENTE];
	valori[0] = 10;
	valori[1] = 670;
	valori[2] = 50;

#endif // VERSIUNE_STATICA

	cout << endl << "Maximul este " <<
		max(valori, 3);

	int vb1 = 10;
	int vb2 = 20;
	int rezultat = SUMA(vb1, vb2)+10;
	//int rezultat = vb1 + vb2+10;
	//+100;

	cout << endl << "Rezultat: " << rezultat;

#ifndef VERSIUNE_STATICA
	cout << endl << "A fost varianta dinamica";
#endif

	//exemple STL
	string nume;
	nume = "Popescu";
	nume = nume + " Alexandru";
	//nume = "Ioana";

	cout << endl << " Numele este " << nume;

	//list: vector, list, queue, stack
	vector<int> vectorValori;
	vectorValori.push_back(10);
	vectorValori.push_back(10);
	vectorValori.push_back(20);
	vectorValori.push_back(30);

	vectorValori.push_back(40);
	vectorValori.pop_back();
	vectorValori[0] = 99;

	cout << endl << "Valorile sunt:";
	for (int i = 0; i < vectorValori.size(); i++)
		cout << " " << vectorValori[i];

	//obtin iterator pentru vector
	vector<int>::iterator it =
		vectorValori.begin();

	cout << endl << "Valorile sunt:";
	while (it != vectorValori.end()) {
		cout << " " << *it;
		it++;
	}

	it = vectorValori.begin();
	cout << endl << "Valorile sunt:";
	for (;it!=vectorValori.end();++it) {
		cout << " " << *it;
	}


	set<string> setNume;
	setNume.insert("Alin");
	setNume.insert("Alin");
	setNume.insert("Ion");
	setNume.insert("Bianca");

	cout << endl << "Lista de nume este ";
	set<string>::iterator itNume =
		setNume.begin();
	for (; itNume != setNume.end(); ++itNume) {
		cout << " " << *itNume;
	}

	map<int, string> studenti;
	studenti.insert(make_pair(1, "Gigel"));
	studenti.insert(make_pair(1, "Alin"));
	studenti.insert(make_pair(20, "Ion"));
	studenti.insert(make_pair(56, "Bianca"));
	studenti[78] = "Alex";

	cout << endl << "Numele studentului/studentei cu "
		<< "numarul matricol 1 este "
		<< studenti[1];


	list<int> listaValori;
	listaValori.sort();






    return 0;
}

