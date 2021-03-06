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
	BonusCard(BonusCard& existing) {

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
		this->setPoints(card.points, card.nrPayments);
		//return card;
		return *this;
	}


	//overload ++ - postincrementation
	BonusCard operator++(int) {
		BonusCard copy = *this;
		for (int i = 0; i < this->nrPayments; i++)
			this->points[i] += 5;
		return copy;
	}

	// ++ - preincrementation
	BonusCard operator++() {
		for (int i = 0; i < this->nrPayments; i++)
			this->points[i] += 5;
		return *this;
	}

	int& operator[](int index) {
		if (index < this->nrPayments && index >= 0)
			return this->points[index];
		else
			throw exception();
	}

	friend void operator<<(ostream& console, const BonusCard& card);

};


istream& operator>>(istream& console, BonusCard& card) {
	cout << endl<<"The owner is ";
	char buffer[100];
	console >> buffer;
	card.setOwner(buffer);
	int noPayments;
	cout << endl << "Insert number of payments: ";
	console >> noPayments;
	int* points = new int[noPayments];
	for (int i = 0; i < noPayments; i++) {
		cout << endl << "Points for payment " << i + 1 << ": ";
		console >> points[i];
	}
	card.setPoints(points, noPayments);
	delete [] points;
	return console;
}


void operator<<(ostream& console, const BonusCard& card) {
	console << endl << "The card owner is " <<
		card.owner;
	if (card.points != NULL) {
		console << endl << "Points:";
		int sum = 0;
		for (int i = 0; i < card.nrPayments; i++)
			sum += card.points[i];
		console << sum;
	}
}

void doSomething(int* v) {
	cout << endl << sizeof(v);
}

void main() {

	int* results = new int[4] {1, 2, 3, 4};
	int staticResults[] = { 1,2,3,4 };
	int n = 4;

	int* newArray = new int[sizeof(results) / sizeof(int)];

	cout << endl << sizeof(results);
	cout << endl << sizeof(staticResults);

	doSomething(staticResults);


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
	clonedCard.setPoints(values2, 3);

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


	//overload operators

	BonusCard newCard("John Doe");
	cin >> newCard >> copy; //operator>>(istream, BonusCard)
	cout << newCard; //operator<<(ostream,BonusCard)

	int vb1 = 10;
	int vb2 = vb1++;
	int vb3 = ++vb1;


	//increment all the points by 5 ++
	BonusCard clone1 = newCard++; //operator++(BonusCard)

	cout << "post" << endl << clone1;

	BonusCard clone2 = ++newCard; //operator++(BonusCard)

	cout << "pre" << endl << clone2;


	//newCard["Alice"];
	int secondPaymentPoints = newCard[1]; //operator[](BonusCard, int)
	newCard[1] = 100;

	//if (newCard > clone1)
	//	cout << endl << "has more points";
	//else
	//	cout << endl << "has less points or the same amount";

	//if (!newCard)
	//	cout << endl << "It has more than 100 points";

	//int bonusPoints = newCard(300); //function operator


}