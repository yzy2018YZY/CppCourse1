#include <iostream>
using namespace std;

static int static_global_number2;
int global_number;

void test_sub()
{
	static int a = 5;
	a = 6;
	cout << "����test_sub�ķֲ����Ե���ʾ" 
		<< static_global_number2++ << " " << global_number << endl;
}