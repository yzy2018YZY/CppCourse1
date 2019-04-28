//1850059 计1班 杨志远

#include "4-b15.h"

void deltaUnderZero(double a, double b, double delta)
{
	cout << "有两个虚根:" << endl;
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
