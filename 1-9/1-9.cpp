//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int add(int x, int y);

int main()
{
	int a, b, c;
	a = 1;
	b = 2;
	c = add(a, b);
	cout << "a + b = " << c << endl;
	return 0;
}

int add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}

/*  程序错误：
1、main中未定义变量c
2、add中未定义变量z
3、未在main前声明add函数
4、变量a和变量b未初始化  */