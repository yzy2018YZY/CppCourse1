//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
using namespace std;

void f_sub(int x)
{
	cout << "x = " << x << endl;
}

void (*fp(const char *p))(int)
{
	cout << "str : " << p << endl;
	return f_sub;
}

int main()
{
	void(*(*f[3])(const char *p))(int x);
	f[0] = fp;
	f[0]("Hello")(2);
	f[0]("Tongji")(7);
	return 0;
}