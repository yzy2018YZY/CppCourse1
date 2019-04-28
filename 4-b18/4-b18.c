//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const double ANSWER = 24;

double calc(double x, double y, double xy)
{
	if (xy == 1)
		return x + y;
	else if (xy == 2)
		return x - y;
	else if (xy == 3)
		return x * y;
	else
		return (double)x / (double)y;
}

char toChar(int xy)
{
	if (xy == 1)
		return '+';
	else if (xy == 2)
		return '-';
	else if (xy == 3)
		return '*';
	else
		return '/';
}

int calc24(int a, int b, int c, int d)
{
	int ab, bc, cd, count = 0;
	for (ab = 1; ab <= 4; ab++)
	{
		for (bc = 1; bc <= 4; bc++)
		{
			for (cd = 1; cd <= 4; cd++)
			{
				if (calc(calc(calc(a, b, ab), c, bc), d, cd) == ANSWER)
				{
					count++;
					printf("((%d%c%d)%c%d)%c%d=%.0f\n", a, toChar(ab), b, toChar(bc), c, toChar(cd), d, ANSWER);
				}
				if (calc(calc(a, calc(b, c, bc), ab), d, cd) == ANSWER)
				{
					count++;
					printf("(%d%c(%d%c%d))%c%d=%.0f\n", a, toChar(ab), b, toChar(bc), c, toChar(cd), d, ANSWER);
				}
				if (calc(a, calc(b, calc(c, d, cd), bc), ab) == ANSWER)
				{
					count++;
					printf("%d%c(%d%c(%d%c%d))=%.0f\n", a, toChar(ab), b, toChar(bc), c, toChar(cd), d, ANSWER);
				}
				if (calc(a, calc(calc(b, c, bc), d, cd), ab) == ANSWER)
				{
					count++;
					printf("%d%c((%d%c%d)%c%d)=%.0f\n", a, toChar(ab), b, toChar(bc), c, toChar(cd), d, ANSWER);
				}
				if (calc(calc(a, b, ab), calc(c, b, cd), bc) == ANSWER)
				{
					count++;
					printf("(%d%c%d)%c(%d%c%d)=%.0f\n", a, toChar(ab), b, toChar(bc), c, toChar(cd), d, ANSWER);
				}
			}
		}
	}
	return count;
}

int main()
{
	int a, b, c, d;
	int count = 0;
	while (1)
	{
		printf("请输入四个（1-10）之间的整数 :\n");
		if (scanf("%d%d%d%d", &a, &b, &c, &d) != 4)
		{
			while (getchar() != '\n')
				;
			continue;
		}
		if (a < 1 || a > 10 || b < 1 || b > 10 || c < 1 || c > 10 || d < 1 || d > 10)
		{
			while (getchar() != '\n')
				;
			continue;
		}
		break;
	}
	count = calc24(a, b, c, d);
	if (count == 0)
		printf("无解\n");
	return 0;
}
