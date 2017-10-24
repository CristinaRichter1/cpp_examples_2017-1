#include <stdio.h>


void afisareVector(int *vector,
	int nrElemente);

void main() {
	printf("\n Hello world !");

	int vb1 = 10;
	char a = 10;
	char b = '0';
	//vectori
	int valori[10];
	int nr = 10;
	int valori2[20];
	int nr2 = 20;
	//nr2 = 24;

	//for (int i = 0; i < nr; i++)
	//	valori[i] = 0;
	for (int i = 0; i < nr2; i++)
		valori2[i] = 15;

	afisareVector(valori2, nr2);
 	afisareVector(valori, nr);


	//vectori definiti dinamic
	int* vectorDinamic;
	int n = 10;
	vectorDinamic = new int[n];

	n = 20;
	//genereaza memory leak-uri
	//for (;;) {
	//	vectorDinamic = new int[n];
	//}

	afisareVector(vectorDinamic, n);
}

void afisareVector(int* vector,
	int nrElemente) {
	printf("\n Valori:");
	for (int i = 0; i < nrElemente; i++)
		printf(" %d", vector[i]);
}