// ProjectLaborator12.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

//clasa abstracta

class Salariat {
public:
	virtual float getSalariu()=0;
};

//definire clasa abstracta
class ResursaInformatica {
protected:
	int id;
	static int generatorId;
public:
	virtual void getDescriere() = 0;
	virtual int getId() {
		return this->id;
	}

	ResursaInformatica() {
		this->id = ++ResursaInformatica::generatorId;
	}
};

int ResursaInformatica::generatorId = 0;

class Util {
public:
	static char* alocareString(const char* valoare) {
		char* sir = new char[strlen(valoare) + 1];
		strcpy(sir, valoare);
		return sir;
	}


};

class Persoana:public ResursaInformatica,public Salariat {
	char* nume[3];
	//char nume[3][50];
	int varsta;
public:
	Persoana() {
		this->nume[0] = Util::alocareString("Nume familie");
		this->nume[1] = Util::alocareString("Initiala");
		this->nume[2] = Util::alocareString("Prenume");
		this->varsta = 0;
	}
	Persoana(const char* NumeFamilie,
		const char* Initiala, const char* Prenume, int Varsta) {
		this->nume[0] = Util::alocareString(NumeFamilie);
		this->nume[1] = Util::alocareString(Initiala);
		this->nume[2] = Util::alocareString(Prenume);
		this->varsta = Varsta;
	}

	//TO DO
	//implementare constructor de copiere si operator =

	~Persoana() {
		delete [] this->nume[0];
		delete [] this->nume[1];
		delete [] this->nume[2];
	}

	void afisare() {
		cout << endl << this->nume[0] 
			<<" "<<this->nume[1]
			<<" "<<this->nume[2]<< " are varsta " << this->varsta;
	}

	//supradefinire metoda pura din parinte
	void getDescriere() {
		cout << endl << this->nume[0] << "." << this->nume[2] 
			<< " - are id " << this->id;
	}

	float getSalariu() {
		return 0;
	}

	int getId() {
		//apel versiune din parinte
		this->ResursaInformatica::getId();
		return this->id;
	}
};

class Computer:public ResursaInformatica {
	char model[50];
public:
	Computer(const char* Model) {
		strcpy(this->model, Model);
	}
	//supradefinire metoda pura din parinte
	void getDescriere() {
		cout << endl << this->model << " - are id " << this->id;
	}
};


int main()
{
	//ResursaInformatica ri;
	ResursaInformatica *pResursa;	//utilizarea unei clase abstracte ca tip pointer

	Persoana p1("Popescu", "A.", "Gigel", 22);
	p1.afisare();
	Computer c1("Dell I7");

	ResursaInformatica* resurseIT[4];
	resurseIT[0] = &p1;
	resurseIT[1] = &c1;
	resurseIT[2] = new Persoana("Ionescu", "Z.", "Alina", 22);
	resurseIT[3] = new Computer("Lenovo Z5");

	for (int i = 0; i < 4; i++)
		resurseIT[i]->getDescriere();


	const char* v = "Gigel#3#9#9#10#CSIE";
	char * testCSV = Util::alocareString(v);

	char buffer[1000];
	strcpy(buffer, v);

	char* valoare = strtok(buffer, "#");
	cout << endl << "Prima valoare " << valoare;
	while (valoare = strtok(NULL, "#")) {
		cout << endl << "valoare " << valoare;
	}


}

