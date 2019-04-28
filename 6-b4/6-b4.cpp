//1850059 计1班 杨志远

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
	cout << "请输入一个长度小于" << maxLength << "的字符串（回文串）" << endl;
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