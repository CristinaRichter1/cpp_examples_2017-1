#include<iostream>
using namespace std;

void main() {
	cout << endl << sizeof(unsigned int);

	int values[10];
	printf("\n Size = %d", sizeof(values));	printf("\n %d", values[0]);
	printf("\n %x", values[9]);	printf("\n %x", values[10]);	//printf("\n %x", values[11000]);	char* cuvant = "abecedar";
	char* cuvant2;
	int *v;
	char cuvant3[20];	cuvant3[0] = 't';
	cuvant3[1] = 'e';
	cuvant3[2] = 's';
	cuvant3[3] = 't';
	cuvant3[4] = '\0';
	printf("\n %s", cuvant3);	cuvant2 = cuvant;
	cuvant2[1] = 'A';
}