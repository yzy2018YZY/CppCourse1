//1850059 ��1�� ��־Զ

#include<iostream>
using namespace std;

int main()
{
	double x;
	cout << "������x��ֵ:" << endl;
	cin >> x;
	if (x < 1)
	{
		cout << "y=" << x << endl;
	}
	else if (x >= 1 && x < 10)
	{
		cout << "y=" << 2 * x - 1 << endl;
	}
	else
	{
		cout << "y=" << 3 * x - 11 << endl;
	}
	return 0;
}