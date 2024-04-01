#include <iostream>
#include <locale.h> 
#include <string>
#include <cmath>

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

	TransportVehicle(int Amount_Vehicles, TransportVehicle* vehicle);

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

	void Detetmination_Fuel_Consumption(int Amount_Vehicles, TransportVehicle* vehicle)
	{
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			vehicle[i].fuel_Consumption = ((pow(vehicle[i].Engine_power, 1 / 3) + sqrt(vehicle[i].Engine_power)) - 6.25);
		}
	}

	void Detetmination_speed(int Amount_Vehicles, TransportVehicle* vehicle)
	{
		for (int i = 0; i < amount; i++)
		{
			vehicle[i].Speed = sqrt(vehicle[i].Engine_power) * ((70 / vehicle[i].amount_wheels) - 2.5);
		}
	}

	void Determination_track(int Lenght_ofthe_Track, TransportVehicle* vehicles, int Amount_Vehicles)
	{
		int Number_Refuelings[Amount_Vehicles];
		char Title_2[Amount_Vehicles][30];
		double Time_ofthe_Race[Amount_Vehicles];
		double Refuelings_D[Amount_Vehicles];
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			Refuelings_D[i] = (((Lenght_ofthe_Track / 100) * vehicles[i].fuel_Consumption) / vehicles[i].get_Tank_capacity());
			Number_Refuelings[i] = (int)Refuelings_D[i];
		}
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			Time_ofthe_Race[i] = Lenght_ofthe_Track / vehicles[i].Speed;
		}
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			strcpy(Title_2[i], vehicles[i].Title);
		}
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			for (int j = 0; j < Amount_Vehicles; j++)
			{
				if (Time_ofthe_Race[j] > Time_ofthe_Race[j + 1])
				{
					double temp = Time_ofthe_Race[j];
					Time_ofthe_Race[j] = Time_ofthe_Race[j + 1];
					Time_ofthe_Race[j + 1] = temp;
					int temp_Refuelings = Number_Refuelings[j];
					Number_Refuelings[j] = Number_Refuelings[j + 1];
					Number_Refuelings[j + 1] = temp_Refuelings;
					char temp_Title[100];
					strcpy(temp_Title, Title_2[j]);
					strcpy(Title_2[j], Title_2[j + 1]);
					strcpy(Title_2[j + 1], temp_Title);
				}
				if (Time_ofthe_Race[j] == Time_ofthe_Race[j + 1])
				{
					if (Number_Refuelings[j] > Number_Refuelings[j + 1])
					{
						int temp = Time_ofthe_Race[j];
						Time_ofthe_Race[j] = Time_ofthe_Race[j + 1];
						Time_ofthe_Race[j + 1] = temp;
						int temp_Refuelings = Number_Refuelings[j];
						Number_Refuelings[j] = Number_Refuelings[j + 1];
						Number_Refuelings[j + 1] = temp_Refuelings;
						char temp_Title[100];
						strcpy(temp_Title, Title_2[j]);
						strcpy(Title_2[j], Title_2[j + 1]);
						strcpy(Title_2[j + 1], temp_Title);
					}
				}
			}
		}
		cout << "Определение завершено" << endl;
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			cout << "Транспорт: " << Title_2[i] << endl;
			cout << "Время пути " << Time_ofthe_Race[i] << " часов" << endl;
			cout << "Количество заправок " << Number_Refuelings[i] << endl;
			cout << endl;
		}
	}

	TransportVehicle()
	{
		cout << "Транспорт создан " << endl;
	}
	~TransportVehicle()
	{
		cout << "Транспорт уничтожен " << endl;
	}
};

TransportVehicle::TransportVehicle(int Amount_Vehicles, TransportVehicle* vehicles)
{

}

int main() {
	setlocale(LC_ALL, "Russian");



	getline(cin, name);



	return 0;
}
