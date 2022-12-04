/* 2.10 - 7 баллов
   Имеется система сцепленных шестеренок, пронумерованных от 1 до N.
   Заданы пары номеров сцепленных шестеренок.
   Первая должна двигаться по  часовой стрелке.Определить характер движения всех шестеренок
   
   Варианты движения:
   - clockwise - по часовой;
   - unclockwise - против;
   - immovable - шестеренка неподвижна;
   - block - заклинивание.

   Ввод из файла INPUT.TXT. 
   В первой строке записаны через пробел число N - количество шестеренок (2 <= N <= 10000) и M - количество пар (1 <= M <= 100000). 
   Во следующих M строках указаны пары шестеренок в виде двух номеров через пробел.

   Вывод в файл OUTPUT.TXT. 
   В i-й строке должна быть информация о движении i-й шестеренки: clockwise - по часовой, against - против, immovable – шестеренка неподвижна. 
   Если система заклинивается, то выдать block.

   ФИО: Подыганов Константин Эдуардович
   Группа: ПС-22
   Окружение: Visual Studio 2022, C++17
*/

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <vector>
#include <queue>

#include "ParseArgs.h"

using namespace std;

const string BLOCK = "block";
const string IMMOVABLE = "immovable";
const string CLOCKWISE = "clockwise";
const string UNCLOCKWISE = "unclockwise";

void ReadGears(std::ifstream&, int, int, vector<vector<int>>&);
void MoveGears(vector<vector<int>>&, vector<string>&, int, bool&);

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    ifstream input;
    input.open(args->inputFile);

    int m, n;
    input >> m >> n;

    vector<vector<int>> gears(m, std::vector<int>());
    vector<string> rotations(m, IMMOVABLE);
    rotations[0] = CLOCKWISE;

    bool blocked = false;
    int k = 0;

    ReadGears(input, m, n, gears);
    MoveGears(gears, rotations, k, blocked);
   
    ofstream output;
    output.open(args->outputFile);

    if (blocked)
    {
        output << BLOCK;
    }
    else
    {
        for (int i = 0; i < rotations.size(); i++)
        {
            output << rotations[i] << endl;
        }
    }
}

void ReadGears(std::ifstream& input, int m, int n, vector<vector<int>>& gears)
{
    int first, second;
    for (int i = 0; i < n; i++)
    {
        input >> first >> second;

        first--;
        second--;

        gears[first].push_back(second);
        gears[second].push_back(first);
    }
}

void MoveGears(vector<vector<int>>& gears, vector<string>& rotations, int k, bool& blocked)
{
    queue<int> q;
    q.push(k);

    blocked = false;

    while (!q.empty() && !blocked)
    {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < gears[v].size(); i++)
        {
            int to = gears[v][i];
            if (!blocked)
            {
                if (rotations[to] == IMMOVABLE)
                {
                    q.push(to);

                    if (rotations[v] == CLOCKWISE)
                    {
                        rotations[to] = UNCLOCKWISE;
                    }
                    else
                    {
                        rotations[to] = CLOCKWISE;
                    }
                }
                else if (rotations[v] == rotations[to])
                {
                    blocked = true;
                }
            }
        }
    }
}
