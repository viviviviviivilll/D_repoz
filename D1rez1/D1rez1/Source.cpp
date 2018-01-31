#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void Print_arr(int arr[], int si);
void Input_arr(int arr[], int si);
void Input_arr_rand(int arr[], int si);
void Sort_arr(int arr[], int si);
void Max_min_arr(int arr[], int si);
int Pos_max(int arr[], int si);
int Pos_min(int arr[], int si);
bool compared(int arr[], int arr1[], int si);
void Copy_arr(int arr1[], int arr[], int si);

const int Size = 10;

void main()
{
	int arr[Size], arr1[Size];
	Input_arr_rand(arr, Size); Sleep(1000);
	Input_arr_rand(arr1, Size);
	cout << endl;
	Sort_arr(arr, Size);
	cout << "First arr:" << endl;
	Print_arr(arr, Size);
	cout << endl;
	cout << "Max element have " << Pos_max(arr, Size) + 1 << " index, this " << arr[Pos_max(arr, Size)] << endl;
	cout << "Min element have " << Pos_min(arr, Size) + 1 << " index, this " << arr[Pos_min(arr, Size)] << endl;
	cout << endl;
	cout << "Second arr:" << endl;
	Print_arr(arr1, Size);
	cout << endl;
	cout << "Compared: " << boolalpha << compared(arr1, arr, Size) << endl;
	cout << endl;
	Max_min_arr(arr, Size);
	Copy_arr(arr1, arr, Size);
	Print_arr(arr1, Size);

	cout << endl;
	cout << "Hello world" << endl;
	int OK;
	cin >> OK;
}



void Input_arr(int arr[], int si)
{
	for (int i = 0; i < si; i++)
	{
		cout << "Input " << i + 1 << " element: ";
		cin >> arr[i];
	}
}

void Input_arr_rand(int arr[], int si)
{
	srand(time(0));
	for (int i = 0; i < si; i++)
	{
		arr[i] = rand() % 50 - 25;
	}
}

void Print_arr(int arr[], int si)
{
	for (int i = 0; i < si; i++)
	{
		cout << i + 1 << ")  " << arr[i] << endl;
	}
}


void Sort_arr(int arr[], int si)
{

	for (int i = 0; i < si - 1; i++)
	{
		int min = arr[i], indmin = i;
		for (int j = i; j < si; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				indmin = j;
			}
		}
		swap(arr[i], arr[indmin]);
	}

}

void Max_min_arr(int arr[], int si)
{
	cout << "Min: " << arr[0] << endl;
	cout << "Max: " << arr[si - 1] << endl;
}

int Pos_max(int arr[], int si)
{
	int pos = 0;
	for (int i = 0; i < si; i++)
	{
		if (arr[i] > arr[pos]) pos = i;
	}
	return pos;
}

int Pos_min(int arr[], int si)
{
	int pos = 0;
	for (int i = 0; i < si; i++)
	{
		if (arr[i] < arr[pos]) pos = i;
	}
	return pos;
}

bool compared(int arr[], int arr1[], int si)
{
	for (int i = 0; i < si; i++)
	{
		if (arr[i] != arr1[i]) return false;
	}
	return true;
}


void Copy_arr(int arr1[], int arr[], int si)
{
	for (int i = 0; i < si; i++)
	{
		arr1[i] = arr[i];
	}
}






