//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	int a[25000] = {0}, size = 0, num = 0;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	while (1)
	{
		cin >> a[size++];
		if (a[size - 1] == -1)
		{
			size--;
			break;
		}
	}
	cout << "原数组为:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl << "请输入要插入的正整数:" << endl;
	cin >> num;
	cout << "插入后的数组为:" << endl;
	int i;
	for (i = size++ -1; i >= 0; i--)
	{
		if (a[i] <= num)
		{

			a[i + 1] = num;
			break;
		}
		a[i + 1] = a[i];
	}
	if (i == -1)
	{
		a[0] = num;
	}
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	return 0;
}
