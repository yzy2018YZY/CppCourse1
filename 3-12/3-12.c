//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num, digit = 0;
	printf("请输入一个[0..99999]间的整数:\n");
	scanf("%d", &num);
	if (num / 10000) digit = 5;
	else if (num / 1000) digit = 4;
	else if (num / 100) digit = 3;
	else if (num / 10) digit = 2;
	else digit = 1;
	printf("%d位数\n", digit);
	printf("每位数字分别是:\n");
	switch (digit)
	{
		case 5:
			printf("%d %d %d %d %d\n", num / 10000, (num / 1000) % 10, (num / 100) % 10, (num / 10) % 10, num % 10);
			break;
		case 4:
			printf("%d %d %d %d\n", (num / 1000) % 10, (num / 100) % 10, (num / 10) % 10, num % 10);
			break;
		case 3:
			printf("%d %d %d\n", (num / 100) % 10, (num / 10) % 10, num % 10);
			break;
		case 2:
			printf("%d %d\n", (num / 10) % 10, num % 10);
			break;
		case 1:
			printf("%d \n", num);
			break;
	}
	printf("逆序输出的每位数字分别是:\n");
	switch (digit)
	{
		case 5:
			printf("%d %d %d %d %d\n", num % 10, (num / 10) % 10, (num / 100) % 10
				,(num / 1000) % 10, num / 10000);
			break;
		case 4:
			printf("%d %d %d %d\n", num % 10, (num / 10) % 10, (num / 100) % 10
				,(num / 1000) % 10);
			break;
		case 3:
			printf("%d %d %d\n", num % 10, (num / 10) % 10, (num / 100) % 10);
			break;
		case 2:
			printf("%d %d\n", num % 10, (num / 10) % 10);
			break;
		case 1:
			printf("%d\n", num % 10);
			break;
	}
	return 0;
}