#include <iostream>

using namespace std;


void Zadanie_1()
{
	srand(time(0));
	float array[50][50];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			array[i][j] = rand() % 50 + round(((float)rand() / RAND_MAX) * 100) / 100;
			std::cout << array[i][j] << "\t";
		}
		std::cout << "\n";
	}

	cout << "\n";
	float avg = 0;
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			avg += array[i][j];
			count++;
		}
	}
	avg /= count;
	cout << "ׁנוה. אנטפל. " << avg;
}