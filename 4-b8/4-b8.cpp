//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int Fibonacci(int num)
{
	if (num == 1 || num == 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(num - 1) + Fibonacci(num - 2);
	}
}

int main()
{
	int num;
	cout << "请输入Fibonacci数列的项数" << endl;
	cin >> num;
	cout << "Fibonacci数列第" << num << "项的值 : " << Fibonacci(num) << endl;
	return 0;
}