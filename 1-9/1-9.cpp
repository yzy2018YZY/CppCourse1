//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

int add(int x, int y);

int main()
{
	int a, b, c;
	a = 1;
	b = 2;
	c = add(a, b);
	cout << "a + b = " << c << endl;
	return 0;
}

int add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}

/*  �������
1��main��δ�������c
2��add��δ�������z
3��δ��mainǰ����add����
4������a�ͱ���bδ��ʼ��  */