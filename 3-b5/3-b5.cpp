//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	double x, y;
	cout << "请输入坐标:" << endl;
	cin >> x >> y;
	cout << "该点高度为:" << endl;
	if (x == 0)
	{
		cout << 0 << endl;
	}
	else if (y == 0)
	{
		cout << 0 << endl;
	}
	else if (x > 0 && y > 0)
	{
		if (x + y <= 3)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if (x < 0 && y > 0)
	{
		if (x - y >= -3)
		{
			cout << 2 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if (x < 0 && y < 0)
	{
		if (x + y >= -3)
		{
			cout << 3 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if (x > 0 && y < 0)
	{
		if (x - y <= 3)
		{
			cout << 4 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}