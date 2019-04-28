//1850059 计1班 杨志远

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
	cout << "请输入整数的数量n(" << minN << "-" << maxN << "):" << endl;
	cin >> n;
	cout << "请输入" << n << "个整数:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> *(num + i);
	}
	cout << "输入的整数序列为:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<  *(num + i) << " ";
	}
	cout << endl << "请输入向后移动的位置m(≥1):" << endl;
	cin >> m;
	m = m % n;
	cout << "移动后的整数序列为:" << endl;
	moveArray(num, m, n);
	for (int i = 0; i < n; i++)
	{
		cout << *(num + i) << " ";
	}
	cout << endl;
	return 0;
}