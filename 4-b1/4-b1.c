//1850059 ��1�� ��־Զ

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
		printf("��������(1900-2100)���¡���:\n");
		if (!scanf("%d", &year))
		{
			while (getchar() != '\n')
			{
				;
			}
			//printf("�����������������\n");
			continue;
		}
		if (!scanf("%d", &month))
		{
			while (getchar() != '\n')
			{
				;
			}
			//printf("�����������������\n");
			continue;
		}
		if (!scanf("%d", &day))
		{
			while (getchar() != '\n')
			{
				;
			}
			//printf("�����������������\n");
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			printf("��������������������\n");
			continue;
		}
		if (month < 1 || month > 12)
		{
			printf("�·������������������\n");
			continue;
		}
		if (month == 2)
		{
			if (day < 1 || day > 29 || (year % 400 != 0 && year % 100 == 0 && day > 28) || (year % 4 != 0 && day > 28))
			{
				printf("���������������������\n");
				continue;
			}

		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 31)
			{
				printf("���������������������\n");
				continue;
			}
		}
		else
		{
			if (day > 30)
			{
				printf("���������������������\n");
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
			printf("����һ\n");
			break;
		}
		case 2:
		{
			printf("���ڶ�\n");
			break;
		}
		case 3:
		{
			printf("������\n");
			break;
		}
		case 4:
		{
			printf("������\n");
			break;
		}
		case 5:
		{
			printf("������\n");
			break;
		}
		case 6:
		{
			printf("������\n");
			break;
		}
		default:
		{
			printf("������\n");
			break;
		}
	}
	return 0;
}