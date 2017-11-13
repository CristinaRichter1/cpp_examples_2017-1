#include <iostream>
using namespace std;

class FidelityCard {
	char owner[50];
	int * points;
	int noPayments;
public:
	FidelityCard(char* name) {
		if (strlen(name) < 50)
			strcpy(this->owner, name);
		else
			throw exception();
		this->points = NULL;
		this->noPayments = 0;
	}
	void display() {
		cout << endl << "Name " << this->owner;
		if (this->points != NULL) {
			cout << endl << "Total points ";
			int sum = 0;
			for (int i = 0; i < this->noPayments; i++)
				sum += this->points[i];
			cout << sum;
		}
	}

	//public interface
	char* getOwner() {
		return this->owner;
	}
	void setOwner(const char* owner) {
		//strcpy(owner,"test");
		if (strlen(owner) < 50)
			strcpy(this->owner, owner);
		else
			throw exception();
	}

	void setPoints(int * newPoints, int n) {
		if (this->points != NULL)
			delete [] this->points;
		this->points = new int[n];
		for (int i = 0; i < n; i++)
			this->points[i] = newPoints[i];
		this->noPayments = n;
	}

	//copy constructor
	FidelityCard(const FidelityCard& card) {
		this->setOwner(card.owner);
		this->points = NULL;
		this->setPoints(card.points, card.noPayments);
	}

	~FidelityCard() {
		delete [] this->points;
	}

	void operator=(FidelityCard fc) {
		this->setOwner(fc.owner);
		this->setPoints(fc.points, fc.noPayments);
	}

};

void doNothing(FidelityCard fd) {
	int values1 [] = { 5,6 };
	fd.setPoints(values1, 2);
}
void main() {
	FidelityCard card1("John");
	card1.display();

	int values1 [] = { 5,6 };
	card1.setPoints(values1, 2);

	FidelityCard card2 = card1;
	card2.display(); 

	int values [] = { 10,20,30 };
	int n = 3;

	card2.setPoints(values, n);
	card2.setOwner("Alice");

	card2.display();

	//doNothing(card1);

	card1.display();
}