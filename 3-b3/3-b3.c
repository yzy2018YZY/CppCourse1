//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double num;
	printf("请输入一个[0.01-100亿)间的数字: ");
	scanf("%lf", &num);
	printf("十亿位 : %d\n", (int)(num / 1000000000));
	printf("亿位   : %d\n", ((int)(num / 100000000)) % 10);
	printf("千万位 : %d\n", ((int)(num / 10000000)) % 10);
	printf("百万位 : %d\n", ((int)(num / 1000000)) % 10);
	printf("十万位 : %d\n", ((int)(num / 100000)) % 10);
	printf("万位   : %d\n", ((int)(num / 10000)) % 10);
	printf("千位   : %d\n", ((int)(num / 1000)) % 10);
	printf("百位   : %d\n", ((int)(num / 100)) % 10);
	printf("十位   : %d\n", ((int)(num / 10)) % 10);
	num = num - ((double)(int)(num / 1000000000) * 1000000000);
	printf("圆     : %d\n", (int)num % 10);
	num = num - ((double)(int)(num / 100000000) * 100000000);
	printf("角     : %d\n", (int)(num * 10 + 0.05) % 10);
	num = num - ((double)(int)(num / 10000000) * 10000000);
	printf("分     : %d\n", (int)(num * 100 + 0.05) % 10);
	return 0;
}