#include <stdio.h>

void printArray(int* values, int n){
	printf("\n Values:");
	for(int i = 0;i<n;i++)
		printf(" %d",values[i]);
}

//funcion that creates a new array in heap
void createArray(int* &existing, int& n){
	printf("\n New number of elements:");
	scanf("%d",&n);
	
	if(existing!=NULL)
		delete[] existing;
	
	existing = new int[n];
	for(int i=0;i<n;i++){
		printf("\n New value:");
		scanf("%d",&existing[i]);
	}
}

//funtion that adds a new element to an existing array
void addNewValue(int*& vector, int& n, int newValue){
	int* newArray = new int[n+1];
	for(int i=0;i<n;i++)
		newArray[i] = vector[i];
	newArray[n] = newValue;
	delete[] vector;
	vector = newArray;
	n+=1;
	
}


void main(){
	printf("Hello world !");
	
	//create a new array
	int* vector = new int[5];
	int n = 5;
	for(int i =0;i<n;i++){
		vector[i] = (i+1);
	}
	printArray(vector,n);
	createArray(vector,n);
	printArray(vector,n);
	addNewValue(vector,n,10);
	addNewValue(vector,n,20);
	printArray(vector,n);
	
}