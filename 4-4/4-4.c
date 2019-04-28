//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fac(int x)
{
	if (x == 0 || x == 1)
		return 1;
	else
		return x * fac(x - 1);
}

int main()
{
	int a, b, c;
	printf("计算a!+b!+c!,请输入a,b,c的值\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("%d!+%d!+%d!=%d\n", a, b, c, fac(a) + fac(b) + fac(c));
	return 0;
}