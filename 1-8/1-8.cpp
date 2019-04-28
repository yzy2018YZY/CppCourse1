//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	a = 1;
	b = 2;
	c = a + b;
	cout << "a + b = " << a + b;
	return 0;
}

/*  程序错误：
    1、没有包含 <iostream>且没有使用标准命名空间
    2、未定义变量c
	3、变量a和变量b未初始化
	4、cout后的输出运算符错误  */