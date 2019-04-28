//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <string.h>
using namespace std;

const int maxLength = 85;

int main()
{
	char str[maxLength];
	cout << "«Î ‰»Î◊÷∑˚¥Æ" << endl;
	fgets(str, maxLength, stdin);
	bool blank = true;
	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			blank = true;
			
		}
		else
		{
			if (str[i] >= 'a' && str[i] <= 'z'  && blank)
			{
				str[i] = str[i] + 'A' - 'a';
			}
			else if (str[i] >= 'A' && str[i] <= 'Z' && !blank)
			{
				str[i] = str[i] + 'a' - 'A';
			}
			blank = false;
		}
	}
	cout << str;
	return 0;
}