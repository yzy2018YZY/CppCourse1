//1850059 计1班 杨志远

//使用了Windows API
//Dev C++和CodeBlocks因为无法编译Windows API的部分，因此设置为不显示效果

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
using namespace std;

const int DELAY = 100;
const double PI = 3.14159;

/*********************************
0=黑色1=蓝色2=绿色3=湖蓝色4=红色
5=紫色6=黄色7=白色8=灰色9=淡蓝色
A=淡绿色B=淡浅绿色C=淡红色D=淡紫色
E=淡黄色F=亮白色
*********************************/
#define COLOR_1 RGB(0, 255, 255)//横线
#define COLOR_2 RGB(255, 0, 255)//竖线
#define COLOR_3 RGB(255, 255, 0)//曲线
#define COLOR_4 RGB(255, 255, 255)//小球
const int MON_COLOR = 0x08;//周一至周五
const int SAT_COLOR = 0x04;//周六
const int SUN_COLOR = 0x01;//周日
const int ORDINARY_COLOR_1 = 0x0F;//星期
const int ORDINARY_COLOR_2 = 0x0E;//月份
const int ORDINARY_COLOR_3 = 0xB0;//未使用

bool is_run4_nian2(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

inline void printBlank()
{
	cout << "        ";
}

void setColor(HANDLE Screen, int num)
{
	if (num == 6)
	{
		SetConsoleTextAttribute(Screen, SAT_COLOR);
	}
	else if (num == 0)
	{
		SetConsoleTextAttribute(Screen, SUN_COLOR);
	}
	else if (num == -1)
	{
		SetConsoleTextAttribute(Screen, ORDINARY_COLOR_1);
	}
	else if (num == -2)
	{
		SetConsoleTextAttribute(Screen, ORDINARY_COLOR_2);
	}
	else if (num == -3)
	{
		SetConsoleTextAttribute(Screen, ORDINARY_COLOR_3);
	}
	else
	{
		SetConsoleTextAttribute(Screen, MON_COLOR);
	}
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
	w = 7 - (-w) % 7;
	return w;
}

void calendar(HANDLE Screen, int year, int month, int day[], int week[])
{
	int i, j, k;
	printBlank();
	setColor(Screen, -2);
	cout << "           ";
	cout << right << setw(2) << month << "月";
	cout << "                            ";
	cout << right << setw(2) << month + 1 << "月";
	cout << "                            ";
	cout << right << setw(2) << month + 2 << "月" << endl;
	printBlank();
	setColor(Screen, -1);
	cout << "一  二  三  四  五  六  日      ";
	cout << "一  二  三  四  五  六  日      ";
	cout << "一  二  三  四  五  六  日      " << endl;
	printBlank();
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < week[month + j]; i++)
		{
			cout << "    ";
		}
		for (i = 1; i <= 7 - week[month + j]; i++)
		{
			setColor(Screen, (i + week[month + j]) % 7);
			cout << left << setw(2) << i << "  ";
		}
		cout << "    ";
	}
	setColor(Screen, -1);
	for (k = 0; k < 3; k++)
	{
		cout << endl;
		printBlank();
		for (j = 0; j < 3; j++)
		{
			for (i = 7 - week[month + j] + 1 + 7 * k; i <= 7 - week[month + j] + 7 * (k + 1) && i <= day[month + j]; i++)
			{
				setColor(Screen, (i + week[month + j]) % 7);
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
		printBlank();
		for (j = 0; j < 3; j++)
		{
			if (7 - week[month + j] + 1 + 7 * k <= day[month + j])
			{
				for (i = 7 - week[month + j] + 1 + 7 * k; i < 7 - week[month + j] + 1 + 7 * (k + 1) && i <= day[month + j]; i++)
				{
					setColor(Screen, (i + week[month + j]) % 7);
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
	setColor(Screen, -1);
	cout << endl << endl;
}

void decoreate(HANDLE Screen)
{
#ifdef _MSC_VER
	static int times = 0;
	HWND hwnd;
	HDC hdc;
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	HPEN hpen1 = CreatePen(PS_SOLID, 1, COLOR_1);
	HPEN hpen2 = CreatePen(PS_SOLID, 1, COLOR_2);
	HPEN hpen3 = CreatePen(PS_SOLID, 1, COLOR_3);
	HPEN hpen4 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HBRUSH hbrush1 = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hbrush2 = CreateSolidBrush(COLOR_4);
	SelectObject(hdc, hpen1);
	MoveToEx(hdc, 50, 190, NULL);
	LineTo(hdc, 900, 190);
	MoveToEx(hdc, 50, 350, NULL);
	LineTo(hdc, 900, 350);
	MoveToEx(hdc, 50, 510, NULL);
	LineTo(hdc, 900, 510);

	SelectObject(hdc, hpen2);
	MoveToEx(hdc, 330, 30, NULL);
	LineTo(hdc, 330, 670);
	MoveToEx(hdc, 620, 30, NULL);
	LineTo(hdc, 620, 670);

	SelectObject(hdc, hpen3);
	SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
	Arc(hdc, 0, 0, 1000, 30, 0, 30, 1000, 30);
	Arc(hdc, 900, 50, 950, 700, 900, 50, 900, 700);
	SetArcDirection(hdc, AD_CLOCKWISE);
	Arc(hdc, 0, 670, 1000, 670 + 40, 0, 670, 1000, 670);
	Arc(hdc, 0, 50, 50, 700, 50, 50, 50, 700);
	if (times++ >= 360)
	{
		times -= 360;
	}
	SelectObject(hdc, hpen4);
	SelectObject(hdc, hbrush1);
	Ellipse(hdc, 465 + (int)(20 * cos((times - 1) * PI / 180 * 30)), 700,
		480 + (int)(20 * cos((times - 1) * PI / 180 * 30)), 715);
	Ellipse(hdc, 950, 350 + (int)(20 * sin((times - 1) * PI / 180 * 30)),
		965, 365 + (int)(20 * sin((times - 1) * PI / 180 * 30)));
	Ellipse(hdc, 950 + (int)(20 * cos((times - 1) * PI / 180 * 30)),
		700 + (int)(20 * sin((times - 1) * PI / 180 * 30)),
		965 + (int)(20 * cos((times - 1) * PI / 180 * 30)),
		715 + (int)(20 * sin((times - 1) * PI / 180 * 30)));
	SelectObject(hdc, hbrush2);
	SelectObject(hdc, hpen4);
	Ellipse(hdc, 465 + (int)(20 * cos(times * PI / 180 * 30)), 700,
		(int)(480 + 20 * cos(times * PI / 180 * 30)), 715);
	Ellipse(hdc, 950, 350 + (int)(20 * sin(times * PI / 180 * 30)),
		965, 365 + (int)(20 * sin(times * PI / 180 * 30)));
	Ellipse(hdc, 950 + (int)(20 * cos(times * PI / 180 * 30)),
		700 + (int)(20 * sin(times * PI / 180 * 30)),
		965 + (int)(20 * cos(times * PI / 180 * 30)),
		715 + (int)(20 * sin(times * PI / 180 * 30)));
	ReleaseDC(hwnd, hdc);
#endif
}

int main()
{
	HANDLE Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con cols=120 lines=42");
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
	system("cls");
	cout << year << "年的月历为:" << endl << endl;
	int day[13] = { 0 }, week[13] = { 0 };
	if (is_run4_nian2(year))
		day_each_month[2]++;
	for (int i = 1; i <= 12; i += 3)
	{
		day[i] = day_each_month[i];
		day[i + 1] = day_each_month[i + 1];
		day[i + 2] = day_each_month[i + 2];
		week[i] = (zeller(year, i, 1) - 1 + 7) % 7;
		week[i + 1] = (zeller(year, i + 1, 1) - 1 + 7) % 7;;
		week[i + 2] = (zeller(year, i + 2, 1) - 1 + 7) % 7;;
		calendar(Screen, year, i, day, week);
	}
#ifdef _MSC_VER
	while (1)
	{
		decoreate(Screen);
		Sleep(DELAY);
	}
#endif
	return 0;
}
