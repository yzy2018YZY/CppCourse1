//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

bool is_run4_nian2(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int days(int month, int day, bool run4_nian2)
{
	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int months_run[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int count = day;
	for (int i = 1; i < month; i++)
	{
		count += run4_nian2 ? months_run[i - 1] : months[i - 1];
	}
	return count;
}

int main()
{
	int year, month, day, run4_nian2;
	cout << "�������꣬�£���" << endl;
	while (1)
	{
		cin >> year >> month >> day;
		if (year < 2000 || year > 2030)
		{
			cout << "�������-��ݴ���" << endl;
			continue;
		}
		if (month <= 0 || month > 12)
		{
			cout << "�������-�·ݴ���" << endl;
			continue;
		}
		run4_nian2 = is_run4_nian2(year);
		if (day <= 0 || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
			|| (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
			|| (month == 2 && run4_nian2 && day > 29) || (month == 2 && !run4_nian2 && day > 28))
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			continue;
		}
		break;
	}
	cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days(month, day, run4_nian2) << "��" << endl;
	return 0;
}