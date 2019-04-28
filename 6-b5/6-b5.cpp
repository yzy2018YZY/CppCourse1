//1850059 计1班 杨志远

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

const int maxLength = 32;

int main()
{
	char str[maxLength + 1];
	int length, result = 0;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << maxLength << endl;
	cin >> str;
	length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if (*(str + i) != '0')
		{
			result += (int)pow(2, length - i - 1);
		}
	}
	cout << (unsigned int)result << endl;
	return 0;
}
