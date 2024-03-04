#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Right_M {
    double len;
    int kolstr;
    double x;
    double y;
    double S;
    double P;
};

// Объявление функций
Right_M* AddStruct(Right_M* Obj, const int amount);
void setData(Right_M* Obj, const int amount);
void showData(const Right_M* Obj, const int amount);
double computeArea(const Right_M& obj);
double computePerimeter(const Right_M& obj);
void Delete(Right_M* Obj, const int amount);
void findMaxArea(const Right_M* Obj, const int amount);
void findMaxPerimetr(const Right_M* Obj, const int amount);
void restorePolygonVertices(const Right_M* Obj, const int amount);
void print_menu();
int get_variant(int count);
void print_menu1();
void case4();

int main()
{
    setlocale(LC_ALL, "Russian");

    Right_M* Geometry = nullptr;
    int M_amount = 0;
    int h;
    int count = 0;
    int YeaOrNot = 0;
    int variant = 0;
    while (true) {
        system("cls");
        print_menu();
        cin >> h;
        switch (h)
        {
        case 1:
            Geometry = AddStruct(Geometry, M_amount);
            setData(Geometry, M_amount);
            M_amount++;
            break;
        case 2:
            showData(Geometry, M_amount);
            restorePolygonVertices(Geometry, M_amount);
            break;
        case 3:
            if (M_amount == 0) {
                cout << "Вы хотите удалить структуры, которых нет " << endl;
                break;
            }
            else {
                Delete(Geometry, M_amount);
                M_amount--;
                break;
            }
        case 4:
            if (M_amount == 0) {
                cout << "Рано" << endl;
                break;
            }
            else {
                case4();
                break;
            }
        case 5:
            cout << "Вы точно хотите выйти? Для подтверждения нажмите 1 " << endl;
            cin >> YeaOrNot;
            if (YeaOrNot == 1) {
                break;
            }
            break;
        }
        if (YeaOrNot == 1) {
            break;
        }
        system("pause");
    }

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
            << Obj[i].x << " " << Obj[i].y << "\t\t" << Obj[i].S << "\t" << Obj[i].P << "\n" << endl;
    }
}

double computeArea(const Right_M& obj)
{
    if (obj.kolstr < 3) return 0.0; // Многоугольник должен иметь хотя бы 3 стороны

    double a = obj.len;
    double S = (obj.kolstr * a * a) / (4 * tan(3.14 / obj.kolstr)); // Формула для правильного многоугольника
    return S;
}

double computePerimeter(const Right_M& obj)
{
    if (obj.kolstr < 3) return 0.0; // Многоугольник должен иметь хотя бы 3 стороны

    double P = obj.kolstr * obj.len;
    return P;
}

void Delete(Right_M* Obj, const int amount) {
    int number;
    int h = 0;
    cout << "Введите номер структуры, от которой вы хотите избавиться:" << endl;
    while (h != 1) {
        cin >> number;
        if (number <= amount && number > 0) {
            h = 1;
        }
        else {
            cout << "Неправильный номер " << endl;
        }
    }
    for (int i = number - 1; i < amount; i++) {         // Сдвигаем элементы влево на одну позицию
        Obj[i] = Obj[i + 1];
    }
}

void findMaxArea(const Right_M* Obj, const int amount)
{
    double maxArea = 0.0;

    // Находим максимальную площадь
    for (int i = 0; i < amount; i++) {
        if (Obj[i].S > maxArea) {
            maxArea = Obj[i].S;
        }
    }

    for (int i = 0; i < amount; i++) {
        if (Obj[i].S == maxArea) {
            cout << "Номер многоугольника с максимальной площадью: " << i + 1 << endl;
            cout << "Максимальная площадь: " << maxArea << "\n" << endl;
        }
    }
}

void findMaxPerimetr(const Right_M* Obj, const int amount)
{
    double maxPerimetr = 0.0;

    // Находим максимальный периметр
    for (int i = 0; i < amount; i++) {
        if (Obj[i].S > maxPerimetr) {
            maxPerimetr = Obj[i].P;
        }
    }

    for (int i = 0; i < amount; i++) {
        if (Obj[i].P == maxPerimetr) {
            cout << "Номер многоугольника с максимальном периметром: " << i + 1 << endl;
            cout << "Максимальный периметр: " << maxPerimetr << "\n" << endl;
        }
    }
}

void print_menu()
{
    system("cls"); // очищает экран
    cout << "Какое действие хотите совершить?" << endl;
    cout << "1. Внести данные о новом многоугольнике" << endl;
    cout << "2. Посмотреть имеющиеся записи о многоугольниках" << endl;
    cout << "3. Удалить запись о каком-либо многоугольнике" << endl;
    cout << "4. Определение максимальных площади или периметра" << endl;
    cout << "5. Выход" << endl;
    cout << ">";
}

//int get_variant(int count)
//{
//    int variant;
//    string s;
//    getline(cin, s);
//    while (s_scanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
//        cout << "Некорректный ввод. Попробуйте еще: "; // выводим сообщение об ошибке
//        getline(cin, s); // считываем строку повторно
//    }
//
//    return variant;
//}

void case4() {
    print_menu1();
    while (variant <= 0 || variant >= 4) {
        cin >> variant;
    }
    switch (variant)
    {
    case 1:
        findMaxArea(Geometry, M_amount);
        break;
    case 2:
        findMaxPerimetr(Geometry, M_amount);
        break;
    case 3:
        break;
    }
}

void print_menu1()
{
    system("cls");
    cout << "Какое действие хотите совершить?" << endl;
    cout << "1. Определить многоугольник с максимальной площадью" << endl;
    cout << "2. Определить многоугольник с максимальным периметром" << endl;
    cout << "3. Выход на главное меню" << endl;
    cout << ">";
}

void restorePolygonVertices(const Right_M* Obj, const int amount)
{
    for (int j = 0; j < amount; j++) {
        cout << "\n" << "Координаты вершин многоугольника №" << j + 1 << endl;
        double angleIncrement = 2 * 3.14 / Obj[j].kolstr; // Угол между соседними вершинами
        double radius = Obj[j].len / (2 * sin(3.14 / Obj[j].kolstr)); // Радиус описанной окружности
        double Ox = Obj[j].x - radius * cos(0);
        double Oy = Obj[j].y - radius * sin(0);

        cout << "Координаты вершин: " << endl;
        cout << "Вершины 1: (" << Obj[j].x << ", " << Obj[j].y << ")" << endl;
        for (int i = 1; i < Obj[j].kolstr; i++) {
            double angle = i * angleIncrement;
            double newX = Ox + radius * cos(angle);
            double newY = Oy + radius * sin(angle);
            cout << "Вершины " << i + 1 << ": (" << newX << ", " << newY << ")" << endl;
        }
    }
}
