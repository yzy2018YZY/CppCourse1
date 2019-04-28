//1850059 计1班 杨志远

#include<iostream>
#include<iomanip>
using namespace std;

const double pi = 3.14159;

int main()
{
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << "圆周长     : " << setprecision(2) << setiosflags(ios::fixed) << 2.0 * pi * r << endl;
	cout << "圆面积     : " << pi * r * r << endl;
	cout << "圆球表面积 : " << 4.0 * pi * r * r << endl;
	cout << "圆球体积   : " << 4.0 / 3.0 * pi * r * r * r << endl;
	cout << "圆柱体积   : " << pi * r * r * h << endl;
	return 0;
}