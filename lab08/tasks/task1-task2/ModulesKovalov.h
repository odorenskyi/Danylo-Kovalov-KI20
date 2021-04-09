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
    while (!(cout <<"Введiть a: ",cin >> a && cout<<"Введiть b: ",cin>>b)){
        cout << "Помилка\n";
        cin.clear();
        fflush(stdin);
    }
    if(a+10 >= b){
        cout << "Результат: ";
        return true;
    }
    else{
        cout << "Результат: ";
        return false;
    }
}

double s_calculation() {
    double x = 0, y = 0, z = 0, S = 0;
    const double PI = 3.141592653589793;
    cout << "Введiть x: ";
    cin >> x;
    cout << "Введiть y: ";
    cin >> y;
    cout << "Введiть z: ";
    cin >> z;
    if (x < y) {
        if (z < y) {
            cout << "ERROR";
        }
    }
    else {
        S = (z + 2*pow(y,2))/(log(x - y)) + sqrt(PI * x);
        cout << "Результат: " << S;
    }
    if (S < 0)
        cout << "ERROR";
    return S;
}

#endif // MODULESKOVALOV_H
