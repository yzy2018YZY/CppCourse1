//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

int main()
{
	int num, original = 1;
	cout << "������ڼ���������Ϊ1" << endl;
	cin >> num;
	for (int i = 1; i < num; i++)
	{
		original = 2 * (original + 1);
	}
	cout << "��" << num << "���������=" << original << endl;
	return 0;
}