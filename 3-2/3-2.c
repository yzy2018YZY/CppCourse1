//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

const double pi = 3.14159;

int main()
{
	double r, h;
	printf("������뾶�͸߶�\n");
	scanf("%lf%lf", &r, &h);
	printf("Բ�ܳ�     : %.2f\n", 2.0 * pi * r);
	printf("Բ���     : %.2f\n", pi * r * r);
	printf("Բ������ : %.2f\n", 4.0 * pi * r * r);
	printf("Բ�����   : %.2f\n", 4.0 / 3.0 * pi * r * r * r);
	printf("Բ�����   : %.2f\n", pi * r * r * h);
	return 0;
}