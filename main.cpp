#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

struct Right_Mnogo{
    double len;
    int kolstr;
    double x;
    double y;
    double S;
    double P;
};


double Square(double dlin, int kolstr)
{
    double S;
    if (kolstr == 3){
        S = (sqrt(3.)*dlin*dlin)/4;
    }
    if (kolstr == 4){
        S = dlin*dlin;
    }
    else if(kolstr > 4){
        S = (dlin*dlin*kolstr)/(4*tan(M_PI/kolstr));
    }
    return S;
}

double Perim (double dlin, int kolstr)
{
    double P;
    P = dlin*kolstr;
    return P;
}

int main()
{
    setlocale(LC_ALL, "");
    Right_Mnogo one;
    cout << "������� ����� �������" << endl;
    cin >> one.len;
    cout << "������� ���������� ������" << endl;
    cin >> one.kolstr;
    cout << "������� ���������� x and y" << endl;
    cin >> one.x;
    cin >> one.y;
    one.S = Square(one.len, one.kolstr);
    cout << one.S << endl;
    one.P = Perim(one.len, one.kolstr);
    cout << one.P << endl;

    return 0;
}
