//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, week, day;
	int i;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		if (!(scanf("%d", &year)))
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("输入错误，请重新输入\n");
			continue;
		}
		if (!(scanf("%d", &month)))
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("输入错误，请重新输入\n");
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
			printf("输入错误，请重新输入\n");
		}
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) : ", year, month);
		if (!(scanf("%d", &week)))
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("输入错误，请重新输入\n");
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
			printf("输入错误，请重新输入\n");
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
	printf("\n%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int count = week + 1;
	printf("  ");
	for (i = 0; i < week; i++)
	{
		printf("        ");
	}
	for (i = 1; i <= day; i++, count++)
	{
		printf("%2d      ", i);
		if (count % 7 == 0)
		{
			printf("\n  ");
		}
	}
	printf("\n");
	return 0;
}
