//1850059 ��1�� ��־Զ

#include <iostream>
#include <string.h>
using namespace std;

const int length = 85;

bool isBig(char x)
{
	if (x >= 'A' && x <= 'Z')
		return true;
	else
		return false;
}

bool isSmall(char x)
{
	if (x >= 'a' && x <= 'z')
		return true;
	else
		return false;
}

bool isNum(char x)
{
	if (x >= '0' && x <= '9')
		return true;
	else
		return false;
}

bool isBlank(char x)
{
	if (x == ' ')
		return true;
	else
		return false;
}

int main()
{
	char str[3][length];
	int big = 0, small = 0, num = 0, blank = 0, other = 0;
	cout << "�������1��" << endl;
	fgets(str[0], length, stdin);
	cout << "�������2��" << endl;
	fgets(str[1], length, stdin);
	cout << "�������3��" << endl;
	fgets(str[2], length, stdin);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < (int)strlen(str[i]) - 1; j++)
		{
			if (isBig(str[i][j]))
				big++;
			else if (isSmall(str[i][j]))
				small++;
			else if (isNum(str[i][j]))
				num++;
			else if (isBlank(str[i][j]))
				blank++;
			else
				other++;
		}
	}
	cout << "��д : " << big << endl;
	cout << "Сд : " << small << endl;
	cout << "���� : " << num << endl;
	cout << "�ո� : " << blank << endl;
	cout << "���� : " << other << endl;
	return 0;
}