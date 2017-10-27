#include<iostream>
using namespace std;

class Student{
private:
	char* nume;
	char facultate[10];
	int* note;
	int nrNote;
	char gen;
public:
	char* getNume(){
		return this->nume;
	}
	
	//constructor default
	Student(){
		cout<<endl<<"Constructor implicit";
		this->nume = 
			new char[strlen("Anonim")+1];
		strcpy(this->nume,"Anonim");
		strcpy(this->facultate,"ASE");
		this->note = NULL;
		this->nrNote = 0;
		this->gen = 78;//'N'
	}
	
	//constructor cu parametri
	Student(char* nume,char* facultate, char gen){
		//shadowing
		//gen = gen;
		this->gen = gen;
		this->nume = new char[strlen(nume)+1];
		strcpy(this->nume,nume);
		strcpy(this->facultate,facultate);
		this->note = NULL;
		this->nrNote = 0;
	}
	void afisare(){
		cout<<endl<<"Nume:"<<this->nume;
		cout<<endl<<"Facultate:"<<this->facultate;
		cout<<endl<<"Gen:"<<this->gen;
		if(this->note!=NULL){
			cout<<endl<<"Note:";
			for(int i=0;i<this->nrNote;i++)
				cout<<" "<<this->note[i];
		}
	}
	
	void adaugaNota(int nota){
		int* noteNoi = new int[this->nrNote+1];
		for(int i =0;i<this->nrNote;i++)
			noteNoi[i] = this->note[i];
		noteNoi[this->nrNote] = nota;
		delete[] this->note;
		this->note = noteNoi;
		this->nrNote+=1;
		
	}
};

void main(){
	Student student;
	//cout<<endl<<"A fost creat "<<
	//student.nume;
	cout<<endl<<"A fost creat "<<
	student.getNume();
	student.afisare();
	Student student2("Gigel","CSIE",'M');
	student2.adaugaNota(9);
	student2.adaugaNota(10);
	student2.adaugaNota(8);
	student2.afisare();
}



