#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<time.h>
using namespace std;

const int r = 5;
const int s = 5;
int arr[r][s];
int min = 50;
int tmpX, tmpY;

void SetPos(int x, int y)
{
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setbackcolor(int col, int back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((back << 4) | col));
}

void PpP(int num) {
	if (num == min) {
		setbackcolor(0, 14);
		cout << num;
		setbackcolor(7, 0);
	}
	else {
		cout << num;
	}
}

void mars(int i, int j, int r, bool s) {
	if (s) {
		int temp = 0;
		temp = arr[r][i];
		arr[r][i] = arr[r][j];
		arr[r][j] = temp;
		temp = 0;
	}
	else {
		int temp = 0;
		temp = arr[i][r];
		arr[i][r] = arr[j][r];
		arr[j][r] = temp;
		temp = 0;
	}
}

void clear(int x, int n) {
	SetPos(0, x);
	for (int i = 0; i < n; i++)
	{
		cout << ' ';
	}
}

void clearY(int x, int n) {
	for (size_t i = 0; i < n; i++)
	{
		SetPos(x, i);
		cout << "  ";
	}
}

void printY(int x, int n, int f) {
	int tmp = 0;
	for (size_t i = n; i < r + n; i++)
	{
		SetPos(r * 2 + (x * 3), i);
		PpP(arr[tmp][f]);
		tmp++;
	}
}

void printX(int x, int n, int f) {
	int tmp = 0;
	for (size_t i = n; i < r + n; i++)
	{
		SetPos(x, i);
		PpP(arr[tmp][f]);
		tmp++;
	}
}

void print_kol(int x1, int x2) {
	if (x1 != x2) {
		for (size_t i = 0; i <= r; i++)
		{
			clearY(r * 2 + (x1 * 3), r * 4);
			clearY(r * 2 + (x2 * 3), r * 4);
			if (x1 < x2) {
				printY(x1, r - i, x1);
				printY(x2, r + i, x2);
				Sleep(100);
			}
			else if (x1 > x2) {
				printY(x1, r + i, x1);
				printY(x2, r - i, x2);
				Sleep(100);
			}
		}
		for (size_t i = 0; i <= abs(x1 - x2) * 3; i++)
		{

			for (size_t j = 0; j < r; j++) { clear(j, 100); clear(r * 2 + j, 100); }
			if (x1 < x2) {
				printX(r * 2 + (x1 * 3) + i, 0, x1);
				printX(r * 2 + (x2 * 3) - i, r * 2, x2);
				Sleep(50);
			}
			else if (x1 > x2) {
				printX(r * 2 + (x1 * 3) - i, r * 2, x1);
				printX(r * 2 + (x2 * 3) + i, 0, x2);
				Sleep(50);
			}
		}
		for (size_t i = 0; i <= r; i++)
		{
			clearY(r * 2 + (x1 * 3), r * 4);
			clearY(r * 2 + (x2 * 3), r * 4);
			if (x1 < x2) {
				printY(x1 + abs(x1 - x2), 0 + i, x1);
				printY(x2 - abs(x1 - x2), r * 2 - i, x2);
				Sleep(100);
			}
			else if (x1 > x2) {
				printY(x1 - abs(x1 - x2), r * 2 - i, x1);
				printY(x2 + abs(x1 - x2), 0 + i, x2);
				Sleep(100);
			}
		}
	}
	for (size_t i = 0; i < s; i++)
	{
		mars(x1, x2, i, 1);
	}
}

void print_st(int y1, int y2) {

	for (size_t i = 0; i <= r * 3; i++)
	{
		clear(y1 + r, 30);
		clear(y2 + r, 30);
		SetPos(r * 3 + i, y1 + r);
		for (size_t j = 0; j < s; j++)
		{
			PpP(arr[y1][j]);
			cout << ' ';
		}
		SetPos(r * 3 - i, y2 + r);
		for (size_t j = 0; j < s; j++)
		{
			PpP(arr[y2][j]);
			cout << ' ';
		}
		Sleep(100);
	}
	for (size_t i = 0; i <= abs(y1 - y2); i++)
	{
		for (size_t j = 0; j < r * 3; j++)
		{
			clearY(j, r * 3);
			clearY(r * 6 + j, r * 3);
		}
		SetPos(r * 3 + r * 3, y1 + r + i);
		for (size_t j = 0; j < r; j++)
		{
			PpP(arr[y1][j]);
			cout << ' ';

		}
		SetPos(0, y2 + r - i);
		for (size_t j = 0; j < r; j++)
		{
			PpP(arr[y2][j]);
			cout << ' ';

		}
		Sleep(100);
	}
	for (size_t i = 0; i <= r * 3; i++)
	{
		clear(y1 + r, 30);
		clear(y2 + r, 30);
		SetPos(r * 3 + r * 3 - i, y1 + r + abs(y1 - y2));
		for (size_t j = 0; j < s; j++)
		{
			PpP(arr[y1][j]);
			cout << ' ';

		}
		SetPos(0 + i, y2 + r - abs(y1 - y2));
		for (size_t j = 0; j < s; j++)
		{
			PpP(arr[y2][j]);
			cout << ' ';

		}
		Sleep(100);
	}
	for (size_t i = 0; i < s; i++)
	{
		mars(y1, y2, i, 0);
	}

}

void main()
{
	srand(time(NULL));
	int g, f;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			arr[i][j] = rand() % 90 + 10;
			if (arr[i][j] < min) {
				min = arr[i][j];
				tmpX = j;
				tmpY = i;
			}
			//min = (arr[i][j] < min) ? arr[i][j] : min;

		}
	}
	SetPos(r * 3, r);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			PpP(arr[i][j]);
			cout << ' ';
		}
		SetPos(r * 3, r + i + 1);
	}
	cout << "enter I :";
	cin >> g;
	cout << "enter II:";
	cin >> f;
	_getch();
	/*for (size_t i = 0; i < 4; i++)
	{
	for (int i = 0; i < r; i++)
	{
	for (int j = 0; j < s; j++)
	{
	if (arr[i][j] < min) {
	min = arr[i][j];
	tmpX = j;
	tmpY = i;
	}
	}
	}
	if (tmpX != r-1) {
	print_kol(tmpX, r-1);
	}
	else {
	if (tmpY != 0) {
	print_st(0, tmpY);
	}
	}
	}*/
	print_st(g, f);
	SetPos(r * 3, r);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			PpP(arr[i][j]);
			cout << ' ';
		}
		SetPos(r * 3, r + i + 1);
	}

	_getch();
	system("pause");
}