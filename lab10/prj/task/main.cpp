#include<iostream>
#include<io.h>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <clocale>
#include <windows.h>
#include <codecvt>
#include <ctime>
#include<cmath>
#include "ModulesKovalov.h"

using namespace std;

void LOcalizal() {
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}
int main()
{
    LOcalizal();
    wstring vowels;
    wstring word;
    wstring str;
    wchar_t check;
    while(true) {
        wcout << L"Щоб дiзнатися чи є буква iз вхiдного файлу у вихiдному , натиснiть t: " << endl;
        wcout << L"Щоб дозаписати у файл, натиснiть l: " << endl;
        wcout << L"Щоб перевести число у двiйкову систему, натиснiть g: " << endl;
        wcout << L"Щоб викликати функцiю s_calculation, натиснiть j: " << endl;
        wcout << L"Щоб завершити роботу, натиснiть f: " << endl;
        wcin >> check;
        switch(check) {
        case 't': {
            checkingFile();
            wifstream op;
            wstring line;
            op.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
            op.open("inputText.txt");
            op>>line;
            op.close();
            wstring text = L"До щастя не пускає лінощів орава\nУ чім воно - ніхто не знає до пуття.\nНавчитись радісно робити кожну справу -\nНайперше правило щасливого життя.\n";
            wofstream output;
            wstring vowels;
            for (int i = 0; text[i]; i++) {
                if (text[i] == L'а' || text[i] == L'е' || text[i] == L'и' || text[i] == L'i' || text[i] == L'о' || text[i] == L'у' || text[i] == L'я' || text[i] == L'ю' || text[i] == L'є' || text[i] == L'ї') {
                    vowels += text[i];
                }
            }
            wstring info = {L"Розробник: Ковальов Данило; ЦНТУ,Кропивницький, Україна, 2021 рiк.\n"};
            output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
            output.open("outputText.txt");
            if(wcsstr(text.c_str(), line.c_str())){
               output <<L"Слово знайдено\n";
            }
            else {
               output << L"Слова не має\n";
            }
            output << info << L"Перевірка на голосні букви: " << vowels;
            output.close();
            break;
        }
        case 'l': {
            wofstream entr;
            wstring str = L"Життя";
            entr.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
            entr.open("inputText.txt", ios_base::app);
            time_t currentTime;
            currentTime = time(NULL);
            tm *tm_local = localtime(&currentTime);
            for (int i = 0; str[i]; i++) {
                if (str[i] >= L'А' && str[i] <= L'Я') {
                    str[i] = rand();
                }
            }
            entr << L"\nЧас: " << tm_local -> tm_hour << ":" << tm_local -> tm_min << endl << L"Замiнено велику букву на випадковий символ: " << str;
            entr.close();
            break;
        }
        case 'g':
            binarySystem();
            break;
        case 'j':
            s_calculation();
            break;
        case 'f':
            return 0;
            break;
        }
    }
}
