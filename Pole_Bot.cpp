#include "Header.h"

int rand_arr(int r_arr[10][10], int r_rows, int r_cols) //—лучайным образом ставит корабли
{
	int foo_sum_result = 0;
	srand(time(NULL));
	for (int g = 0; g < 10; g++) // выводим координату Ѕ
	{
		cout << "\tЅ-" << g;
	}
	cout << "\n";
	for (int i = 0; i < r_rows; i++)
	{
		cout << "A-" << i;                         //координата ј
		for (int j = 0; j < r_cols; j++)
		{
			if (foo_sum_result != 10)             //услови если кораблей (1) меньше 10 то продолжаем ставить 1
			{
				r_arr[i][j] = rand() % 10;         // генерируем почти случайные числа
				if (r_arr[i][j] < 2)              //если меньше 2 то это 1
					r_arr[i][j] = 1;
				else
					r_arr[i][j] = 0;                  //иначе 0
				foo_sum_result += r_arr[i][j];       //считаем до 10
			}
			else
				foo_sum_result += r_arr[i][j];     //продолжаем подсчет 
			
			if (r_arr[i][j] == 0)  //выводим строки массива
				cout << "\t#";
			if (r_arr[i][j] == 1) 
				cout << "\t#";
			if (r_arr[i][j] == 2)
				cout << "\t@";
			if (r_arr[i][j] == 3)
				cout << "\t*";
			
		}
		cout << '\n' << endl;                   //пробел
	}
	cout << " ораблей на плаву - " << foo_sum_result << endl;     //выводим суму всех кораблей

	return 0;
}
