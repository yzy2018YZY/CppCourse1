//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cout << "请输入四个整数:" << endl;
	cin >> a >> b >> c >> d;
	cout << "输出:" << endl;
	if (a <= b && b <= c && c <= d)
	{
		cout << a << " " << b << " " << c << " " << d << endl;
	}
	else if (a <= b && b <= d && d <= c)
	{
		cout << a << " " << b << " " << d << " " << c << endl;
	}
	else if (a <= c && c <= b && b <= d)
	{
		cout << a << " " << c << " " << b << " " << d << endl;
	}
	else if (a <= c && c <= d && d <= b)
	{
		cout << a << " " << c << " " << d << " " << b << endl;
	}
	else if (a <= d && d <= b && b <= c)
	{
		cout << a << " " << d << " " << b << " " << c << endl;
	}
	else if (a <= d && d <= c && c <= b)
	{
		cout << a << " " << d << " " << c << " " << b << endl;
	}
	else if (b <= a && a <= c && c <= d)
	{
	    cout << b << " " << a << " " << c << " " << d << endl;
	}
	else if (b <= a && a <= d && d <= c)
	{
		cout << b << " " << a << " " << d << " " << c << endl;
	}
	else if (b <= c && c <= a && a <= d)
	{
		cout << b << " " << c << " " << a << " " << d << endl;
	}
	else if (b <= c && c <= d && d <= a)
	{
		cout << b << " " << c << " " << d << " " << a << endl;
	}
	else if (b <= d && d <= a && a <= c)
	{
		cout << b << " " << d << " " << a << " " << c << endl;
	}
	else if (b <= d && d <= c && c <= a)
	{
		cout << b << " " << d << " " << c << " " << a << endl;
	}
	else if (c <= a && a <= b && b <= d)
	{
		cout << c << " " << a << " " << b << " " << d << endl;
	}
	else if (c <= a && a <= d && d <= b)
	{
		cout << c << " " << a << " " << d << " " << b << endl;
	}
	else if (c <= b && b <= a && a <= d)
	{
		cout << c << " " << b << " " << a << " " << d << endl;
	}
	else if (c <= b && b <= d && d <= a)
	{
		cout << c << " " << b << " " << d << " " << a << endl;
	}
	else if (c <= d && d <= a && a <= b)
	{
		cout << c << " " << d << " " << a << " " << b << endl;
	}
	else if (c <= d && d <= b && b <= a)
	{
		cout << c << " " << d << " " << b << " " << a << endl;
	}
	else if (d <= a && a <= b && b <= c)
	{
		cout << d << " " << a << " " << b << " " << c << endl;
	}
	else if (d <= a && a <= c && c <= b)
	{
		cout << d << " " << a << " " << c << " " << b << endl;
	}
	else if (d <= b && b <= a && a <= c)
	{
		cout << d << " " << b << " " << a << " " << c << endl;
	}
	else if (d <= b && b <= c && c <= a)
	{
		cout << d << " " << b << " " << c << " " << a << endl;
	}
	else if (d <= c && c <= a && a <= b)
	{
		cout << d << " " << c << " " << a << " " << b << endl;
	}
	else
	{
		cout << d << " " << c << " " << b << " " << a << endl;
	}
	return 0;
}