// ProjectCourse13.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

//int sum(int a, int b) {
//	return a + b;
//}
//
//float sum_float(float a, float b) {
//	return a + b;
//}

template<typename X> X sumFunction(X a, X b) {
	X result;
	result = a + b;
	return result;
}

//template specialization
template<> char* sumFunction(char* a, char* b) {
	cout << endl << "Special version";
	char* result = new char[strlen(a) + strlen(b) + 1];
	strcpy(result, a);
	strcat(result, b);
	return result;
}

class Box {
	void *content;

public:
	Box(void * value) {
		this->content = value;
	}

	void * getValue() {
		return this->content;
	}


};

template<typename T>
class TemplateBox {
	T content;

public:
	TemplateBox(T  value) {
		this->content = value;
	}

	T  getValue() {
		return this->content;
	}

	void addValue(T value) {
		this->content += value;
	}
};

//specialize class functions
template<> 
void TemplateBox<char*>::addValue(char* value) {
	char* newValue = new char[strlen(this->content) +
		strlen(value) + 1];
	strcpy(newValue, this->content);
	strcat(newValue, value);
	delete[] this->content;
	this->content = newValue;
}



class NegativeWeightException : public exception {

};

class TooLargeWeightException : public exception {

};

class Box2 {
	int weight;
public:
	Box2(int value) {
		if (value <= 0)
			throw new NegativeWeightException();
		if (value > 1000)
			throw TooLargeWeightException();
		else
			this->weight = value;
	}
};


int main()
{
	int a = 10;
	int b = 4;
	//cout << endl << "The result is " << sum(a, b);
	float vb1 = 10.3;
	float vb2 = 20.0;
	//cout << endl << "The result is " << sum_float(vb1, vb2);

	char c1 = 6;
	char c2 = 7;


	char text1[50];
	strcpy(text1, "test");
	char text2[50];
	strcpy(text2, " value");

	cout << endl << "The result is " << sumFunction<int>(a, b);
	cout << endl << "The result is " << sumFunction<float>(vb1, vb2);
	cout << endl << "The result is " << sumFunction<int>(a, vb2);
	cout << endl << "The result is " << (int)sumFunction<char>(c1, c2);

	cout << endl << "The result is " << sumFunction<char*>(text1, text2);

	int intValue = 34;
	Box intBox((void*)&intValue);
	int boxedValue = *((int*)intBox.getValue());
	cout << endl << "The value was " << boxedValue;

	float floatValue = 55.7;
	Box intBox2((void*)&floatValue);

	boxedValue = *((int*)intBox2.getValue());
	cout << endl << "The value was " << boxedValue;

	intValue = 99;
	TemplateBox<int> integerBox(intValue);
	boxedValue = integerBox.getValue();
	cout << endl << "The value was " << boxedValue;

	floatValue = 55.7;
	//TemplateBox<int> intBox2(&floatValue); //compiler error

	int weight;
	cout << endl << "Give us the package weight";
	cin >> weight;

	try {
		cout << endl << "Trying something";
		Box2 flowerBox(weight);
		cout << endl << "We are done";
	}
	catch (TooLargeWeightException ex) {
		cout << endl << "You have privided a bigger than 1000 value";
	}
	catch (NegativeWeightException* ex) {
		cout << endl << "You have privided a negative value";
	}
	catch (...) {
		cout << endl << "You have a problem";
	}
	//Box2 laptopBox(-10);
	//Box2 fridgeBox(20000);

}

