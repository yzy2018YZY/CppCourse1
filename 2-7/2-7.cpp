//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	int i, j, m, n;
	i = 8;
	j = 10;
	m = ++i + j++;
	n = (++i) + (++j) + m;
	cout << i << '\t' << j << '\t' << m << '\t' << n << endl;
	return 0;
}

/*  程序功能：
	输入：无
	输出：依次输出i，j，m，n并用制表符分隔
	      10 (制表符) 12 (制表符) 19 (制表符) 41 (回车)
*/