//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

int func(int n)
{
	if (n == 1)
		return 1;
	else
		return n * n + func(n - 1);
}

int main()
{
	int n;
	cout << "��1^2+...+n^2,������n" << endl;
	cin >> n;
	cout << "1^2+...+" << n << "^2" << "=" << func(n) << endl;
	return 0;
}
