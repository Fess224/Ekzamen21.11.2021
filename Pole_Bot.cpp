#include "Header.h"

int rand_arr(int r_arr[10][10], int r_rows, int r_cols) //��������� ������� ������ �������
{
	int foo_sum_result = 0;
	srand(time(NULL));
	for (int g = 0; g < 10; g++) // ������� ���������� �
	{
		cout << "\t�-" << g;
	}
	cout << "\n";
	for (int i = 0; i < r_rows; i++)
	{
		cout << "A-" << i;                         //���������� �
		for (int j = 0; j < r_cols; j++)
		{
			if (foo_sum_result != 10)             //������ ���� �������� (1) ������ 10 �� ���������� ������� 1
			{
				r_arr[i][j] = rand() % 10;         // ���������� ����� ��������� �����
				if (r_arr[i][j] < 2)              //���� ������ 2 �� ��� 1
					r_arr[i][j] = 1;
				else
					r_arr[i][j] = 0;                  //����� 0
				foo_sum_result += r_arr[i][j];       //������� �� 10
			}
			else
				foo_sum_result += r_arr[i][j];     //���������� ������� 
			
			if (r_arr[i][j] == 0)  //������� ������ �������
				cout << "\t#";
			if (r_arr[i][j] == 1) 
				cout << "\t#";
			if (r_arr[i][j] == 2)
				cout << "\t@";
			if (r_arr[i][j] == 3)
				cout << "\t*";
			
		}
		cout << '\n' << endl;                   //������
	}
	cout << "�������� �� ����� - " << foo_sum_result << endl;     //������� ���� ���� ��������

	return 0;
}
