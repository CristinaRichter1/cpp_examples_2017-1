#include <stdio.h>
#include <iostream>
using namespace std;

void printArray(int* vector, int no) {
	//cout << "\n The values are:";
	cout << std::endl<<" The values are:";
	for (int i = 0; i < no; i++) {
		cout << " " << vector[i];
	}
}

//stupid - DON'T do it
int* createArray(int no) {
	int bigVector[100];
	for (int i = 0; i < no; i++) {
		cout << "Values for [" << i << "] is ";
		cin >> bigVector[i];
	}
	return bigVector;  //the mistake
}

int* createArray2(int no) {
	int * newArray = new int[no];
	for (int i = 0; i < no; i++) {
		cout << "\n Values for [" << i << "] is ";
		cin >> newArray[i];
	}
	return newArray;
}

void main() {

	int* values;
	int noElements;

	//std::cout << "Give me the number of elements";
	//cin >> noElements;

	//values = new int[noElements];

	//for (int i = 0; i < noElements; i++) {
	//	cout << "Values for [" << i << "] is ";
	//	cin >> values[i];
	//}

	//printArray(values, noElements);

	int* values2 = createArray2(4);
	printArray(values2, 4);

	//shallow copy - DON'T DO IT
	int* values3 = values2; //DON'T use =
	values2[1] = 99999;
	printArray(values3, 4);

	//deep copy
	int* copy = new int[4];
	for (int i = 0; i < 4; i++)
		copy[i] = values2[i];

	delete[] values2;

	printArray(values3, 4);
	printArray(copy, 4);

	//strings
	char* name = "John";
	char* name2;
	name2 = "Alice";

	char* name3 = new char[20];
	//strcpy_s(name3,3,"Bob");
	name3[0] = 'B';
	name3[1] = 'o';
	name3[2] = 'b';
	name3[3] = '\0';

	delete[] name3;
	delete[] name2;

	cout << endl << "Name 1 " << name;
	//cout << endl << "Name 3 " << name3;
}