#include <iostream>
#include <math.h>
#include <locale.h>
#include "windows.h"
#include "ModulesKovalov.h"

using namespace std;

int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    information();
    cout << logicalExpression() << endl;
    s_calculation();
}
