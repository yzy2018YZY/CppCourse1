//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}

int max(int a, int b, int c, int d)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;
	return max;
}

int main()
{
	int num, a, b, c, d;
	while (1)
	{
		cout << "请输入个数num及num个整数:" << endl;
		if (!(cin >> num))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (num < 2 || num > 4)
		{
			cout << "个数输入错误" << endl;
			break;
		}
		else if (num == 2)
		{
			if (!(cin >> a >> b))
			{
				cin.clear();
				cin.ignore(999999999, '\n');
				continue;
			}
			cout << "max=" << max(a, b) << endl;
		}
		else if (num == 3)
		{
			if (!(cin >> a >> b >> c))
			{
				cin.clear();
				cin.ignore(999999999, '\n');
				continue;
			}
			cout << "max=" << max(a, b, c) << endl;
		}
		else
		{
			if (!(cin >> a >> b >> c >> d))
			{
				cin.clear();
				cin.ignore(999999999, '\n');
				continue;
			}
			cout << "max=" << max(a, b, c, d) << endl;
		}
		break;
	}
	return 0;
}