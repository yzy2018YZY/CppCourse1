//1850059 ��1�� ��־Զ

#include<iostream>
#include<iomanip>
using namespace std;

const double pi = 3.14159;

int main()
{
	double r, h;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << "Բ�ܳ�     : " << setprecision(2) << setiosflags(ios::fixed) << 2.0 * pi * r << endl;
	cout << "Բ���     : " << pi * r * r << endl;
	cout << "Բ������ : " << 4.0 * pi * r * r << endl;
	cout << "Բ�����   : " << 4.0 / 3.0 * pi * r * r * r << endl;
	cout << "Բ�����   : " << pi * r * r * h << endl;
	return 0;
}