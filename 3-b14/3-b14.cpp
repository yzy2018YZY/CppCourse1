//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double left = 0, right = 1, middle = 0.5;
	while (true)
	{
		if (fabs(2 * middle * middle * middle - 9 * middle * middle + 12 * middle - 3) < 1e-6)
		{
			cout << "x=" << middle << endl;
			break;
		}
		if ((2 * left * left * left - 9 * left * left + 12 * left - 3)
			* (2 * middle * middle * middle - 9 * middle * middle + 12 * middle - 3) < 0)
		{
			right = middle;
			middle = (left + right) / 2;
		}
		else
		{
			left = middle;
			middle = (left + right) / 2;
		}
		
	}
	return 0;
}

float f(float a, float b, float c, float d, float x)
{
	float f;
	f = ((a*x + b)*x + c)*x + d;
	return f;
}
float f1(float a, float b, float c, float x)
{
	float f;
	f = (x * 3 * a + 2 * b)*x + c;
	return f;
}
float root(float a, float b, float c, float d)
{
	float x0, x1 = 1;
	do
	{
		x0 = x1;
		x1 = x0 - f(a, b, c, d, x0) / f1(a, b, c, x0);
	} while (fabs(x1 - x0) >= 1e-6);
	return x0;
}
void main()
{
	float a, b, c, d, x;
	printf("input four float numbers:\n");
	scanf("%f%f%f%f", &a, &b, &c, &d);
	x = root(a, b, c, d);
	printf("%.1fX^3+%.1fX^2+%.1fX+%.1f=0 its root near x=1.5 is :%.4f\n", a, b, c, d, x);
	getch();
}