#ifndef MODULESKOVALOV_H
#define MODULESKOVALOV_H

#include <iostream>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include<codecvt>

using namespace std;

std::wifstream::pos_type filesize(const char* filename)
{
    std::wifstream in(filename, std::wifstream::ate | std::wifstream::binary);
    return in.tellg();
}

void localization(){
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

void checkingFile () {
    localization();
    wifstream in;
    in.open("inputText.txt");
    if (!(in.is_open())) {
        wcout << L"Файл не знайдено...";
    }
    else {
        wcout << L"Файл успiшно вiдкритий" << endl;
    }
}

int validationForBinary(){
    localization();
    int i = 0;
    while (!(wcin >> i)) {
        wcout << L"Введiть число: ";
        wcin.clear();
        fflush(stdin);
    }
    while(i < 0 || i == 0 || i > 7483650) {
        if(i < 0 || i == 0 || i > 7483650) {
            wcout << L"Число повинне бути бiльше 0 та менше 7483650: ";
            wcin.clear();
            fflush(stdin);
        }
        i = validationForBinary();
    }
    return i;
}
void binarySystem()
{
    localization();
    wcout << L"Введiть число вiд 0 до 7483650: ";
    wstring str = L"";
    int num1 = 0, i = 0, counterNull = 0, counterOne = 0, num2 = 0;
    num1 = validationForBinary();
    while (num1) {
        num2 = num1 % 2;
        num1 = num1 / 2;
        str = to_wstring(num2) + str;
    }
    while (str[i]) {
        if(str[i] == '0')
            counterNull++;
        else if(str[i] == '1')
            counterOne++;
        i++;
    }
    wofstream f;
    f.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    f.open("outputText.txt", ios_base::app);
    f << L"\n0 бiт: " << str[str.length() - 1] << endl << L"\nДвійковий код: " << str;
    f.close();
    if (str[str.length() - 1] == '0') {
        wofstream f;
        f.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        f.open("outputText.txt", ios_base::app);
        f << L"\nКiлькiсть 0: " << counterNull << endl;
        f.close();
    }
    else {
        wofstream f;
        f.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        f.open("outputText.txt", ios_base::app);
        f << L"\nКiлькiсть 1: " << counterOne << endl;
        f.close();
    }
}
int check(int number) {
    bool valid = false;
    while (!valid){
        valid = true;
        wcin >> number;
        if(wcin.fail()) {
            wcin.clear();
            wcin.ignore();
            valid = false;
        }
    }
    return number;
}
double s_calculation() {
    double x = 0, y = 0, z = 0, S = 0;
    const double PI = 3.141592653589793;
    wcout << L"Введiть х: ";
    x = check(x);
    while(x < 0|| x == 0){
        if(x < 0 || x == 0){
            wcout << L"х не може бути менше 0";
        }
        x = check(x);
    }
    while(x < y || y == 0 || y < 0 || y == x-1) {
        wcout << L"Введiть у: ";
        if(x <= y || y < 0) {
            wcout << L"y не може бути бiльше х та менше нуля: ";
        }
        y = check(y);
    }
    while(z == 0 || z < 0){
        wcout << L"Введiть z: ";
        if(z < 0 || z == 0){
            wcout << L"z не може бути або дорiвнювати нулю.  ";
        }
        z = check(z);
    }
    S = (z + (2*pow(y,2)))/(log(x - y)) + sqrt(PI * x);
    wofstream f;
    f.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    f.open("outputText.txt", ios_base::app);
    f << L"Результат: " << S << endl;
    f.close();
    return S;
}
#endif // MODULESKOVALOV_H
