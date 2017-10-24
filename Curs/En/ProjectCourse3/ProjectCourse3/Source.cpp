#include <stdio.h>
#include <iostream>
using namespace std;

void interchange(int a, int b);
void interchange2(int *pa, int* pb);
void interchange3(int *pa, int* pb);
void interchange4(int& a, int& b);

char* getUserName() {
	char name[100];
	cout << endl << "Your name:";
	cin >> name;
	return name;
}

char* getUserName2() {
	char buffer[1000];
	char* name;
	//create it
	//name = new char[100];
	cout << endl << "Your name:";
	cin >> buffer;
	name = new char[strlen(buffer) + 1];
	strcpy_s(name, strlen(buffer) + 1,buffer);
	return name;
}

void main() {

	int vb1, vb2;
	vb1 = 10;
	vb2 = 20;

	cout << endl<<"vb1 =" << vb1 << " vb2 = " << vb2;

	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;

	std::cout << endl<< "vb1 =" << vb1 << " vb2 = " << vb2;

	interchange3(&vb1, &vb2);

	std::cout << endl << "vb1 =" << vb1 << " vb2 = " << vb2;

	interchange4(vb1, vb2);

	std::cout << endl << "vb1 =" << vb1 << " vb2 = " << vb2;

	char* name1 = getUserName2();
	char* name2 = getUserName2();
	name1[strlen(name1)] = '\0';
	cout << endl << "Name1 =" << name1;
	cout<<endl<< " and Name2 = " << name2;
}



void interchange2(int *pa, int* pb) {
	int temp = (int)pa;
	pa = pb;
	pb = (int*)temp;
}

void interchange(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interchange3(int *pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void interchange4(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}