//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	double a = 0, b = 0, c = 0, p = 0, x1, x2, x3, y1, y2, y3;
	printf("�����������������:\n");
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
	{
		printf("������������\n");
	}
	else
	{
		p = (a + b + c) / 2;
		printf("�����ε���� : %f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	}
	return 0;
}