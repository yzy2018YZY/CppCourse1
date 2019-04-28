//1850059 º∆1∞‡ —Ó÷æ‘∂

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

const int maxString = 3;
const int maxLength = 30;

int main()
{
	char str[maxString][maxLength];
	cout << "please input three strings:" << endl;
	for (int i = 0; i < maxString; i++)
	{
		cin >> str[i];
	}
	for (int i = maxString - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				char tempStr[maxLength];
				strcpy(tempStr, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], tempStr);
			}
		}
	}
	for (int i = 0; i < maxString; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	return 0;
}