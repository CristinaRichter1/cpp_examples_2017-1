#include <stdio.h>

void printArray(int* vector, int noElements);

void main() {

	//variables
	int vb1 = 0;
	char c;

	//arrays
	//static aproach
	int values[10];
	int noElements = 10;

	int values2[5];
	int noElements2 = 5;

	//values2 = values;

	//increase the number of values in values2
	noElements2 = noElements2 + 5;

	values2[8] = 99;

	values2[10] = 0x0000000D;

	printf("\n Value = %d", vb1);
	printArray(values, noElements);
	printArray(values2, noElements2);


	//dynamic
	int * values3;
	int noElements3 = 10;
	values3 = new int[noElements3];
	values3[0] = 10;
	delete[] values3;

	values3 = new int[noElements3];
	values3[0] = 10;
	int* values4 = new int[5];
	values4[0] = 99;

	values3 = values4;
	values3[0] = 55;

	printArray(values3, noElements3);
	printArray(values4, 5);

	//if (values3 != NULL)
	//	printf("Points to nothing");
	//else
	//	printf("It's ok");

}

void printArray(int* vector, int noElements) {
	printf("\n Values =");

	for (int i = 0; i < noElements; i++) {
		printf(" %d", vector[i]);
	}
	
}
