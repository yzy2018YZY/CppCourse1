//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int num)
{
	if (num < 0)
	{
		func(-num);
		printf("- ");
	}
	else if (num <= 9)
	{
		printf("%d ", num);
	}
	else
	{
		printf("%d ", num % 10);
		func(num / 10);
	}
}

int main()
{
	int num;
	printf("������һ������\n");
	scanf("%d", &num);
	func(num);
	printf("\n");
	return 0;
}