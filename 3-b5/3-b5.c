//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double x, y;
	printf("����������:\n");;
	scanf("%lf%lf", &x, &y);
	printf("�õ�߶�Ϊ:\n");;
	if (x == 0)
	{
		printf("0");
	}
	else if (y == 0)
	{
		printf("0");
	}
	else if (x > 0 && y > 0)
	{
		if (x + y <= 3)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	else if (x < 0 && y > 0)
	{
		if (x - y >= -3)
		{
			printf("2");
		}
		else
		{
			printf("0");
		}
	}
	else if (x < 0 && y < 0)
	{
		if (x + y >= -3)
		{
			printf("3");
		}
		else
		{
			printf("0");
		}
	}
	else if (x > 0 && y < 0)
	{
		if (x - y <= 3)
		{
			printf("4");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
	return 0;
}