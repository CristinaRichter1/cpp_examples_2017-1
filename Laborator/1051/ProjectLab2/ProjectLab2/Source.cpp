#include <stdio.h>
#include <iostream>
using namespace std;

void printArray(int* vector, int n);

//stupid - DON'T DO IT
int* createArray() {
	int newVector[10];
	int n;
	std::cout << "give me the number of elements:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << std::endl << "Value " << i << ":";
		cin >> newVector[i];
	}
	return newVector;
}

//still not correct
int* createArray2() {
	int* newArray;
	int n;
	cout << endl<<"No of elements:";
	cin >> n;
	newArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << std::endl << "Value " << i << ":";
		cin >> newArray[i];
	}
	return newArray;
}

int* createArray3(int* no) {
	int* newArray;
	int n;
	cout << endl << "No of elements:";
	cin >> n;
	*no = n;
	newArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << std::endl << "Value " << i << ":";
		cin >> newArray[i];
	}
	return newArray;
}

void interchange(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interchange2(int* pa, int *pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}



void main() {

	int values[10];
	int n1 = 10;
	int *values2;
	int n2 = 10;

	//values2 = createArray2();
	values2 = createArray3(&n2);

	printArray(values2, n2);
	printArray(values, n1);

	int vb1 = 10;
	int vb2 = 20;
	cout << endl << vb1 << " " << vb2;
	//interchange(vb1, vb2);
	interchange2(&vb1, &vb2);
	cout << endl << vb1 << " " << vb2;

	printf("program finished");
}

void printArray(int* vector, int n) {
	printf("\n Values: ");
	for (int i = 0; i < n; i++)
		printf(" %d", vector[i]);
}