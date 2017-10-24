#include <iostream>
using namespace std;

void afisareVector(int* v, int m){
	cout<<endl<<"Valori:";
	for(int i=0;i<m;i++)
		cout<<" "<<v[i];
}

int* redefinireVector(int* v, int& pn){
	cout<<endl<<"Noua dimensiune:";
	cin>>pn;
	delete[] v;
	v = new int[pn];
	for(int i=0;i<pn;i++){
		cout<<endl<<"Valoare:";
		cin>>v[i];
	}
	return v;
}

void main(){
	cout<<endl<<"hello !";
	int* vector = new int[5];
	int n = 5;

	
	
	for(int i=0;i<n;i++)
		vector[i] = i+1;
	
	afisareVector(vector,n);
	vector = redefinireVector(vector,n);
	afisareVector(vector,n);
}

