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

	int* getPoints() {
		return this->points;
	}

	int getNoPoints() {
		return this->noPayments;
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


	//postincrementation
	FidelityCard operator++(int) {
		FidelityCard copy = *this;
		for (int i = 0; i < this->noPayments; i++)
			this->points[i] += 5;
		return copy;
	}

	//preincrementation
	FidelityCard operator++(){
		for (int i = 0; i < this->noPayments; i++)
			this->points[i] += 5;
		return *this;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->noPayments) {
			return this->points[index];
		}
		else
			throw exception();
	}

	bool operator!() {
		int sum = 0;
		for (int i = 0; i < this->noPayments; i++)
			sum += this->points[i];
		if (sum < 100)
			return false;
		else
			return true;
	}

	//friend void operator>>(istream& console, FidelityCard& card);

};

ostream& operator<<(ostream& console, FidelityCard& card) {
	console << endl << "Name " << card.getOwner();
	int* points = card.getPoints();
	if (card.getPoints() != NULL) {
		console << endl << "Total points ";
		int sum = 0;
		for (int i = 0; i < card.getNoPoints(); i++)
			//sum += card.getPoints()[i];
			sum += points[i];
		console << sum;
	}

	return console;
}

void operator>>(istream& console, FidelityCard& card) {
	cout << endl << "The new owner:";
	char buffer[100];
	console >> buffer;
	card.setOwner(buffer);

	cout << endl << "New number of payments:";
	int noPayments;
	console >> noPayments;
	int* payments = new int[noPayments];
	for (int i = 0; i < noPayments; i++) {
		cout << endl << "Points for payment " << i + 1 << ": ";
		console >> payments[i];
	}

	card.setPoints(payments, noPayments);
}

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

	cout << card1 << card2;	//ostream operator<<(ostream,FidelityCard)
	cin >> card1; //void operator>>(istream,FidelityCard)
	cout << card1;

	FidelityCard card3("Empty");

	//operator++(Student)
	card3 = card1++; //increment all points by 5
	card2 = ++card1;

	cout << endl << "After ++ opertor";
	cout << card1 << card2 << card3;

	int firstPayment = card1[0]; //int operator[](FidelityCard,int)
	card1[0] = 100;
	cout << endl << "After index opertor";
	cout << card1;

	if (!card1) //less points than 100 bool operator!(Student)
		cout << endl << "Is not a premium client";
	else
		cout << endl << "Is a premium client";

	//if (card1 > card2)
	//	cout << endl << card1.getOwner() << " has more points";
	//else
	//	cout << endl << card2.getOwner() 
	//	<< " has more points or the same";

}