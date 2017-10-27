#include <iostream>
using namespace std;

void afisareVector(int* v, int n) {
	cout << endl << "Valori:";
	for (int i = 0; i < n; i++)
		cout << " " << v[i];
}

void initVector(int* v, int n, int valoare) {
	for (int i = 0; i < n; i++)
		v[i] = valoare;
}

//void redimensionareVector(int* v, int n, 
//	int dimensiuneNoua) {
//	int *nou = new int[dimensiuneNoua];
//	if (dimensiuneNoua < n) {
//		for (int i = 0; i < dimensiuneNoua; i++)
//			nou[i] = v[i];
//	}
//	else
//		for(int i=0;i<n;i++)
//			nou[i] = v[i];
//	delete [] v;
//
//}

int* redimensionareVector(int* v, int n,
	int dimensiuneNoua) {
	int *nou = new int[dimensiuneNoua];
	if (dimensiuneNoua < n) {
		for (int i = 0; i < dimensiuneNoua; i++)
			nou[i] = v[i];
	}
	else
		for (int i = 0; i<n; i++)
			nou[i] = v[i];
	delete [] v;
	return nou;
}

void redimensionareVector2(int** v, int n,
	int dimensiuneNoua) {
	int *nou = new int[dimensiuneNoua];
	if (dimensiuneNoua < n) {
		for (int i = 0; i < dimensiuneNoua; i++)
			nou[i] = (*v)[i];
	}
	else
		for (int i = 0; i<n; i++)
			nou[i] = (*v)[i];
	delete [] *v;
	*v = nou;
}

void redimensionareVector3(int*& v, int n,
	int dimensiuneNoua) {
	int *nou = new int[dimensiuneNoua];
	if (dimensiuneNoua < n) {
		for (int i = 0; i < dimensiuneNoua; i++)
			nou[i] = v[i];
	}
	else
		for (int i = 0; i<n; i++)
			nou[i] = v[i];
	delete [] v;
	v = nou;
}

void main() {
	int vector1 [] = { 1,2,3 };
	int* vector2 = new int[3] {1, 2, 3};

	afisareVector(vector1, 3);
	afisareVector(vector2, 3);

	//vector1 = new int[5]; - NU se poate
	//vector2 = new int[5];

	//initVector(vector1, 3, 10);
	//initVector(vector2, 3, 5);

	//redimensionareVector(vector1, 3, 2);
	//vector2 = redimensionareVector(vector2, 3, 5);
	//redimensionareVector2(&vector2, 3, 5);

	redimensionareVector3(vector2, 3, 5);
	//afisareVector(vector1, 2);
	afisareVector(vector2, 5);
}