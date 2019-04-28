//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define maxSize (20)

void merge(int *list_a, int *list_b, int *list_c)
{
	int x = 0, y = 0, z = 0;
	while (*(list_a + x) != -1 && *(list_b + y) != -1)
	{
		if (*(list_a + x) > *(list_b + y))
		{
			if (*(list_a + x) != *(list_c + z - 1))
			{
				*(list_c + z++) = *(list_a + x);
			}
			x++;
		}
		else if (*(list_a + x) < *(list_b + y))
		{
			if (*(list_b + y) != *(list_c + z - 1))
			{
				*(list_c + z++) = *(list_b + y);
			}
			y++;
		}
		else
		{
			if (*(list_b + y) != *(list_c + z - 1))
			{
				*(list_c + z++) = *(list_b + y);
			}
			x++;
			y++;
		}
	}
	while (*(list_a + x) != -1)
	{
		if (*(list_a + x) != *(list_c + z - 1))
		{
			*(list_c + z++) = *(list_a + x);
		}
		x++;
	}
	while (*(list_b + y) != -1)
	{
		if (*(list_b + y) != *(list_c + z - 1))
		{
			*(list_c + z++) = *(list_b + y);
		}
		y++;
	}
	*(list_c + z) = -1;
}

int main()
{
	int a[maxSize + 1] = { 0 }, b[maxSize + 1] = { 0 }, c[2 * maxSize + 1] = { 0 };
	int i;
	printf("请输入第1个数组，降序序列(最多%d) , 以-1结束(-1不计入内)\n", maxSize);
	for (i = 0; i < maxSize; i++)
	{
		scanf("%d", a + i);
		if (*(a + i) == -1)
		{
			break;
		}
	}
	printf("请输入第2个数组，降序序列(最多%d) , 以-1结束(-1不计入内)\n", maxSize);
	for (i = 0; i < maxSize; i++)
	{
		scanf("%d", b + i);
		if (*(b + i) == -1)
		{
			break;
		}
	}

	merge(a, b, c);

	printf("第1个数组的内容为:\n");
	for (i = 0; *(a + i) != -1; i++)
	{
		printf("%d ", *(a + i));
	}
	printf("\n第2个数组的内容为:\n");
	for (i = 0; *(b + i) != -1; i++)
	{
		printf("%d ", *(b + i));
	}
	printf("\n合并后的数组的内容为:\n");
	for (i = 0; *(c + i) != -1; i++)
	{
		printf("%d ",*(c + i));
	}
	printf("\n");
	return 0;
}
