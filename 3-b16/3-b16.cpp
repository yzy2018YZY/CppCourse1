//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	int year, month, week, day;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		if (!(cin >> year))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (!(cin >> month))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误，请重新输入" << endl;
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
			cout << "输入错误，请重新输入" << endl;
		}
	}
	while (1)
	{
		cout << "请输入" << year << "年" << month << "月1日的星期(0 - 6表示星期日 - 星期六) : ";
		if (!(cin >> week))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误，请重新输入" << endl;
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
			cout << "输入错误，请重新输入" << endl;
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
	cout << endl << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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