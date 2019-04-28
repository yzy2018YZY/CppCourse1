//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int func(int a, int b)
{
	if (b == 0)
		return a;
	else
		return func(b, a % b);
}

int main()
{
	int a, b, c;
	cout << "请输入两个正整数:" << endl;
	cin >> a >> b;
	c = func(a, b);
	cout << "最大公约数 : " << c << endl;
	cout << "最小公倍数 : " << a * b / c << endl;
	return 0;
}