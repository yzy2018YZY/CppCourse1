//1850059 ��1�� ��־Զ

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x;
	while (1) {
		cout << "������x��ֵ(0-100)��";
		if (!(cin >> x))//����x�ķ�ʽ������ˣ���׼�÷�cin
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�������" << endl;
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�������" << endl;
		}
	}

	cout << "x=" << x << endl;

	return 0;
}
