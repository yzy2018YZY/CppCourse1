//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else
	{
		return 2 * (func(num - 1) + 1);
	}
}

int main()
{
	int num;
	printf("请输入第几天桃子数为1\n");
	scanf("%d", &num);
	/*for (int i = 1; i < num; i++)
	{
		original = 2 * (original + 1);
	}*/
	printf("第%d天的桃子数=%d\n", num, func(num));
	return 0;
}