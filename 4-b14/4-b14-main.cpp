//1850059 计1班 杨志远

#include <iostream>
#include <math.h>
using namespace std;

void aEqualZero();
void deltaOverZero(double a, double b, double delta);
void deltaEqualZero(double a, double b);
void deltaUnderZero(double a, double b, double delta);

int main()
{
	double a, b, c, delta;
	while (1)
	{
		cout << "请输入一元二次方程的三个系数:" << endl;
		if (!(cin >> a >> b >> c))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
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
