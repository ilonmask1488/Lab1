#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <locale.h> 
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

void print_menu();

class TransportVehicle {
	string Title;
	int amount_wheels;
	double mileage;
	double Tank_capacity;
	double Engine_power;
	double Travel_time;
	double Speed;
	double fuel_Consumption;

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

int count_refueling(int lenght_of_the_track, int Amount_Vehicles, TransportVehicle* vehicles, int i)
{
	int* number_of_refuelings = new int[Amount_Vehicles];
	number_of_refuelings[i] = (int)(((lenght_of_the_track / 100) * vehicles[i].Get_fuel_consumption()) / vehicles[i].Get_volume_tank());
	return number_of_refuelings[i];
	delete[] number_of_refuelings;
}

void PrintRaceResults(int amount_vehicles, string* name_v, double* time_of_the_race, int* num_refuelings) {
	cout << "Определение завершено!" << endl;
	for (int i = 0; i < amount_vehicles; i++) {
		cout << "Транспорт: " << name_v[i] << endl;
		cout << "Время в пути:" << (int)time_of_the_race[i] << " часов" << endl;
		cout << (int)((time_of_the_race[i] - (int)time_of_the_race[i]) * 60) << " минут" << endl;
		cout << (int)(time_of_the_race[i] * 3600 - (int)(time_of_the_race[i]) * 3600 - (int)((time_of_the_race[i] - (int)time_of_the_race[i]) * 60) * 60) << " секунд" << endl;
		cout << "Количество дозаправок: " << num_refuelings[i] << endl;
	}
}

void Determination_track(int lenght_of_the_track, TransportVehicle* vehicles, int amount_vehicles)
{
	int* num_refuelings = new int[amount_vehicles];
	for (int i = 0; i < amount_vehicles; i++)
	{
		num_refuelings[i] = count_refueling(lenght_of_the_track, amount_vehicles, vehicles, i);
	}
	double* time_of_the_race = new double[amount_vehicles];
	string* name_v = new string[amount_vehicles];
	for (int i = 0; i < amount_vehicles; i++)
	{
		time_of_the_race[i] = lenght_of_the_track / vehicles[i].Get_speed();
	}
	for (int i = 0; i < amount_vehicles; ++i)
	{
		name_v[i] = vehicles[i].Get_name();
	}
	for (int i = 0; i < amount_vehicles; i++)
	{
		for (int j = 0; j < amount_vehicles - 1; ++j)
		{

			if (time_of_the_race[j] > time_of_the_race[j + 1])
			{
				double temp = time_of_the_race[j];
				time_of_the_race[j] = time_of_the_race[j + 1];
				time_of_the_race[j + 1] = temp;
				int temp_refuelings = num_refuelings[j];
				num_refuelings[j] = num_refuelings[j + 1];
				num_refuelings[j + 1] = temp_refuelings;
				string temp_name;
				temp_name = name_v[j];
				name_v[j] = name_v[j + 1];
				name_v[j + 1] = temp_name;
			}
			if (time_of_the_race[j] == time_of_the_race[j + 1])
			{
				if (num_refuelings[j] > num_refuelings[j + 1])
				{
					double temp = time_of_the_race[j];
					time_of_the_race[j] = time_of_the_race[j + 1];
					time_of_the_race[j + 1] = temp;
					int temp_refuelings = num_refuelings[j];
					num_refuelings[j] = num_refuelings[j + 1];
					num_refuelings[j + 1] = temp_refuelings;
					string temp_name;
					temp_name = name_v[j];
					name_v[j] = name_v[j + 1];
					name_v[j + 1] = temp_name;
				}
			}
		}
	}
	PrintRaceResults(amount_vehicles, name_v, time_of_the_race, num_refuelings);
	delete[] num_refuelings;
	delete[] time_of_the_race;
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
		cout << "\nМашина №" << i + 1 << endl;
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
			cout << "Введите длину трассы: ";
			cin >> lenght_of_the_track;

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

void print_menu()
{
	system("cls"); // очищает экран
	cout << "Какое действие хотите совершить?" << endl;
	cout << "1. Внести данные о транспортном средстве" << endl;
	cout << "2. Посмотреть данные о транспортных средствах" << endl;
	cout << "3. Ввести протяженность трассы" << endl;
	cout << "4. Вывод результатов прохождения трассы" << endl; // должно появляться после расчетов
	cout << "5. Выход" << endl;
	cout << "> ";
}
