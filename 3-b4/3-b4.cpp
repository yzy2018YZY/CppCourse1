//1850059 ��1�� ��־Զ

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

const double PI = 3.14159;

int main()
{
	double side1, side2, angel;
	cout << "�����������ε����߼��н�(�Ƕ�) : ";
	cin >> side1 >> side2 >> angel;
	cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) 
		 << side1 * side2 * sin(angel / 180.0 * PI) / 2.0 << endl;
	return 0;
}