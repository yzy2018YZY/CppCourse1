//1850059 ��1�� ��־Զ

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	double a, b, c, p = 0;
	cout << "�����������ε������߳���:" << endl;
	cin >> a >> b >> c;
	if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
	{
		cout << "������������" << endl;
	}
	else
	{
		p = (a + b + c) / 2;
		cout << "�����ε���� : " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
	}
	return 0;
}