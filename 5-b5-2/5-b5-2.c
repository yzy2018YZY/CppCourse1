//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[3][10];
int top[3];

void print_stack(int layer)
{
	int i;
	printf(" A:");
	for (i = 0; i < top[0]; i++)
	{
		printf("%2d", stack[0][i]);
	}
	for (i = top[0]; i < 10; i++)
	{
		printf("  ");
	}
	printf(" B:");
	for (i = 0; i < top[1]; i++)
	{
		printf("%2d", stack[1][i]);
	}
	for (i = top[1]; i < 10; i++)
	{
		printf("  ");
	}
	printf(" C:");
	for (i = 0; i < top[2]; i++)
	{
		printf("%2d", stack[2][i]);
	}
	for (i = top[2]; i < 10; i++)
	{
		printf("  ");
	}
	printf("\n");
}

void Hanoi(int layer, char start, char end)
{
	static int steps = 0;
	if (layer == 1)
	{
		printf("第%4d 步(%2d): %c-->%c", ++steps, layer, start, end);
		stack[end - 'A'][top[end - 'A']++] = stack[start - 'A'][--top[start - 'A']];
		print_stack(layer);
		return;
	}
	char middle;
	middle = 'A' + 'B' + 'C' - start - end;
	Hanoi(layer - 1, start, middle);
	printf("第%4d 步(%2d): %c-->%c", ++steps, layer, start, end); 
	stack[end - 'A'][top[end - 'A']++] = stack[start - 'A'][--top[start - 'A']];
	print_stack(layer);
	Hanoi(layer - 1, middle, end);
}

int main()
{
	int layer;
	char start, end;
	int i;
	while (1)
	{
		printf("请输入汉诺塔的层数(1-10): \n");
		scanf("%d", &layer);
		while (getchar() != '\n')
			;
		if (layer <= 0 || layer > 10)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入起始柱(A-C): \n");
		scanf("%c", &start);
		while (getchar() != '\n')
			;
		if (!((start >= 'A' && start <= 'C') || (start >= 'a' && start <= 'c')))
		{
			continue;
		}
		start = (start >= 'a' && start <= 'c') ? start - ('a' - 'A') : start;
		break;
	}
	while (1)
	{
		printf("请输入目标柱(A-C): \n");
		scanf("%c", &end);
		while (getchar() != '\n')
			;
		if (!((end >= 'A' && end <= 'C') || (end >= 'a' && end <= 'c')))
		{
			continue;
		}
		if (start == end)
		{
			printf("目标柱(%c)不能与起始柱(%c)相同\n", end, start);
			continue;
		}
		end = (end >= 'a' && end <= 'c') ? end - ('a' - 'A') : end;
		break;
	}
	for (i = 0; i < layer; i++)
	{
		stack[start - 'A'][i] = layer - i;
	}
	top[start - 'A'] = layer;
	printf("初始:               ");
	print_stack(layer);
	Hanoi(layer, start, end);
	return 0;
}
