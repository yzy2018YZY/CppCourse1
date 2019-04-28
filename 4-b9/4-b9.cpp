//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int is_power(int num, int base)
{
	if (num == base || num == 1)
		return 1;
	else if (num % base != 0)
		return 0;
	else
		return is_power(num / base, base);
}

int main()
{
	int num, base;
	cout << "请输入整数num及基数base" << endl;
	cin >> num >> base;
	cout  << num << (is_power(num, base)? "是" : "不是") << base << "的幂" << endl;
	return 0;
}