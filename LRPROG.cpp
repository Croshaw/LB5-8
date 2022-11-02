#include <iostream>
#include <windows.h>

using namespace std;

void LR5_Zadanie_1()
{
	cout << "------------------------------------------->ЛР5 №1<-------------------------------------------" << endl;
	float array[50][50];
	float avg = 0;
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			array[i][j] = rand() % 50 + round(((float)rand() / RAND_MAX) * 100) / 100;
			cout << array[i][j] << "\t";
			if (j > i) {
				avg += array[i][j];
				count++;
			}
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "Сред. арифм. " << avg << endl;
}

void LR5_Zadanie_2()
{
	cout << "------------------------------------------->ЛР5 №2<-------------------------------------------" << endl;
	float array[50][50];
	int quanity = 0;
	float sum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			array[i][j] = rand() % 101 - 50 + round(((float)rand() / RAND_MAX) * 100) / 100;
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	for (int i = 0; i < 7; i++)
	{
		quanity = 0;
		sum = 0;
		int j = 0;
		while (quanity < 2 && j < 6)
		{
			if (array[j][i] > 0)
			{
				sum += array[j][i];
				quanity++;
			}
			j++;
		}
		array[6][i] = sum;
	}
	cout << "\n";
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
}

void LR5_Zadanie_3()
{
	cout << "------------------------------------------->ЛР5 №3<-------------------------------------------" << endl;
	int array[100][50];
	int n, m;
	cout << "Введите кол-во строк и столбцом через пробел(100, 50): ";
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i][j] = rand() % 101 - 50;
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	int temp;
	for (int i = 0; i < n; i++)
		for (int j = m-1; j > 0; j--)
			if (array[i][j] < 0)
				for (int b = 0; b < j; b++)
					if (array[i][b] > 0)
					{
						temp = array[i][b];
						array[i][b] = array[i][j];
						array[i][j] = temp;
					}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
}

void LR6_Zadanie_1()
{
	cout << "------------------------------------------->ЛР6 №1<-------------------------------------------" << endl;
	char array[50];
	cout << "Введите строку: ";
	cin.getline(array, 50);
	char gl[] = "ауеыоэяи ,.:;";
	int tempQ = 0;
	int quantity = 0;
	for (int i = 0; i < strlen(array); i++)
	{
		for (tempQ = 0; tempQ < strlen(gl); tempQ++)
			if (array[i] == gl[tempQ])
				break;

		if (tempQ == strlen(gl))
			quantity++;
	}
	cout << "Кол-во согласных: " << quantity << endl;
}

void LR6_Zadanie_2()
{
	cout << "------------------------------------------->ЛР6 №2<-------------------------------------------" << endl;
	char array[50];
	for (int c = 0; c < 5; c++)
	{
		int switcher = 0;
		cout << "Введите число: ";
		cin.getline(array, 50);
		for (int i = 0; i < strlen(array); i++)
		{
			if (array[i] != '0' && array[i] != '1')
			{
				cout << "Это не двоичное число!\n";
				switcher = 1;
				break;
			}
		}
		if (switcher == 0)
			cout << "Это двоичное число!\n";
	}
}

void LR7_Zadanie_1()
{
	cout << "------------------------------------------->ЛР7 №1<-------------------------------------------" << endl;
	int rows = 13;
	int columns = 15;
	int** array = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = rand() % 100;
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	int rowNum;
	cout << "Какую строку скопировать в конец? ";
	cin >> rowNum;
	rows++;
	int** array1 = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		if(i!=rows-1)
			array1[i] = array[i];
		else
		{
			array1[i] = new int[columns];
			for (int j = 0; j < columns; j++)
				array1[i][j] = array[rowNum-1][j];
		}
	}

	array = array1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << array[i][j] << "\t";
		cout << endl;
	}
	for (int i = 0; i < rows;i++)
		delete[] array[i];
	delete[] array;
}

#pragma region ЛР8 1 Задание
double GetLenVector(int x, int y, int z)
{
	return sqrt(pow(x, 2)+ pow(y, 2)+ pow(z, 2));
}

void LR8_Zadanie_1()
{
	cout << "------------------------------------------->ЛР8 №1<-------------------------------------------" << endl;
	double ALen = GetLenVector(8, 1, -1);
	double BLen = GetLenVector(2, 3, -6);
	double CLen = GetLenVector(1, 7, 4);
	double min = min(min(ALen, BLen), CLen);
	if (min == ALen) cout << "Точка A";
	if (min == BLen) cout << "Точка B";
	if (min == CLen) cout << "Точка C";
	cout << endl;
}
#pragma endregion

#pragma region ЛР8 2 Задание
int* GetMassive(int n)
{
	int* array = new int[n];
	
	for (int i = 0; i < n; i++)
		array[i] = rand() %  41 - 20;

	return array;
}

void ShowMassive(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}

int GetQuantityByNumber(int array[], int n, int num)
{
	int result=0;
	for (int i = 0; i < n; i++)
		if (array[i] % num == 0) result++;
	return result;
}

void LR8_Zadanie_2()
{
	cout << "------------------------------------------->ЛР8 №2<-------------------------------------------" << endl;
	int n = 20;
	int* U1 = GetMassive(n);
	int* U2 = GetMassive(n);
	ShowMassive(U1, n);
	cout << "Кол-во элементов кратных 3: " << GetQuantityByNumber(U1, n, 3) << endl;
	ShowMassive(U2, n);
	cout << "Кол-во элементов кратных 5: " << GetQuantityByNumber(U2, n, 5) << endl;
	delete[] U1;
	delete[] U2;
}
#pragma endregion

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	LR5_Zadanie_1();
	LR5_Zadanie_2();
	LR5_Zadanie_3();
	LR6_Zadanie_1();
	LR6_Zadanie_2();
	LR7_Zadanie_1();
	LR8_Zadanie_1();
	LR8_Zadanie_2();
}
