/* Лабиринт представляет собой квадрат, состоящий из NxN сегментов. 
   Каждый из сегментов может быть либо пустым, либо заполненным монолитной каменной стеной. 
   Гарантируется, что левый верхний и правый нижний сегменты пусты. 
   Лабиринт обнесён сверху, снизу, слева и справа стенами, оставляющими свободными только левый верхний и правый нижний углы. 
   Директор лабиринта решил покрасить стены лабиринта, видимые изнутри (см. рисунок). 
   Помогите ему рассчитать количество краски, необходимой для этого

   ФИО: Подыганов Константин Эдуардович
   Группа: ПС-22
   Окружение: Visual Studio 2022, C++17
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "ParseArgs.h"

using namespace std;

const char EMPTY = '.';
const char WALL = '#';

void ReadMatrix(ifstream&, vector<vector<int>>);
int FindSquare(vector<vector<int>>, int, int);

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    ifstream input;
    input.open(args->inputFile);

    int n;
    input >> n;
}

void ReadMatrix(ifstream& input, vector<vector<int>> matr)
{
    string line;
    vector<int> row;

    while (getline(input, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == EMPTY)
            {
                row.push_back(0);
            }
            else if (line[i] == WALL)
            {
                row.push_back(1);
            }
        }
        matr.push_back(row);
    }
}

int FindSquare(vector<vector<int>> matr, int i, int j)
{
    int count = 0;

    return 0;
}
