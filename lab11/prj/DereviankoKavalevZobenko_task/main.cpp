#include <iostream>
#include <list>
#include <bits/stdc++.h>
#include <codecvt>
#include <locale>
#include <iostream>
#include <windows.h>
#include <clocale>
#include <wchar.h>
#include <fcntl.h>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

using namespace std;

class Index {
private:
    wstring index;
    wstring city;
    wstring area;
    wstring locality;
    wstring vpz;
public:
    bool operator == (Index test) {
        return index == test.getIndex()
               && city == test.getCity()
               && area == test.getArea()
               && locality == test.getLocality()
               && vpz == test.getVpz();
    }

    bool operator != (Index test) { return !operator==(test);}

    Index(wstring index, wstring city, wstring area, wstring locality, wstring vpz) {
        this->index = index;
        this->city = city;
        this->area = area;
        this->locality = locality;
        this->vpz = vpz;
    }

    wstring getIndex() {
        return index;
    }

    void setIndex(wstring index) {
        this->index = index;
    }

    wstring getCity() {
        return city;
    }

    void setCity(wstring city) {
        this->city = city;
    }

    wstring getArea() {
        return area;
    }

    void setArea(wstring area) {
        this->area = area;
    }

    wstring getLocality() {
        return locality;
    }

    void setLocality(wstring locality) {
        this->locality = locality;
    }

    wstring getVpz() {
        return vpz;
    }

    void setVpz(wstring vpz) {
        this->vpz = vpz;
    }

    wstring toString() {
        wstring s = index + L" " + city + L" " + area + L" " + locality + L" " + vpz;
        return s;
    }
};

void sout(list<Index> List) {
    list<Index>::iterator it;

    for(it = List.begin(); it != List.end(); it++)
        wcout << it->toString() <<'\n';
}

string wstringToString(wstring s) {
    string str(s.begin(), s.end());
    return str;
}

void finishWork(list<Index> *List, wstring ouputFile) {
    list<Index>::iterator it;
    fstream appendFileToWorkWith;
    appendFileToWorkWith.open(wstringToString(ouputFile),  fstream::in | fstream::out | fstream::trunc);

    for (it = List->begin(); it != List->end(); it++) {
        appendFileToWorkWith << wstringToString(it->toString()) << "\n";
    }
}

list<Index> readFile(wstring file, list<Index> indexList) {
    ifstream reader;
    reader.open(wstringToString(file));
    wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    if (reader.is_open()) {
        string s;
        while(getline(reader, s)){
            stringstream ss(s);
            string word;
            vector<string> strings;
            for (int i = 0; ss >> word; i++) {
                strings.push_back(word);
            }

            string vpz;
            for (int i = 4; i < strings.size(); i++) {
                vpz += strings[i] + " ";
            }

            Index index(converter.from_bytes(strings[0]),
                        converter.from_bytes(strings[1]),
                        converter.from_bytes(strings[2]),
                        converter.from_bytes(strings[3]),
                        converter.from_bytes(vpz));
            indexList.push_back(index);
        }

        reader.close();
    }

    return indexList;
}

Index iteratorToIndex(list<Index>::iterator it) {
    Index index(it->getIndex(), it->getCity(), it->getArea(), it->getLocality(), it->getVpz());
    return index;
}

