//1850059 ��1�� ��־Զ

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
	printf("����������������n(%d-%d):\n", minN, maxN);
	scanf("%d", &n);
	printf("������%d������:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", num + i);
	}
	printf("�������������Ϊ:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(num + i));
	}
	printf("\n����������ƶ���λ��m(��1):\n");
	scanf("%d", &m);
	m = m % n; // ȡ�࣬��С������
	printf("�ƶ������������Ϊ:\n");
	moveArray(num, m, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(num + i));
	}
	printf("\n");
	return 0;
}
