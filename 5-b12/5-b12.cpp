//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

bool is_run4_nian2(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

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

void calendar(int year, int month, int day[], int week[])
{
	int i, j, k;
	cout << "            " << month << "月                             " << month + 1
		<< "月                             " << month + 2 << "月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < week[month + j]; i++)
		{
			cout << "    ";
		}
		for (i = 1; i <= 7 - week[month + j]; i++)
		{
			cout << left << setw(2) << i << "  ";
		}
		cout << "    ";
	}
	for (k = 0; k < 3; k++)
	{
		cout << endl;
		for (j = 0; j < 3; j++)
		{
			for (i = 7 - week[month + j] + 1 + 7 * k; i <= 7 - week[month + j] + 7 * (k + 1) && i <= day[month + j]; i++)
			{
				cout << left << setw(2) << i << "  ";
				if (i >= day[month + j])
				{
					for (int t = i + week[month + j]; t % 7 != 0; t++)
					{
						cout << "    ";
					}
					break;
				}
			}
			cout << "    ";
		}
	}
	for (; k < 5; k++)
	{
		cout << endl;
		for (j = 0; j < 3; j++)
		{
			if (7 - week[month + j] + 1 + 7 * k <= day[month + j])
			{

				for (i = 7 - week[month + j] + 1 + 7 * k; i < 7 - week[month + j] + 1 + 7 * (k + 1)  && i <= day[month + j]; i++)
				{
					cout << left << setw(2) << i << "  ";
					if (i >= day[month + j])
					{
						for (int t = i + week[month + j]; t % 7 != 0; t++)
						{
							cout << "    ";
						}
						break;
					}
				}
			}
			else
			{
				cout << "                            ";
			}
			cout << "    ";
		}
	}
	cout << endl << endl;
}

int main()
{
	system("mode con cols=120 lines=45");
	int year;
	int day_each_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (1)
	{
		cout << "请输入年(1900-2100) : ";
		if (!(cin >> year))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			continue;
		}
		break;
	}
	cout << year << "年的月历为:" << endl << endl;
	int day[13] = { 0 }, week[13] = { 0 };
	if (is_run4_nian2(year))
		day_each_month[2]++;
	for (int i = 1; i <= 12; i += 3)
	{
		day[i] = day_each_month[i];
		day[i + 1] = day_each_month[i + 1];
		day[i + 2] = day_each_month[i + 2];
		week[i] = zeller(year, i, 1);
		week[i + 1] = zeller(year, i + 1, 1);
		week[i + 2] = zeller(year, i + 2, 1);
		calendar(year, i, day, week);
	}
	return 0;
}
