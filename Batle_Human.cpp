#include "Header.h"

int Batle_Human(int b_arr[10][10], int b_rows, int b_cols)//����� �������� ������ �� ������ ������� ���� � ������������ �������
{
	int foo_sum_result = 0;
	for (int g = 0; g < 10; g++) // ������� ���������� �
	{
		cout << "\t�-" << g;
	}
	cout << "\n";
	for (int i = 0; i < b_rows; i++)
	{
		cout << "A-" << i;                           //���������� �

		for (int j = 0; j < b_cols; j++)
		{
			if (b_arr[i][j] == 1)
				foo_sum_result += b_arr[i][j];    //������� �� 10

			cout << "\t" << b_arr[i][j];          //������� ������ �������
		}
		cout << '\n' << endl;                    //������
	}
	
	cout << "�������� �� ����� - " << foo_sum_result << endl;     //������� ���� ���� ��������

	return 0;
}