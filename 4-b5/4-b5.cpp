//1850059 ��1�� ��־Զ

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
	cout << "����������������:" << endl;
	cin >> a >> b;
	c = func(a, b);
	cout << "���Լ�� : " << c << endl;
	cout << "��С������ : " << a * b / c << endl;
	return 0;
}