#define _CRT_SECURE_NO_WARNINGS  //VS2017��Ҫ
#include <iostream>
using namespace std;

int main()
{
	char a[3][30] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
				   "abcdefghijklmnopqrstuvwxyz",
				   "0123456789" };

	scanf("%s", &a[1][3]);//&+������+˫�±�

	cout << "a[0]=" << a[0] << endl;
	cout << "a[1]=" << a[1] << endl;
	cout << "a[2]=" << a[2] << endl;

	return 0;
}
