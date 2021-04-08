#include <iostream>
#include <math.h>
#include <locale.h>
#include "windows.h"

using namespace std;

int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    double x = 0, y = 0, z = 0, S = 0;
    const double PI = 3.141592653589793;
    cout << "Введ?ть x: ";
    cin >> x;
    cout << "Введ?ть y: ";
    cin >> y;
    cout << "Введ?ть z: ";
    cin >> z;
    S = (z + 2*pow(y,2))/(log(x - y)) + sqrt(PI * x);
    cout << "Результат: " << S;
}
