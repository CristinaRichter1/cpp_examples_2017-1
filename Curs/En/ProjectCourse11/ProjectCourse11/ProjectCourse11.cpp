// ProjectCourse11.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;

class Toy {
public:
	char name[50];
	int minAge;
	float price;
public:

	Toy() :minAge(0), price(0) {
		strcpy(this->name, "Nothing");
	}
	Toy(char* Name, int age, float Price)
		:minAge(age),price(Price) {
		strcpy(this->name, Name);
	}

	void display() {
		cout << endl << "The toy " << this->name << 
			" ( "<<this->minAge<<") has a price of "
			<< this->price;
	}

	virtual float getPrice() {
		return this->price;
	}
};

class DiscountToy : public Toy {
	float discount;

	DiscountToy():Toy("",0,0.0) {
		this->discount = 0;
	}

public:
	DiscountToy(char* Name, int age, float Price, float Discount)
		:Toy(Name, age, Price) {
		this->discount = Discount;
	}

	float getDiscountedPrice() {
		return this->price*((100 - this->discount) / (float)100);
	}

	//override the base class method for getPrice()
	float getPrice() {
		return this->getDiscountedPrice();
	}
};

class RobotToy:public Toy {
	char OS[50];

public:
	RobotToy(char* Name, int age, float Price, char* OperatingSystem)
	:Toy(Name, age, Price)
	{
		strcpy(this->OS, OperatingSystem);
	}
};



int main()
{
	Toy rcCar("RC Car", 12, 100);
	rcCar.minAge = 10;
	rcCar.display();

	DiscountToy puppet("Maria",3,200,20);
	puppet.minAge = 10;

	cout << endl << "Puppet Initial price " << puppet.getPrice();
	cout << endl << "Final price " << puppet.getDiscountedPrice();

	RobotToy lego("Lego Mind", 12, 1600, "LegoOS");
	cout << endl << "Final price " << lego.getPrice();

	//upcasting
	Toy genericToy = lego;
	cout << endl << "Final price " << genericToy.getPrice();;;;;;;;;
	//lego = genericToy;	DOWN-CASTING

	genericToy = puppet;
	cout << endl << "Final price " << genericToy.getPrice();

	Toy toys[3];
	toys[0] = rcCar;
	toys[1] = lego;
	toys[2] = puppet;

	float stockValue = 0;
	for (int i = 0; i < 3; i++)
		stockValue += toys[i].getPrice();
	cout << endl << "The stock value is " << stockValue;

	Toy *toys2[3];
	toys2[0] = &rcCar;
	toys2[1] = &lego;
	toys2[2] = &puppet;
	stockValue = 0;
	for (int i = 0; i < 3; i++)
		stockValue += toys2[i]->getPrice();
	cout << endl << "The stock value is " << stockValue;
}

