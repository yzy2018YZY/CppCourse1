//1850059 ��1�� ��־Զ

#include<iostream>
using namespace std;

int main()
{
	int num;
	cout << "������һ��[1...30000]�������" << endl;
	cin >> num;
	cout << "��λ : " << num / 10000 << endl;
	cout << "ǧλ : " << (num % 10000) / 1000 << endl;
	cout << "��λ : " << (num % 1000) / 100 << endl;
	cout << "ʮλ : " << (num % 100) / 10 << endl;
	cout << "��λ : " << num % 10 << endl;
	return 0;
}