//1850059 计1班 杨志远

#include <iostream>
using namespace std;

double fnx(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	else
	{
		return ((2 * n-1) * x * fnx(x, n-1) - (n-1) * fnx(x, n-2)) / n;
	}
}

int main()
{
	int n;
	double x;
	cout << "计算legendre,请输入x和n的值" << endl;
	cin >> x >> n;
	cout << "legendre[" << n << "](" << x << ")=" << fnx(x, n) << endl;
	return 0;
}