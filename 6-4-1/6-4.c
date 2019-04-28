//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define minN (10)
#define maxN (20)

void moveArray(int *a, int m, int n)
{
	int temp, j, i;
	for (j = 0; j < m; j++)
	{
		temp = *(a + n - 1);
		for (i = n - 2; i >= 0; i--)
		{
			*(a + i + 1) = *(a + i);
		}
		*a = temp;
	}
}

int main()
{
	int m, n, num[maxN], i;
	printf("请输入整数的数量n(%d-%d):\n", minN, maxN);
	scanf("%d", &n);
	printf("请输入%d个整数:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", num + i);
	}
	printf("输入的整数序列为:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(num + i));
	}
	printf("\n请输入向后移动的位置m(≥1):\n");
	scanf("%d", &m);
	m = m % n; // 取余，减小运算量
	printf("移动后的整数序列为:\n");
	moveArray(num, m, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(num + i));
	}
	printf("\n");
	return 0;
}
