//1850059 ��1�� ��־Զ

#include <iostream>
#include <math.h>
using namespace std;

void aEqualZero()
{
	cout << "����һԪ���η��� " << endl;
}

void deltaOverZero(double a, double b, double delta)
{
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (x1 < x2)
	{
		double temp = x1;
		x1 = x2;
		x2 = temp;
	}
	cout << "����������ʵ��:" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void deltaEqualZero(double a, double b)
{
	double x = -b / (2 * a);
	cout << "���������ʵ��:" << endl;
	cout << "x1=x2=" << x << endl;
}

void deltaUnderZero(double a, double b, double delta)
{
	cout << "���������:" << endl;
	double x1 = sqrt(-delta) / (2 * a);
	if (x1 < 0)
	{
		x1 = -x1;
	}
	cout << "x1=";
	if (fabs(-b / (2 * a)) > 1e-10)
	{
		cout << -b / (2 * a);
		cout << "+";
	}
	if (fabs(x1 - 1) > 1e-10 && fabs(x1 + 1) > 1e-10)
	{
		cout << x1;
	}
	if (fabs(x1 + 1) < 1e-10)
	{
		cout << "-";
	}
	cout << "i" << endl;
	double x2 = -x1;
	cout << "x2=";
	if (fabs(-b / (2 * a)) > 1e-10)
	{
		cout << -b / (2 * a);
	}
	if (fabs(x2 - 1) > 1e-10 && fabs(x2 + 1) > 1e-10)
	{
		cout << x2;
	}
	if (fabs(x2 + 1) < 1e-10)
	{
		cout << "-";
	}
	cout << "i" << endl;
}

int main()
{
	double a, b, c, delta;
	while (1) 
	{
		cout << "������һԪ���η��̵�����ϵ��:" << endl;
		if (!(cin >> a))
		{
			cin.clear(); 
			cin.ignore(999999999, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		if (!(cin >> b))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		if (!(cin >> c))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		break;
	}
	delta = b * b - 4 * a * c;
	if (a == 0)
	{
		aEqualZero();
	}
	else if (delta > 0)
	{
		deltaOverZero(a, b, delta);
	}
	else if (fabs(delta) < 1e-7)
	{
		deltaEqualZero(a, b);
	}
	else
	{
		deltaUnderZero(a, b, delta);
	}
	return 0;
}
