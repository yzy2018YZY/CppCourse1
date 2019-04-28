//1850059 计1班 杨志远

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int x;
	while (1) {
		cout << "请输入x的值(0-100)：";
		if (!(cin >> x))//读入x的方式必须如此，不准用非cin
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误" << endl;
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误" << endl;
		}
	}

	cout << "x=" << x << endl;

	return 0;
}
