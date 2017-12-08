// Project8Decembrie2017.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << endl << argv[0];

	if (argc == 3) {
		cout << endl << "am primit fisier 1 " << argv[1];
		cout << endl << "am primit fisier 2 " << argv[2];
	}
	else
	{
		cout << endl << "Trebuie indicate 2 nume de fisiere";
	}

	ifstream fisierIntrare;
	fisierIntrare.open("DateIntrare.txt", ios::in);
	
	ofstream fisiereIesireText;
	fisiereIesireText.open("date.txt", ios::out);

	ofstream fisiereIesireBinar;
	fisiereIesireBinar.open("date.bin", 
		ios::out|ios::binary);

	int valoare = 4;
	char* nume = new char[6] {"Gigel"};
	float* numere = new float[3]{ 1,2,3 };

	cout << endl << valoare;
	cout << endl << nume;

	fisiereIesireText << endl << valoare;
	fisiereIesireText << endl << nume;

	//fisiereIesireBinar << valoare;
	//fisiereIesireBinar << nume;

	fisiereIesireBinar.write((char*) &valoare, 
		sizeof(int));
	fisiereIesireBinar.write(nume,
		(strlen(nume) + 1) * sizeof(char));

	char nume2[100];
	fisiereIesireBinar.write(nume2,
		sizeof(nume2));
	fisiereIesireBinar.write(nume,
		(strlen(nume2) + 1) * sizeof(char));

	////solutia 2
	////for (int i = 0; i < strlen(nume) + 1; i++) {
	////	fisiereIesireBinar.write((char*) &nume[i],
	////		sizeof(char));
	////}

	////solutia 1
	//fisiereIesireBinar.write((char*) numere,
	//	3 * sizeof(float));

	//solutia 2
	for (int i = 0; i < 3; i++) {
		fisiereIesireBinar.write((char*) &numere[i],
			sizeof(float));
	}


	fisiereIesireBinar.close();
	fisiereIesireText.close();


	ifstream fisierBinarIntrare;
	fisierBinarIntrare.open("date.bin", ios::in | ios::binary);

	if (fisierBinarIntrare.is_open()) {
		char test[100];
		fisierBinarIntrare.read((char*) &valoare, sizeof(int));
		int contor = 0;
		while (true) {
			char caracter;
			fisierBinarIntrare.read(&caracter, sizeof(char));
			test[contor] = caracter;
			contor += 1;
			if (caracter == '\0')
				break;
		}

		fisierBinarIntrare.seekg((-1)*contor, ios::cur);
		char test2[100];
		fisierBinarIntrare.read(test2, contor * sizeof(char));



		fisierBinarIntrare.close();
		cout << endl << "Numele citit este " << test;
		cout << endl << "Numele citit este " << test2;
	}
	else
		cout << endl << "Eroare deschidere fisier";

	
}

