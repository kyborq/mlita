/* 3.5 - 6 баллов
   Результат эксперимента представляет собой матрицу из N  × M  (1 ≤ N, M ≤ 2000), 
   заполненную целыми числами, по модулю не превосходящими 500. 
   Отвечающим условиям эксперимента считаются такие подматрицы 
   размера K строк и L столбцов (0 < K < N, 0 < L < M), 
   что сумма элементов в каждой из них в точности равна заданному числу S.
   
   Определить, сколько подматриц в исходной матрице отвечают условиям эксперимента

   Ввод. 
   В первой строке файла INPUT.TXT находятся 5 чисел N, M, K, L и S, разделенных пробелами. 
   В каждой из следующих N строк находятся через пробел по M чисел, являющихся элементами матрицы

   Вывод. 
   В первой строке файла OUTPUT.TXT вывести единственное число 
   – количество подматриц размера K×L, сумма элементов в которых равна S.

   ФИО: Подыганов Константин Эдуардович
   Группа: ПС-22
   Окружение: Visual Studio 2022, C++17
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "ParseArgs.h"

using namespace std;

int N, M, K, L, S;

vector<vector<int>> GetMatrix(ifstream&);
int GetSteps(vector<vector<int>>);

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    ifstream input(args->inputFile);
    ofstream output(args->outputFile);

    input >> N >> M >> K >> L >> S;

    vector<vector<int>> matrix = GetMatrix(input);
    int count = GetSteps(matrix);

    output << count << endl;
}

vector<vector<int>> GetMatrix(ifstream& input)
{
    vector<vector<int>> matrix;
    int value;

    for (int i = 0; i < N; i++)
    {
        matrix.push_back({});
        for (int j = 0; j < M; j++)
        {
            input >> value;
            matrix[i].push_back(value);
        }
    }

    return matrix;
}

int GetVerticalSteps(vector<vector<int>> matrix, int i, int j, int colSum, int sum)
{
    if (i + K > N)
    {
        return 0;
    }

    int lastSum = 0;
    int firstSum = 0;

    int index = i + K - 1;

    for (int k = j; k < j + L; k++)
    {
        lastSum += matrix[index][k];
        firstSum += matrix[i][k];
    }

    int sumDiff = lastSum - colSum;
    bool success = sumDiff == (S - sum);

    return (success ? 1 : 0) + GetVerticalSteps(matrix, i + 1, j, firstSum, sum + sumDiff);
}

int GetHorizontalSteps(vector<vector<int>> matrix, int j, int colSum, int sum)
{
    if (j + L > M)
    {
        return 0;
    }

    int currentSum = 0;
    int currentColSum = 0; 
    int currentRowSum = 0;

    int index = j + L - 1;

    for (int i = 0; i < K; i++)
    {
        currentSum += matrix[i][index];
        currentColSum += matrix[i][j];
    }

    for (int k = j; k <= index; k++)
    {
        currentRowSum += matrix[0][k];
    }

    int sumDiff = currentSum - colSum;
    bool success = sumDiff == (S - sum);

    return (success ? 1 : 0) + GetVerticalSteps(matrix, 1, j, currentRowSum, sum + sumDiff) + GetHorizontalSteps(matrix, j + 1, currentColSum, sum + sumDiff);
}

int GetSteps(vector<vector<int>> matrix)
{
    int sum = 0;
    int rowSum = 0;
    int colSum = 0;

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < L; j++)
        {
            sum += matrix[i][j];
            if (i == 0)
            {
                rowSum += matrix[i][j];
            }
            if (j == 0)
            {
                colSum += matrix[i][j];
            }
        }
    }

    int count = (sum == S) ? 1 : 0;
    count += GetVerticalSteps(matrix, 1, 0, rowSum, sum);
    count += GetHorizontalSteps(matrix, 1, rowSum, sum);

    return count;
}