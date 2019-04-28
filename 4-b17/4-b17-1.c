//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int steps = 0;

void Hanoi(int layer, char start, char end)
{
	if (layer == 1)
	{
		printf("%5d : %d# %c-->%c\n", ++steps, layer, start, end);
		return;
	}
	char middle;
	if (start == 'A' && end == 'C' || start == 'C' && end == 'A')
		middle = 'B';
	if (start == 'B' && end == 'C' || start == 'C' && end == 'B')
		middle = 'A';
	if (start == 'A' && end == 'B' || start == 'B' && end == 'A')
		middle = 'C';
	Hanoi(layer - 1, start, middle);
	printf("%5d : %d# %c-->%c\n", ++steps, layer, start, end);
	Hanoi(layer - 1, middle, end);
}

int main()
{
	int layer;
	char start, end;
	while (1)
	{
		printf("�����뺺ŵ���Ĳ���(1-16):\n");
		if (!scanf("%d", &layer))
		{
			while (getchar() != '\n')
				;
		}
		else if (layer <= 0 || layer > 16)
		{
			while (getchar() != '\n')
				;
		}
		else
		{
			while (getchar() != '\n')
				;
			break;
		}
	}
	while (1)
	{
		printf("��������ʼ��(A-C):\n");
		scanf("%c", &start);
		while (getchar() != '\n')
			;
		if (!(start >= 'A' && start <= 'C' || start >= 'a' && start <= 'c'))
			continue;
		start = (start >= 'a' && start <= 'c') ? start - ('a' - 'A') : start;
		break;
	}
	while (1)
	{
		printf("������Ŀ����(A-C):\n");
		scanf("%c", &end);
      while (getchar() != '\n')
			;
		if (!(end >= 'A' && end <= 'C' || end >= 'a' && end <= 'c'))
			continue;
		if (start == end)
		{
			printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", end, start);
			continue;
		}
		end = (end >= 'a' && end <= 'c') ? end - ('a' - 'A') : end;
		break;
	}
	printf("�ƶ�����Ϊ:\n");
	Hanoi(layer, start, end);
	return 0;
}
