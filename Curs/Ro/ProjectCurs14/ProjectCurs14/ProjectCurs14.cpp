// ProjectCurs14.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

#define INCERC2
#define MAX 100
#define SUMA(X,Y) X+Y

int main()
{
	int vector[MAX];
	int vb1 = 10;
	int vb2 = 20;

	int suma = SUMA(vb1, vb2);
	suma = SUMA(vb1, vb2) + 30;
	//suma = vb1 + vb2; + 30;
	//+100;

#ifdef INCERC
	cout << endl << "Incerc solutie alternativa";
#else
	cout << endl << "Incerc solutie initiala";
#endif 


	cout << endl << "Suma este " << suma;
#ifdef INCERC
	cout << endl << "Sfarsit program";
#endif 
    return 0;
}

