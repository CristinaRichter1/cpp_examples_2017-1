// Project17Nov2017.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

class Test {
	int valori[50];
	int n;
public:
	Test() {
		for (int i = 0; i < 50; i++)
			this->valori[i] = 0;
		this->n = 0;
	}

	int getValoare(int index) {
		if (index >= 0 && index < n)
			return this->valori[index];
		else
			throw exception();
	}

	Test operator++(int) {
		Test copie = *this;
		if (n < 50) {
			n += 1;
			this->valori[n - 1] = 10;
		}
		return copie;
	}

	int& operator[](int index) {
		if (index >= 0 && index < n)
			return this->valori[index];
		else
			throw exception();
	}

	explicit operator float() {
		float medie = 0;
		for (int i = 0; i < n; i++)
			medie += valori[i];
		return medie / 3;
	}

	int operator()(int iStart, int iFinal) {
		int sumaPartiala = 0;
		for (int i = iStart; i <= iFinal;i++)
			sumaPartiala += this->valori[i];
		return sumaPartiala;
	}

	friend ostream& operator<<(ostream& consola, Test t);
	friend Test operator++(Test& test);
};

Test operator++(Test& test) {
	if (test.n < 50) {
		test.n += 1;
		test.valori[test.n - 1] = 10;
	}
	return test;
}

ostream& operator<<(ostream& consola, Test t) {
	consola << endl<<"Obiectul test este";
	for (int i = 0; i < t.n; i++)
		consola << " " << t.valori[i];
	return consola;
}

//
// operator float(Test t) {
//
//}



int main()
{
	Test t,t2;
	cout << t;

	t2 = t++; //operator++(Test)
	++t;
	t++;

	int valoare = t.getValoare(1);

	valoare = t[1];
	cout << endl << "Valoare de pe pozitia 2 este " << valoare;
	t[1] = 99;

	cout << t;


	int z = 1000 + (float)t;

	float medieValori = (float)t;
	cout << "Media este " << medieValori;

	t++;
	t++;
	t++;
	t[2] = 5;

	cout << t;
	int sumaPartialaElemente = t(1,3);	//suma elementelor cuprinse intre 1 si 3
	cout << endl << "Suma partiala " << sumaPartialaElemente;

}

