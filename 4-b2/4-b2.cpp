//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	int c = y / 100, year = y % 100, month = m, w;
	if (m == 1 || m == 2)
	{
		c = (y - 1) / 100;
		year = (y - 1) % 100;
		month = m + 12;

	}
	w = (year + int(year / 4) + int(c / 4) - 2 * c + int(13 * (month + 1) / 5) + d - 1) % 7;
	while (w < 0)
	{
		w += 7;
	}
	return w;
}

void calendar(int year, int month, int day, int week)
{
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
}

int main()
{
	int year, month, week, day;
	while (1)
	{
		cout << "请输入年(1900-2100)、月:" << endl;
		if (!(cin >> year))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			//cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (!(cin >> month))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			//cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			cout << "年份输入错误，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month > 12)
		{
			cout << "月份输入错误，请重新输入" << endl;
			continue;
		}
		break;
	}
	if (month == 2)
	{
		if ((year % 400 != 0 && year % 100 == 0) || year % 4 != 0)
		{
			day = 28;
		}
		else
		{
			day = 29;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		day = 31;
	}
	else
	{
		day = 30;
	}
	week = zeller(year, month, 1);
	calendar(year, month, day, week);
	return 0;
}