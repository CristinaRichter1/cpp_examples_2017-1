// ProjectCurs13.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

class VarstaPreaMareException : public exception {

};
class VarstaNegativaException :public exception {
public:
	VarstaNegativaException(const char* mesaj):exception(mesaj) {
	}
};

class VarstaMinorException : public exception {

};

class Student {
	int varsta;
	char* nume;
public:
	Student(int Varsta) {
		if (Varsta < 0)
			throw new VarstaNegativaException("Varsta negativa");
		if (Varsta > 80)
			throw new VarstaPreaMareException();
		if (Varsta < 14)
			throw new VarstaMinorException();
		this->varsta = Varsta;
		if (Varsta == 18)
			throw exception("Varsta speciala");

	}

	int getVarsta() {
		return this->varsta;
	}
};

class Cutie {
	int greutate;
	void *continut;
public:
	Cutie(int Greutate, void * Continut) {
		this->greutate = Greutate;
		this->continut = Continut;
	}
	void* getContinut() {
		return this->continut;
	}
};

class Frigider {

};

 
int main()
{
	while (true) {
		try {
			cout << endl << "Varsta student:";
			int varsta;
			cin >> varsta;
			Student s1(varsta);
			cout << endl << "Date student citite";

			Frigider f;

			Cutie c1(60, &f);

			//destinatie
			Student *ps = (Student*)c1.getContinut();
			cout << endl << "Varsta student " <<
				ps->getVarsta();

			break;
		}

		catch (VarstaNegativaException* e) {
			cout << endl << "Varsta este negativa. Reintroduceti valoarea";
		}
		catch (VarstaPreaMareException* e) {
			cout << endl << "Varsta este > 80. Reintroduceti valoarea";
		}
		catch (exception* e) {
			cout << endl << "Eroare introducere date: "
				<< e->what();
		}
		catch (...) {
			cout << endl << "Eroare generica !";
		}

	}
	cout << endl << "Sfarsit";
}

