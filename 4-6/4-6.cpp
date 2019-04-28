//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <math.h>
using namespace std;

double fx(double x, double a, double b, double c, double d)
{
	return a * x * x * x + b * x * x + c * x + d;
}

double NewTon(double a, double b, double c, double d)
{
	double x1, x2 = -1;
	do
	{
		x1 = x2;
		x2 = x1 - fx(x1, a, b, c, d) * 1e-7 / (fx(x1, a, b, c, d) - fx(x1 - (1e-7), a, b, c, d));
	} while (fabs(x1-x2) > 1e-10);
	return x2;
}

int main()
{
	double a = 1, b = 2, c = 3, d = 4;
	cout << "x=" << NewTon(a, b, c, d) << endl;
}