//1850059 计1班 杨志远
/*已验证 1851573 李博宇 1852101 曹乾 1852822 李宇龙 1851726 汪一泓 1853466 胡新邦 的扫雷内部数组*/

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
	//读取和处理数据
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

	//判断地雷数
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
		printf("错误%d\n", booms);
		return 0;
	}

	//判断数字
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
				printf("错误\n");
				return 0;
			}
		}
	}
	
	printf("正确\n");
	return 0;
}
