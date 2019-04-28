//1850059 计1班 杨志远

#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

int main()
{
	char str[80], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* 上面的定义不准动，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */

	cout << "请输入间隔有若干正负数字的字符串" << endl;
	for (p = str; p < str + 80; p++)
	{
		*p = getchar();
		if (*p == '\n')
		{
			*p = '\0';
			break;
		}
	}
	pnum = a;
	is_num = false;
	for (p = str; *p != '\0' && pnum - a < N; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			is_num = true;
			*pnum = *pnum * 10 + *p - '0';
		}
		else
		{
			if (is_num == true)
			{
				pnum++;
			}
			is_num = false;
		}
	}
	cout << "共有" << pnum - a + bool(*(p - 1) >= '0' && *(p - 1) <= '9') << "个整数" << endl;
	for (pa = a; pa <= pnum - 1 + bool(*(p - 1) >= '0' && *(p - 1) <= '9'); pa++)
	{
		cout << *pa << " ";
	}
	cout << endl;
	return 0;
}
