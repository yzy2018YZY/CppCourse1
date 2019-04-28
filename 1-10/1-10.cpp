//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int add(int x, int y);

int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);
	return 0;
}

void sort(int x, int y, int z)
{
	int temp;
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}
	if (z < x) cout << z << ',' << x << ',' << y << endl;
	else if (z < y) cout << x << ',' << z << ',' << y << endl;
	else cout << x << ',' << y << ',' << z << endl;
}


/*  程序功能：
    输入：三个整数
    输出：按照从小到大的顺序输出这三个整数  */