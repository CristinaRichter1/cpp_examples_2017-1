#include <stdio.h>

void main() {

	int vector[5];
	int vector2[10];

	vector2[11] = 99;
	vector2[12] = 99;
	vector2[13] = 99;
	vector2[14] = 99;

	int a = 10;
	int b = 20;
	//printf("a = %d and b = %x");
	printf("a = %d and b = %x",a,b);


	
		int z = 10;
	
	void *pointer;
	int *pointer_int;

	pointer_int = (int*)a;

	int c = *pointer_int;

	printf("\n c = %d", c);
}