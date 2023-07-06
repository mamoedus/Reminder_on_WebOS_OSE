#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
int arr[4];
using namespace std;
string text(int strings);
int maker(int nums) {
    int numsd = nums;
    int sum = 0;
    for (int i = 0; i < nums; i++) {
        sum += arr[i] * pow(10, numsd - 1);
        numsd--;
    }

    return sum;
}
int main() {
    // current date/time based on current system
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // print various components of tm structure.
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    while (1) {
    B:;
        FILE* inp = fopen("dates1.txt", "r");

        int d = 0, m = 0, y = 0, flag = 0, flags = 0, nums = 0, cnt = 0, str = 0, cont = 0,strings=1;
        int d1 = 0, m1 = 0, y1 = 0;
        char c = 0;
        while (!feof(inp)) {
            c = fgetc(inp);
            if (flags != 3) {
                if (c != 32) {
                    arr[nums] = c - 48;
                    nums++;

                }
                else {
                    flags++;
                    if (flags == 1) { d1 = maker(nums); nums = 0; for (int i = 0; i < nums; i++) { arr[i] = 0; } }
                    else if (flags == 2) { m1 = maker(nums); nums = 0; for (int i = 0; i < nums; i++) { arr[i] = 0; } }
                    else if (flags == 3) { y1 = maker(nums); nums = 0; for (int i = 0; i < nums; i++) { arr[i] = 0; } }
                }
            }
            if (c == '\n') {
                flags = 0;
                strings++;
            }
            if (d1 == ltm->tm_mday) {
                if (m1 == 1 + ltm->tm_mon) {
                    if (y1 == 1900 + ltm->tm_year) {//fix0
                        FreeConsole();
                      //  string message = 0;
                    //    message= text(strings);
                        
                        int mess = MessageBoxA(NULL, "Нажмите ДА, если требуется напомнить через час\nНажмите НЕТ для отключения уведомлений на сегодня ", "Напоминание", MB_YESNO | MB_ICONASTERISK);
                        switch (mess)
                        {
                        case IDYES:
                            cout << "scan ended for hour\n";
                            fclose(inp);
                            Sleep(3600000);
                            goto B;

                        case IDNO:
                            int a = 1440 - ((ltm->tm_hour) * 60 + ltm->tm_min);
                            a = a * 60 * 1000;
                            fclose(inp);
                            cout << "scan ended till days ens\n";
                            Sleep(a);
                            goto B;
                        }


                        goto A;
                    }
                }
            }
        }
    A:;

        fclose(inp);//fix1
        Sleep(1000000);//fix1
        cout << "scan ended\n";


    }
    
}
string text(int strings) {
    FILE* inp = fopen("dates1.txt", "r");
    char c = 0;
    char text[100];
    int control = 1,flag=0,i=0;
    while (!feof(inp)) {
        c = fgetc(inp);
        if (control==strings) {
            if (c == 45) {
                flag = 1;
            }
            if (flag == 1) {
                text[i] = c;
                i++;
            }
        }

        if (c=='\n') {
            control++;
            flag = 0;
        }



    }

    string str(text);


    return str;
}
