//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

const double PI = 3.14159;

int main()
{
	double side1, side2, angel;
	printf("请输入三角形的两边及夹角(角度) : ");
	scanf("%lf%lf%lf", &side1, &side2, &angel);
	printf("三角形面积为 : %.3f\n", side1 * side2 * sin(angel / 180.0 * PI) / 2.0);
	return 0;
}