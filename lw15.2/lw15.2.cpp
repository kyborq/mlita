/* 15.2 - 5 баллов
   Двое играют в умножение: умножают целое число P на одно из чисел от 2 до 5. 
   Первый игрок всегда начинает с P=1, делает умножение, 
   затем число умножает второй игрок, снова первый и т. д. 
   Перед началом игры им задают число N, и победителем считается тот, 
   кто первым добьется условия P ≥ N. Определить, кто выиграет при заданном N, 
   если оба играют наилучшим образом.

   Ограничения: 2 <= N <= 10000, время 1 с.

   Ввод из файла INPUT.TXT. 
   В первой строке находится количество партий M. 
   В следующих M строках задаются значения N для каждой партии.

   Вывод в файл OUTPUT.TXT. 
   Выводится М строк с числами 1 – если победит первый игрок, 
   или 2 - если победит второй.

   ФИО: Подыганов Константин Эдуардович
   Группа: ПС-22
   Окружение: Visual Studio 2022, C++17
*/

#include <iostream>
#include <fstream>

#include "ParseArgs.h"

using namespace std;

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	ifstream input(args->inputFile);
	ofstream output(args->outputFile);

	int count = 0;
	input >> count;

	while (count)
	{
		double a = 0;
		double b = 0;
		double p = 0;

		input >> p;

		int c = 0;
		a = p;

		bool toggle = true;
		while (p > 1)
		{
			if (toggle)
			{
				b = p = a = a / 5;
				toggle = false;
			}
			else
			{
				a = p = b = b / 2;
				toggle = true;
			}
			c++;
		}

		if (c % 2 == 0)
		{
			output << 2 << endl;
		}
		else
		{
			output << 1 << endl;
		}

		count--;
	}
}