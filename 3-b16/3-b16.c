//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, week, day;
	int i;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		if (!(scanf("%d", &year)))
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("�����������������\n");
			continue;
		}
		if (!(scanf("%d", &month)))
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("�����������������\n");
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
			printf("�����������������\n");
		}
	}
	while (1)
	{
		printf("������%d��%d��1�յ�����(0 - 6��ʾ������ - ������) : ", year, month);
		if (!(scanf("%d", &week)))
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("�����������������\n");
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
			printf("�����������������\n");
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
	printf("\n%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
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
