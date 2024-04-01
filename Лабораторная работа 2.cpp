#include <iostream>
#include <locale.h> 
#include <string>

using namespace std;

class TransportVehicle {
	int amount_wheels;
	double mileage;
	double Tank_capacity;
	double Engine_power;
	double Travel_time;
	char Title[100];

public:
	
	double Speed;
	double fuel_Consumption;

	TransportVehicle(int Amount_Vehicles, Vehicle* vehicle);

	void set_Wheels(int wheels) {
		amount_wheels = wheels;
	}
	
	int get_Kolcol() {
		return amount_wheel;
	}

	void set_mileage(double M_mileage) {
		mileage = M_mileage;
	}
	
	double get_mileage() {
		return mileage;
	}

	void set_Tank_capacity(int capacity) {
		Tank_capacity = capacity;
	}

	int get_Tank_capacity() {
		return Tank_capacity;
	}

	void set_Title(char name_of_car[100]) {
		strcpy(Title, name_of_car);
	}

	char get_Title() {
		for (int i = 0; i < 100; i++) {
			cout << Title[i];
		}
		return 0;
	}

	void set_Engine_power(double power) {
		Engine_power = power;
	}

	double get_Engine_power() {
		return Engine_power;
	}

	void set_Travel_time(double time) {
		Travel_time = time;
	}

	double get_Travel_time() {
		return Travel_time;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	TransportVehicle car;
	string name;
	getline(cin, name);



	return 0;
}
