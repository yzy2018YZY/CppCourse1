//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int f(int x, int y, int z);
	cin >> a >> b >> c;
	c = f(a, b, c);
	cout << c << endl;
	return 0;
}

int f(int x, int y, int z)
{
	int m;
	if (x < y) m = x;
	else m = y;
	if (z < m) m = z;
	return m;
}

/*  程序功能：
    输入：三个整数
    输出：三个整数中的最小值  */
