#ifndef MODULESKOVALOV_H
#define MODULESKOVALOV_H

#include <iostream>
#include <math.h>

using namespace std;

string information() {
    string inf = "<<C>>Розробник: Ковальов Данило";
    cout << inf << endl;
    return inf;
}

bool logicalExpression(){
    char a = 0;
    char b = 0;
    cout << "Введiть а:";
    cin >> a;
    cout << "Введiть b: ";
    cin >> b;
    if(a+10 >= b){
        cout << "Результат: ";
        return true;
    }
    else {
        cout << "Результат: ";
        return false;
    }
}
int check(int number) {
    bool valid = false;
    while (!valid){
        valid = true;
        cin >> number;
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            valid = false;
        }
    }
    return number;
}

double s_calculation() {
    double x = 0, y = 0, z = 0, S = 0;
    const double PI = 3.141592653589793;
    cout << "Введiть х: ";
    x = check(x);
    while(x < 0|| x == 0){
        if(x < 0 || x == 0){
            cout << "x не може бути вiд'ємним. ";
        }
        x = check(x);
    }
    while(x < y || y == 0 || y < 0 || y == x-1) {
        cout << "Введiть у: ";
        if(x <= y || y < 0) {
            cout << "y не може бути бiльше або дорiвнювати х:  ";
        }
        y = check(y);
    }
    while(z == 0 || z < 0){
        cout << "Введiть z: ";
        if(z < 0 || z == 0){
            cout << "z не може бути менше або дорiвнювати нулю.  ";
        }
        z = check(z);
    }
    S = (z + (2*pow(y,2)))/(log(x - y)) + sqrt(PI * x);
    cout << "Результат: " << S;
    return S;
}

#endif // MODULESKOVALOV_H
