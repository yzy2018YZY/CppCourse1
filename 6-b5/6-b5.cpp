//1850059 ��1�� ��־Զ

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
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << maxLength << endl;
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
