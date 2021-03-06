// ProjectLab13.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class WrongWeightException : public exception {
public:
	WrongWeightException(const char* msg):exception(msg) {

	}
};

class WrongPriceException :public exception {

};

class ElectronicDevice {
	float price;
	int weight;
	char name[50];
public:
	ElectronicDevice(const char* Name, float Price,
		int Weight) {
		if (Name == NULL) {
			throw new exception("The name is NULL");
		}
		if (Weight < 0) {
			throw new WrongWeightException(
				"Received Weight is negative");
		}
		if (Price < 0)
			throw new WrongPriceException();

		this->price = Price;
		this->weight = Weight;
		strcpy(this->name, Name);
	}

	char* getName() {
		return this->name;
	}
	float getPrice() {
		return this->price;
	}
};

void doSomething() {
	cout << endl << "Starting to do something";
	throw new exception("Sorry !");
}

void doSomethingSpecial() {
	cout << endl << "Starting to do something special";
	doSomething();
	cout << endl << "You got something special";
}

void doSomethingExtraordinary() {
	cout << endl << "Starting to do something extra";
	doSomethingSpecial();
	cout << endl << "You got something extra";
}

int main()
{
	ElectronicDevice fridge1("Samsung", 1000, 34);
	try {
		char buffer[100];
		cout << endl << "Insert the device name ";
		cin >> buffer;
		float price;
		cout << endl << "Insert the device price ";
		cin >> price;
		int weight;
		cout << endl << "Insert the device weight ";
		cin >> weight;

		//throw 34;

		//call stack example - exceptions management
		//doSomethingExtraordinary();

		ElectronicDevice fridge2(buffer, price, weight);
	}

	catch (WrongPriceException* e) {
		cout << endl << "The price is wrong";
	}
	catch (exception* e) {
		cout << endl << "Something went wrong: "
			<< e->what();
	}
	catch (...) {
		cout << endl << "Generic error";
	}
}

