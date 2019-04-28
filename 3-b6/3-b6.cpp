//1850059 计1班 杨志远

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	double a, b, c, p = 0;
	cout << "请输入三角形的三条边长度:" << endl;
	cin >> a >> b >> c;
	if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
	{
		cout << "不构成三角形" << endl;
	}
	else
	{
		p = (a + b + c) / 2;
		cout << "三角形的面积 : " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
	}
	return 0;
}