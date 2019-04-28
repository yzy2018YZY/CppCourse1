//1850059 计1班 杨志远

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
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s%s%d", ID[i], name[i], &score[i]);
	}
	printf("\n不及格名单 : \n");
	for (i = 0; i < maxStudents; i++)
	{
		if (score[i] < 60)
		{
			printf("%s %s %d\n", name[i], ID[i], score[i]);
		}
	}
	return 0;
}
