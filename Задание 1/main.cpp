#include <iostream>
using namespace std;

void getLenOfArr(int& row, int& column);
void inicializationOFArr(int row, int column, int **newArr, int arr1[]);
void foundMaxElOfRow(int row, int column, int **newArr);

int main()
{
	setlocale(0, "rus");

	int arr1[100] = { 16, 78, 99, 6, -29, 19, -52, 65, -88, 51,

	  -79, -22, 32, -25, -62, -69, -2, -59, -75, 89,

	  -87, 95, -22, 85, -49, -75, 76, 73, -59, -52,

	   30, 49, -28, -48, 0, 57, -6, -85, 0, -18,

	  -97, -21, -95, 64, 22, -2,69, -84, -1, -71,

	  -25, 47, 72, 43, 15, -44, 44, 61, 4, 74,

	   88, -61, 0, -64, -83, 97,  0, 90, 15, 8,

	  -54, 19, 73, 35, -67, -87, 85, -99, -70, 10,

	   98, 58, -10, -29, 95, 62, 77, 89, 36, -32,

	   78, 60, -79, -18, 30, -13, -34, -92, 1, -38 };
	int row;
	int column;
	// получаем размеры для массива
	getLenOfArr(row, column);
	// выделяем память под двумерный массив
	int** newArr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		newArr[i] = new int[column];
	}
	inicializationOFArr(row, column, newArr, arr1);
	foundMaxElOfRow(row, column, newArr);

	for (int i = 0; i < row; i++)
	{
		delete[] newArr[i];
	}
	delete[] newArr;

	return 0;
}


void getLenOfArr(int& row, int& column)
{
	cout << "Введите количество строк: ";
	cin >> row;
	cout << "Введите количество столбцов: ";
	cin >> column;
	std::cout << std::endl;
}

void inicializationOFArr(int row, int column, int** newArr, int arr1[])
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			newArr[i][j] = arr1[count++];
		}
	}
}

void foundMaxElOfRow(int row, int column, int** newArr)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		int maxEl = newArr[i][0];
		for (int j = 1; j <= column; j++)
		{
			if (count > 99)
			{
				std::cout << std::endl;
				std::cout << "Дальше в массиве лежит мусор!\n";
				return;
			}
			if (newArr[i][j] > maxEl)
				maxEl = newArr[i][j];

			count++;
		}
		std::cout << "Наибольший элемент строки " << i + 1 << ": " << maxEl << std::endl;
	}
}
