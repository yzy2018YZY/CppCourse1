//1850059 ��1�� ��־Զ
/*����֤ 1851573 ��� 1852101 ��Ǭ 1852822 ������ 1851726 ��һ�� 1853466 ���°� ��ɨ���ڲ�����*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define maxX 26
#define maxY 10
#define maxBooms 50

int main()
{
	int map[maxY + 2][maxX + 2] = { 0 };
	int realMap[maxY + 2][maxX + 2] = { 0 };
	int booms = 0;
	char tempCh;
	int i, j;
	//��ȡ�ʹ�������
	for (j = 1; j < maxY + 1; j++)
	{
		for (i = 1; i < maxX + 1; i++)
		{
			scanf("%c", &tempCh);
			if (tempCh == '*')
			{
				map[j][i] = -1;
				realMap[j][i] = -1;
			}
			else if (tempCh >= '0' && tempCh <= '9')
				map[j][i] = tempCh - '0';
			else
				i--;
		}
	}

	//�жϵ�����
	for (j = 1; j < maxY + 2; j++)
	{
		for (i = 1; i < maxX + 2; i++)
		{
			if (map[j][i] == -1)
				booms++;
		}
	}
	if (booms != maxBooms)
	{
		printf("����%d\n", booms);
		return 0;
	}

	//�ж�����
	for (j = 1; j < maxY + 2; j++)
	{
		for (i = 1; i < maxX + 2; i++)
		{
			if (realMap[j][i] != -1)
			{
				if (realMap[j - 1][i - 1] == -1)
					realMap[j][i]++;
				if (realMap[j - 1][i] == -1)
					realMap[j][i]++;
				if (realMap[j - 1][i + 1] == -1)
					realMap[j][i]++;
				if (realMap[j][i - 1] == -1)
					realMap[j][i]++;
				if (realMap[j][i + 1] == -1)
					realMap[j][i]++;
				if (realMap[j + 1][i - 1] == -1)
					realMap[j][i]++;
				if (realMap[j + 1][i] == -1)
					realMap[j][i]++;
				if (realMap[j + 1][i + 1] == -1)
					realMap[j][i]++;
			}
		}
	}
	for (j = 1; j < maxY + 1; j++)
	{
		for (i = 1; i < maxX + 1; i++)
		{
			if (map[j][i] != realMap[j][i])
			{
				printf("����\n");
				return 0;
			}
		}
	}
	
	printf("��ȷ\n");
	return 0;
}
