// ConsoleApplication17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cmath>
using namespace std;
void write();
void remove();
int maker( int nums);
void delet(int cnt);
void show();
int arr[4];
int deletable[1024];
int main()
{
   // SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    int for_auth;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    cout << "Здарова, петушара!\n Что собираешься делать? \n 1- Сделать запись\n 2- Отчистить запись \n 3- Посмотреть записи\n ";
    cin >> for_auth;
    switch(for_auth){
    case 1: write();
    case 2: remove();
    case 3:show();
    default: cout << "Бля, ты тупой?     Ступай отсюда...";
    }
}
void write() {
    FILE* inp = fopen("dates1.txt","a");
    cout << "Напишите дату в формате 01 01 1970\n";
    int d=0, m=0, y=0;
    string mes;
    cin >>d >>m >>y;
    fprintf(inp, "%d ", d); fprintf(inp, "%d ", m);fprintf(inp, "%d-", y);
    cout << "О чем вас уведомить?\n";
    cin >> mes;
    fprintf(inp, " %s\n", mes);

}
void remove() {
    FILE* inp = fopen("dates1.txt", "r");
    int d = 0, m = 0, y = 0, flag = 0, flags=0, nums=0, cnt=0, str=0;
    cout << "Напишите дату в формате 01 01 1970\n";
    cin >> d >> m >> y;
    int d1=0, m1=0, y1=0;
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
        if (c == '\n') { flags = 0;
        if ((d1 == d) and (m1 == m) and (y1 == y)) { deletable[cnt] = str; cnt++; str++; }
        }
    }
    fclose(inp);
    delet(cnt);

}
int maker(int nums) {
    int numsd = nums;
    int govno = 0;
    for (int i = 0; i<nums; i++) {
        govno += arr[i] * pow(10, numsd-1);
        numsd--;
    }

    return govno;
}
void delet(int cnt) {
    FILE* inp = fopen("dates1.txt", "w");
    int poop=0, flag=0;
    char c = 0;
    while (!feof(inp)) {
        for (int i = 0; i < 1024; i++) {
            if (poop == deletable[i]) { flag = 1; }
        }
      //  if ();
        c = fgetc(inp);
        if (c == '\n') { poop++; }
    }
}
void show() {
    FILE* inp = fopen("dates1.txt", "r");
    char c = 0;
    while (!feof(inp)) {
        c = fgetc(inp);
        cout << c;
    }
}

