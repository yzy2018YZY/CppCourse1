//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	double num;
	int count = 0;
	int c50 = 0, c20 = 0, c10 = 0, c5 = 0, c1 = 0, c05 = 0, c01 = 0, c005 = 0, c002 = 0, c001 = 0;
	cout << "请输入找零数:" << endl;
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
	cout << "共" << count << "张找零，具体如下:" << endl;
	if (c50 > 0)
	{
		cout << "50元 : " << c50 << "张" << endl;
	}
	if (c20 > 0)
	{
		cout << "20元 : " << c20 << "张" << endl;
	}
	if (c10 > 0)
	{
		cout << "10元 : " << c10 << "张" << endl;
	}
	if (c5 > 0)
	{
		cout << "5元  : " << c5 << "张" << endl;
	}
	if (c1 > 0)
	{
		cout << "1元  : " << c1 << "张" << endl;
	}
	if (c05 > 0)
	{
		cout << "5角  : " << c05 << "张" << endl;
	}
	if (c01 > 0)
	{
		cout << "1角  : " << c01 << "张" << endl;
	}
	if (c005 > 0)
	{
		cout << "5分  : " << c005 << "张" << endl;
	}
	if (c002 > 0)
	{
		cout << "2分  : " << c002 << "张" << endl;
	}
	if (c001 > 0)
	{
		cout << "1分  : " << c001 << "张" << endl;
	}
	return 0;
}