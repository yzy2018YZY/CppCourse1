//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	while (1) {
		printf("������x��ֵ(0-100)��");
		if (!scanf("%d", &x))//����x�ķ�ʽ������ˣ���׼�÷�scanf
		{
			while (getchar() != '\n')
			{
				;
			}
			printf("�������\n");
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
			printf("�������\n");
		}
	}

	printf("x=%d\n", x);

	return 0;
}
