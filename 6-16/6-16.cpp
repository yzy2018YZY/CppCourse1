//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

int main()
{
	char str[80], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* ����Ķ��岻׼��������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */

	cout << "���������������������ֵ��ַ���" << endl;
	for (p = str; p < str + 80; p++)
	{
		*p = getchar();
		if (*p == '\n')
		{
			*p = '\0';
			break;
		}
	}
	pnum = a;
	is_num = false;
	for (p = str; *p != '\0' && pnum - a < N; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			is_num = true;
			*pnum = *pnum * 10 + *p - '0';
		}
		else
		{
			if (is_num == true)
			{
				pnum++;
			}
			is_num = false;
		}
	}
	cout << "����" << pnum - a + bool(*(p - 1) >= '0' && *(p - 1) <= '9') << "������" << endl;
	for (pa = a; pa <= pnum - 1 + bool(*(p - 1) >= '0' && *(p - 1) <= '9'); pa++)
	{
		cout << *pa << " ";
	}
	cout << endl;
	return 0;
}
