#include <stdio.h>

void main() {
	printf("hello world !");

	int a = 10;
	int b = 20;
	int c = 0x11;
	int d = 11;

	printf("a = %d, b = %x, c = %d",a,b,c);

	int *pointer;
	char* caracter;
	void *pointer_generic;

	pointer = (int*)a;

	int z = *pointer;

	printf("%d", z);
}