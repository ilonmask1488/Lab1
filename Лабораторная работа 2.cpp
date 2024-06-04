#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <locale.h>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class TransportVehicle {
	string Title;
	int amount_wheels;
	double mileage;
	double Tank_capacity;
	double Engine_power;
	double Travel_time;
	double Speed;
	double fuel_Consumption;
	int num_refuelings;
	double time_of_the_race;
public:

	TransportVehicle(int Amount_Vehicles, TransportVehicle* vehicle);

	void Set_name(string Title) { this->Title = Title; }
	string Get_name() { return Title; }
	void Set_amount_wheels(int amount_wheels) { this->amount_wheels = amount_wheels; }
	int Get_amount_wheels() { return amount_wheels; }
	void Set_mileage(double mileage) { this->mileage = mileage; }
	double Get_mileage() { return mileage; }
	void Set_volume_tank(double Tank_capacity) { this->Tank_capacity = Tank_capacity; }
	double Get_volume_tank() { return Tank_capacity; }
	void Set_power(double Engine_power) { this->Engine_power = Engine_power; }
	double Get_power() { return Engine_power; }
	void Set_travel_time(double Travel_time) { this->Travel_time = Travel_time; }
	double Get_travel_time() { return Travel_time; }
	void Set_num_refuelings(int num_refuelings) { this->num_refuelings = num_refuelings; }
	int Get_num_refuelings() { return num_refuelings; }
	void Set_Time_race(double time_of_the_race) { this->time_of_the_race = time_of_the_race; }
	double Get_Time_race() { return time_of_the_race; }

	void Determination_speed(int Amount_Vehicles, TransportVehicle* vehicle)
	{
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			vehicle[i].Speed = fabs(sqrt(vehicle[i].Engine_power) * ((70 / (double)vehicle[i].amount_wheels) - 2.5));
		}
	}

	friend void ShowSpeed(int Amount_Vehicles, TransportVehicle* vehicles, int i)
	{
		cout << "Скорость: " << vehicles[i].Speed << endl;
	}

	double Get_speed()
	{
		return Speed;
	}

	void Determination_Fuel_Consumption(int Amount_Vehicles, TransportVehicle* vehicle)
	{
		for (int i = 0; i < Amount_Vehicles; i++)
		{
			vehicle[i].fuel_Consumption = fabs(((pow(vehicle[i].Engine_power, 1 / 3) + sqrt(vehicle[i].Engine_power)) - 6.25));
		}
	}

	double Get_fuel_consumption()
	{
		return fuel_Consumption;
	}

	friend void Showfuelcons(int Amount_Vehicles, TransportVehicle* vehicles, int i)
	{
		cout << "Расход топлива: " << vehicles[i].fuel_Consumption << endl;
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

int Get_Variant() {
	int number;
	string userInput;
	getline(cin, userInput);
	stringstream ss(userInput);
	while (true) {
		cout << "Введите число: " << endl;
		getline(cin, userInput);
		stringstream ss(userInput);
		if (ss >> number && number > 0) {
			break;
		}
		else {
			cout << "Ошибка! Пожалуйста, введите допустимое значение." << endl;
		}
	}
	return number;
}

void PrintRaceResults(int amount_vehicles, string* name_v, TransportVehicle* vehicles) {
	cout << "Определение завершено!" << endl;
	for (int i = 0; i < amount_vehicles; i++) {
		cout << "Транспорт: " << name_v[i] << endl;

		int hours = (int)(vehicles[i].Get_Time_race());
		int minutes = (int)((vehicles[i].Get_Time_race() - hours) * 60);
		int seconds = (int)((vehicles[i].Get_Time_race() * 3600) - (hours * 3600) - (minutes * 60));

		cout << "Время в пути: " << hours << " часов " << minutes << " минут " << seconds << " секунд" << endl;

		cout << "Количество дозаправок: " << vehicles[i].Get_num_refuelings() << endl;
	}
}

void Determination_track(int length_of_the_track, TransportVehicle* vehicles, int amount_vehicles)
{
	for (int i = 0; i < amount_vehicles; i++) {
		int num_refuelings;
		double time_of_the_race;
		num_refuelings = (int)(((length_of_the_track / 100) * vehicles[i].Get_fuel_consumption()) / vehicles[i].Get_volume_tank());
		vehicles[i].Set_num_refuelings(num_refuelings);
		time_of_the_race = (double)(length_of_the_track) / vehicles[i].Get_speed();
		vehicles[i].Set_Time_race(time_of_the_race);
	}


	string* name_v = new string[amount_vehicles];
	for (int j = 0; j < amount_vehicles; ++j)
	{
		name_v[j] = vehicles[j].Get_name();
	}

	for (int i = 0; i < amount_vehicles - 1; ++i)
	{
		if (vehicles[i].Get_Time_race() > vehicles[i + 1].Get_Time_race())
		{
			double temp = vehicles[i].Get_Time_race();
			vehicles[i].Set_Time_race(vehicles[i + 1].Get_Time_race());
			vehicles[i + 1].Set_Time_race(temp);

			int temp_refuelings = vehicles[i].Get_num_refuelings();
			vehicles[i].Set_num_refuelings(vehicles[i + 1].Get_num_refuelings());
			vehicles[i + 1].Set_num_refuelings(temp_refuelings);

			string temp_name = name_v[i];
			name_v[i] = name_v[i + 1];
			name_v[i + 1] = temp_name;
		}
		else if (vehicles[i].Get_Time_race() == vehicles[i + 1].Get_Time_race())
		{
			if (vehicles[i].Get_num_refuelings() > vehicles[i + 1].Get_num_refuelings())
			{
				int temp_refuelings = vehicles[i].Get_num_refuelings();
				vehicles[i].Set_num_refuelings(vehicles[i + 1].Get_num_refuelings());
				vehicles[i + 1].Set_num_refuelings(temp_refuelings);

				string temp_name = name_v[i];
				name_v[i] = name_v[i + 1];
				name_v[i + 1] = temp_name;
			}
		}
	}

	PrintRaceResults(amount_vehicles, name_v, vehicles);
	delete[] name_v;
}

void ignoreLine()
{
	cin.clear();
	cin.ignore();
}

TransportVehicle::TransportVehicle(int Amount_Vehicles, TransportVehicle* vehicles)
{
	for (int i = 0; i < Amount_Vehicles; i++)
	{
		string carname;
		int amount_wheels;
		double volume_tank;
		double power;
		cout << "Машина №" << i + 1 << endl;
		cout << "Введите название вашей машины: " << endl;
		cin >> carname;
		vehicles[i].Set_name(carname);
		cout << "Введите количество колёс: " << endl;
		cin >> amount_wheels;
		while (cin.fail()) {
			ignoreLine();
			cout << "Вы ввели символ, пожалуйста, введите число" << endl;
			cin >> amount_wheels;
		}
		do
		{
			if (amount_wheels <= 0)
			{
				cout << "Ошибка! Повторите попытку (количество колёс > 0)" << endl;
				cin >> amount_wheels;
			}
		} while (amount_wheels <= 0);
		vehicles[i].Set_amount_wheels(amount_wheels);
		cout << "Введите объем резервуара: " << endl;
		cin >> volume_tank;
		while (cin.fail()) {
			ignoreLine();
			cout << "Вы ввели символ, пожалуйста, введите число" << endl;
			cin >> volume_tank;
		}
		do
		{
			if (volume_tank <= 0)
			{
				cout << "Ошибка! Повторите попытку (объём бака>0)" << endl;
				cin >> volume_tank;
			}
		} while (volume_tank <= 0);
		vehicles[i].Set_volume_tank(volume_tank);
		cout << "Введите мощность: " << endl;
		cin >> power;
		while (cin.fail()) {
			ignoreLine();
			cout << "Вы ввели символ, пожалуйста, введите число" << endl;
			cin >> power;
		}
		do
		{
			if (power <= 0)
			{
				cout << "Ошибка! Повторите попытку (мощность > 0)" << endl;
				cin >> power;
			}
		} while (power <= 0);
		vehicles[i].Set_power(power);
	}
}

void output(int amount_vehicles, TransportVehicle* vehicles)
{
	for (int i = 0; i < amount_vehicles; i++)
	{
		cout << "Название: " << vehicles[i].Get_name() << endl;
		cout << "Количество колёс: " << vehicles[i].Get_amount_wheels() << endl;
		ShowSpeed(amount_vehicles, vehicles, i);
		cout << "Объем резервуара: " << vehicles[i].Get_volume_tank() << endl;
		Showfuelcons(amount_vehicles, vehicles, i);
		cout << "Мощность: " << vehicles[i].Get_power() << endl;
	}
}

void menu(int amount_vehicles, TransportVehicle* vehicles, int lenght_of_the_track)
{
	int choice;
	int exit_menu = 0;
	int determination_complete = 0;
	int car = 0;

	while (exit_menu == 0)
	{
		cout << "Какое действие хотите совершить?" << endl;
		cout << "1. Внести данные о транспортном средстве" << endl;
		cout << "2. Посмотреть данные о транспортных средствах" << endl;
		cout << "3. Ввести протяженность трассы" << endl;
		cout << "4. Вывод результатов прохождения трассы" << endl; // должно появляться после расчетов
		cout << "5. Выход" << endl;
		cout << "> ";
		cin >> choice;
		while (cin.fail()) {
			ignoreLine();
			cout << "Вы ввели символ, пожалуйста, введите число" << endl;
			cin >> amount_vehicles;
		}
		switch (choice)
		{
		case 1:
			system("cls");
			TransportVehicle(amount_vehicles, vehicles);
			for (int i = car - 1; i < car; ++i)
			{
				vehicles[i].Determination_Fuel_Consumption(amount_vehicles, vehicles);
				vehicles[i].Determination_speed(amount_vehicles, vehicles);
			}
			car++;
			break;
		case 2:
			system("cls");
			if (car == 0)
			{
				cout << "Во-первых, введите транспортное средство!" << endl;
				break;
			}
			output(amount_vehicles, vehicles);
			break;
		case 3:
			system("cls");
			if (car == 0)
			{
				cout << "Во-первых, введите транспортное средство!" << endl;
				break;
			}
			cout << "Введите длину трассы: " << endl;
			lenght_of_the_track = Get_Variant();
			break;
		case 4:
			if (lenght_of_the_track == 0)
			{
				cout << "ВВЕДИТЕ ДЛИНУ ТРАССЫ, прежде чем определить её!" << endl;
				break;
			}
			system("cls");
			Determination_track(lenght_of_the_track, vehicles, amount_vehicles);
			determination_complete++;
			break;

		case 5:
			system("cls");
			cout << "Вы уверены, что выходите? 1 - да, 0 - нет\n";
			cin >> exit_menu;
			if (exit_menu == 1)
			{
				return;
			}
			break;
		default:
			cout << "Ошибка! Пробовать снова" << "\n";
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int prov = 0;

	int Amount_Vehicles;
	int Lenght_ofthe_Track = 0;
	cout << "Введите количесвто транспортных средств " << endl;
	cin >> Amount_Vehicles;
	while (cin.fail()) {
		ignoreLine();
		cout << "Вы ввели символ, пожалуйста, введите число" << endl;
		cin >> Amount_Vehicles;
	}
	do
	{
		if (Amount_Vehicles <= 0)
		{
			cout << "Ошибка! Повторите попытку (количество транспортных средств > 0)" << endl;
			cin >> Amount_Vehicles;
		}
	} while (Amount_Vehicles <= 0);

	TransportVehicle* vehicles = new TransportVehicle[Amount_Vehicles];

	menu(Amount_Vehicles, vehicles, Lenght_ofthe_Track);

	delete[] vehicles;
	return 0;
}
