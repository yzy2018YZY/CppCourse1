//1850059 ��1�� ��־Զ

#include <iostream>
#include <math.h>
using namespace std;

const double PI = 3.14159;

double definite_integration(double (*func)(double), double low, double high, int n)
{
	double delta = (high - low) / n, value = 0;
	for (double i = high; i > low && fabs(i - low) > 1e-8; i -= delta)
	{
		value += func(i) * delta;
	}
	return value;
}

int main()
{
	int n;
	double low, high, value;
	while (1)
	{
		cout << "������sinxdx�����ޡ����޼����仮������" << endl;
		if (!(cin >> low >> high >> n) || low > high || high - low < 1e-8 || n <= 1)
		{
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "���������������������" << endl;
			continue;
		}
		break;
	}
	value = definite_integration(sin, low, high, n);
	cout << "sinxdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	while (1)
	{
		cout << "������cosxdx�����ޡ����޼����仮������" << endl;
		if (!(cin >> low >> high >> n) || low > high || high - low < 1e-8 || n <= 1)
		{
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "���������������������" << endl;
			continue;
		}
		break;
	}
	value = definite_integration(cos, low, high, n);
	cout << "cosxdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	while (1)
	{
		cout << "������e^xdx�����ޡ����޼����仮������" << endl;
		if (!(cin >> low >> high >> n) || low > high || high - low < 1e-8 || n <= 1)
		{
			cin.clear();
			cin.ignore(99999, '\n');
			cout << "���������������������" << endl;
			continue;
		}
		break;
	}
	value = definite_integration(exp, low, high, n);
	cout << "e^xdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	return 0;
}