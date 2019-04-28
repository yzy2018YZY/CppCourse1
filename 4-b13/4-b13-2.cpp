//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

/* �˴�����fun������ʵ�� */

template <typename T>
T fun(T num)
{
	T sum = 0;
	for (T i = 1; i <= num; i++)
	{
		sum += i;
	}
	return sum;
}

/* main������׼�޸� */
int main()
{
	short          s1 = 255, s2 = s1 + 1;
	unsigned short us1 = 255, us2 = us1 + 1;
	int            i1 = 65535, i2 = i1 + 1;
	unsigned int   ui1 = 65535, ui2 = ui1 + 1;

	cout << fun(s1) << endl; //������� 32640
	cout << fun(s2) << endl; //������� -32640
	cout << fun(us1) << endl; //������� 32640
	cout << fun(us2) << endl; //������� 32896
	cout << fun(i1) << endl; //������� 2147450880
	cout << fun(i2) << endl; //������� -2147450880
	cout << fun(ui1) << endl; //������� 2147450880
	cout << fun(ui2) << endl; //������� 2147516416

	return 0;
}