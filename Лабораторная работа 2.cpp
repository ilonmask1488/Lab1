#include <iostream>
#include <locale.h> 
#include <string>

using namespace std;

class TransportVehicle {
private:
	int Kolcol;
	double mileage;
	int Tank_capacity;
	double Engine_power;
	double Travel_time;
	string Title;
	double Speed;
	double Eat;

public:

	void set_Kolcol(int wheels) {
		Kolcol = wheels;
	}

	int get_Kolcol() {
		return Kolcol;
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

	void set_Title(string name_of_car) {
		Title = name_of_car;
	}

	string get_Title() {
		return Title;
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

	void set_Speed(double v) {
		Speed = v;
	}

	double get_Speed() {
		return Speed;
	}

	void set_Eat(double eat_engine) {
		Eat = eat_engine;
	}

	double get_Eat() {
		return Eat;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	TransportVehicle car;
	string name;
	int Kolcol;
	double mileage;
	int Tank_capacity;
	double Engine_power;
	double Travel_time;
	double Speed;
	double Eat;
	
	
	cout << "Введите название вашей чудо машины: " << endl;
	getline(cin, name);
	car.set_Title(name);

	cout << "Введите количество колёс: " << endl;
	cin >> Kolcol;
	car.set_Kolcol(Kolcol);

	cout << "Введите значение пробега: " << endl;
	cin >> mileage;
	car.set_mileage(mileage);

	cout << "Введите объем бака: " << endl;
	cin >> Tank_capacity;
	car.set_Tank_capacity(Tank_capacity);
	
	cout << "Введите мощность двигателя: " << endl;
	cin >> Engine_power;
	car.set_Engine_power(Engine_power);

	



	return 0;
}
