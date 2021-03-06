#include <iostream>
#include <fstream>
using namespace std;

class Weather {
public:
	char location[50];
	float tempValues[24];
	int currentHour;	//from 0 to 23
	static float ABSOLUT_ZERO;
public:
	Weather() {
		currentHour = 0;
		strcpy(location, "Unknown");
	}
	Weather(char* location) {
		strcpy(this->location, location);
		currentHour = 0;
	}

	void setTemp(int hour, float temperature) {
		if (hour >= 0 && hour < 24) {
			if (hour > this->currentHour + 1)
			{
				for (int i = currentHour; i < hour; i++)
					this->tempValues[i] = ABSOLUT_ZERO;
			}
			this->tempValues[hour] = temperature;
			this->currentHour = hour+1;
		}
		else
			throw exception();
	}

	float operator[](int index) {
		if (index >= 0 && index < 24) {
			return this->tempValues[index];
		}
		else
			throw exception();
	}

	friend ostream& operator<<(ostream& buffer, Weather& weather);
	friend void createLastTempReport(Weather* stations,
		int noStations,
		char* reportName);
};

float Weather::ABSOLUT_ZERO = -273.15;

ostream& operator<<(ostream& buffer, Weather& weather) {
	buffer << endl << "Station name " << weather.location;
	buffer << endl << "Recorded temps: ";
	for (int i = 0; i < weather.currentHour; i++)
		buffer << " " << weather.tempValues[i];
	return buffer;
}

void createLastTempReport(Weather* stations,
	int noStations,  
	char* reportName) {

	ofstream lastTempReport;
	lastTempReport.open(reportName, ios::trunc | ios::out);
	if (lastTempReport.is_open()) {
		lastTempReport << "The last temp recordings are";
		for (int i = 0; i < noStations; i++) {
			lastTempReport << endl << stations[i].location << " - " <<
				stations[i].tempValues[stations[i].currentHour-1];
		}
	}
	lastTempReport.close();
}

class WeatherStations {
public:
	Weather* list;
	int noStations;

	WeatherStations() {
		list = NULL;
		noStations = 0;
	}
	~WeatherStations() {
		delete [] list;
	}
};

WeatherStations readStationsData(char* inputFileName) {
	ifstream input;
	input.open(inputFileName, ios::in);
	if (input.is_open()) {
		int noStations;
		input >> noStations;
		WeatherStations stations;
		stations.list = new Weather[noStations];
		for (int i = 0; i < noStations; i++) {
			char name[100];
			input >> name;
			int noRecordings;
			input >> noRecordings;
			for (int j = 0; j < noRecordings; j++) {
				int hour;
				float temp;
				input >> hour;
				input >> temp;
				stations.list[i].setTemp(hour, temp);
			}
			strcpy(stations.list[i].location, name);
		}
		input.close();

		return stations;
	}
	else
		throw exception("No input file");
}


void main() {
	Weather ws1("Bucharest");
	Weather ws2("Brasov");

	ws1.setTemp(0, 14.2);
	ws1.setTemp(9, 23);

	ws2.setTemp(12, 17.6);

	cout << ws1 << ws2;

	ofstream currentWeatherConditions;
	currentWeatherConditions.open("CurrentTemp.txt", ios::app | ios::out);
	if (currentWeatherConditions.is_open()) {
		currentWeatherConditions << "\t\t The current temp report";
		currentWeatherConditions << ws1;
		currentWeatherConditions << ws2;
	}
	currentWeatherConditions.close();


	Weather* stations = new Weather[2]{ ws1,ws2 };

	createLastTempReport(stations, 2, "LastRecordings.txt");

}