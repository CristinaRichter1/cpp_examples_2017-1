// ProjectLab10.cpp : Defines the entry point for the console application.
// composition and inheritance
//

#include <iostream>
#include <fstream>
using namespace std;

class Engine {
public:
	float cc;
	float rpm;
	const int serialNumber;
public:
	Engine() :serialNumber(0) {
	}

	Engine(float CC, float RPM, int Serial)
		:serialNumber(Serial)
	{
		this->cc = CC;
		this->rpm = RPM;
	}

};

class Vehicle {
protected:
	char model[50];
	Engine engine;	//composition

public:
	Vehicle():engine(0,0,1) {

	}

	Vehicle(char* Model, float CC, float RPM, int Serial)
		:engine(CC,RPM,Serial) {
		//this->engine.cc = CC;
		//this->engine.rpm = RPM;
		//this->engine.serialNumber = Serial;

		strcpy(this->model, Model);
	}
};

//inheritance
class ElectricCar :public Vehicle {
	int chargingLevel;
public:
	ElectricCar():Vehicle("electric",0,4500,2) {

	}

	ElectricCar(char* Model, float RPM, int Serial)
		:Vehicle(Model, 0, RPM, Serial), chargingLevel(100) {
		//this->chargingLevel = 100;
	}
};

int main(int argc, char* argv[])
{
	if (argc > 3) {
		cout << endl << "Current location is " << argv[0];
		cout << endl << "You have input files ";
		cout << endl << argv[1];
		cout << endl << argv[2];

		ifstream engines;
		engines.open(argv[1], ios::in);
		if (engines.is_open()) {
			int noEngines;
			engines >> noEngines;
			for (int i = 0; i < noEngines; i++)
			{
				int CC;
				engines >> CC;
				int RPM;
				engines >> RPM;
				int serial;
				engines >> serial;
				Engine engine(CC, RPM, serial);
				cout << endl << "We have an engine";
			}
		}
		engines.close();
		ifstream vehicles;
		vehicles.open(argv[2], ios::in);
		if (vehicles.is_open()) {
			int noVehicles;
			vehicles >> noVehicles;
			for (int i = 0; i < noVehicles; i++) {
				char buffer[1000];
				vehicles >> buffer;

				char *token;

				/* get the first token */
				token = strtok(buffer, "#");

				/* walk through other tokens */
				while (token != NULL) {
					cout << endl << "We have a value " << token;

					token = strtok(NULL, "#");
				}
			}
		}
		vehicles.close();
	}

	cin >> ws;

	//Vehicle vehicle;
	ElectricCar eVehicle;
}

