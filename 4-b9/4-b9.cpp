//1850059 ��1�� ��־Զ

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
	cout << "����������num������base" << endl;
	cin >> num >> base;
	cout  << num << (is_power(num, base)? "��" : "����") << base << "����" << endl;
	return 0;
}