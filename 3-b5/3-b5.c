//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double x, y;
	printf("请输入坐标:\n");;
	scanf("%lf%lf", &x, &y);
	printf("该点高度为:\n");;
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