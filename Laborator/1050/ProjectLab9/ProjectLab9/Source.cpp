#include <iostream>
#include <fstream>
using namespace std;

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
	
	BonusCard() {
		this->points = NULL;
		*this = BonusCard("John Doe");
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

		if (this == &card) {
			return *this;
		}

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

	//functions used to serialize a BonusCard into a binary filre
	void write2File(ofstream& file) {
		if (file.is_open()) {
			//write the name
			file.write(this->owner, sizeof(BonusCard::owner));
			//write number of points
			file.write((char*) &this->nrPayments, sizeof(int));
			for (int i = 0; i < this->nrPayments; i++)
				file.write((char*) &this->points[i], sizeof(int));
		}
		else
			throw exception();
	}

	friend void operator<<(ostream& console, const BonusCard& card);

};


istream& operator>>(istream& console, BonusCard& card) {
	cout << endl << "The owner is ";
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


class OnlineStore {
public:
	BonusCard *clientCards;
	int noClients;
public:
	OnlineStore() {
		this->clientCards = NULL;
		this->noClients = 0;
	}

	~OnlineStore() {
		delete [] clientCards;
	}

	OnlineStore(OnlineStore& store) {
		this->clientCards = new BonusCard[store.noClients];
		for (int i = 0; i < store.noClients; i++)
			this->clientCards[i] = store.clientCards[i];
		this->noClients = store.noClients;
	}

	void operator=(OnlineStore& store) {
		if (this == &store) {
			return;
		}

		delete [] this->clientCards;
		this->clientCards = new BonusCard[store.noClients];
		for (int i = 0; i < store.noClients; i++)
			this->clientCards[i] = store.clientCards[i];
		this->noClients = store.noClients;
	}

	void registerNewClient(char* clientName) {
		BonusCard clientCard(clientName);
		BonusCard *newList = new BonusCard[this->noClients + 1];
		for (int i = 0; i < this->noClients; i++)
			newList[i] = this->clientCards[i];
		newList[this->noClients] = clientCard;
		delete [] this->clientCards;
		this->clientCards = newList;
		this->noClients += 1;
	}

	void generateReport(char* reportName) {
		ofstream report;
		report.open(reportName, ios::out | ios::trunc);
		if (report.is_open()) {
			report << "\t\t Current list of clients";
			report << *this;
		}
		report.close();
	}

	void saveData(char* fileName) {
		ofstream file;
		file.open(fileName, 
			ios::out | ios::trunc | ios::binary);
		if (file.is_open()) {
			//write the number of clients
			file.write((char*)&(this->noClients),
				sizeof(int));
			//write the objects
			for (int i = 0; i < this->noClients; i++)
				this->clientCards[i].write2File(file);
		}
		file.close();
	}

	//deserialization
	void loadData(char* fileName) {
		ifstream inputFile;
		inputFile.open(fileName, ios::in | ios::binary);
		if (inputFile.is_open()) {
			//read number of clients
			inputFile.read((char*) &this->noClients, sizeof(int));
			//create the clients array
			delete [] this->clientCards;
			this->clientCards = new BonusCard[this->noClients];
			//read the clients data
			for (int i = 0; i < this->noClients; i++) {
				//use the BonusCard public interface
				//other option - implement a specific method in BonusCard
				char nameBuffer[50];
				inputFile.read(nameBuffer, sizeof(nameBuffer));
				int noPoints;
				inputFile.read((char*) &noPoints, sizeof(int));
				int* points = new int[noPoints];
				for (int j = 0; j < noPoints; j++)
					inputFile.read((char*) &points[j], sizeof(int));
				this->clientCards[i].setOwner(nameBuffer);
				this->clientCards[i].setPoints(points, noPoints);
			}
			inputFile.close();
		}
	}

	void loadTextData(char* fileName) {
		ifstream inputFile;
		inputFile.open(fileName, ios::in);
		if (inputFile.is_open()) {
			//read number of clients
			inputFile>>this->noClients;
			//create the clients array
			delete [] this->clientCards;
			this->clientCards = new BonusCard[this->noClients];
			//read the clients data
			for (int i = 0; i < this->noClients; i++) {
				//use the BonusCard public interface
				//other option - implement a specific method in BonusCard
				char nameBuffer[50];
				inputFile>>nameBuffer;
				int noPoints;
				inputFile>>noPoints;
				int* points = new int[noPoints];
				for (int j = 0; j < noPoints; j++)
					inputFile>>points[j];
				this->clientCards[i].setOwner(nameBuffer);
				this->clientCards[i].setPoints(points, noPoints);
			}
			inputFile.close();
		}
	}

	friend ostream& operator<<(ostream& console, OnlineStore& store);
};

ostream& operator<<(ostream& console, OnlineStore& store) {
	console << endl << "The online store clients data is:";
	for (int i = 0; i < store.noClients; i++)
		console << endl << store.clientCards[i];
	return console;
}



void main() {
	OnlineStore store;
	//store.registerNewClient("Alice");
	//store.registerNewClient("Bob");

	//int pointsAlice [] = { 10,5,6 };
	//int pointsBob [] = { 4,9 };

	//store.clientCards[0].setPoints(pointsAlice, 3);
	//store.clientCards[1].setPoints(pointsBob, 2);

	//cout << store;

	//store.generateReport("November clients.txt");

	////serialize data
	//store.saveData("Backup.dat");

	//test load
	store.loadData("Backup.dat");
	cout << store;
	store.loadTextData("ClientsData.txt");
	cout << store;
}
