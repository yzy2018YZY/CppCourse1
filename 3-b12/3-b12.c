//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	while (1) {
		printf("请输入x的值(0-100)：");
		if (!scanf("%d", &x))//读入x的方式必须如此，不准用非scanf
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("输入错误\n");
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("输入错误\n");
		}
	}

	printf("x=%d\n", x);

	return 0;
}
