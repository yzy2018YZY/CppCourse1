//1850059 ��1�� ��־Զ

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
	printf("����a!+b!+c!,������a,b,c��ֵ\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("%d!+%d!+%d!=%d\n", a, b, c, fac(a) + fac(b) + fac(c));
	return 0;
}