#include "Header.h"

int Batle_Bot(int b_arr[10][10], int b_rows, int b_cols)//после выстрела здесть мы просто выводим поле и подсчитываем корабли
{
	int foo_sum_result = 0;
	for (int g = 0; g < 10; g++) // выводим координату Б
	{
		cout << "\tБ-" << g;
	}
	cout << "\n";
	for (int i = 0; i < b_rows; i++)
	{
		cout << "A-" << i;                           //координата а

		for (int j = 0; j < b_cols; j++)
		{
			if (b_arr[i][j] == 1)
				foo_sum_result += b_arr[i][j];    //считаем до 10

			if (b_arr[i][j] == 0)  //выводим строки массива
				cout << "\t#";
			if (b_arr[i][j] == 1)
				cout << "\t#";
			if (b_arr[i][j] == 2)
				cout << "\t@";
			if (b_arr[i][j] == 3)
				cout << "\t*";
		}
		cout << '\n' << endl;                    //пробел
	}

	cout << "кораблей на плаву - " << foo_sum_result << endl;     //выводим суму всех кораблей

	return 0;
}