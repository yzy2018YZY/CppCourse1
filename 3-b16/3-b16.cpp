//1850059 ��1�� ��־Զ

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	int year, month, week, day;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		if (!(cin >> year))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�����������������" << endl;
			continue;
		}
		if (!(cin >> month))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�����������������" << endl;
			continue;
		}
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
		{
			break;
		}
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�����������������" << endl;
		}
	}
	while (1)
	{
		cout << "������" << year << "��" << month << "��1�յ�����(0 - 6��ʾ������ - ������) : ";
		if (!(cin >> week))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�����������������" << endl;
			continue;
		}
		if (week >= 0 && week <= 6)
		{
			break;
		}
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "�����������������" << endl;
		}
	}
	switch (month)
	{
		case 1:
			day = 31;
			break;
		case 2:
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			{
				day = 29;
			}
			else
			{
				day = 28;
			}
			break;
		case 3:
			day = 31;
			break;
		case 4:
			day = 30;
			break;
		case 5:
			day = 31;
			break;
		case 6:
			day = 30;
			break;
		case 7:
			day = 31;
			break;
		case 8:
			day = 31;
			break;
		case 9:
			day = 30;
			break;
		case 10:
			day = 31;
			break;
		case 11:
			day = 30;
			break;
		case 12:
			day = 31;
			break;
	}
	cout << endl << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	int count = week + 1;
	cout << "  ";
	for (int i = 0; i < week; i++)
	{
		cout << "        ";
	}
	for (int i = 1; i <= day; i++, count++)
	{
		cout << setw(2) << i << "      ";
		if (count % 7 == 0)
		{
			cout << endl << "  ";
		}
	}
	cout << endl;
	return 0;
}