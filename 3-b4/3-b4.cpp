//1850059 计1班 杨志远

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

const double PI = 3.14159;

int main()
{
	double side1, side2, angel;
	cout << "请输入三角形的两边及夹角(角度) : ";
	cin >> side1 >> side2 >> angel;
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) 
		 << side1 * side2 * sin(angel / 180.0 * PI) / 2.0 << endl;
	return 0;
}