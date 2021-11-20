#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime> // содержит time()
using namespace std;


int Sea_Battle();
int sea_auto_pole();
int rand_arr(int r_arr[10][10], int r_rows, int r_cols);
int Batle_Human(int r_arr[10][10], int r_rows, int r_cols);
int Batle_Bot(int r_arr[10][10], int r_rows, int r_cols);
int auto_ship(int r_arr[10][10], int r_rows, int r_cols);