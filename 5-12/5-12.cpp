//1850059 ��1�� ��־Զ

#include <iostream>
#include <string.h>
using namespace std;

const int length = 85;

int main()
{
	char str[length];
	cout << "���������봮" << endl;
	fgets(str, length, stdin);
	cout << "ԭ��:" << str;
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
	cout << "����:" << str;
	return 0;
}