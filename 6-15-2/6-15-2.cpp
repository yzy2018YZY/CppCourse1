//1850059 ��1�� ��־Զ

#include <iostream>
#include <iomanip>
using namespace std;

/* ���һ�ſε�ƽ���� */
void average(int(*a)[4])
{
	double sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum = sum + *(*a + i);
	}
	cout << sum / 4;
}

/* �ҳ����������Ͽγ̲������ѧ�� */
void fail(int(*a)[4])
{
	int count = 0;
	double sum = 0;
	for (int j = 0; j < 4; j++)
	{
		count = 0;
		sum = 0;
		for (int(*p)[4] = a; p != a + 5; p++)
		{
			sum += *(*p + j);
			if (*(*p + j) < 60)
			{
				count++;
			}
		}
		if (count >= 2)
		{
			cout << "No: " << j + 1 << " ";
			for (int(*p)[4] = a; p != a + 5; p++)
			{
				cout << *(*p + j) << " ";
			}
			cout << "ƽ��: " << sum / 5 << endl;
		}
	}
}

/* �ҳ�ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ�� */
void good(int(*a)[4])
{
	int count = 0;
	double sum = 0;
	for (int j = 0; j < 4; j++)
	{
		count = 0;
		sum = 0;
		for (int(*p)[4] = a; p != a + 5; p++)
		{
			sum += *(*p + j);
			if (*(*p + j) >= 85)
			{
				count++;
			}
		}
		if (count == 5 || sum / 5 >= 90)
		{
			cout << "No: " << j + 1 << " ";
			for (int(*p)[4] = a; p != a + 5; p++)
			{
				cout << *(*p + j) << " ";
			}
			cout << "ƽ��: " << sum / 5 << endl;
		}
	}
}

int main()
{
	int a[5][4] = { {91,92,93,97},  //��1-4��ѧ���ĵ�1�ſγɼ�
		{81,82,83,85},  //��1-4��ѧ���ĵ�2�ſγɼ�
		{71,72,99,87},  //��1-4��ѧ���ĵ�3�ſγɼ�
		{61,32,80,91},  //��1-4��ѧ���ĵ�4�ſγɼ�
		{51,52,95,88} };//��1-4��ѧ���ĵ�5�ſγɼ�
	cout << "��ʼ��Ϣ:" << endl;
	for (int(*p)[4] = a; p != a + 5; p++)
	{
		cout << "No.1-4ѧ���ĵ�" << p - a + 1 << "�ſγɼ�: ";
		for (int j = 0; j < 4; j++)
		{
			cout << *(*p + j) << " ";
		}
		cout << endl;
	}
	cout << endl << "��1�ſ�ƽ����: ";
	average(a);
	cout << endl << endl << "2�����ϲ������ѧ��: " << endl;
	fail(a);
	cout << endl << "ƽ��90���ϻ���ȫ��85���ϵ�ѧ��: " << endl;
	good(a);
	return 0;
}