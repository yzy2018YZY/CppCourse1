//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define maxStudents   10
#define maxNameLength 10
#define maxIDLength    7

int main()
{
	char name[maxStudents][maxNameLength + 1];
	char ID[maxStudents][maxIDLength + 1];
	int score[maxStudents];
	int i;
	for (i = 0; i < maxStudents; i++)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		scanf("%s%s%d", ID[i], name[i], &score[i]);
	}
	printf("\n���������� : \n");
	for (i = 0; i < maxStudents; i++)
	{
		if (score[i] < 60)
		{
			printf("%s %s %d\n", name[i], ID[i], score[i]);
		}
	}
	return 0;
}
