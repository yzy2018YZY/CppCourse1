//1850059 ��1�� ��־Զ

#include <iostream>
#include <iomanip>
using namespace std;

/* ���һ�ſε�ƽ���� */
void average(int(*a)[5])
{
	double sum = 0;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		sum = sum + *(*p);
	}
	cout << sum / 4;
}

/* �ҳ����������Ͽγ̲������ѧ�� */
void fail(int(*a)[5])
{
	int count = 0;
	double sum = 0;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		count = 0;
		sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum += *(*p + i);
			if (*(*p + i) < 60)
			{
				count++;
			}
		}
		if (count >= 2)
		{
			cout << "No: " << p - a + 1 << " ";
			for (int k = 0; k < 5; k++)
			{
				cout << *(*p + k) << " ";
			}
			cout << "ƽ��: " << sum / 5 << endl;
		}
	}
}

/* �ҳ�ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ�� */
void good(int(*a)[5])
{
	int count = 0;
	double sum = 0;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		count = 0;
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += *(*p + j);
			if (*(*p + j) >= 85)
			{
				count++;
			}
		}
		if (count == 5 || sum / 5 >= 90)
		{
			cout << "No: " << p - a + 1 << " ";
			for (int k = 0; k < 5; k++)
			{
				cout << *(*p + k) << " ";
			}
			cout << "ƽ��: " << sum / 5 << endl;
		}
	}
}

int main()
{
	int a[4][5] = { {91, 81, 71, 61, 51},	//��1��ѧ����1-5�ſεĳɼ�
		{92, 82, 72, 32, 52},   //��2��ѧ����1-5�ſεĳɼ�
		{93, 83, 99, 80, 95},   //��3��ѧ����1-5�ſεĳɼ�
		{97, 85, 87, 91, 88} }; //��4��ѧ����1-5�ſεĳɼ�
	cout << "��ʼ��Ϣ:" << endl;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		cout << "No." << p - a + 1 << "��1-5�ſγɼ�: ";
		for (int j = 0; j < 5; j++)
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