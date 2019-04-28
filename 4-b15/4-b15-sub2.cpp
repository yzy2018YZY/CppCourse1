//1850059 计1班 杨志远

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
	cout << "有两个不等实根:" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
