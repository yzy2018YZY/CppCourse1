//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	int num;
	cout << "请输入一个[1...30000]间的整数" << endl;
	cin >> num;
	cout << "万位 : " << num / 10000 << endl;
	cout << "千位 : " << (num % 10000) / 1000 << endl;
	cout << "百位 : " << (num % 1000) / 100 << endl;
	cout << "十位 : " << (num % 100) / 10 << endl;
	cout << "个位 : " << num % 10 << endl;
	return 0;
}