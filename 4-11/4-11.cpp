//1850059 计1班 杨志远

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
	cout << "求1^2+...+n^2,请输入n" << endl;
	cin >> n;
	cout << "1^2+...+" << n << "^2" << "=" << func(n) << endl;
	return 0;
}
