#include <iostream>
#include "ModulesKovalov.h"
#include "windows.h"

using namespace std;

int main()
{
    char letter = 0;
    information();
    while(true) {
        cout << "Щоб викликати s_calculation, то натиснiсть v: " << endl;
        cout << "Щоб порахувати зарплатню за кiлькiстю днiв, то натиснiть n: " << endl;
        cout << "Щоб перевести розмiр шкарпеток в iншу систему, то натиснiть m: " << endl;
        cout << "Щоб перевести число в двiйкову систему, то натиснiть q: " << endl;
        cout << "Щоб вийти з програми, то натиснiсть w або W: ";
        cin >> letter;
        cout << endl;
        if (letter == 'v')
            s_calculation();
        if (letter == 'n')
            calculation_salary();
        if (letter == 'm')
            sizeOfSocks();
        if (letter == 'q')
            binarySystem();
        if (letter == 'w' || letter == 'W') {
            break;
        }
        else {
            cout << endl << endl;
            Beep(370, 500);
        }
    }
    system("pause");
}
