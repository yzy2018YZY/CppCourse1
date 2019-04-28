//1850059 ��1�� ��־Զ
/*����֤ 1851573 ��� 1852101 ��Ǭ 1852822 ������ 1851726 ��һ�� 1853466 ���°� �����봮����*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define passwordCounts 10
#define maxPasswordLength 16

int main()
{
	char password[maxPasswordLength + 1];
	int passwordLength, upperCh, lowerCh, numberCh, otherCh;
	int upperChCount = 0, lowerChCount = 0, numberChCount = 0, otherChCount = 0;
	int i, j;
	for(i = 0; i < 5; i++)
		fgets(password, 1024, stdin);
	scanf("%d%d%d%d%d", &passwordLength, &upperCh, &lowerCh, &numberCh, &otherCh);
	for (j = 0; j < passwordCounts; j++)
	{
		scanf("%s", password);
		if (strlen(password) != passwordLength)
		{
			printf("����\n",);
			return 0;
		}
		for (i = 0; i < passwordLength; i++)
		{
			if (password[i] >= 'A' && password[i] <= 'Z')
				upperChCount++;
			else if (password[i] >= 'a' && password[i] <= 'z')
				lowerChCount++;
			else if (password[i] >= '0' && password[i] <= '9')
				numberChCount++;
			else if(password[i] >= 33 && password[i] <= 126)
				otherChCount++;
			else
			{
			    printf("����\n");
			    return 0;
		    }
		}
		if (upperCh > upperChCount || lowerCh > lowerChCount
			|| numberCh > numberChCount || otherCh > otherChCount)
		{
			printf("����\n");
			return 0;
		}
	}
	printf("��ȷ\n");
	return 0;
}
