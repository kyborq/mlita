/* 10.13 - 5 баллов
   Требуется в каждую клетку квадратной таблицы 
   размером N × N поставить ноль или единицу так, 
   чтобы в максимальном количестве квадратов размера K×K было ровно S единиц.

   Ввод из файла INPUT.TXT. 
   Единственная строка  содержит  три  числа:  N,  K,  S  (1 £ N £ 500, 1 £ K £ N, 0 £ S £ K2).

   Вывод в файл OUTPUT.TXT. 
   В первую строку необходимо вывести максимальное число квадратов из нулей и единиц размера K×K, 
   в каждом из которых ровно S единиц. 
   В следующих N строках вывести по N элементов в строке полученную таблицу из нулей и единиц. 
   Если решений несколько, то вывести любое из них.

   ФИО: Подыганов Константин Эдуардович
   Группа: ПС-22
   Окружение: Visual Studio 2022, C++17
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "ParseArgs.h"

using namespace std;

vector<vector<int>> CreateSquare(int, int);
vector<vector<int>> CreateTable(int, int, int);

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	ifstream input(args->inputFile);
	ofstream output(args->outputFile);

	int N;
	int K;
	int S;

	input >> N >> K >> S;

	output << (N - K + 1) * (N - K + 1) << endl;
	vector<vector<int>> table = CreateTable(N, K, S);

	for (auto& row : table)
	{
		for (auto value : row)
		{
			output << value << " ";
		}
		output << endl;
	}
}

vector<vector<int>> CreateSquare(int n, int ones)
{
	vector<vector<int>> square(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ones - 1 == 0)
			{
				goto ret;
			}
			square[i][j] = 1;
		}
	}

ret:
	return square;
}

vector<vector<int>> CreateTable(int n, int k, int ones)
{
	vector<vector<int>> square = CreateSquare(k, ones);
	vector<vector<int>> table(n, vector<int>(k, 0));

	for (int i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; ++j)
		{
			table[i][j] = square[i % k][j % k];
		}
	}

	return table;
}