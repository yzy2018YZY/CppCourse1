//1850059 ��1�� ��־Զ

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

const int maxLength = 80;

int tj_strrev(char *str)
{
	int strLength = strlen(str);
	for (int i = 0; i < strLength / 2; i++)
	{
		char tempCh = *(str + i);
		*(str + i) = *(str + strLength - 1 - i);
		*(str + strLength - 1 - i) = tempCh;
	}
	return 0;
}

int main()
{
	char str[maxLength + 1], tempStr[maxLength + 1];
	cout << "������һ������С��" << maxLength << "���ַ��������Ĵ���" << endl;
	cin >> str;
	strcpy(tempStr, str);
	tj_strrev(tempStr);
	if (strcmp(tempStr, str))
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return 0;
}