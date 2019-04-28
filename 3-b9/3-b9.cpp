//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	int year, month, day, count = 0, run4_nian2;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	run4_nian2 = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	if (day <= 0)
	{
		cout << "输入错误-日与月的关系非法" << endl;
		return 0;
	}
	switch (month)
	{
		case 1:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = day;
			break;
		case 2:
			if (day >= 29 && !run4_nian2 || day > 29 && run4_nian2)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + day;
			break;
		case 3:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + day;
			break;
		case 4:
			if (day > 30)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + day;
			break;
		case 5:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + day;
			break;
		case 6:
			if (day > 30)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + day;
			break;
		case 7:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + day;
			break;
		case 8:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + day;
			break;
		case 9:
			if (day > 30)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + day;
			break;
		case 10:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
			break;
		case 11:
			if (day > 30)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
			break;
		case 12:
			if (day > 31)
			{
				cout << "输入错误-日与月的关系非法" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
			break;
		default:
			cout << "输入错误-月份不正确" << endl;
			return 0;
	}
	cout << year << "-" << month << "-" << day << "是" << year << "年的第" << count << "天" << endl;
	return 0;
}