//1850059 ��1�� ��־Զ

#include "4-b15.h"

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
