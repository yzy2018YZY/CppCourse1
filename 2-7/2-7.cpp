//1850059 ��1�� ��־Զ

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

/*  �����ܣ�
	���룺��
	������������i��j��m��n�����Ʊ���ָ�
	      10 (�Ʊ��) 12 (�Ʊ��) 19 (�Ʊ��) 41 (�س�)
*/