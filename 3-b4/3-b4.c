//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

const double PI = 3.14159;

int main()
{
	double side1, side2, angel;
	printf("�����������ε����߼��н�(�Ƕ�) : ");
	scanf("%lf%lf%lf", &side1, &side2, &angel);
	printf("���������Ϊ : %.3f\n", side1 * side2 * sin(angel / 180.0 * PI) / 2.0);
	return 0;
}