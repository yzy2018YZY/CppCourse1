//1850059 计1班 杨志远

#include <iostream>
using namespace std;

const double ANSWER = 24;

double calc(double x, double y, double xy)
{
	if (xy == 1)
		return x + y;
	else if (xy == 2)
		return x - y;
	else if (xy == 3)
		return x * y;
	else
		return (double)x / (double)y;
}

char toChar(int xy)
{
	if (xy == 1)
		return '+';
	else if (xy == 2)
		return '-';
	else if (xy == 3)
		return '*';
	else
		return '/';
}

int calc24(int a, int b, int c, int d)
{
	int ab, bc, cd, count = 0;
	for (ab = 1; ab <= 4; ab++)
	{
		for (bc = 1; bc <= 4; bc++)
		{
			for (cd = 1; cd <= 4; cd++)
			{
				if (calc(calc(calc(a, b, ab), c, bc), d, cd) == ANSWER)
				{
					count++;
					cout << "(" << "(" << a << toChar(ab) << b << ")" << toChar(bc) << c << ")" << toChar(cd) << d << "=" << ANSWER << endl;
				}
				if (calc(calc(a, calc(b, c, bc), ab), d, cd) == ANSWER)
				{
					count++;
					cout << "(" << a << toChar(ab) << "(" << b << toChar(bc) << c << ")" << ")" << toChar(cd) << d << "=" << ANSWER << endl;
				}
				if (calc(a, calc(b, calc(c, d, cd), bc), ab) == ANSWER)
				{
					count++;
					cout << a << toChar(ab) << "(" << b << toChar(bc) << "(" << c << toChar(cd) << d << ")" << ")" << "=" << ANSWER << endl;
				}
				if (calc(a, calc(calc(b, c, bc), d, cd), ab) == ANSWER)
				{
					count++;
					cout << a << toChar(ab) << "(" << "(" << b << toChar(bc) << c << ")" << toChar(cd) << d << ")" << "=" << ANSWER << endl;
				}
				if (calc(calc(a, b, ab), calc(c, b, cd), bc) == ANSWER)
				{
					count++;
					cout << "(" << a << toChar(ab) << b << ")" << toChar(bc) << "(" << c << toChar(cd) << d << ")" << "=" << ANSWER << endl;
				}
			}
		}
	}
	return count;
}

int main()
{
	int a, b, c, d, count;
	while (1)
	{
		cout << "请输入四个（1-10）之间的整数 :" << endl;
		if (!(cin >> a >> b >> c >> d))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (a < 1 || a > 10 || b < 1 || b > 10 || c < 1 || c > 10 || d < 1 || d > 10)
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	count = calc24(a, b, c, d);
	if (count == 0)
		cout << "无解" << endl;
	return 0;
}
