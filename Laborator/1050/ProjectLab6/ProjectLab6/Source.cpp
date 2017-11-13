#include <iostream>
using namespace std;


class BonusCard {
	char owner[50];
	int* points;
	int nrPayments;
public:
	BonusCard(char* name) {
		strcpy(owner, name);
		this->nrPayments = 0;
		this->points = NULL;
	}

	void display() {
		cout << endl << "The card owner is " <<
			this->owner;
		if (this->points != NULL) {
			cout << endl << "Points:";
			int sum = 0;
			for (int i = 0; i < this->nrPayments; i++)
				sum += this->points[i];
			cout << sum;
		}
	}

	//public interface
	void setOwner(const char* name) {
		if (strlen(name) >= 3) {
			strcpy(this->owner, name);
		}
		else
			throw exception();
	}

	void setPoints(int* points, int n) {
		if (this->points != NULL)
			delete [] this->points;
		this->points = new int[n];
		for (int i = 0; i < n; i++)
			this->points[i] = points[i];
		this->nrPayments = n;
	}

	//copy constructor
	BonusCard(const BonusCard& existing) {

		this->setOwner(existing.owner);
		//strcpy(this->owner, existing.owner);
		this->points = NULL;
		this->setPoints(existing.points, 
			existing.nrPayments);
	}

	~BonusCard() {
		delete [] this->points;
	}

	BonusCard operator=(BonusCard& card) {
		this->setOwner(card.owner);
		this->setPoints(card.points,card.nrPayments);
		//return card;
		return *this;
	}

};

void main() {
	BonusCard bc1("Alice");
	BonusCard bc2("Bob");
	bc1.display();
	bc2.display();

	bc2.setOwner("John");
	int values [] = { 1,2,3,4,5 };
	bc1.setPoints(values, 5);

	bc1.display();
	bc2.display();

	BonusCard clonedCard = bc1;

	clonedCard.setOwner("Vader");

	bc1.display();
	clonedCard.display();

	int values2 [] = { 999,999,999 };
	clonedCard.setPoints(values2,3);

	bc1.display();
	clonedCard.display();

	//for (;;) {
	//	BonusCard * pCard = new BonusCard("Test");
	//	pCard->setPoints(values, 5);
	//	delete pCard;
	//}

	BonusCard copy("Alice copy");
	copy = bc1;
	bc2 = copy = bc1;
	//copy.operator=(bc1);



}