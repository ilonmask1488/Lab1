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
	
	int get_Wheels() {
		return amount_wheels;
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
		for (int i = 0; i < Amount_Vehicles; i++)
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
	for (int i = 0; i < Amount_Vehicles; i++)
	{
		int amount_wheels;
		double mileage;
		double Tank_capacity;
		double Engine_power;
		double Travel_time;
		char Title[100];

		cout << "Введите название вашего транспортного средства " << endl;
		cin >> Title;
		vehicles[i].set_Title(Title);

		cout << "Введите количество колёс" << endl;
		amount_wheels = Get_Variant();
		vehicles[i].set_Wheels(amount_wheels);

		cout << "Введите пробег " << endl;
		mileage = Get_Variant();
		vehicles[i].set_mileage(mileage);

		cout << "Введите объём резервуара " << endl;
		Tank_capacity = Get_Variant();
		vehicles[i].set_Tank_capacity(Tank_capacity);

		cout << "Введите мощность " << endl;
		Engine_power = Get_Variant();
		vehicles[i].set_Engine_power(Engine_power);

		cout << "Введите время в пути в часах " << endl;
		Travel_time = Get_Variant();
		vehicles[i].set_Travel_time(Travel_time);
		cout << endl;
	}
}

void ignoreline()
{
	cin.clear();
	cin.ignore();
}

void print_menu()
{
	system("cls"); // очищает экран
	cout << "Какое действие хотите совершить?" << endl;
	cout << "1. Внести данные о транспортном средстве" << endl;
	cout << "2. Посмотреть данные о транспортных средствах" << endl;
	cout << "3. Ввести протяженность трассы" << endl;
	cout << "4. Произвести расчет прохождения трассы" << endl;
	cout << "5. Вывод результатов прохождения трассы" << endl; // должно появляться после расчетов
	cout << "6. Выход" << endl;
	cout << "> ";
}

int Get_Variant() {
	int number;
	string userInput;
	while (true) {
		getline(cin, userInput);
		stringstream ss(userInput);

		if (ss >> number) {
			break;
		}
		else {
			cout << "Ошибка! Пожалуйста, введите число." << endl;
		}
	}
	return number;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int Amount_Vehicles;
	int Lenght_ofthe_Track = 0;
	cout << "Введите предполагаемое количесвто ваших транспортных средств " << endl;
	Amount_Vehicles = Get_Variant();
	TransportVehicle* vehicles = new TransportVehicle[Amount_Vehicles];

	delete[] vehicles;
	return 0;
}
