//1850059 ��1�� ��־Զ

#include<iostream>
using namespace std;

int main()
{
	double x, y;
	cout << "����������:" << endl;
	cin >> x >> y;
	cout << "�õ�߶�Ϊ:" << endl;
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