//1850059 ��1�� ��־Զ

#include<iostream>
using namespace std;

int main()
{
	int year, month, day, count = 0, run4_nian2;
	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;
	run4_nian2 = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	if (day <= 0)
	{
		cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
		return 0;
	}
	switch (month)
	{
		case 1:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = day;
			break;
		case 2:
			if (day >= 29 && !run4_nian2 || day > 29 && run4_nian2)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + day;
			break;
		case 3:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + day;
			break;
		case 4:
			if (day > 30)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + day;
			break;
		case 5:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + day;
			break;
		case 6:
			if (day > 30)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + day;
			break;
		case 7:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + day;
			break;
		case 8:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + day;
			break;
		case 9:
			if (day > 30)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + day;
			break;
		case 10:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
			break;
		case 11:
			if (day > 30)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
			break;
		case 12:
			if (day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				return 0;
			}
			count = 31 + (run4_nian2 ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
			break;
		default:
			cout << "�������-�·ݲ���ȷ" << endl;
			return 0;
	}
	cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << count << "��" << endl;
	return 0;
}