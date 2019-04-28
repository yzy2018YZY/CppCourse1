//1850059 计1班 杨志远

#include <iostream>
#include <string.h>
using namespace std;

const int length = 85;

int main()
{
	char str[length];
	cout << "请输入密码串" << endl;
	fgets(str, length, stdin);
	cout << "原文:" << str;
	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'Z' - str[i] + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = 'z' - str[i] + 'a';
		}
	}
	cout << "密文:" << str;
	return 0;
}