Index search(list<Index> indexes) {
    wcout << L"Віберіть по чтому хочете знайти данні: " << endl;
    wcout << L"1.Індекс" << endl << L"2.Місто" << endl << L"3.Область" << endl << L"4.Район" << endl << L"5.ВПЗ" << endl;
    int searchBy = 0;
    do {
        wcin >> searchBy;
        if (searchBy <= 0 || searchBy > 5) {
            wcout << L"Уведіть вірні данні" << endl;
        }
    } while (searchBy <= 0 || searchBy > 5);

    wcout << L"Зараз будь ласка уведіть значення: " << endl;
    wstring searchData;
    wcin >> searchData;

    list<Index>::iterator it;
    switch (searchBy) {
        case 1:
            for (it = indexes.begin(); it != indexes.end(); it++) {
                if (it->getIndex() == searchData) {
                    return iteratorToIndex(it);
                }
            }
            break;
        case 2:
            for (it = indexes.begin(); it != indexes.end(); it++) {
                if (it->getCity() == searchData) {
                    return iteratorToIndex(it);
                }
            }
            break;
        case 3:
            for (it = indexes.begin(); it != indexes.end(); it++) {
                if (it->getArea() == searchData) {
                    return iteratorToIndex(it);
                }
            }
            break;
        case 4:
            for (it = indexes.begin(); it != indexes.end(); it++) {
                if (it->getLocality() == searchData) {
                    return iteratorToIndex(it);
                }
            }
            break;
        case 5:
            for (it = indexes.begin(); it != indexes.end(); it++) {
                if (it->getVpz() == searchData) {
                    return iteratorToIndex(it);
                }
            }
            break;
    }

    Index nothing(L"", L"", L"", L"", L"");
    return nothing;
}

list<Index> addNewIndex(list<Index> indexes) {
    wstring index;
    wstring city;
    wstring area;
    wstring locality;
    wstring vpz;
    wcout << L"Уведіть індекс:" << endl;
    wcin >> index;
    wcout << L"Уведіть місто: " << endl;
    wcin >> city;
    wcout << L"Уведіть область: " << endl;
    wcin >> area;
    wcout << L"Уведіть район: " << endl;
    wcin >> locality;
    wcout << L"Уведіть впз: " << endl;
    wcin.ignore();
    getline(wcin, vpz);

    Index object(index, city, area, locality, vpz);
    wcout << object.toString() << endl;
    indexes.push_back(object);

    return indexes;
}

list<Index> remove(list<Index> indexes) {
    bool removed = false;
    wstring index;
    wcout << L"Будь ласка уведіть індекс запису який ви хочете видалити: " << endl;
    wcin >> index;

    list<Index>::iterator it;
    for (it = indexes.begin(); it != indexes.end(); it++) {
        if (it->getIndex() == index) {
            wcout << L"Видалення об'екту: " << iteratorToIndex(it).toString() << endl;
            indexes.remove(iteratorToIndex(it));
            removed = true;
            break;
        }
    }

    if (!removed) {
        wcout << L"Нічого не булло видалено!" << endl;
    }

    return indexes;
}

void localisation() {
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(fileno(stdout), _O_U8TEXT);
}

int main() {
    list<Index> indexes;

    localisation();

    char input = 0;
    wstring fileName;
    wcout << L"Уведіть назву файлу який будемо читати: " << endl;
    wcin >> fileName;

    do {
        indexes = readFile(fileName, indexes);

        wcout << L"Уведiть \"u\" – для виведення данних із файлу, \"t\" – для додання нового запису, " << endl;
        wcout << L"\"r\" – для пошуку по файлу, \"e\" - для видалення запису із файла" << endl;
        cin >> input;

        if (input == 'u') {
            sout(indexes);

            wcout << L"Для виходу уведiть \"w\"  або \"i\":" << endl;
            cin >> input;
        } else if (input == 't') {
            indexes = addNewIndex(indexes);

            wcout << L"Для виходу уведiть \"w\" або \"i\":" << endl;
            cin >> input;
        } else if (input == 'r') {
            Index index = search(indexes);
            Index empty(L"", L"", L"", L"", L"");

            if (index == empty) {
                wcout << L"Нічого не було знайдено" << endl;
            } else {
                wcout << index.toString() << endl;
            }

            wcout << L"Для виходу уведiть \"w\"  або \"i\":" << endl;
            cin >> input;
        } else if (input == 'e') {
            indexes = remove(indexes);

            wcout << L"Для виходу уведiть \"w\"  або \"i\":" << endl;
            cin >> input;
        } else if (input != 'w' && input != 'i') {
            Beep(523, 500);
            wcout << L"Не вiрний ввод" << endl;
        }
    } while (input != 'w' && input != 'i');

    finishWork(&indexes, fileName);

    system("pause");
    return 0;
}
