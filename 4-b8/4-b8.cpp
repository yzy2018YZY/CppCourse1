//1850059 ��1�� ��־Զ

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
	cout << "������Fibonacci���е�����" << endl;
	cin >> num;
	cout << "Fibonacci���е�" << num << "���ֵ : " << Fibonacci(num) << endl;
	return 0;
}