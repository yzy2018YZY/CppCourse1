//1850059 计1班 杨志远

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	double a, b, c, x1, x2, delta;
	cout << "请输入一元二次方程的三个系数 : " << endl;
	cin >> a >> b >> c;
	if (a == 0)
	{
		cout << "不是一元二次方程" << endl;
	}
	else if ((delta = b * b - 4 * a * c) < 0)
	{
		cout << "有两个虚根:" << endl;
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
			cout << "有两个相等实根:" << endl;
			cout << "x1=x2=" << x1 << endl;
		}
		else
		{
			cout << "有两个不等实根:" << endl;
			cout << "x1=" << x1 << endl;
			cout << "x2=" << x2 << endl;
		}
	}
}
