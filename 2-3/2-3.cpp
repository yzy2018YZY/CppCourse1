//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = '\101', c5 = '\116';
	cout << c1 << c2 << c3 << '\n';
	cout << "\t\b" << c4 << '\t' << c5 << '\n';
	return 0;
}

/*  程序功能：
    输入：无
	输出：第一行：abc (换行)
	第二行：(制表符)(退格一格) A (制表符) N (换行)
*/