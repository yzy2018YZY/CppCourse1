//1850059 ��1�� ��־Զ

#include<iostream>
using namespace std;

int main()
{
	double num;
	int count = 0;
	int c50 = 0, c20 = 0, c10 = 0, c5 = 0, c1 = 0, c05 = 0, c01 = 0, c005 = 0, c002 = 0, c001 = 0;
	cout << "������������:" << endl;
	cin >> num;
	if (num >= 50)
	{
		c50++;
		count++;
		num -= 50;
	}
	if (num >= 50)
	{
		c50++;
		count++;
		num -= 50;
	}
	if (num >= 20)
	{
		c20++;
		count++;
		num -= 20;
	}
	if (num >= 20)
	{
		c20++;
		count++;
		num -= 20;
	}
	if (num >= 10)
	{
		c10++;
		count++;
		num -= 10;
	}
	if (num >= 5 || (num - 5) < 1e-10 && (num - 5) > -1e-10)
	{
		c5++;
		count++;
		num -= 5;
	}
	if (num >= 1 || (num - 1) < 1e-10 && (num - 1) > -1e-10)
	{
		c1++;
		count++;
		num -= 1;
	}
	if (num >= 1 || (num - 1) < 1e-10 && (num - 1) > -1e-10)
	{
		c1++;
		count++;
		num -= 1;
	}
	if (num >= 1 || (num - 1) < 1e-10 && (num - 1) > -1e-10)
	{
		c1++;
		count++;
		num -= 1;
	}
	if (num >= 1 || (num - 1) < 1e-10 && (num - 1) > -1e-10)
	{
		c1++;
		count++;
		num -= 1;
	}
	if (num >= 0.5 || (num - 0.5) < 1e-10 && (num - 0.5) > -1e-10)
	{
		c05++;
		count++;
		num -= 0.5;
	}
	if (num >= 0.1 || (num - 0.1) < 1e-10 && (num - 0.1) > -1e-10)
	{
		c01++;
		count++;
		num -= 0.1;
	}
	if (num >= 0.1 || (num - 0.1) < 1e-10 && (num - 0.1) > -1e-10)
	{
		c01++;
		count++;
		num -= 0.1;
	}
	if (num >= 0.1 || (num - 0.1) < 1e-10 && (num - 0.1) > -1e-10)
	{
		c01++;
		count++;
		num -= 0.1;
	}
	if (num >= 0.1 || (num - 0.1) < 1e-10 && (num - 0.1) > -1e-10)
	{
		c01++;
		count++;
		num -= 0.1;
	}
	if (num >= 0.05 || (num - 0.05) < 1e-10 && (num - 0.05) > -1e-10)
	{
		c005++;
		count++;
		num -= 0.05;
	}
	if (num >= 0.02 || (num - 0.02) < 1e-10 && (num - 0.02) > -1e-10)
	{
		c002++;
		count++;
		num -= 0.02;
	}
	if (num >= 0.02 || (num - 0.02) < 1e-10 && (num - 0.02) > -1e-10)
	{
		c002++;
		count++;
		num -= 0.02;
	}
	if (num >= 0.01 || (num - 0.01) < 1e-10 && (num - 0.01) > -1e-10)
	{
		c001++;
		count++;
		num -= 0.01;
	}
	cout << "��" << count << "�����㣬��������:" << endl;
	if (c50 > 0)
	{
		cout << "50Ԫ : " << c50 << "��" << endl;
	}
	if (c20 > 0)
	{
		cout << "20Ԫ : " << c20 << "��" << endl;
	}
	if (c10 > 0)
	{
		cout << "10Ԫ : " << c10 << "��" << endl;
	}
	if (c5 > 0)
	{
		cout << "5Ԫ  : " << c5 << "��" << endl;
	}
	if (c1 > 0)
	{
		cout << "1Ԫ  : " << c1 << "��" << endl;
	}
	if (c05 > 0)
	{
		cout << "5��  : " << c05 << "��" << endl;
	}
	if (c01 > 0)
	{
		cout << "1��  : " << c01 << "��" << endl;
	}
	if (c005 > 0)
	{
		cout << "5��  : " << c005 << "��" << endl;
	}
	if (c002 > 0)
	{
		cout << "2��  : " << c002 << "��" << endl;
	}
	if (c001 > 0)
	{
		cout << "1��  : " << c001 << "��" << endl;
	}
	return 0;
}