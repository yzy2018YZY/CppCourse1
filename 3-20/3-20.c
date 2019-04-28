//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <stdio.h>

int main()
{
	int sum = 0, i, j;
	for (i = 2; i < 1000; i++)
	{
		sum = 0;
		for (j = 1; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		if (i == sum)
		{
			printf("%d,its factors are 1", i);
			for (j = 2; j <= i / 2; j++)
			{
				if (i % j == 0)
				{
					printf(",%d", j);
				}
			}
			printf("\n");
		}
	}
	return 0;
}