#define button1_click 1
#define button2_click 2
#define button3_click 3
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <windows.h>

LRESULT CALLBACK SoftmainProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWinClass(HBRUSH BGcolor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Proc);
void widgets(HWND hwnd);
void write();
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR args, int ncmdshow) {

	WNDCLASS softmainclass= NewWinClass((HBRUSH) COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),L"MainWndClass", SoftmainProc);
	if (!RegisterClassW(&softmainclass)) { return -1; }
	MSG SoftMainMsg = { 0 };
	CreateWindow(L"MainWndClass", L"Напоминания", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL);
	while (GetMessage(&SoftMainMsg, NULL, NULL, NULL)) {
		TranslateMessage(&SoftMainMsg);
		DispatchMessage(&SoftMainMsg);
	}return 0;
}
WNDCLASS NewWinClass(HBRUSH BGcolor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Proc) {
	WNDCLASS NWC = { 0 };
	NWC.hCursor = Cursor;
	NWC.hIcon = Icon;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGcolor;
	NWC.lpfnWndProc = Proc;
	return NWC;
}
LRESULT CALLBACK SoftmainProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case button1_click:
			 write(); break;
		case button2_click:
			MessageBoxA(hwnd, "Слышь, тебя тут быть не должно, так что давай, ступай", "В разработке", MB_OK); break;
		case button3_click:
			system("dates1.txt"); break;
		}
	case WM_CREATE:
		widgets(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hwnd, msg, wp, lp);
	}
}
void widgets(HWND hwnd) {
	CreateWindowA("static", "Введите дату и нажатием кнопки выберите действие:", WS_VISIBLE | WS_CHILD, 5, 5, 490, 20, hwnd, NULL, NULL, NULL);
	CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD, 5, 30, 490, 20, hwnd, NULL, NULL, NULL);
	CreateWindowA("button", "Добавить Напоминание", WS_VISIBLE | WS_CHILD, 5, 45, 490, 20, hwnd, (HMENU)button1_click, NULL, NULL);
	CreateWindowA("button", "Удалить Напоминание", WS_VISIBLE | WS_CHILD, 5, 70, 490, 20, hwnd, (HMENU)button2_click, NULL, NULL);
	CreateWindowA("button", "Посмотреть Записи", WS_VISIBLE | WS_CHILD, 5, 95, 490, 20, hwnd, (HMENU)button3_click, NULL, NULL);
}
using namespace std;
void write() {
	FILE* inp = fopen("dates1.txt", "a");
	//GetWindowText();
	int d = 0, m = 0, y = 0;
	string mes;
	cin >> d >> m >> y;
	fprintf(inp, "%d ", d); fprintf(inp, "%d ", m); fprintf(inp, "%d-", y);
	cout << "О чем вас уведомить?\n";
	cin >> mes;
	fprintf(inp, " %s\n", mes);

}