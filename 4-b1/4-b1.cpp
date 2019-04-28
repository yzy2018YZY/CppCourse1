//1850059 计1班 杨志远

#include <iostream>
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

int main()
{
	int year, month, day;
	while (1)
	{
		cout << "请输入年(1900-2100)、月、日:" << endl;
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
		if (!(cin >> day))
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
		if (month == 2)
		{
			if (day < 1 || day > 29 || (year % 400 != 0 && year % 100 == 0 && day > 28) || (year % 4 != 0 && day > 28))
			{
				cout << "日期输入错误，请重新输入" << endl;
				continue;
			}

		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31)
			{
				cout << "日期输入错误，请重新输入" << endl;
				continue;
			}
		}
		else
		{
			if (day > 30)
			{
				cout << "日期输入错误，请重新输入" << endl;
				continue;
			}
		}
		break;
	}
	int w = zeller(year, month, day);
	switch (w)
	{
		case 1:
		{
			cout << "星期一" << endl;
			break;
		}
		case 2:
		{
			cout << "星期二" << endl;
			break;
		}
		case 3:
		{
			cout << "星期三" << endl;
			break;
		}
		case 4:
		{
			cout << "星期四" << endl;
			break;
		}
		case 5:
		{
			cout << "星期五" << endl;
			break;
		}
		case 6:
		{
			cout << "星期六" << endl;
			break;
		}
		default:
		{
			cout << "星期日" << endl;
			break;
		}
	}
	return 0;
}