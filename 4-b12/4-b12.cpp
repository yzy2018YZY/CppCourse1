//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

int min(int a, int b, int c = 2147483647, int d = 2147483647)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return min;
}

int main()
{
	int num, a, b, c, d;
	while (1)
	{
		cout << "���������num��num������:" << endl;
		if (!(cin >> num))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (num < 2 || num > 4)
		{
			cout << "�����������" << endl;
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
			cout << "min=" << min(a, b) << endl;
		}
		else if (num == 3)
		{
			if (!(cin >> a >> b >> c))
			{
				cin.clear();
				cin.ignore(999999999, '\n');
				continue;
			}
			cout << "min=" << min(a, b, c) << endl;
		}
		else
		{
			if (!(cin >> a >> b >> c >> d))
			{
				cin.clear();
				cin.ignore(999999999, '\n');
				continue;
			}
			cout << "min=" << min(a, b, c, d) << endl;
		}
		break;
	}
	return 0;
}