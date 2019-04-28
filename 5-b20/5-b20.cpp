//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int maxX = 26;
const int maxY = 10;
const int maxBooms = 50;

int main()
{
	int map[maxY + 2][maxX + 2] = { 0 };
	srand((unsigned int)time(0));
	for (int i = 0; i < maxBooms; i++)
	{
		int tempRand = rand() % (maxX * maxY);
		if (map[tempRand / maxX + 1][tempRand % maxX + 1] == 0)
		{
			map[tempRand / maxX + 1][tempRand % maxX + 1] = -1;
		}
		else
		{
			i--;
		}
	}
	for (int j = 1; j < maxY + 1; j++)
	{
		for (int i = 1; i < maxX + 1; i++)
		{
			if (map[j][i] != -1)
			{
				if (map[j - 1][i - 1] == -1)
					map[j][i]++;
				if (map[j - 1][i] == -1)
					map[j][i]++;
				if (map[j - 1][i + 1] == -1)
					map[j][i]++;
				if (map[j][i - 1] == -1)
					map[j][i]++;
				if (map[j][i + 1] == -1)
					map[j][i]++;
				if (map[j + 1][i - 1] == -1)
					map[j][i]++;
				if (map[j + 1][i] == -1)
					map[j][i]++;
				if (map[j + 1][i + 1] == -1)
					map[j][i]++;
			}
		}
	}
	for (int j = 1; j < maxY + 1; j++)
	{
		for (int i = 1; i < maxX + 1; i++)
		{
			if (map[j][i] != -1)
				cout << map[j][i] << " ";
			else
				cout << "*" << " ";
		}
		cout << endl;
	}
	return 0;
}