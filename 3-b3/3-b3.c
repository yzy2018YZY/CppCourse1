//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double num;
	printf("������һ��[0.01-100��)�������: ");
	scanf("%lf", &num);
	printf("ʮ��λ : %d\n", (int)(num / 1000000000));
	printf("��λ   : %d\n", ((int)(num / 100000000)) % 10);
	printf("ǧ��λ : %d\n", ((int)(num / 10000000)) % 10);
	printf("����λ : %d\n", ((int)(num / 1000000)) % 10);
	printf("ʮ��λ : %d\n", ((int)(num / 100000)) % 10);
	printf("��λ   : %d\n", ((int)(num / 10000)) % 10);
	printf("ǧλ   : %d\n", ((int)(num / 1000)) % 10);
	printf("��λ   : %d\n", ((int)(num / 100)) % 10);
	printf("ʮλ   : %d\n", ((int)(num / 10)) % 10);
	num = num - ((double)(int)(num / 1000000000) * 1000000000);
	printf("Բ     : %d\n", (int)num % 10);
	num = num - ((double)(int)(num / 100000000) * 100000000);
	printf("��     : %d\n", (int)(num * 10 + 0.05) % 10);
	num = num - ((double)(int)(num / 10000000) * 10000000);
	printf("��     : %d\n", (int)(num * 100 + 0.05) % 10);
	return 0;
}