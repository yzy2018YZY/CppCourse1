//1850059 计1班 杨志远

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
	cout << "请输入第1行" << endl;
	fgets(str[0], length, stdin);
	cout << "请输入第2行" << endl;
	fgets(str[1], length, stdin);
	cout << "请输入第3行" << endl;
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
	cout << "大写 : " << big << endl;
	cout << "小写 : " << small << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << blank << endl;
	cout << "其他 : " << other << endl;
	return 0;
}