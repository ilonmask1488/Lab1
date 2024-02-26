#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

struct Right_M {
    double len;
    int kolstr;
    double x;
    double y;
    double S;
    double P;
};

Right_M* AddStruct(Right_M* Obj, const int amount);
void setData(Right_M* Obj, const int amount);
void showData(const Right_M* Obj, const int amount);
double computeArea(const Right_M& obj);
double computePerimeter(const Right_M& obj);

int main()
{
    setlocale(LC_ALL, "");

    Right_M* Geometry = nullptr;
    int M_amount = 0;
    int YeaOrNot = 0;

    do
    {
        Geometry = AddStruct(Geometry, M_amount);
        setData(Geometry, M_amount);

        M_amount++;

        cout << "Продолжить ввод данных? (1 - да, 0 - нет): ";
        cin >> YeaOrNot;
        cin.ignore();
    } while (YeaOrNot != 0);

    showData(Geometry, M_amount);

    delete[] Geometry;
    return 0;
}

Right_M* AddStruct(Right_M* Obj, const int amount)
{
    Right_M* tempObj = new Right_M[amount + 1];

    for (int i = 0; i < amount; i++) {
        tempObj[i] = Obj[i];
    }
    delete[] Obj;

    return tempObj;
}

void setData(Right_M* Obj, const int amount)
{
    cout << "Введите длину стороны" << endl;
    cin >> Obj[amount].len;
    cout << "Введите количество сторон" << endl;
    cin >> Obj[amount].kolstr;
    cout << "Введите координаты x и y" << endl;
    cin >> Obj[amount].x >> Obj[amount].y;

    // Вычисляем площадь и периметр
    Obj[amount].S = computeArea(Obj[amount]);
    Obj[amount].P = computePerimeter(Obj[amount]);

    cout << endl;
}

void showData(const Right_M* Obj, const int amount)
{
    cout << "№\tДлина\tКоличество сторон\tКоординаты\tПлощадь\tПериметр" << endl;
    for (int i = 0; i < amount; i++) {
        cout << i + 1 << "\t" << Obj[i].len << "\t" << Obj[i].kolstr << "\t\t\t"
            << Obj[i].x << " " << Obj[i].y << "\t\t" << Obj[i].S << "\t" << Obj[i].P << endl;
    }
}

double computeArea(const Right_M& obj)
{
    if (obj.kolstr < 3) return 0.0; // Многоугольник должен иметь хотя бы 3 стороны

    double a = obj.len;
    double S = (obj.kolstr * a * a) / (4 * tan(M_PI / obj.kolstr)); // Формула для правильного многоугольника
    return S;
}

double computePerimeter(const Right_M& obj)
{
    if (obj.kolstr < 3) return 0.0; // Многоугольник должен иметь хотя бы 3 стороны

    double P = obj.kolstr * obj.len;
    return P;
}


