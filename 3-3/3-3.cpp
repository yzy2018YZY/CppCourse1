//1850059 ��1�� ��־Զ

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double F;
	cout << "�����뻪���¶�" << endl;
	cin >> F;
	cout << "�����¶� : " << setprecision(2) << setiosflags(ios::fixed) << 5.0 / 9.0 * (F - 32) << endl;
	return 0;
}