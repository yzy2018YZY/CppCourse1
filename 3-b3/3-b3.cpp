//1850059 ��1�� ��־Զ

#include<iostream>
using namespace std;

int main()
{
	double num;
	cout << "������һ��[0.01-100��)�������: ";
	cin >> num;
	cout << "ʮ��λ : " << (int)(num / 1000000000) << endl;
	cout << "��λ   : " << ((int)(num / 100000000)) % 10 << endl;
	cout << "ǧ��λ : " << ((int)(num / 10000000)) % 10 << endl;
	cout << "����λ : " << ((int)(num / 1000000)) % 10 << endl;
	cout << "ʮ��λ : " << ((int)(num / 100000)) % 10 << endl;
	cout << "��λ   : " << ((int)(num / 10000)) % 10 << endl;
	cout << "ǧλ   : " << ((int)(num / 1000)) % 10 << endl;
	cout << "��λ   : " << ((int)(num / 100)) % 10 << endl;
	cout << "ʮλ   : " << ((int)(num / 10)) % 10 << endl;
	num = num - ((double)(int)(num / 1000000000) * 1000000000);
	cout << "Բ     : " << (int)num % 10 << endl;
	num = num - ((double)(int)(num / 100000000) * 100000000);
	cout << "��     : " << (int)(num * 10 + 0.05) % 10 << endl;
	num = num - ((double)(int)(num / 10000000) * 10000000);
	cout << "��     : " << (int)(num * 100 + 0.05) % 10 << endl;
	return 0;
}