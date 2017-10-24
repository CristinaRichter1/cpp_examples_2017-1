#include <stdio.h>
#include <iostream>
using namespace std;

void afisareVector(int* vector, int nr);

//NU FACETI ASA
int* creareVector() {
	int vector[10];
	int n;
	cout << endl << "Numar elemente:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << endl << "Valoare " << i << ": ";
		cin >> vector[i];
	}
	return vector;
}

//nu e ok
int* creareVector2() {
	int *vector;
	int n;
	
	cout << endl << "Numar elemente:";
	cin >> n;
	vector = new int[n];
	for (int i = 0; i < n; i++) {
		cout << endl << "Valoare " << i << ": ";
		cin >> vector[i];
	}
	return vector;
}

int* creareVector3() {
	int *vector;
	int n;

	cout << endl << "Numar elemente:";
	cin >> n;
	vector = new int[n];
	for (int i = 0; i < n; i++) {
		cout << endl << "Valoare " << i << ": ";
		cin >> vector[i];
	}
	return vector;
}

void interschimbare(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void main() {

	int* valori;
	int n = 10;

	//valori = creareVector2();
	//afisareVector(valori, n);

	int vb1 = 10;
	int vb2 = 20;
	cout << endl << vb1 << " --- " << vb2;
	interschimbare(vb1, vb2);
	cout << endl << vb1 << " --- " << vb2;
}

void afisareVector(int* vector, int nr) {
	std::cout << std::endl<< "Valori: ";
	for (int i = 0; i < nr; i++)
		cout << " " << vector[i];
}