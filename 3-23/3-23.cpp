//1850059 计1班 杨志远

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, x, x2;
	cout << "请输入a值(整数)" << endl;
	cin >> a;
	x = a;
	if (a == 0)
	{
		x2 = 0;
	}
	else
	{
		while (true)
		{
			x2 = 0.5 * (x + a / x);
			if ((fabs(x - x2)) < 1e-5)
			{
				break;
			}
			x = x2;
		}
	}
	cout << a << "的平方根=" << x2 << endl;
	return 0;
}