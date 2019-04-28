#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

char s[11000000] = "";

char ToLower(char x)
{
	return (x >= 'A' && x <= 'Z') ? x - 'A' + 'a' : x;
}

int main()
{
	char target[12] = "";
	bool flag;
	fgets(target, 12, stdin);
	fgets(s, 11000000, stdin);
	int len = strlen(s), tLen = strlen(target);
	int count = 0, first = -1;
	for (int i = 0; i < len; i++)
	{
		flag = true;
		for (int j = 0; j < tLen - 1; j++)
		{
			if (ToLower(s[i + j]) != ToLower(target[j]))
			{
				flag = false;
				break;
			}
		}
		if (flag && (i == 0 || s[i - 1] == ' ') && (s[i + tLen - 1] == ' ' || s[i + tLen - 1] == '\n'))
		{
			count++;
			if (first == -1)
				first = i;
		}
	}
	if (count == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << count << " " << first << endl;
	}
	return 0;
}
