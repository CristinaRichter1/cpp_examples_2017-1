#include <iostream>
using namespace std;

enum ENGINE_TYPE {
	DIESEL=10,
	GASOLINE=20,
	ELECTRIC,
	HYBRID};

class Vehicle {
	char* owner;
	float cc;
	const ENGINE_TYPE type;
	int mileage;
	static int OLD_CAR_LIMIT;
public:
	Vehicle() :type(ENGINE_TYPE::GASOLINE) {
		this->cc = 0;
		this->mileage = 0;
		this->owner = NULL;
	}

	Vehicle(char* owner, float cc,
		int mileage, ENGINE_TYPE type):type(type) {
		this->owner = new char[strlen(owner) + 1];
		strcpy(this->owner, owner);

		if (mileage < 0)
			throw exception();
		this->mileage = mileage;

		if (cc < 0)
			throw exception();
		this->cc = cc;


	}


	void display() {
		cout << endl << "Type " << this->type;
		cout << endl << "CC " << this->cc;
		cout << endl << "Mileage " << this->mileage;
		if (this->mileage < Vehicle::OLD_CAR_LIMIT)
			cout << endl << "New car";
		else
			cout << endl << "Old car";
		if (this->owner != NULL)
			cout << endl << "Name " << this->owner;
		else
			cout << endl << "No owner";
	}

	//public interface for cc
	int getCC() {
		return this->cc;
	}

	void setMileage(int value) {
		if (value > 0)
			this->mileage = value;
		else
			throw exception("The value is WRONG!");
	}


};

int Vehicle::OLD_CAR_LIMIT = 100000;

void main() {
	Vehicle vehicle1;
	vehicle1.display();

	Vehicle* pVehicle1 = new Vehicle();
	pVehicle1->display();

	Vehicle vehicle2("Alice",1400,120000,
		ENGINE_TYPE::HYBRID);
	Vehicle* pVehicle2 = new Vehicle("Bob", 0, 25000, 
		ENGINE_TYPE::ELECTRIC);

	//vehicle2.setMileage(-56);

	vehicle2.display();
	pVehicle2->display();

	Vehicle vehicle3 = vehicle2;
	Vehicle* pVehicle3 = pVehicle2;

	cout << endl << "******************";
	vehicle3.display();
	pVehicle3->display();

}