//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num;
	printf("������һ��[1...30000]�������\n");
	scanf("%d", &num);
	printf("��λ : %d\n", num / 10000);
	printf("ǧλ : %d\n", (num % 10000) / 1000);
	printf("��λ : %d\n", (num % 1000) / 100);
	printf("ʮλ : %d\n", (num % 100) / 10);
	printf("��λ : %d\n", num % 10);
	return 0;
}