//1850059 计1班 杨志远

#include <iostream>
using namespace std;

bool check(int num[][9])
{
	for (int i = 0; i < 9; i++)
	{
		int temp1[10] = { 0 }, temp2[10] = { 0 };
		for (int j = 0; j < 9; j++)
		{
			if (++temp1[num[i][j]] > 1)
				return false;
		}
		for (int j = 0; j < 9; j++)
		{
			if (++temp2[num[j][i]] > 1)
				return false;
		}
	}
	for(int i = 1; i < 9; i += 3)
	{
		for (int j = 1; j < 9; j += 3)
		{
			int temp[10] = { 0 };
			++temp[num[i - 1][j - 1]];
			++temp[num[i - 1][j]];
			++temp[num[i - 1][j + 1]];
			++temp[num[i][j - 1]];
			++temp[num[i][j]];
			++temp[num[i][j + 1]];
			++temp[num[i + 1][j - 1]];
			++temp[num[i + 1][j]];
			++temp[num[i + 1][j + 1]];
			for (int k = 1; k <= 9; k++)
			{
				if (temp[k] > 1)
					return false;
			}
		}
	}
	return true;
}

int main()
{
	int num[9][9] = { 0 };
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			while (1)
			{
				if (!(cin >> num[i][j]))
				{
					cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(999999999, '\n');
					continue;
				}
				if (num[i][j] < 1 || num[i][j] > 9)
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				break;
			}
		}
	}
	if (check(num))
	{
		cout << "是数独的解" << endl;
	}
	else
	{
		cout << "不是数独的解" << endl;
	}
	return 0;
}