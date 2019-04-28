//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	char a[80];
#if (defined __GNUC__ && defined _WIN32) || (defined __GNUC__ && defined _WIN64)
	gets(a);
#elif(defined _MSC_VER)
	gets_s(a);
#elif(defined __linux)
	fgets(a, 80, stdin);
#endif

	cout << a << endl;
	return 0;
}
