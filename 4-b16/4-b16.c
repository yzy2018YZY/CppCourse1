//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double a, b, c;

void aEqualZero()
{
	printf("不是一元二次方程\n");
}

void deltaOverZero()
{
	double delta = b * b - 4 * a * c;
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (x1 < x2)
	{
		double temp = x1;
		x1 = x2;
		x2 = temp;
	}
	printf("有两个不等实根:\n");
	printf("x1=%f\n" ,x1);
	printf("x2=%f\n", x2);
}

void deltaEqualZero()
{
	double x = -b / (2 * a);
	printf("有两个相等实根:\n");
	printf("x1=x2=%f\n" ,x);
}

void deltaUnderZero()
{
	double delta = b * b - 4 * a * c;
	printf("有两个虚根:\n");
	double x1 = sqrt(-delta) / (2 * a);
	if (x1 < 0)
	{
		x1 = -x1;
	}
	printf("x1=");
	if (fabs(-b / (2 * a)) > 1e-10)
	{
		printf("%f", -b / (2 * a));
		printf("+");
	}
	if (fabs(x1 - 1) > 1e-10 && fabs(x1 + 1) > 1e-10)
	{
		printf("%f", x1);
	}
	if (fabs(x1 + 1) < 1e-10)
	{
		printf("-");
	}
	printf("i\n");
	double x2 = -x1;
	printf("x2=");
	if (fabs(-b / (2 * a)) > 1e-10)
	{
		printf("%f", -b / (2 * a));
	}
	if (fabs(x2 - 1) > 1e-10 && fabs(x2 + 1) > 1e-10)
	{
		printf("%f", x2);
	}
	if (fabs(x2 + 1) < 1e-10)
	{
		printf("-");
	}
	printf("i\n");
}

int main()
{
	while (1)
	{
		printf("请输入一元二次方程的三个系数:\n");
		if (scanf("%lf%lf%lf", &a, &b, &c) != 3)
		{
			while (getchar() != '\n')
				;
			continue;
		}
		break;
	}
	double delta = b * b - 4 * a * c;
	if (a == 0)
	{
		aEqualZero();
	}
	else if (delta > 0)
	{
		deltaOverZero();
	}
	else if (fabs(delta) < 1e-7)
	{
		deltaEqualZero();
	}
	else
	{
		deltaUnderZero();
	}
	return 0;
}
