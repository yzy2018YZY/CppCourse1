//1850059 计1班 杨志远

#include <iostream>
using namespace std;

void func(int num)
{
	if (num < 0)
	{
		cout << "- ";
		func(-num);
	}
	else if (num <= 9)
	{
		cout << num << " ";
	}
	else
	{
		func(num / 10);
		cout << num % 10 << " ";
	}
}

int main()
{
	int num;
	cout << "请输入一个整数" << endl;
	cin >> num;
	func(num);
	cout << endl;
	return 0;
}