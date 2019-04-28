//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	const char *monthStr[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int month;
	cout << "请输入月份数(1-12)" << endl;
	if (!(cin >> month) || month < 1 || month > 12)
	{
		cout << "Invalid" << endl;
	}
	else
	{
		cout << *(monthStr + month - 1) << endl;
	}
	return 0;
}