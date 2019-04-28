//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	double num;
	cout << "请输入一个[0.01-100亿)间的数字: ";
	cin >> num;
	cout << "十亿位 : " << (int)(num / 1000000000) << endl;
	cout << "亿位   : " << ((int)(num / 100000000)) % 10 << endl;
	cout << "千万位 : " << ((int)(num / 10000000)) % 10 << endl;
	cout << "百万位 : " << ((int)(num / 1000000)) % 10 << endl;
	cout << "十万位 : " << ((int)(num / 100000)) % 10 << endl;
	cout << "万位   : " << ((int)(num / 10000)) % 10 << endl;
	cout << "千位   : " << ((int)(num / 1000)) % 10 << endl;
	cout << "百位   : " << ((int)(num / 100)) % 10 << endl;
	cout << "十位   : " << ((int)(num / 10)) % 10 << endl;
	num = num - ((double)(int)(num / 1000000000) * 1000000000);
	cout << "圆     : " << (int)num % 10 << endl;
	num = num - ((double)(int)(num / 100000000) * 100000000);
	cout << "角     : " << (int)(num * 10 + 0.05) % 10 << endl;
	num = num - ((double)(int)(num / 10000000) * 10000000);
	cout << "分     : " << (int)(num * 100 + 0.05) % 10 << endl;
	return 0;
}