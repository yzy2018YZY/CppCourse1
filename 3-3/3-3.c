//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double F;
	printf("请输入华氏温度\n");
	scanf("%lf", &F);
	printf("摄氏温度 : %.2f\n", 5.0 / 9.0 * (F - 32));
	return 0;
}