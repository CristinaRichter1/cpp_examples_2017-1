// ProjectLab5.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

enum engineType { NONE = 0, ELECTRIC = 10, 
	DIESEL = 20, GASOLINE, HYBRID };

class Vehicle {
	char* model;
	float cc;
	const engineType type;
	int mileage;

	static int MILEAGE_LIMIT;

	Vehicle():type(engineType::NONE) {
		this->model = NULL;
		this->cc = 0;
		this->mileage = 0;
	}
public:
	Vehicle(char* model, float cc,
		engineType Type, int mileage) :type(Type) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1,model);
		this->mileage = mileage;
		this->cc = cc;
	}

	void display() {
		if(this->model!=NULL)
			cout << endl << "Model " << this->model;
		cout << endl << "Mileage " << this->mileage;
		cout << endl << "CC " << this->cc;
		cout << endl << "Engine type " << this->type;
	}

	//class public interface
	//for reading attributes values
	char* getModel() {
		return this->model;
	}
	int getMileage() {
		return this->mileage;
	}

	bool isOld() {
		if (this->mileage >= Vehicle::MILEAGE_LIMIT)
			return true;
		else
			return false;
	}

	void setMileage(int value) {
		if (value > this->mileage)
			this->mileage = value;
		else
			throw exception("Wrong value");
	}

};

int Vehicle::MILEAGE_LIMIT = 100000;

int main()
{
	//Vehicle vehicle;
	//vehicle.display();

	Vehicle vehicle1("Dacia", 1400, DIESEL, 450);
	Vehicle* pVehicle1 =
		new Vehicle("Renault", 1100, HYBRID, 10000);
	//vehicle1.setMileage(-4500);
	vehicle1.setMileage(4500);

	vehicle1.display();
	pVehicle1->display();

	Vehicle vehicle2 = vehicle1;
	//vehicle2 = vehicle1;

	Vehicle* pVehicle2 = pVehicle1;

	vehicle2.display();
	pVehicle2->display();
}

