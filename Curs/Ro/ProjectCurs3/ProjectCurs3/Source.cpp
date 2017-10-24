#include <stdio.h>
#include <iostream>
using namespace std;


void interschimbare(int a, int b);
void interschimbare2(int* pa, int* pb);
void interschimbare3(int* pa, int* pb);
void interschimbare4(int& a, int& b);

void main() {
	int vb1 = 10;
	int vb2 = 20;

	std::cout <<endl<< " vb1 = " << vb1 << " vb2 = " << vb2;

	//interschimbare
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;

	cout << "\n vb1 = " << vb1 << " vb2 = " << vb2;

	interschimbare4(vb1, vb2);

	cout << "\n vb1 = " << vb1 << " vb2 = " << vb2;
}

void interschimbare(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interschimbare2(int* pa, int* pb) {
	int temp = (int)pa;
	pa = pb;
	pb = (int*)temp;
}


void interschimbare3(int* pa, int* pb) {
	int temp =  *pa;
	*pa = *pb;
	*pb =  temp;
}

void interschimbare4(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}