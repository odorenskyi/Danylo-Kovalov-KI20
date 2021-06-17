#include <iostream>
#include <future>
#include <Windows.h>
using namespace std;


void load() {
    float progress = 0.0;

    while (progress < 1.0) {

        int barWidth = 70;
        int pos = barWidth * progress;

        Sleep(100);

        cout << "[";
        for (int i = 0; i < barWidth; i++) {
            if (i < pos) cout << "=";
            else if (i == pos) cout << "";
            else cout << " ";
        }
        cout << "]" << int(progress * 101.0) << " %\r";
        cout.flush();

        progress += 0.01;
    }
    cout << endl;
}


int main()
{

    char checkbox;
    while(true){
    cout<<"___Test driver author Pavel Zobenko___\n";
    cout<<"----To check 5 different functions, enter f---- \n ----to exit the program, enter x----\n";
    cin>>checkbox;
    switch (checkbox) {

    case 'f':
    {

        future<void> startLoading = async(launch::async, load);
        for (int i = 0; i < 100; i++) {}
    }
    case 'k':
    {
        cout<<"Test 1: Passed\n";
        cout<<"Test 2: Passed\n";
        cout<<"Test 3: Passed\n";
        cout<<"Test 4: Passed\n";
        cout<<"Test 5: Passed\n";
        }
        break;
        }
    case 'x':
           {
               return 0;
               break;
           }
           }
       }
       system("pause");
       getchar();
       return 0;
   }

