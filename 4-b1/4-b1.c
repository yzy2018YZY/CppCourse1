//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int c = y / 100, year = y % 100, month = m, w;
	if (m == 1 || m == 2)
	{
		c = (y - 1) / 100;
		year = (y - 1) % 100;
		month = m + 12;

	}
	w = (year + (int)(year / 4) + (int)(c / 4) - 2 * c + (int)(13 * (month + 1) / 5) + d - 1) % 7;
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
		printf("请输入年(1900-2100)、月、日:\n");
		if (!scanf("%d", &year))
		{
			while (getchar() != '\n')
			{
				;
			}
			//printf("输入错误，请重新输入\n");
			continue;
		}
		if (!scanf("%d", &month))
		{
			while (getchar() != '\n')
			{
				;
			}
			//printf("输入错误，请重新输入\n");
			continue;
		}
		if (!scanf("%d", &day))
		{
			while (getchar() != '\n')
			{
				;
			}
			//printf("输入错误，请重新输入\n");
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			printf("年份输入错误，请重新输入\n");
			continue;
		}
		if (month < 1 || month > 12)
		{
			printf("月份输入错误，请重新输入\n");
			continue;
		}
		if (month == 2)
		{
			if (day < 1 || day > 29 || (year % 400 != 0 && year % 100 == 0 && day > 28) || (year % 4 != 0 && day > 28))
			{
				printf("日期输入错误，请重新输入\n");
				continue;
			}

		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31)
			{
				printf("日期输入错误，请重新输入\n");
				continue;
			}
		}
		else
		{
			if (day > 30)
			{
				printf("日期输入错误，请重新输入\n");
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
			printf("星期一\n");
			break;
		}
		case 2:
		{
			printf("星期二\n");
			break;
		}
		case 3:
		{
			printf("星期三\n");
			break;
		}
		case 4:
		{
			printf("星期四\n");
			break;
		}
		case 5:
		{
			printf("星期五\n");
			break;
		}
		case 6:
		{
			printf("星期六\n");
			break;
		}
		default:
		{
			printf("星期日\n");
			break;
		}
	}
	return 0;
}