#include "Header.h"

int Batle_Human(int b_arr[10][10], int b_rows, int b_cols)//после выстрела здесть мы просто выводим поле и подсчитываем корабли
{
	int foo_sum_result = 0;
	for (int g = 0; g < 10; g++) // выводим координату Ѕ
	{
		cout << "\tЅ-" << g;
	}
	cout << "\n";
	for (int i = 0; i < b_rows; i++)
	{
		cout << "A-" << i;                           //координата ј

		for (int j = 0; j < b_cols; j++)
		{
			if (b_arr[i][j] == 1)
				foo_sum_result += b_arr[i][j];    //считаем до 10

			cout << "\t" << b_arr[i][j];          //выводим строки массива
		}
		cout << '\n' << endl;                    //пробел
	}
	
	cout << " ораблей на плаву - " << foo_sum_result << endl;     //выводим суму всех кораблей

	return 0;
}