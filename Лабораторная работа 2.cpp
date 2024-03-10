#include <iostream>
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
public:
	TransportVehicle(int wheels, int mileage, int capacity, int power, string vehicleName):
	Kolcol(wheels),mileage(mileage), Tank_capacity(capacity), Engine_power(power), Title(vehicleName)
	{
	}
	//void Message() {
	//	cout << "Введите данные" << endl;
	//}
	//void setDate(int wheels, int mileage, int capacity, int power, string vehicleName)
	//{
	//	Kolcol = wheels;
	//	mileage = mileage;
	//	Tank_capacity = capacity;
	//	Engine_power = power;
	//	Title = vehicleName;
	//}
	//void getDate() {
	//	
	//}


	~TransportVehicle() {
		cout << "Транспортное средство удалено" << endl;
	}
	


};