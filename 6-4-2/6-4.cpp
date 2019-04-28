//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

const int minN = 10;
const int maxN = 20;

void moveArray(int *a, int m, int n)
{
	int tempNum[maxN];
	for (int i = 0; i < n; i++)
	{
		*(tempNum + (i + m) % n) = *(a + i);
	}
	for (int i = 0; i < n; i++)
	{
		*(a + i) = *(tempNum + i);
	}
}

int main()
{
	int m, n, num[maxN];
	cout << "����������������n(" << minN << "-" << maxN << "):" << endl;
	cin >> n;
	cout << "������" << n << "������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> *(num + i);
	}
	cout << "�������������Ϊ:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<  *(num + i) << " ";
	}
	cout << endl << "����������ƶ���λ��m(��1):" << endl;
	cin >> m;
	m = m % n;
	cout << "�ƶ������������Ϊ:" << endl;
	moveArray(num, m, n);
	for (int i = 0; i < n; i++)
	{
		cout << *(num + i) << " ";
	}
	cout << endl;
	return 0;
}