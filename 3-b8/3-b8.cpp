//1850059 ��1�� ��־Զ

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	double a, b, c, x1, x2, delta;
	cout << "������һԪ���η��̵�����ϵ�� : " << endl;
	cin >> a >> b >> c;
	if (a == 0)
	{
		cout << "����һԪ���η���" << endl;
	}
	else if ((delta = b * b - 4 * a * c) < 0)
	{
		cout << "���������:" << endl;
		x1 = sqrt(-delta) / (2 * a);
		if (x1 < 0)
		{
			x1 = -x1;
		}
		cout << "x1 = " ;
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
		x2 = -x1;
		cout << "x2 = ";
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
	else
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		if (x1 < x2)
		{
			double temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (fabs(x1 - x2) < 1e-10)
		{
			cout << "���������ʵ��:" << endl;
			cout << "x1=x2=" << x1 << endl;
		}
		else
		{
			cout << "����������ʵ��:" << endl;
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
		}
	}
}
