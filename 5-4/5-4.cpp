//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

int main()
{
	int a[25000] = {0}, size = 0, num = 0;
	cout << "��������������������������20��������-1����" << endl;
	while (1)
	{
		cin >> a[size++];
		if (a[size - 1] == -1)
		{
			size--;
			break;
		}
	}
	cout << "ԭ����Ϊ:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl << "������Ҫ�����������:" << endl;
	cin >> num;
	cout << "����������Ϊ:" << endl;
	int i;
	for (i = size++ -1; i >= 0; i--)
	{
		if (a[i] <= num)
		{

			a[i + 1] = num;
			break;
		}
		a[i + 1] = a[i];
	}
	if (i == -1)
	{
		a[0] = num;
	}
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	return 0;
}
