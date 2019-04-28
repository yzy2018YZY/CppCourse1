//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double profit;
	printf("请输入当月利润:\n");
	scanf("%lf", &profit);
	printf("应发奖金数:\n");
	if (profit <= 100000)
	{
		printf("%d\n", (int)(profit * 0.1));
	}
	else if (profit > 100000 && profit <= 200000)
	{
		printf("%d\n", (int)((profit - 100000) * 0.075 + 10000));
	}
	else if (profit > 200000 && profit <= 400000)
	{
		printf("%d\n", (int)((profit - 200000) * 0.05 + 17500));
	}
	else if (profit > 400000 && profit <= 600000)
	{
		printf("%d\n", (int)((profit - 400000) * 0.03 + 27500));
	}
	else if (profit > 600000 && profit <= 1000000)
	{
		printf("%d\n", (int)((profit - 600000) * 0.015 + 33500));
	}
	else
	{
		printf("%d\n", (int)((profit - 1000000) * 0.01 + 39500));
	}
	return 0;
}